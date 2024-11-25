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
// cppcheck-suppress missingInclude
#include "ext/standard/info.h"
#include "php_k2hash.h"
#include "k2hash_arginfo.h"

extern php_stream* k2hpx_da_open(k2h_h handle, const char* key, const char* mode STREAMS_DC);
extern zend_class_entry *php_k2hqueue_ce;
extern zend_class_entry *php_k2hkeyqueue_ce;
extern zend_class_entry *php_k2hiterator_ce;

/* {{{ Class K2hash */
zend_class_entry * php_k2hash_ce = NULL;
static zend_object_handlers k2hash_object_handlers;

/* {{{ Methods */

/* {{{ proto bool create(string filepath[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]])
  K2hash::create method */

PHP_METHOD(K2hash, create)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_long maskbitcnt = K2H_VAL_MASK_BIT;
	zend_long cmaskbitcnt = K2H_VAL_CMASK_BIT;
	zend_long maxelementcnt = K2H_VAL_ELEMENT;
	zend_long pagesize = K2H_VAL_PAGESIZE;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|llll", &filepath, &filepath_len, &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
		return;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "K2hash::create: filepath is empty.");
		RETURN_FALSE;
	}
	// create file
	if(!k2h_create(filepath, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::create: failed to create k2hash file.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} create */

/* {{{ proto bool open(string filepath, bool readonly[, bool removefile = false[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]]])
  K2hash::open method */

PHP_METHOD(K2hash, open)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool readonly = 0;
	zend_bool removefile = false;
	zend_bool fullmap = true;
	zend_long maskbitcnt = K2H_VAL_MASK_BIT;
	zend_long cmaskbitcnt = K2H_VAL_CMASK_BIT;
	zend_long maxelementcnt = K2H_VAL_ELEMENT;
	zend_long pagesize = K2H_VAL_PAGESIZE;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "sb|bbllll", &filepath, &filepath_len, &readonly, &removefile, &fullmap, &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
		return;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "K2hash::open: filepath is empty.");
		RETURN_FALSE;
	}
	// open new handle
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_newhandle = intern->handle;
	if (!res_newhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::open: custom object initialize error.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	*res_newhandle = k2h_open(filepath, 0 != readonly ? true : false, 0 != removefile ? true : false, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize);
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == *res_newhandle) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} open */

/* {{{ proto bool openRW(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  K2hash::openRW method */

PHP_METHOD(K2hash, openRW)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool fullmap = true;
	zend_long maskbitcnt = K2H_VAL_MASK_BIT;
	zend_long cmaskbitcnt = K2H_VAL_CMASK_BIT;
	zend_long maxelementcnt = K2H_VAL_ELEMENT;
	zend_long pagesize = K2H_VAL_PAGESIZE;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|bllll", &filepath, &filepath_len, &fullmap, &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
		return;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "K2hash::openRW: filepath is empty.");
		RETURN_FALSE;
	}
	// open new handle
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_newhandle = intern->handle;
	if (!res_newhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::open: custom object initialize error.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	*res_newhandle = k2h_open_rw(filepath, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize);
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == *res_newhandle) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} openRW */

/* {{{ proto bool openRO(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  K2hash::openRO method */

PHP_METHOD(K2hash, openRO)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool fullmap = true;
	zend_long maskbitcnt = K2H_VAL_MASK_BIT;
	zend_long cmaskbitcnt = K2H_VAL_CMASK_BIT;
	zend_long maxelementcnt = K2H_VAL_ELEMENT;
	zend_long pagesize = K2H_VAL_PAGESIZE;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|bllll", &filepath, &filepath_len, &fullmap, &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
		return;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "K2hash::openRO: filepath is empty.");
		RETURN_FALSE;
	}
	// open new handle
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_newhandle = intern->handle;
	if (!res_newhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::open: custom object initialize error.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	*res_newhandle = k2h_open_ro(filepath, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize);
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == *res_newhandle) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} openRO */

/* {{{ proto bool openTempfile(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  K2hash::openTempfile method */

PHP_METHOD(K2hash, openTempfile)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool fullmap = true;
	zend_long maskbitcnt = K2H_VAL_MASK_BIT;
	zend_long cmaskbitcnt = K2H_VAL_CMASK_BIT;
	zend_long maxelementcnt = K2H_VAL_ELEMENT;
	zend_long pagesize = K2H_VAL_PAGESIZE;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|bllll", &filepath, &filepath_len, &fullmap, &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
		return;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "K2hash::openTempfile: filepath is empty.");
		RETURN_FALSE;
	}
	// open new handle
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_newhandle = intern->handle;
	if (!res_newhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::open: custom object initialize error.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	*res_newhandle = k2h_open_tempfile(filepath, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize);
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == *res_newhandle) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} openTempfile */

/* {{{ proto bool openMem([int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]])
  K2hash::openMem method */

PHP_METHOD(K2hash, openMem)
{
	zend_long maskbitcnt = K2H_VAL_MASK_BIT;
	zend_long cmaskbitcnt = K2H_VAL_CMASK_BIT;
	zend_long maxelementcnt = K2H_VAL_ELEMENT;
	zend_long pagesize = K2H_VAL_PAGESIZE;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|llll", &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
		return;
	}
	// open new handle
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_newhandle = intern->handle;
	if (!res_newhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::open: custom object initialize error.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	*res_newhandle = k2h_open_mem((int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize);
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == *res_newhandle) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} openMem */

