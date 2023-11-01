/*
* K2HASH PHP Extension library
*
* Copyright 2015 Yahoo Japan Corporation.
*
* K2HASH is key-valuew store base libraries.
* K2HASH is made for the purpose of the construction of
* original KVS system and the offer of the library.
* The characteristic is this KVS library which Key can
* layer. And can support multi-processing and multi-thread,
* and is provided safely as available KVS.
*
* For the full copyright and license information, please view
* the LICENSE file that was distributed with this source code.
*
* AUTHOR:   Takeshi Nakatani
* CREATE:   Tue, Feb 22 2022
* REVISION:
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

// cppcheck-suppress missingInclude
#include "php.h"
#include "php_k2hash.h"

/* {{{ internal structures */
//
// internal staructure
//
typedef struct _k2h_da_stream_info {
	k2h_da_h	dahandle;
	int			mode;
	bool		need_close_handle;
	k2h_h		handle;
} K2HDA_STREAM_INFO, *PK2HDA_STREAM_INFO;
/* }}} internal structures for k2hash php_stream */

/* {{{ functions for php_stream_ops */
/* {{{ k2hpx_da_write */
static ssize_t k2hpx_da_write(php_stream* stream, const char* buf, size_t count)
{
	if(!stream || !stream->abstract || !buf) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_write: parameter is wrong.");
		return 0;
	}
	if(0 == count) {
		return 0;
	}
	PK2HDA_STREAM_INFO	pinfo = (PK2HDA_STREAM_INFO)stream->abstract;
	if(K2H_DA_WRITE != pinfo->mode && K2H_DA_RW != pinfo->mode) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_write: stream does not open for writing.");
		return 0;
	}
	// write
	off_t	woffset	= k2h_da_get_write_offset(pinfo->dahandle);	// backup
	if(!k2h_da_set_value(pinfo->dahandle, (const unsigned char*)buf, count)) {
		// try to reset write offset
		k2h_da_set_write_offset(pinfo->dahandle, woffset);
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_write: failed to write data.");
		return 0;
	}
	// get offset and set offset
	off_t	new_woffset = k2h_da_get_write_offset(pinfo->dahandle);
	if(K2H_DA_RW == pinfo->mode) {
		k2h_da_set_read_offset(pinfo->dahandle, new_woffset);
	}
	return (ssize_t)(new_woffset - woffset);
}
/* }}} */

/* {{{ k2hpx_da_read */
static ssize_t k2hpx_da_read(php_stream *stream, char *buf, size_t count)
{
	if(!stream || !stream->abstract || !buf) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_read: parameter is wrong.");
		return 0;
	}
	if(0 == count) {
		return 0;
	}
	PK2HDA_STREAM_INFO	pinfo = (PK2HDA_STREAM_INFO)stream->abstract;
	if(K2H_DA_READ != pinfo->mode && K2H_DA_RW != pinfo->mode) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_read: stream does not open for reading.");
		return 0;
	}
	// read
	unsigned char*	rbuff;
	size_t			rcount = count;
	if(NULL == (rbuff = k2h_da_read(pinfo->dahandle, &rcount))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_read: failed to read or nothing to read.");
		return 0;
	}
	memcpy(buf, rbuff, rcount);
	free(rbuff);
	// get offset and set offset
	if(K2H_DA_RW == pinfo->mode) {
		off_t	roffset	= k2h_da_get_read_offset(pinfo->dahandle);
		k2h_da_set_write_offset(pinfo->dahandle, roffset);
	}
	// is eof ?
	if(0 == rcount || rcount < count) {
		stream->eof = 1;
	}
	return (ssize_t)rcount;
}
/* }}} */

/* {{{ k2hpx_da_close */
static int k2hpx_da_close(php_stream *stream, int close_handle)
{
	if(!stream || !stream->abstract) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_close: parameter is wrong.");
		return EOF;
	}
	PK2HDA_STREAM_INFO	pinfo = (PK2HDA_STREAM_INFO)stream->abstract;
	if(!k2h_da_free(pinfo->dahandle)) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_close: could not close dahandle.");
		return EOF;
	}
	if(pinfo->need_close_handle && K2H_INVALID_HANDLE == pinfo->handle) {
		// close main handle
		k2h_close(pinfo->handle);
	}
	efree(pinfo);
	stream->abstract = NULL;
	return 0;
}
/* }}} */

/* {{{ k2hpx_da_flush */
static int k2hpx_da_flush(php_stream *stream)
{
	if(!stream || !stream->abstract) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_flush: parameter is wrong.");
		return EOF;
	}
	return 0;	// always nothing to do, because this stream is not buffering.
}
/* }}} */

/* {{{ k2hpx_da_seek */
static int k2hpx_da_seek(php_stream *stream, off_t offset, int whence, off_t *newoffset)
{
	if(!stream || !newoffset) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_seek: parameter is wrong.");
		return -1;
	}
	PK2HDA_STREAM_INFO	pinfo = (PK2HDA_STREAM_INFO)stream->abstract;
	// make offset and check it
	off_t	setoffset;
	if(SEEK_SET == whence) {
		setoffset = offset;
	} else if(SEEK_CUR == whence) {
		off_t	nowoffset;
		if(-1 == (nowoffset = k2h_da_get_offset(pinfo->dahandle, (K2H_DA_READ == pinfo->mode || K2H_DA_RW == pinfo->mode ? true : false)))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_seek: could not get offset.");
			return -1;
		}
		setoffset = nowoffset + offset;
	} else if(SEEK_END == whence) {
		ssize_t	length;
		if(-1 == (length = k2h_da_get_length(pinfo->dahandle))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_seek: could not get length.");
			return -1;
		}
		setoffset = length + offset;
	} else {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_seek: whence parameter is wrong.");
		return -1;
	}
	if(setoffset < 0) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_seek: could not set offset over head of data.");
		return -1;
	}
	// Be careful by order, setting write offset expands data, but read does not.
	// Then we try to change write offset at first.
	if(K2H_DA_WRITE == pinfo->mode || K2H_DA_RW == pinfo->mode) {
		if(!k2h_da_set_write_offset(pinfo->dahandle, setoffset)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_seek: could not set offset for writing.");
			return -1;
		}
	}
	if(K2H_DA_READ == pinfo->mode || K2H_DA_RW == pinfo->mode) {
		ssize_t	length;
		if(-1 == (length = k2h_da_get_length(pinfo->dahandle))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_seek: could not get length.");
			return -1;
		}
		if((off_t)length < setoffset) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_seek: could not set offset over end of data for reading.");
			return -1;
		}
		if(!k2h_da_set_read_offset(pinfo->dahandle, setoffset)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_seek: could not set offset for reading.");
			return -1;
		}
	}
	*newoffset = setoffset;
	return 0;
}
/* }}} */
/* }}} php_stream_ops */

/* {{{ structures for php_stream_ops */
//
// php_stream_ops
//
static php_stream_ops k2h_da_stream_ops = {
	k2hpx_da_write,
	k2hpx_da_read,
	k2hpx_da_close,
	k2hpx_da_flush,
	K2HDA_STREAMTYPE,
	k2hpx_da_seek,
	NULL,				// cast is unsupport
	NULL,				// stat is unsupport
	NULL				// set option is unsupport
};
/* }}} structures for php_stream_ops */