/* {{{ proto bool close([int waitms = 0])
  K2hash::close method */

PHP_METHOD(K2hash, close)
{
	zend_long waitms = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|l", &waitms) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	/*
	  1555		k2h_h* res_k2hhandle = intern->handle;
	  (gdb) p intern
		$1 = (php_k2hash_object *) 0x7ffff605ddc0
		(gdb) p *intern
		$2 = {handle = 0x7ffff6075050, std = {gc = {refcount = 2, u = {v = {type = 8 '\b', flags = 0 '\000', gc_info = 49154},
	*/
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::close: custom object initialize error.");
		RETURN_FALSE;
	}
	// check parameter
	if(waitms < -1) {
		php_error_docref(NULL, E_NOTICE, "K2hash::close: waitms must be -1, 0, 1...");
		RETURN_FALSE;
	}
	// close with timeout
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_close_wait(*res_k2hhandle, waitms)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::close: failed to close k2hash.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} close */

/* {{{ proto bool transaction(bool enable[, string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]])
  K2hash::transaction method */

PHP_METHOD(K2hash, transaction)
{
	zend_bool enable = 0;
	const char * transfile = NULL;
	size_t transfile_len = 0;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	const char * param = NULL;
	size_t param_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "b|sssl", &enable, &transfile, &transfile_len, &prefix, &prefix_len, &param, &param_len, &expire) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::transaction: could not open k2hash.");
		RETURN_FALSE;
	}
	// cppcheck-suppress unreadVariable
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	// transaction
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_transaction_param_we(*res_k2hhandle, 0 != enable ? true : false, (!transfile || 0 == transfile_len) ? NULL : transfile, (!prefix || 0 == prefix_len) ? NULL : (const unsigned char*)prefix, prefix_len, (!param || 0 == param_len) ? NULL : (const unsigned char*)param, param_len, ptmexpire)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::transaction: failed to enable/disable transaction.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} transaction */

/* {{{ proto bool enableTransaction([string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]])
  K2hash::enableTransaction method */

PHP_METHOD(K2hash, enableTransaction)
{
	const char * transfile = NULL;
	size_t transfile_len = 0;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	const char * param = NULL;
	size_t param_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|sssl", &transfile, &transfile_len, &prefix, &prefix_len, &param, &param_len, &expire) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::enableTransaction: could not open k2hash.");
		RETURN_FALSE;
	}
	// cppcheck-suppress unreadVariable
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	// transaction
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_enable_transaction_param_we(*res_k2hhandle, (!transfile || 0 == transfile_len) ? NULL : transfile, (!prefix || 0 == prefix_len) ? NULL : (const unsigned char*)prefix, prefix_len, (!param || 0 == param_len) ? NULL : (const unsigned char*)param, param_len, ptmexpire)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::enableTransaction: failed to enable transaction.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} enableTransaction */

/* {{{ proto bool disableTransaction()
  K2hash::disableTransaction method */

PHP_METHOD(K2hash, disableTransaction)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::disableTransaction: could not open k2hash.");
		RETURN_FALSE;
	}
	// transaction
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_disable_transaction(*res_k2hhandle)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::disableTransaction: failed to disable transaction.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} disableTransaction */

/* {{{ proto int getTransactionThreadPool()
  K2hash::getTransactionThreadPool method */

PHP_METHOD(K2hash, getTransactionThreadPool)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	int	count = k2h_get_transaction_thread_pool();
	RETURN_LONG((long)count);
}
/* }}} getTransactionThreadPool */

/* {{{ proto bool setTransactionThreadPool(int count)
  K2hash::getTransactionThreadPool method */

PHP_METHOD(K2hash, setTransactionThreadPool)
{
	zend_long count = 0;
	if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "l", &count) == FAILURE) {
		return;
	}
	if(!k2h_set_transaction_thread_pool((int)count)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::setTransactionThreadPool: failed to set transaction thread pool.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} setTransactionThreadPool */

/* {{{ proto bool unsetTransactionThreadPool()
  K2hash::unsetTransactionThreadPool method */

PHP_METHOD(K2hash, unsetTransactionThreadPool)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	if(!k2h_unset_transaction_thread_pool()) {
		php_error_docref(NULL, E_NOTICE, "K2hash::setTransactionThreadPool: failed to unset transaction thread pool.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} unsetTransactionThreadPool */

/* {{{ proto bool putArchive(string filepath[, bool errskip = true])
  K2hash::putArchive method */

PHP_METHOD(K2hash, putArchive)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool errskip = true;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|b", &filepath, &filepath_len, &errskip) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::putArchive: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::putArchive: file path is empty.");
		RETURN_FALSE;
	}
	// archive
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_put_archive(*res_k2hhandle, filepath, 0 != errskip ? true : false)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::putArchive: failed to put archive.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} putArchive */

/* {{{ proto bool loadArchive(string filepath[, bool errskip = true])
  K2hash::loadArchive method */

PHP_METHOD(K2hash, loadArchive)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool errskip = true;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|b", &filepath, &filepath_len, &errskip) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::loadArchive: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::loadArchive: file path is empty.");
		RETURN_FALSE;
	}
	// archive
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_load_archive(*res_k2hhandle, filepath, 0 != errskip ? true : false)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::loadArchive: failed to load archive.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} loadArchive */

/* {{{ proto bool setCommonAttribute([int is_mtime = K2H_ATTR_DEFAULT[, int is_history = K2H_ATTR_DEFAULT[, int is_encrypt = K2H_ATTR_DEFAULT, string passfile = NULL[, int is_expire = K2H_ATTR_DEFAULT, int expire = 0]]]])
  K2hash::setCommonAttribute method */

PHP_METHOD(K2hash, setCommonAttribute)
{
	zend_long is_mtime = K2H_VAL_ATTR_DEFAULT;
	zend_long is_history = K2H_VAL_ATTR_DEFAULT;
	zend_long is_encrypt = K2H_VAL_ATTR_DEFAULT;
	const char * passfile = NULL;
	size_t passfile_len = 0;
	zend_long is_expire = K2H_VAL_ATTR_DEFAULT;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|lllsll", &is_mtime, &is_history, &is_encrypt, &passfile, &passfile_len, &is_expire, &expire) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::setCommonAttribute: could not open k2hash.");
		RETURN_FALSE;
	}
	// cppcheck-suppress unreadVariable
	bool	mtime_val	= false;
	bool*	pmtime_val	= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_mtime) {
		mtime_val	= K2H_VAL_ATTR_ENABLE == is_mtime ? true : false;
		pmtime_val	= &mtime_val;
	}
	// cppcheck-suppress unreadVariable
	bool		enc_val		= false;
	bool*		penc_val	= NULL;
	const char*	pfile		= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_encrypt) {
		if(K2H_VAL_ATTR_ENABLE == is_encrypt) {
			if(!passfile || passfile_len == 0) {
				php_error_docref(NULL, E_ERROR, "K2hash::setCommonAttribute: passfile must not be empty.");
				RETURN_FALSE;
			}
			enc_val		= false;
			penc_val	= &enc_val;
			pfile		= passfile;
		} else {
			enc_val		= false;
			penc_val	= &enc_val;
			pfile		= !passfile || passfile_len == 0 ? NULL : passfile;
		}
	}
	// cppcheck-suppress unreadVariable
	bool	his_val		= false;
	bool*	phis_val	= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_history) {
		his_val		= K2H_VAL_ATTR_ENABLE == is_history ? true : false;
		phis_val	= &his_val;
	}
	// cppcheck-suppress unreadVariable
	time_t	expire_val	= 0;
	time_t*	pexpire_val	= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_expire) {
		if(K2H_VAL_ATTR_ENABLE == is_expire) {
			if(expire <= 0) {
				php_error_docref(NULL, E_ERROR, "K2hash::setCommonAttribute: expire must not be over zero.");
				RETURN_FALSE;
			}
			expire_val	= (time_t)expire;
			pexpire_val	= &expire_val;
		} else {
			expire_val	= -1;			// == NOT_EXPIRE
			pexpire_val	= &expire_val;
		}
	}
	// set
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_set_common_attr(*res_k2hhandle, pmtime_val, penc_val, pfile, phis_val, pexpire_val)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::setCommonAttribute: failed to set common attributes.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} setCommonAttribute */

/* {{{ proto bool cleanCommonAttribute()
  K2hash::cleanCommonAttribute method */

PHP_METHOD(K2hash, cleanCommonAttribute)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::cleanCommonAttribute: could not open k2hash.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_clean_common_attr(*res_k2hhandle)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::cleanCommonAttribute: failed to clear common attributes.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} cleanCommonAttribute */

/* {{{ proto bool addAttrPluginLib(string libfile)
  K2hash::addAttrPluginLib method */

PHP_METHOD(K2hash, addAttrPluginLib)
{
	const char * libfile = NULL;
	size_t libfile_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &libfile, &libfile_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttrPluginLib: could not open k2hash.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_add_attr_plugin_library(*res_k2hhandle, libfile)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttrPluginLib: failed to load plugin attribute library.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} addAttrPluginLib */

/* {{{ proto bool addAttrCryptPass(string encpass[, bool is_default_encrypt = false])
  K2hash::addAttrCryptPass method */

PHP_METHOD(K2hash, addAttrCryptPass)
{
	const char * encpass = NULL;
	size_t encpass_len = 0;
	zend_bool is_default_encrypt = false;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|b", &encpass, &encpass_len, &is_default_encrypt) == FAILURE) {
		return;
	}

	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttrCryptPass: could not open k2hash.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_add_attr_crypt_pass(*res_k2hhandle, encpass, is_default_encrypt)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttrCryptPass: failed to add pass phrase.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} addAttrCryptPass */

/* {{{ proto bool getAttrVersionInfos([stream output = NULL])
  K2hash::getAttrVersionInfos method */

PHP_METHOD(K2hash, getAttrVersionInfos)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrVersionInfos: could not open k2hash.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "K2hash::getAttrVersionInfos: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_print_attr_version(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrVersionInfos: failed to print attribute version inrmation.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} getAttrVersionInfos */

/* {{{ proto bool getAttrInfos([stream output = NULL])
  K2hash::getAttrInfos method */