/* {{{ functions for php_stream */
//------------------------------------------------------------
// PHP_STREAM functions for k2hash
//------------------------------------------------------------
/* {{{ k2hpx_da_open_ex */
static php_stream* k2hpx_da_open_ex(k2h_h handle, const char* key, const char* mode, PK2HDA_STREAM_INFO pinfo)
{
	if(K2H_INVALID_HANDLE == handle || NULL == key || !pinfo) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open_ex: some parameters are invalid.");
		return NULL;
	}
	// open & Set offset
	if(0 == strcmp(mode, "r")) {
		pinfo->mode		= K2H_DA_READ;
		pinfo->dahandle	= k2h_da_handle_read(handle, (const unsigned char*)key, strlen(key) + 1);
	} else if(0 == strcmp(mode, "r+")) {
		pinfo->mode		= K2H_DA_RW;
		pinfo->dahandle	= k2h_da_handle_rw(handle, (const unsigned char*)key, strlen(key) + 1);
	} else if(0 == strcmp(mode, "w")) {
		k2h_remove_str(handle, key);	// for initializing key
		pinfo->mode		= K2H_DA_WRITE;
		pinfo->dahandle	= k2h_da_handle_write(handle, (const unsigned char*)key, strlen(key) + 1);
	} else if(0 == strcmp(mode, "w+")) {
		k2h_remove_str(handle, key);	// for initializing key
		pinfo->mode		= K2H_DA_RW;
		pinfo->dahandle	= k2h_da_handle_rw(handle, (const unsigned char*)key, strlen(key) + 1);
	} else if(0 == strcmp(mode, "a")) {
		pinfo->mode		= K2H_DA_WRITE;
		if(K2H_INVALID_HANDLE != (pinfo->dahandle = k2h_da_handle_write(handle, (const unsigned char*)key, strlen(key) + 1))) {
			ssize_t	length;
			if(-1 != (length = k2h_da_get_length(pinfo->dahandle))) {
				k2h_da_set_write_offset(pinfo->dahandle, (off_t)length);
			}
		}
	} else if(0 == strcmp(mode, "a+")) {
		pinfo->mode		= K2H_DA_RW;
		if(K2H_INVALID_HANDLE != (pinfo->dahandle = k2h_da_handle_rw(handle, (const unsigned char*)key, strlen(key) + 1))) {
			ssize_t	length;
			if(-1 != (length = k2h_da_get_length(pinfo->dahandle))) {
				k2h_da_set_read_offset(pinfo->dahandle, (off_t)length);
				k2h_da_set_write_offset(pinfo->dahandle, (off_t)length);
			}
		}
	} else if(0 == strcmp(mode, "c")) {
		pinfo->mode		= K2H_DA_WRITE;
		pinfo->dahandle	= k2h_da_handle_write(handle, (const unsigned char*)key, strlen(key) + 1);
	} else if(0 == strcmp(mode, "c+")) {
		pinfo->mode		= K2H_DA_RW;
		pinfo->dahandle	= k2h_da_handle_rw(handle, (const unsigned char*)key, strlen(key) + 1);
	} else if(0 == strcmp(mode, "x") || 0 == strcmp(mode, "x+")) {
		// we do not have existing check function. and this flag is supported on local file system.
		// then we this mode is error.
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open_ex: mode is not supported.");
		return NULL;
	} else {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open_ex: unknown mode is specified.");
		return NULL;
	}
	if(K2H_INVALID_HANDLE == pinfo->dahandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open_ex: could not open key.");
		return NULL;
	}
	// build stream
	php_stream*	stream = php_stream_alloc(&k2h_da_stream_ops, pinfo , NULL, mode);
	if(!stream) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open_ex: failed to build php_stream.");
		return NULL;
	}
	return stream;
}
/* }}} */
/* {{{ k2hpx_da_open */
php_stream* k2hpx_da_open(k2h_h handle, const char* key, const char* mode STREAMS_DC)
{
	if(K2H_INVALID_HANDLE == handle || NULL == key) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open: some parameters are invalid.");
		return NULL;
	}
	PK2HDA_STREAM_INFO	pinfo = emalloc(sizeof(K2HDA_STREAM_INFO));
	if(!pinfo) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open: could not allocation memory.");
		return NULL;
	}
	pinfo->need_close_handle= false;
	pinfo->handle			= handle;
	// build php_stream
	php_stream*	stream = k2hpx_da_open_ex(handle, key, mode, pinfo);
	if(!stream) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_open: failed to build php_stream.");
		efree(pinfo);
		return NULL;
	}
	return stream;
}
/* }}} */
/* }}} functions for k2hash php_stream */

/* {{{ functions for php_stream_wrapper_ops */
/* {{{ k2hpx_da_check_filename */
static bool k2hpx_da_check_filename(const char* filename, char** path, char** key)
{
	if(!filename || !path || !key) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_check_filename: parameters are wrong.");
		return false;
	}
	if(0 != strncasecmp(K2HDA_STREAM_URL_PREFIX, filename, K2HDA_STREAM_URL_PREFIX_LENGTH)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_check_filename: invalid filename, it does not have \"k2h://\" prefix.");
		return false;
	}
	*key	= NULL;
	*path	= NULL;

	// check
	int		cnt;
	int		keylength;
	int		fnamelength;
	char*	pkey_pos;
	char*	ptmp;
	for(
	    ptmp = (char*)&filename[K2HDA_STREAM_URL_PREFIX_LENGTH],
	    pkey_pos = NULL,
	    cnt = 0,
	    fnamelength = 0,
	    keylength = -1;
	    '\0' != *ptmp && ptmp;
	    ptmp++) {
		if('#' == *ptmp) {
			cnt++;
			pkey_pos = ptmp + sizeof(char);
		}
		if(0 == cnt) {
			fnamelength++;
		} else {	// 1 <= cnt
			keylength++;
		}
	}
	if(1 != cnt) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_check_filename: invalid filename, it does not have key or many sepalator.");
		return false;
	}
	if(keylength <= 0) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_check_filename: invalid filename, it does not have key.");
		return false;
	}
	// parse & copy
	if(NULL == (*key = ecalloc(keylength + 1, sizeof(char)))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_check_filename: could not allocate memory.");
		return false;
	}
	strncpy(*key, pkey_pos, keylength);
	if(0 < fnamelength) {
		if(NULL == (*path = ecalloc(fnamelength + 1, sizeof(char)))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_check_filename: could not allocate memory.");
			efree(*key);
			*key = NULL;
			return false;
		}
		strncpy(*path, &filename[K2HDA_STREAM_URL_PREFIX_LENGTH], fnamelength);
	}
	return true;
}
/* }}} */