PHP_METHOD(K2hash, getAttrInfos)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrInfos: could not open k2hash.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "K2hash::getAttrInfos: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_print_attr_version(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrInfos: failed to print all attribute inrmation.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} getAttrInfos */

/* {{{ proto string getValue(string key[, string subkey = NULL[, bool attrcheck = true[, string pass = NULL]]])
  K2hash::getValue method */

PHP_METHOD(K2hash, getValue)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	zend_bool attrcheck = true;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|sbs", &key, &key_len, &subkey, &subkey_len, &attrcheck, &pass, &pass_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getValue: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getValue: key is empty.");
		RETURN_FALSE;
	}
	// get
	char*	pvalue = NULL;
	if(!subkey || 0 == subkey_len) {
		if(attrcheck) {
			if(NULL == (pvalue = k2h_get_str_direct_value_wp(*res_k2hhandle, key, pass))) {
				//php_error_docref(NULL, E_NOTICE, "K2hash::getValue: failed to get value.");
				RETURN_FALSE;
			}
		} else {
			if(NULL == (pvalue = k2h_get_str_direct_value_np(*res_k2hhandle, key))) {
				//php_error_docref(NULL, E_NOTICE, "K2hash::getValue: failed to get value.");
				RETURN_FALSE;
			}
		}
	} else {
		// cppcheck-suppress nullPointerRedundantCheck
		char**	pskeyarray = NULL;
		int		subkey_count;
		bool	isFound = false;
		if(attrcheck) {
			subkey_count = k2h_get_str_subkeys(*res_k2hhandle, key, &pskeyarray);
			if (subkey_count == -1 || subkey_count == 0) {
				//php_error_docref(NULL, E_NOTICE, "K2hash::getValue: the key does not have subkey.");
				if(pskeyarray) {
					k2h_free_keyarray(pskeyarray);
				}
				RETURN_FALSE;
			}
		} else {
			subkey_count = k2h_get_str_subkeys_np(*res_k2hhandle, key, &pskeyarray);
			if (subkey_count == -1 || subkey_count == 0) {
				//php_error_docref(NULL, E_NOTICE, "K2hash::getValue: the key does not have subkey.");
				if(pskeyarray) {
					k2h_free_keyarray(pskeyarray);
				}
				RETURN_FALSE;
			}
		}
		char**	pptmp;
		for(pptmp = pskeyarray; pptmp && *pptmp; pptmp++) {
			if(0 == strcmp(*pptmp, subkey)) {
				isFound = true;
				break;
			}
		}
		k2h_free_keyarray(pskeyarray);
		if(!isFound) {
			//php_error_docref(NULL, E_NOTICE, "K2hash::getValue: the key does not have subkey.");
			RETURN_FALSE;
		}
		if(attrcheck) {
			if(NULL == (pvalue = k2h_get_str_direct_value_wp(*res_k2hhandle, subkey, pass))) {
				//php_error_docref(NULL, E_NOTICE, "K2hash::getValue: the key does not exist.");
				RETURN_FALSE;
			}
		} else {
			if(NULL == (pvalue = k2h_get_str_direct_value_np(*res_k2hhandle, subkey))) {
				//php_error_docref(NULL, E_NOTICE, "K2hash::getValue: the key does not exist.");
				RETURN_FALSE;
			}
		}
	}
	RETVAL_STRING(pvalue);
	free(pvalue);
}
/* }}} getValue */

/* {{{ proto array getSubkeys(string key[, bool attrcheck = true])
  K2hash::getSubkeys method */

PHP_METHOD(K2hash, getSubkeys)
{
	const char * key = NULL;
	size_t key_len = 0;
	zend_bool attrcheck = true;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|b", &key, &key_len, &attrcheck) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getSubkeys: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getSubkeys: key is empty.");
		RETURN_FALSE;
	}
	array_init(return_value);
	// get
	char**	pskeyarray = NULL;
	if(attrcheck) {
		if(0 != k2h_get_str_subkeys(*res_k2hhandle, key, &pskeyarray)) {
			char**	pptmp;
			for(pptmp = pskeyarray; pptmp && *pptmp; pptmp++) {
				add_next_index_string(return_value, *pptmp);
			}
		}
	} else {
		if(0 != k2h_get_str_subkeys_np(*res_k2hhandle, key, &pskeyarray)) {
			char**	pptmp;
			for(pptmp = pskeyarray; pptmp && *pptmp; pptmp++) {
				add_next_index_string(return_value, *pptmp);
			}
		}
	}
	if(pskeyarray) {
		k2h_free_keyarray(pskeyarray);
	}
}
/* }}} getSubkeys */

/* {{{ proto array getAttrs(string key)
  K2hash::getAttrs method */

PHP_METHOD(K2hash, getAttrs)
{
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &key, &key_len) == FAILURE) {
		return;
	}
	array_init(return_value);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrs: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrs: key is empty.");
		RETURN_FALSE;
	}
	// get
	PK2HATTRPCK	pattrs;
	int			attrspckcnt = 0;
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL != (pattrs = k2h_get_str_direct_attrs(*res_k2hhandle, key, &attrspckcnt)) && 0 < attrspckcnt) {
		int	cnt;
		for(cnt = 0; cnt < attrspckcnt; ++cnt) {
			char*	pattrkey;
			if(NULL != (pattrkey = (char*)malloc(pattrs[cnt].keylength + 1))) {
				memcpy(pattrkey, pattrs[cnt].pkey, pattrs[cnt].keylength);
				pattrkey[pattrs[cnt].keylength] = '\0';
				add_next_index_string(return_value, pattrkey);
				free(pattrkey);
			}
		}
	}
	if(pattrs) {
		k2h_free_attrpack(pattrs, attrspckcnt);
	}
}
/* }}} getAttrs */

/* {{{ proto string getAttrValue(string key, string attrkey)
  K2hash::getAttrValue method */

PHP_METHOD(K2hash, getAttrValue)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * attrkey = NULL;
	size_t attrkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &key, &key_len, &attrkey, &attrkey_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrValue: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrValue: key is empty.");
		RETURN_FALSE;
	}
	if(!attrkey || 0 == attrkey_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrValue: attribute key is empty.");
		RETURN_FALSE;
	}
	// get
	PK2HATTRPCK	pattrs;
	int			attrspckcnt	= 0;
	bool		is_found	= false;
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL != (pattrs = k2h_get_str_direct_attrs(*res_k2hhandle, key, &attrspckcnt)) && 0 < attrspckcnt) {
		int	cnt;
		for(cnt = 0; cnt < attrspckcnt; ++cnt) {
			if(pattrs[cnt].keylength < (size_t)attrkey_len) {
				continue;	// wrong length
			}
			if(0 == memcmp(attrkey, pattrs[cnt].pkey, (size_t)attrkey_len)) {
				// found attribute key
				char*	pattrval;
				if(NULL == (pattrval = (char*)malloc(pattrs[cnt].vallength + 1))) {
					php_error_docref(NULL, E_ERROR, "K2hash::getAttrValue: could not allocate memory.");
					k2h_free_attrpack(pattrs, attrspckcnt);
					RETURN_FALSE;
				}
				// copy
				// cppcheck-suppress nullPointerRedundantCheck
				memcpy(pattrval, pattrs[cnt].pval, pattrs[cnt].vallength);
				// cppcheck-suppress nullPointerRedundantCheck
				pattrval[pattrs[cnt].vallength] = '\0';
				// set return value
				RETVAL_STRING(pattrval);
				free(pattrval);
				is_found = true;
				break;
			}
		}
	}
	if(pattrs) {
		k2h_free_attrpack(pattrs, attrspckcnt);
	}
	if(!is_found) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getAttrValue: could not find attribute key name.");
		RETURN_FALSE;
	}
}
/* }}} getAttrValue */

/* {{{ proto bool setValue(string key, string value[, string subkey = NULL[, string pass=NULL[, int expire=0]]])
  K2hash::setValue method */

PHP_METHOD(K2hash, setValue)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * value = NULL;
	size_t value_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss|ssl", &key, &key_len, &value, &value_len, &subkey, &subkey_len, &pass, &pass_len, &expire) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::setValue: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::setValue: key is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress unreadVariable
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	// set
	if(!subkey || 0 == subkey_len) {
		if(!k2h_set_str_value_wa(*res_k2hhandle, key, value, pass, ptmexpire)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::setValue: failed to set value to key");
			RETURN_FALSE;
		}
	} else {
		if(!k2h_add_str_subkey_wa(*res_k2hhandle, key, subkey, value, pass, ptmexpire)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::setValue: failed to set value to subkey in key");
			RETURN_FALSE;
		}
	}
	RETURN_TRUE;
}
/* }}} setValue */

/* {{{ proto bool addSubkey(string key, string subkey)
  K2hash::addSubkey method */

PHP_METHOD(K2hash, addSubkey)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &key, &key_len, &subkey, &subkey_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addSubkey: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len || !subkey || 0 == subkey_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addSubkey: key or subkey is empty.");
		RETURN_FALSE;
	}
	// get now subkeys list
	int			skeypckcnt	= 0;
	// cppcheck-suppress nullPointerRedundantCheck
	PK2HKEYPCK	pskeypck	= k2h_get_direct_subkeys(*res_k2hhandle, (const unsigned char*)key, strlen(key) + 1, &skeypckcnt);
	// make new subkeys list(+1)
	PK2HKEYPCK	pnewpck;
	if(NULL == (pnewpck = (PK2HKEYPCK)calloc((skeypckcnt + 1), sizeof(K2HKEYPCK)))) {
		php_error_docref(NULL, E_ERROR, "K2hash::addSubkey: could not allocation memory.");
		if(pskeypck) {
			k2h_free_keypack(pskeypck, skeypckcnt);
		}
		RETURN_FALSE;
	}
	// set subkey into first entry in new subkeys list
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL == (pnewpck[0].pkey = (unsigned char*)calloc(strlen(subkey) + 1, sizeof(unsigned char)))) {
		php_error_docref(NULL, E_ERROR, "K2hash::addSubkey: could not allocation memory.");
		if(pskeypck) {
			k2h_free_keypack(pskeypck, skeypckcnt);
		}
		free(pnewpck);
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	memcpy(pnewpck[0].pkey, subkey, strlen(subkey));
	// cppcheck-suppress nullPointerRedundantCheck
	pnewpck[0].length = strlen(subkey) + 1;
	// set old subkeys list into new list
	int setpos = 1;
	int	cnt;
	for(cnt = 0; cnt < skeypckcnt; cnt++) {
		// cppcheck-suppress nullPointerRedundantCheck
		if(0 == strcmp((const char*)pskeypck[cnt].pkey, subkey)) {
			// found same key name
			continue;
		}
		if(NULL == (pnewpck[setpos].pkey = (unsigned char*)calloc(pskeypck[cnt].length, sizeof(unsigned char)))) {
			php_error_docref(NULL, E_ERROR, "K2hash::addSubkey: could not allocation memory.");
			k2h_free_keypack(pskeypck, skeypckcnt);
			k2h_free_keypack(pnewpck, setpos);
			RETURN_FALSE;
		}
		memcpy(pnewpck[setpos].pkey, pskeypck[cnt].pkey, pskeypck[cnt].length);
		pnewpck[setpos].length = pskeypck[cnt].length;
		setpos++;
	}
	if(pskeypck) {
		k2h_free_keypack(pskeypck, skeypckcnt);
	}
	// set new subkeys
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_set_subkeys(*res_k2hhandle, (const unsigned char*)key, strlen(key) + 1, pnewpck, setpos)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addSubkey: failed to set subkey into key.");
		k2h_free_keypack(pnewpck, setpos);
		RETURN_FALSE;
	}
	k2h_free_keypack(pnewpck, setpos);
	RETURN_TRUE;
}
/* }}} addSubkey */