/* {{{ php_stream_k2hpx_da_opener */
static php_stream *php_stream_k2hpx_da_opener(php_stream_wrapper *wrapper, const char *filename, const char *mode, int options, zend_string **opened_path, php_stream_context *context STREAMS_DC)
{
	// parse file path for open file and get key string
	char*	path= NULL;
	char*	key	= NULL;
	if(!k2hpx_da_check_filename(filename, &path, &key)) {
		php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: invalid filename.");
		return NULL;
	}
	// has already opened handle?
	bool	need_close_handle	= true;
	k2h_h	handle				= K2H_INVALID_HANDLE;
	if(context) {
		// check context and set handle.
		zval*	tmpzval;
		tmpzval = php_stream_context_get_option(context, K2HDA_STREAM_CTX_NAME, K2HDA_STREAM_CTX_HANDLE);
		if(tmpzval) {
			if(IS_RESOURCE != Z_TYPE_P(tmpzval)) {
				php_error_docref(NULL, E_NOTICE, "php_stream_k2hpx_da_opener: invalid k2hhandle is specified in context.");
				if(path) {
					efree(path);
				}
				efree(key);
				return NULL;
			}
			extern int	le_k2hhandle;		// defined behind Resource destructors section.
			k2h_h*		res_handle;
			res_handle = (k2h_h*) zend_fetch_resource(Z_RES_P(tmpzval), RESOURCE_K2H_HANDLE, le_k2hhandle);
			if(K2H_INVALID_HANDLE == *res_handle) {
				php_error_docref(NULL, E_NOTICE, "php_stream_k2hpx_da_opener: invalid k2hhandle is specified in context.");
				if(path) {
					efree(path);
				}
				efree(key);
				return NULL;
			}
			need_close_handle	= false;
			handle				= *res_handle;
		}
	}
	// need to open handle
	if(K2H_INVALID_HANDLE == handle) {
		if(!path) {
			php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: not found filepath in parameter.");
			efree(key);
			return NULL;
		}
		//
		// [TODO]
		// do need to call php_check_open_basedir(path TSRMLS_CC) function?
		//
		// get options in context
		bool	is_fullmap		= true;
		int		maskbitcnt		= K2H_VAL_MASK_BIT;		// = K2H_DEF_MASK_BIT
		int		cmaskbitcnt		= K2H_VAL_CMASK_BIT;	// = K2H_DEF_CMASK_BIT
		int		maxelementcnt	= K2H_VAL_ELEMENT;		// = K2H_DEF_ELEMENT
		int		pagesize		= K2H_VAL_PAGESIZE;		// = K2H_DEF_PAGESIZE
		if(context) {
			zval*	tmpzval;
			tmpzval = php_stream_context_get_option(context, K2HDA_STREAM_CTX_NAME, K2HDA_STREAM_CTX_FULLMAP);
			if(tmpzval) {
				if(IS_TRUE == Z_TYPE_P(tmpzval)) {
					is_fullmap = Z_LVAL_P(tmpzval);
				}
			}
			tmpzval = php_stream_context_get_option(context, K2HDA_STREAM_CTX_NAME, K2HDA_STREAM_CTX_MBITCNT);
			if(tmpzval) {
				if(IS_LONG == Z_TYPE_P(tmpzval)) {
					maskbitcnt = Z_LVAL_P(tmpzval);
				}
			}
			tmpzval = php_stream_context_get_option(context, K2HDA_STREAM_CTX_NAME, K2HDA_STREAM_CTX_CMBITCNT);
			if(tmpzval) {
				if(IS_LONG == Z_TYPE_P(tmpzval)) {
					cmaskbitcnt = Z_LVAL_P(tmpzval);
				}
			}
			tmpzval = php_stream_context_get_option(context, K2HDA_STREAM_CTX_NAME, K2HDA_STREAM_CTX_MECNT);
			if(tmpzval) {
				if(IS_LONG == Z_TYPE_P(tmpzval)) {
					maxelementcnt = Z_LVAL_P(tmpzval);
				}
			}
			tmpzval = php_stream_context_get_option(context, K2HDA_STREAM_CTX_NAME, K2HDA_STREAM_CTX_PSIZE);
			if(tmpzval) {
				if(IS_LONG == Z_TYPE_P(tmpzval)) {
					pagesize = Z_LVAL_P(tmpzval);
				}
			}
		}
		// First: try to open file.
		if(0 == strcmp(mode, "r")) {
			// read mode
			handle = k2h_open_ro(path, is_fullmap, maskbitcnt, cmaskbitcnt, maxelementcnt, pagesize);
		} else if(0 == strcmp(mode, "r+") || 0 == strcmp(mode, "w+") || 0 == strcmp(mode, "a+") || 0 == strcmp(mode, "c+") || 0 == strcmp(mode, "w") || 0 == strcmp(mode, "a") || 0 == strcmp(mode, "c")) {
			// read write mode
			handle = k2h_open_rw(path, is_fullmap, maskbitcnt, cmaskbitcnt, maxelementcnt, pagesize);
		} else {
			php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: mode is unsupported.");
			efree(path);
			efree(key);
			return NULL;
		}
		// Try to create file if the file does not exist.
		if(K2H_INVALID_HANDLE == handle) {
			// does file exist?
			struct stat	st;
			if(0 == stat(path, &st)) {
				php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: could not attach file.");
				efree(path);
				efree(key);
				return NULL;
			}
			// create file
			if(!k2h_create(path, maskbitcnt, cmaskbitcnt, maxelementcnt, pagesize)) {
				php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: could not create file.");
				efree(path);
				efree(key);
				return NULL;
			}
			// retry to open file.
			if(0 == strcmp(mode, "r")) {
				// read mode
				handle = k2h_open_ro(path, is_fullmap, maskbitcnt, cmaskbitcnt, maxelementcnt, pagesize);
			} else {
				// read write mode
				handle = k2h_open_rw(path, is_fullmap, maskbitcnt, cmaskbitcnt, maxelementcnt, pagesize);
			}
			// last check
			if(K2H_INVALID_HANDLE == handle) {
				php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: could not attach file.");
				efree(path);
				efree(key);
				return NULL;
			}
		}
	}
	// build php_stream
	PK2HDA_STREAM_INFO	pinfo = emalloc(sizeof(K2HDA_STREAM_INFO));
	if(!pinfo) {
		php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: could not allocation memory.");
		efree(key);
		efree(path);
		return NULL;
	}
	pinfo->need_close_handle= need_close_handle;
	pinfo->handle			= handle;
	php_stream*	stream = k2hpx_da_open_ex(handle, key, mode, pinfo);
	efree(key);
	if(!stream) {
		php_error_docref(NULL, E_ERROR, "php_stream_k2hpx_da_opener: failed to build php_stream.");
		efree(pinfo);
		efree(path);
		return NULL;
	}
	if(opened_path) {
		*opened_path = zend_string_init(path, sizeof(path)-1, 0);
	}
	efree(path);
	return stream;
}
/* }}} */
/* }}} functions for php_stream_wrapper_ops */

/* {{{ structures for php_stream_wrapper_ops */
//
// php_stream_wrapper_ops
//
static php_stream_wrapper_ops k2h_da_stream_wops = {
	php_stream_k2hpx_da_opener,
	NULL,	/* close */
	NULL,	/* fstat */
	NULL,	/* stat */
	NULL,	/* opendir */
	K2HDA_STREAM_WRAPPER,
	NULL,	/* unlink */
	NULL,	/* rename */
	NULL,	/* mkdir */
	NULL,	/* rmdir */
	NULL
};
/* }}} structures for k2hash php_stream_wrapper_ops */

/* {{{ structures for php_stream_wrapper */
//
// php_stream_wrapper
//
php_stream_wrapper php_stream_k2h_wrapper = {
       &k2h_da_stream_wops,
       NULL,
       0
};
/* }}} structures for php_stream_wrapper */

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