/* {{{ proto bool addSubkeys(string key, array &subkeys)
  K2hash::addSubkeys method */

PHP_METHOD(K2hash, addSubkeys)
{
	const char * key = NULL;
	size_t key_len = 0;
	zval * subkeys = NULL;
	HashTable * subkeys_hash = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "sa", &key, &key_len, &subkeys) == FAILURE) {
		return;
	}
	subkeys_hash = Z_ARRVAL_P(subkeys);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addSubkeys: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addSubkeys: key or subkey is empty.");
		RETURN_FALSE;
	}
	// make new subkeys
	int			subkeys_count = zend_hash_num_elements(subkeys_hash);
	PK2HKEYPCK	pnewpck = NULL;
	int			setpos = 0;
	if(0 < subkeys_count) {
		// allocate new subkeys list
		if(NULL == (pnewpck = (PK2HKEYPCK)calloc(subkeys_count, sizeof(K2HKEYPCK)))) {
			php_error_docref(NULL, E_ERROR, "K2hash::addSubkeys: could not allocation memory.");
			RETURN_FALSE;
		}
		// copy
		zend_long lkey;
		zval *val;
		// cppcheck-suppress uninitvar
		ZEND_HASH_FOREACH_NUM_KEY_VAL(subkeys_hash, lkey, val) {
			if(!val || IS_STRING != Z_TYPE_P(val)) {
				php_error_docref(NULL, E_WARNING, "K2hash::addSubkeys: found unsafe reference zval, skip it.");
				continue;
			}
			char*	subkey = Z_STRVAL_P(val);
			if(!subkey) {
				php_error_docref(NULL, E_WARNING, "K2hash::addSubkeys: found null element in array, skip it.");
				continue;
			}
			if(NULL == (pnewpck[lkey].pkey = (unsigned char*)calloc(strlen(subkey) + 1, sizeof(unsigned char)))) {
				php_error_docref(NULL, E_ERROR, "K2hash::addSubkeys: could not allocation memory.");
				k2h_free_keypack(pnewpck, lkey);
				RETURN_FALSE;
			}
			memcpy(pnewpck[lkey].pkey, subkey, strlen(subkey) + 1);
			pnewpck[lkey].length = strlen(subkey) + 1;
			setpos++;
		}
		ZEND_HASH_FOREACH_END();
	}
	// over write all subkeys(if pnewpck is null, remove all subkeys)
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_set_subkeys(*res_k2hhandle, (const unsigned char*)key, strlen(key) + 1, pnewpck, setpos)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addSubkeys: failed to set subkeys into key.");
		k2h_free_keypack(pnewpck, setpos);
		RETURN_FALSE;
	}
	k2h_free_keypack(pnewpck, setpos);
	RETURN_TRUE;
}
/* }}} addSubkeys */

/* {{{ proto bool addAttr(string key, string attrkey, string attrval)
  K2hash::addAttr method */

PHP_METHOD(K2hash, addAttr)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * attrkey = NULL;
	size_t attrkey_len = 0;
	const char * attrval = NULL;
	size_t attrval_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "sss", &key, &key_len, &attrkey, &attrkey_len, &attrval, &attrval_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttr: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttr: key is empty.");
		RETURN_FALSE;
	}
	if(!attrkey || 0 == attrkey_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttr: attribute key is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_add_str_attr(*res_k2hhandle, key, attrkey, attrval)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::addAttr: failed to add attribute into key.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} addAttr */

/* {{{ proto bool removeAll(string key)
  K2hash::removeAll method */

PHP_METHOD(K2hash, removeAll)
{
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &key, &key_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::removeAll: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::removeAll: key is empty.");
		RETURN_FALSE;
	}
	// remove
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_remove_str_all(*res_k2hhandle, key)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::removeAll: failed to remove all for key.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} removeAll */

/* {{{ proto bool remove(string key[, string subkey = NULL])
  K2hash::remove method */

PHP_METHOD(K2hash, remove)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|s", &key, &key_len, &subkey, &subkey_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::remove: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::remove: key is empty.");
		RETURN_FALSE;
	}
	// remove
	if(!subkey || 0 == subkey_len) {
		if(!k2h_remove_str(*res_k2hhandle, key)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::remove: failed to remove only key.");
			RETURN_FALSE;
		}
	} else {
		if(!k2h_remove_str_subkey(*res_k2hhandle, key, subkey)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::remove: failed to remove subkey from subkey list in key.");
			RETURN_FALSE;
		}
	}
	RETURN_TRUE;
}
/* }}} remove */

/* {{{ proto bool rename(string key, string newkey)
  K2hash::rename method */

PHP_METHOD(K2hash, rename)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * newkey = NULL;
	size_t newkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &key, &key_len, &newkey, &newkey_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::rename: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::rename: key is empty.");
		RETURN_FALSE;
	}
	if(!newkey || 0 == newkey_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::rename: new key is empty.");
		RETURN_FALSE;
	}
	// rename
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_rename_str(*res_k2hhandle, key, newkey)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::rename: failed to rename key name.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} rename */

/* {{{ proto object getIterator([string key = NULL])
  K2hash::getIterator method */

PHP_METHOD(K2hash, getIterator)
{
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|s", &key, &key_len) == FAILURE) {
		return;
	}
	object_init_ex(return_value, php_k2hiterator_ce);
	php_k2hiterator_object* rintern = Z_K2HITERATOR_OBJECT_P(return_value);
	k2h_find_h* res_findhandle = rintern->handle;
	if (!res_findhandle) {
		php_error_docref(NULL, E_ERROR, "K2hash::getIterator: custom object init error.");
		RETURN_FALSE;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* handle = intern->handle;
	if (!handle || K2H_INVALID_HANDLE == handle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getIterator: could not open k2hash.");
		RETURN_FALSE;
	}
	// open k2h_find_h handle
	if(!key || 0 == key_len) {
		*res_findhandle = k2h_find_first(*handle);
	} else {
		*res_findhandle = k2h_find_first_str_subkey(*handle, key);
	}
}
/* }}} getIterator */

/* {{{ proto stream getStream(string key, string mode)
  K2hash::getStream method */

PHP_METHOD(K2hash, getStream)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * mode = NULL;
	size_t mode_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &key, &key_len, &mode, &mode_len) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getStream: could not open k2hash.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len || !mode || 0 == mode_len) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getStream: key or mode is empty.");
		RETURN_NULL();
	}
	// build stream
	php_stream*	res_stream;
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL == (res_stream = k2hpx_da_open(*res_k2hhandle, key, mode STREAMS_REL_CC))) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getStream: could not open stream by key with mode.");
		RETURN_NULL();
	}
	php_stream_to_zval(res_stream, return_value);
}
/* }}} getStream */

/* {{{ proto object getQueue([bool is_fifo = true[, string prefix = NULL]])
  K2hash::getQueue method */

PHP_METHOD(K2hash, getQueue)
{
	zend_bool is_fifo = true;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|bs", &is_fifo, &prefix, &prefix_len) == FAILURE) {
		return;
	}
	// class entry is K2hQueue
	// object_init_ex internally calls php_k2hqueue_object_alloc function.
	object_init_ex(return_value, php_k2hqueue_ce);
	
	// k2h_find_h variable is allocated in the K2hQueue object.
	php_k2hqueue_object* rintern = Z_K2HQUEUE_OBJECT_P(return_value);
	k2h_q_h* res_k2hqhandle = rintern->handle;
	if (!res_k2hqhandle) {
		// handle must be allocated in php_k2hqueue_object_alloc
		php_error_docref(NULL, E_ERROR, "K2hash::getQueue: custom object init error.");
		RETURN_FALSE;
	}
	// get php_k2hash_object pointer from current object.
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* handle = intern->handle;
	if (!handle || K2H_INVALID_HANDLE == handle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getQueue: could not open k2hash.");
		RETURN_FALSE;
	}
	// get queue handle
	// k2h_q_handle function returns k2h_q_h handle which is stored in return_value.
	if(!prefix || 0 == prefix_len) {
		*res_k2hqhandle = k2h_q_handle(*handle, is_fifo);
	} else {
		*res_k2hqhandle = k2h_q_handle_str_prefix(*handle, is_fifo, prefix);
	}
}
/* }}} getQueue */

/* {{{ proto object getKeyQueue([bool is_fifo = true[, string prefix = NULL]])
  K2hash::getKeyQueue method */

PHP_METHOD(K2hash, getKeyQueue)
{
	zend_bool is_fifo = true;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|bs", &is_fifo, &prefix, &prefix_len) == FAILURE) {
		return;
	}
	// class entry is K2hKeyQueue.
	object_init_ex(return_value, php_k2hkeyqueue_ce);
	php_k2hqueue_object* rintern = Z_K2HQUEUE_OBJECT_P(return_value);
	k2h_keyq_h* res_k2hkeyqhandle = rintern->handle;
	if (!res_k2hkeyqhandle) {
		php_error_docref(NULL, E_ERROR, "K2hash::getKeyQueue: custom object init error.");
		RETURN_FALSE;
	}
	// get php_k2hash_object pointer from current object.
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* handle = intern->handle;
	if (!handle || K2H_INVALID_HANDLE == handle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::getKeyQueue: could not open k2hash.");
		RETURN_FALSE;
	}
	// open k2h_keyq_h handle
	if(!prefix || 0 == prefix_len) {
		*res_k2hkeyqhandle = k2h_keyq_handle(*handle, is_fifo);
	} else {
		*res_k2hkeyqhandle = k2h_keyq_handle_str_prefix(*handle, is_fifo, prefix);
	}
}
/* }}} getKeyQueue */

/* {{{ proto bool dumpHead([stream output = NULL])
  K2hash::dumpHead method */

PHP_METHOD(K2hash, dumpHead)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpHead: could not open k2hash.");
		RETURN_FALSE;
	}
	php_stream_from_zval(res_output, output);
	// output fp
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::dumpHead: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_head(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpHead: failed to dump head.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} dumpHead */

/* {{{ proto bool dumpKeytable([stream output = NULL])
  K2hash::dumpKeytable method */

PHP_METHOD(K2hash, dumpKeytable)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpKeytable: could not open k2hash.");
		RETURN_FALSE;
	}
	// output fp
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::dumpKeytable: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_keytable(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpKeytable: failed to dump head.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} dumpKeytable */

/* {{{ proto bool dumpFullKeytable([stream output = NULL])
  K2hash::dumpFullKeytable method */

PHP_METHOD(K2hash, dumpFullKeytable)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpFullKeytable: could not open k2hash.");
		RETURN_FALSE;
	}
	// output fp
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::dumpFullKeytable: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_full_keytable(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpFullKeytable: failed to dump head.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} dumpFullKeytable */

/* {{{ proto bool dumpElementtable([stream output = NULL])
  K2hash::dumpElementtable method */

PHP_METHOD(K2hash, dumpElementtable)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpElementtable: could not open k2hash.");
		RETURN_FALSE;
	}
	// output fp
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::dumpElementtable: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_elementtable(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpElementtable: failed to dump head.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} dumpElementtable */

/* {{{ proto bool dumpFull([stream output = NULL])
  K2hash::dumpFull method */

PHP_METHOD(K2hash, dumpFull)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpFull: could not open k2hash.");
		RETURN_FALSE;
	}
	// output fp
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::dumpFull: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_full(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::dumpFull: failed to dump head.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} dumpFull */

/* {{{ proto bool printState([stream output = NULL])
  K2hash::printState method */

PHP_METHOD(K2hash, printState)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hash_object* intern = Z_K2HASH_OBJECT_P(getThis());
	k2h_h* res_k2hhandle = intern->handle;
	if (!res_k2hhandle || K2H_INVALID_HANDLE == res_k2hhandle) {
		php_error_docref(NULL, E_NOTICE, "K2hash::printState: could not open k2hash.");
		RETURN_FALSE;
	}
	// output fp
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::printState: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_print_state(*res_k2hhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hash::printState: failed to dump head.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} printState */

/* {{{ proto bool printVersion([stream output = NULL])
  K2hash::printVersion method */

PHP_METHOD(K2hash, printVersion)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_NOTICE, "K2hash::printVersion: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	k2h_print_version(fp);
	RETURN_TRUE;
}
/* }}} printVersion */

static void php_k2hash_object_free(zend_object *object)
{
	// 1. get php_k2hash_object from zend_object pointer.
	php_k2hash_object* intern = get_php_k2hash_object(object);
	if (!intern) {
		return;
	}
	// 2. efree handle.
	if (intern->handle != NULL) {
		if(*intern->handle != K2H_INVALID_HANDLE) {
			k2h_close(*intern->handle);
		}
		efree(intern->handle);
	}
	// 3. destruct zend_object.
	zend_object_std_dtor(&intern->std);
}

static zend_object * php_k2hash_object_alloc(zend_class_entry *class_type)
{
	// The variable name of custom object is conventionaly intern.
	php_k2hash_object *intern;
	// 1. allocate intern.
	intern = ecalloc(1, sizeof(php_k2hash_object) + zend_object_properties_size(class_type));
	intern->handle = emalloc(sizeof(long));
	*intern->handle = K2H_INVALID_HANDLE;
	
	// 2. zend_object intialize(std)
	zend_object_std_init(&intern->std, class_type);
	// set properties.
	object_properties_init(&intern->std, class_type);
	// set handlers
	intern->std.handlers = &k2hash_object_handlers;
	
	// 3. return zend_object pointer
	return &intern->std;
}

void class_init_k2hash(void)
{
	zend_class_entry ce;
	// 1. initialize zend_object handlers
	memcpy(&k2hash_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	k2hash_object_handlers.free_obj = php_k2hash_object_free;
	k2hash_object_handlers.offset = XtOffsetOf(php_k2hash_object, std);
	
	// 2. initialize a local class entry variable and set a create object handler to it.
	INIT_CLASS_ENTRY(ce, PHP_K2HASH_CLASS_NAME, class_K2hash_methods);
	ce.create_object = php_k2hash_object_alloc; // k2hash_object_handlers used in create_object
	
	// The local class entry is  registered in zend_register_internal_class.
	// The final class entry is stored in the global class entry
	php_k2hash_ce = zend_register_internal_class(&ce);
}

/* }}} Class K2hash */

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
