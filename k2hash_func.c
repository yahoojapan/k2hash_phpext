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

#include "php.h"
#include "ext/standard/info.h"
#include "php_k2hash.h"
#include "k2hash_compat.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ protptypes for k2hash php_stream */
php_stream* k2hpx_da_open(k2h_h handle, const char* key, const char* mode STREAMS_DC);
extern php_stream_wrapper php_stream_k2h_wrapper;
/* }}} protptypes for k2hash php_stream */

/* {{{ Resource destructors */
int le_k2hhandle;
static void k2hhandle_dtor(zend_resource *res)
{
	k2h_h *resource = zend_fetch_resource(res, NULL, le_k2hhandle);
	efree(resource);
}

int le_k2hfindhandle;
static void k2hfindhandle_dtor(zend_resource *res)
{
	k2h_find_h *resource = zend_fetch_resource(res, NULL, le_k2hfindhandle);
	efree(resource);
}

int le_k2hdahandle;
static void k2hdahandle_dtor(zend_resource* res)
{
	k2h_da_h *resource = zend_fetch_resource(res, NULL, le_k2hdahandle);
	efree(resource);
}

int le_k2hqhandle;
static void k2hqhandle_dtor(zend_resource *res)
{
	k2h_q_h *resource = zend_fetch_resource(res, NULL, le_k2hqhandle);
	efree(resource);
}

int le_k2hkeyqhandle;
static void k2hkeyqhandle_dtor(zend_resource *res)
{
	k2h_keyq_h *resource = zend_fetch_resource(res, NULL, le_k2hkeyqhandle);
	efree(resource);
}
/* }}} */

/* {{{ void k2hpx_bump_debug_level() */
PHP_FUNCTION(k2hpx_bump_debug_level)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	k2h_bump_debug_level();
}
/* }}} */

/* {{{ void k2hpx_set_debug_level_silent() */
PHP_FUNCTION(k2hpx_set_debug_level_silent)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	k2h_set_debug_level_silent();
}
/* }}} */

/* {{{ void k2hpx_set_debug_level_error() */
PHP_FUNCTION(k2hpx_set_debug_level_error)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	k2h_set_debug_level_error();
}
/* }}} */

/* {{{ void k2hpx_set_debug_level_warning() */
PHP_FUNCTION(k2hpx_set_debug_level_warning)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	k2h_set_debug_level_warning();
}
/* }}} */

/* {{{ void k2hpx_set_debug_level_message() */
PHP_FUNCTION(k2hpx_set_debug_level_message)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	k2h_set_debug_level_message();
}
/* }}} */

/* {{{ bool k2hpx_unset_debug_file() */
PHP_FUNCTION(k2hpx_set_debug_file)
{
	const char * filepath = NULL;
	size_t filepath_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &filepath, &filepath_len) == FAILURE) {
		return;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_set_debug_file: filepath is empty.");
		RETURN_FALSE;
	}
	if(!k2h_set_debug_file(filepath)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_set_debug_file: failed to set debugging file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_unset_debug_file() */
PHP_FUNCTION(k2hpx_unset_debug_file)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	if(!k2h_unset_debug_file()) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_unset_debug_file: failed to unset debugging file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_load_debug_env() */
PHP_FUNCTION(k2hpx_load_debug_env)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	if(!k2h_load_debug_env()) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_load_debug_env: failed to load environment about debugging.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_unload_hash_library() */
PHP_FUNCTION(k2hpx_unload_hash_library)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	if(!k2h_unload_hash_library()) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_unload_hash_library: failed to unset hash library file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_load_transaction_library(string libpath) */
PHP_FUNCTION(k2hpx_load_transaction_library)
{
	const char * libpath = NULL;
	size_t libpath_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &libpath, &libpath_len) == FAILURE) {
		return;
	}
	if(!libpath || 0 == libpath_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_load_transaction_library: libpath is empty.");
		RETURN_FALSE;
	}
	if(!k2h_load_transaction_library(libpath)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_load_transaction_library: failed to set transaction library file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_unload_transaction_library() */
PHP_FUNCTION(k2hpx_unload_transaction_library)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	if(!k2h_unload_transaction_library()) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_unload_transaction_library: failed to unset transaction library file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_load_hash_library(string libpath) */
PHP_FUNCTION(k2hpx_load_hash_library)
{
	const char * libpath = NULL;
	size_t libpath_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &libpath, &libpath_len) == FAILURE) {
		return;
	}
	if(!libpath || 0 == libpath_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_load_hash_library: libpath is empty.");
		RETURN_FALSE;
	}
	if(!k2h_load_hash_library(libpath)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_load_hash_library: failed to set hash library file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_create(string filepath[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]) */
PHP_FUNCTION(k2hpx_create)
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
		php_error_docref(NULL, E_ERROR, "k2hpx_create: filepath is empty.");
		RETURN_FALSE;
	}
	if(!k2h_create(filepath, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_create: failed to create k2hash file.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ resource|false k2hpx_open_opt */
static void k2hpx_open_opt(INTERNAL_FUNCTION_PARAMETERS, int opt)
{
	k2h_h * return_res;
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool readonly = 0;
	zend_bool removefile = false;
	zend_bool fullmap = true;
	zend_long maskbitcnt = K2H_VAL_MASK_BIT;
	zend_long cmaskbitcnt = K2H_VAL_CMASK_BIT;
	zend_long maxelementcnt = K2H_VAL_ELEMENT;
	zend_long pagesize = K2H_VAL_PAGESIZE;
	if (opt == 2) {
		if (zend_parse_parameters(ZEND_NUM_ARGS(), "sb|bbllll", &filepath, &filepath_len, &readonly, &removefile, &fullmap, &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
			return;
		}
	} else if(opt == 4) {
		if (zend_parse_parameters(ZEND_NUM_ARGS(), "|llll", &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
			return;
		}
	} else {
		if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|bllll", &filepath, &filepath_len, &fullmap, &maskbitcnt, &cmaskbitcnt, &maxelementcnt, &pagesize) == FAILURE) {
			return;
		}
	}
	if(opt != 4 && (!filepath || 0 == filepath_len)) {
		php_error_docref(NULL, E_ERROR, "k2hpx_open_rw: filepath is empty.");
		RETURN_FALSE;
	}
	k2h_h	handle;
	switch (opt) {
	case 0:
		if(K2H_INVALID_HANDLE == (handle = k2h_open_rw(filepath, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_open_rw: failed to attach k2hash file.");
			RETURN_FALSE;
		}
		break;
	case 1:
		if(K2H_INVALID_HANDLE == (handle = k2h_open_ro(filepath, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_open_ro: failed to attach k2hash file.");
			RETURN_FALSE;
		}
		break;
	case 2:
		if(K2H_INVALID_HANDLE == (handle = k2h_open(filepath, 0 != readonly ? true : false, 0 != removefile ? true : false, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_open: failed to attach k2hash file.");
			RETURN_FALSE;
		}
		break;
	case 3:
		if(K2H_INVALID_HANDLE == (handle = k2h_open_tempfile(filepath, 0 != fullmap ? true : false, (int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_open_tempfile: failed to attach k2hash file.");
			RETURN_FALSE;
		}
		break;
	case 4:
		if(K2H_INVALID_HANDLE == (handle = k2h_open_mem((int)maskbitcnt, (int)cmaskbitcnt, (int)maxelementcnt, (size_t)pagesize))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_open_mem: failed to attach k2hash file.");
			RETURN_FALSE;
		}
		break;
	default:
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long));// TODO free?
	(*return_res) = handle;
	RETURN_RES(zend_register_resource(return_res, le_k2hhandle));
}
/* }}} */

/* {{{ resource|false k2hpx_open(string filepath, bool readonly[, bool removefile = false[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]]]) */
PHP_FUNCTION(k2hpx_open)
{
	k2hpx_open_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 2);
}
/* }}} */

/* {{{ resource|false k2hpx_open_rw(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]]) */
PHP_FUNCTION(k2hpx_open_rw)
{
	k2hpx_open_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 0);
}
/* }}} */

/* {{{ resource|false k2hpx_open_ro(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]]) */
PHP_FUNCTION(k2hpx_open_ro)
{
	k2hpx_open_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 1);
}
/* }}} */

/* {{{ resource|false k2hpx_open_tempfile(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]]) */
PHP_FUNCTION(k2hpx_open_tempfile)
{
	k2hpx_open_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 3);
}
/* }}} */

/* {{{ resource|false k2hpx_open_mem([int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]) */
PHP_FUNCTION(k2hpx_open_mem)
{
	k2hpx_open_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 4);
}
/* }}} */

/* {{{ bool k2hpx_close(resource k2hhandle handle[, int waitms = 0]) */
PHP_FUNCTION(k2hpx_close)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zend_long waitms = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|l", &handle_res, &waitms) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_close: handle is empty.");
		RETURN_FALSE;
	}
	// check parameter
	if(waitms < -1) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_close: waitms must be -1, 0, 1...");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_close_wait(*handle, waitms)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_close: failed to close handle.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_transaction_opt */
static void k2hpx_transaction_opt(INTERNAL_FUNCTION_PARAMETERS, int opt)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zend_bool enable = 0;
	const char * transfile = NULL;
	size_t transfile_len = 0;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	const char * param = NULL;
	size_t param_len = 0;
	zend_long expire = 0;
	if(opt == 0) {
		if (zend_parse_parameters(ZEND_NUM_ARGS(), "rb|sssl", &handle_res, &enable, &transfile, &transfile_len, &prefix, &prefix_len, &param, &param_len, &expire) == FAILURE) {
			return;
		}
	} else if(opt == 1) {
		if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|sssl", &handle_res, &transfile, &transfile_len, &prefix, &prefix_len, &param, &param_len, &expire) == FAILURE) {
			return;
		}
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_transaction: handle is empty.");
		RETURN_FALSE;
	}
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	switch (opt) {
	case 0:
		// transfile and prefix is allowed null
		if(!k2h_transaction_param_we(*handle, 0 != enable ? true : false, (!transfile || 0 == transfile_len) ? NULL : transfile, (!prefix || 0 == prefix_len) ? NULL : (const unsigned char*)prefix, prefix_len, (!param || 0 == param_len) ? NULL : (const unsigned char*)param, param_len, ptmexpire)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_transaction: failed to set transfile and dis/enable.");
			RETURN_FALSE;
		}
		RETURN_TRUE;
		break;
	case 1:
		// transfile and prefix is allowed null
		if(!k2h_enable_transaction_param_we(*handle, (!transfile || 0 == transfile_len) ? NULL : transfile, (!prefix || 0 == prefix_len) ? NULL : (const unsigned char*)prefix, prefix_len, (!param || 0 == param_len) ? NULL : (const unsigned char*)param, param_len, ptmexpire)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_enable_transaction: failed to set transfile for enable.");
			RETURN_FALSE;
		}
		RETURN_TRUE;
		break;
	default:
		break;
	}
	RETURN_FALSE;
}
/* }}} */

/* {{{ bool k2hpx_transaction(resource k2hhandle handle, bool enable[, string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]]) */
PHP_FUNCTION(k2hpx_transaction)
{
	k2hpx_transaction_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 0);
}
/* }}} */

/* {{{ bool k2hpx_enable_transaction(resource k2hhandle handle[, string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]]) */
PHP_FUNCTION(k2hpx_enable_transaction)
{
	k2hpx_transaction_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 1);
}
/* }}} */

/* {{{ bool k2hpx_disable_transaction(resource k2hhandle handle) */
PHP_FUNCTION(k2hpx_disable_transaction)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &handle_res) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_disable_transaction: handle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_disable_transaction(*handle)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_disable_transaction: failed to set disable.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ int k2hpx_get_transaction_thread_pool() */
PHP_FUNCTION(k2hpx_get_transaction_thread_pool)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	int	count = k2h_get_transaction_thread_pool();
	RETURN_LONG((long)count);
}
/* }}} */

/* {{{ bool k2h_set_transaction_thread_pool(int count) */
PHP_FUNCTION(k2hpx_set_transaction_thread_pool)
{
	zend_long count = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &count) == FAILURE) {
		return;
	}
	if(!k2h_set_transaction_thread_pool((int)count)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_set_transaction_thread_pool: failed to set transaction thread pool count.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2h_unset_transaction_thread_pool() */
PHP_FUNCTION(k2hpx_unset_transaction_thread_pool)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	if(!k2h_unset_transaction_thread_pool()) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_unset_transaction_thread_pool: failed to unset transaction thread pool.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_put_archive(resource k2hhandle handle, string filepath, bool errskip) */
PHP_FUNCTION(k2hpx_put_archive)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool errskip = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rsb", &handle_res, &filepath, &filepath_len, &errskip) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_put_archive: handle is empty.");
		RETURN_FALSE;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_put_archive: filepath is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_put_archive(*handle, filepath, 0 != errskip ? true : false)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_put_archive: failed to put archive to filepath.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_load_archive(resource k2hhandle handle, string filepath, bool errskip) */
PHP_FUNCTION(k2hpx_load_archive)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_bool errskip = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rsb", &handle_res, &filepath, &filepath_len, &errskip) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_load_archive: handle is empty.");
		RETURN_FALSE;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_load_archive: filepath is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_load_archive(*handle, filepath, 0 != errskip ? true : false)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_load_archive: failed to load archive from filepath.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_set_common_attr(resource k2hhandle handle[, int is_mtime = K2H_ATTR_DEFAULT[, int is_history = K2H_ATTR_DEFAULT[, int is_encrypt = K2H_ATTR_DEFAULT, string passfile = NULL[, int is_expire = K2H_ATTR_DEFAULT, int expire = 0]]]]) */
PHP_FUNCTION(k2hpx_set_common_attr)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zend_long is_mtime = K2H_VAL_ATTR_DEFAULT;
	zend_long is_history = K2H_VAL_ATTR_DEFAULT;
	zend_long is_encrypt = K2H_VAL_ATTR_DEFAULT;
	const char * passfile = NULL;
	size_t passfile_len = 0;
	zend_long is_expire = K2H_VAL_ATTR_DEFAULT;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|lllsll", &handle_res, &is_mtime, &is_history, &is_encrypt, &passfile, &passfile_len, &is_expire, &expire) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_set_common_attr: handle is empty.");
		RETURN_FALSE;
	}
	bool	mtime_val	= false;
	bool*	pmtime_val	= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_mtime) {
		mtime_val	= K2H_VAL_ATTR_ENABLE == is_mtime ? true : false;
		pmtime_val	= &mtime_val;
	}
	bool		enc_val		= false;
	bool*		penc_val	= NULL;
	const char*	pfile		= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_encrypt) {
		if(K2H_VAL_ATTR_ENABLE == is_encrypt) {
			if(!passfile || passfile_len == 0) {
				php_error_docref(NULL, E_ERROR, "k2hpx_set_common_attr: passfile must not be empty.");
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
	bool	his_val		= false;
	bool*	phis_val	= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_history) {
		his_val		= K2H_VAL_ATTR_ENABLE == is_history ? true : false;
		phis_val	= &his_val;
	}
	time_t	expire_val	= 0;
	time_t*	pexpire_val	= NULL;
	if(K2H_VAL_ATTR_DEFAULT != is_expire) {
		if(K2H_VAL_ATTR_ENABLE == is_expire) {
			if(expire <= 0) {
				php_error_docref(NULL, E_ERROR, "k2hpx_set_common_attr: expire must not be over zero.");
				RETURN_FALSE;
			}
			expire_val	= (time_t)expire;
			pexpire_val	= &expire_val;
		} else {
			expire_val	= -1;			// == NOT_EXPIRE
			pexpire_val	= &expire_val;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_set_common_attr(*handle, pmtime_val, penc_val, pfile, phis_val, pexpire_val)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_set_common_attr: failed to set common attributes.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_clean_common_attr(resource k2hhandle handle) */
PHP_FUNCTION(k2hpx_clean_common_attr)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &handle_res) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_clean_common_attr: handle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_clean_common_attr(*handle)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_clean_common_attr: failed to clear common attributes setting.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_add_attr_plugin_library(resource k2hhandle handle, string libfile) */
PHP_FUNCTION(k2hpx_add_attr_plugin_library)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * libfile = NULL;
	size_t libfile_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs", &handle_res, &libfile, &libfile_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_attr_plugin_library: handle is empty.");
		RETURN_FALSE;
	}
	if(!libfile || libfile_len == 0) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_attr_plugin_library: library file path is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_add_attr_plugin_library(*handle, libfile)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_add_attr_plugin_library: failed to load plugin attribute library.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_add_attr_crypt_pass(resource k2hhandle handle, string encpass[, bool is_default_encrypt = false]) */
PHP_FUNCTION(k2hpx_add_attr_crypt_pass)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * encpass = NULL;
	size_t encpass_len = 0;
	zend_bool is_default_encrypt = false;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|b", &handle_res, &encpass, &encpass_len, &is_default_encrypt) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_attr_crypt_pass: handle is empty.");
		RETURN_FALSE;
	}
	if(!encpass || encpass_len == 0) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_attr_crypt_pass: encrypt pass phrase is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_add_attr_crypt_pass(*handle, encpass, is_default_encrypt)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_add_attr_crypt_pass: failed to add encrypt pass phrase.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_print_attr_version(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_print_attr_version)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_print_attr_version: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_print_attr_version: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_print_attr_version(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_print_attr_version: failed to print all attributes version.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_print_attr_information(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_print_attr_information)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_print_attr_information: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_print_attr_information: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_print_attr_information(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_print_attr_information: failed to print attributes information.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ string k2hpx_get_value(resource k2hhandle handle, string key[, string subkey = NULL[, bool attrcheck = true[, string pass = NULL]]]) */
PHP_FUNCTION(k2hpx_get_value)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	zend_bool attrcheck = true;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|sbs", &handle_res, &key, &key_len, &subkey, &subkey_len, &attrcheck, &pass, &pass_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_value: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_value: key is empty.");
		RETURN_FALSE;
	}
	char*	pvalue;
	if(!subkey || 0 == subkey_len) {
		if(attrcheck) {
			if(NULL == (pvalue = k2h_get_str_direct_value_wp(*handle, key, pass))) {
				//php_error_docref(NULL, E_NOTICE, "k2hpx_get_value: the key does not exist.");
				RETURN_FALSE;
			}
		} else {
			if(NULL == (pvalue = k2h_get_str_direct_value_np(*handle, key))) {
				//php_error_docref(NULL, E_NOTICE, "k2hpx_get_value: the key does not exist.");
				RETURN_FALSE;
			}
		}
	} else {
		int		subkey_count;
		char**	pskeyarray = NULL;
		bool	isFound = false;
		if(attrcheck) {
			if(0 == (subkey_count = k2h_get_str_subkeys(*handle, key, &pskeyarray))) {
				//php_error_docref(NULL, E_NOTICE, "k2hpx_get_value: the key does not have subkey.");
				if(pskeyarray) {
					k2h_free_keyarray(pskeyarray);
				}
				RETURN_FALSE;
			}
		} else {
			if(0 == (subkey_count = k2h_get_str_subkeys_np(*handle, key, &pskeyarray))) {
				//php_error_docref(NULL, E_NOTICE, "k2hpx_get_value: the key does not have subkey.");
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
			//php_error_docref(NULL, E_NOTICE, "k2hpx_get_value: the key does not have subkey.");
			RETURN_FALSE;
		}
		if(attrcheck) {
			if(NULL == (pvalue = k2h_get_str_direct_value_wp(*handle, subkey, pass))) {
				//php_error_docref(NULL, E_NOTICE, "k2hpx_get_value: the key does not exist.");
				RETURN_FALSE;
			}
		} else {
			if(NULL == (pvalue = k2h_get_str_direct_value_np(*handle, subkey))) {
				//php_error_docref(NULL, E_NOTICE, "k2hpx_get_value: the key does not exist.");
				RETURN_FALSE;
			}
		}
	}
	zend_string *str = zend_string_init(pvalue, strlen(pvalue), 0);
	RETVAL_STR(str);
	free(pvalue);
}
/* }}} */

/* {{{ array k2hpx_get_subkeys(resource k2hhandle handle, string key[, bool attrcheck = true]) */
PHP_FUNCTION(k2hpx_get_subkeys)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	zend_bool attrcheck = true;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|b", &handle_res, &key, &key_len, &attrcheck) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	array_init(return_value);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_subkeys: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_subkeys: key is empty.");
		RETURN_FALSE;
	}
	int		subkey_count;
	char**	pskeyarray = NULL;
	if(attrcheck) {
		if(0 != (subkey_count = k2h_get_str_subkeys(*handle, key, &pskeyarray))) {
			char**	pptmp;
			for(pptmp = pskeyarray; pptmp && *pptmp; pptmp++) {
				add_next_index_string(return_value, *pptmp);
			}
		}
	} else {
		if(0 != (subkey_count = k2h_get_str_subkeys_np(*handle, key, &pskeyarray))) {
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
/* }}} */

/* {{{ array k2hpx_get_attrs(resource k2hhandle handle, string key) */
PHP_FUNCTION(k2hpx_get_attrs)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs", &handle_res, &key, &key_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	array_init(return_value);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_attrs: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_attrs: key is empty.");
		RETURN_FALSE;
	}
	PK2HATTRPCK	pattrs; // TODO where malloc?
	int			attrspckcnt = 0;
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL != (pattrs = k2h_get_str_direct_attrs(*handle, key, &attrspckcnt)) && 0 < attrspckcnt) {
		int	cnt;
		for(cnt = 0; cnt < attrspckcnt; ++cnt) {
			char*	pattrkey;
			if(NULL != (pattrkey = (char*)emalloc(pattrs[cnt].keylength + 1))) {
				memcpy(pattrkey, pattrs[cnt].pkey, pattrs[cnt].keylength);
				pattrkey[pattrs[cnt].keylength] = '\0';
				add_next_index_string(return_value, pattrkey);
				efree(pattrkey);
			}
		}
	}
	if(pattrs) {
		k2h_free_attrpack(pattrs, attrspckcnt);
	}
}
/* }}} */

/* {{{ string k2hpx_get_attr_value(resource k2hhandle handle, string key, string attrkey) */
PHP_FUNCTION(k2hpx_get_attr_value)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * attrkey = NULL;
	size_t attrkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rss", &handle_res, &key, &key_len, &attrkey, &attrkey_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_attr_value: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_attr_value: key is empty.");
		RETURN_FALSE;
	}
	if(!attrkey || 0 == attrkey_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_get_attr_value: attribute key is empty.");
		RETURN_FALSE;
	}
	PK2HATTRPCK	pattrs; // TODO where malloc?
	int			attrspckcnt	= 0;
	bool		is_found	= false;
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL != (pattrs = k2h_get_str_direct_attrs(*handle, key, &attrspckcnt)) && 0 < attrspckcnt) {
		int	cnt;
		for(cnt = 0; cnt < attrspckcnt; ++cnt) {
			if(pattrs[cnt].keylength < (size_t)attrkey_len) {
				continue;	// wrong length
			}
			if(0 == memcmp(attrkey, pattrs[cnt].pkey, (size_t)attrkey_len)) {
				// found attribute key
				char*	pattrval;
				if(NULL == (pattrval = (char*)emalloc(pattrs[cnt].vallength + 1))) {
					php_error_docref(NULL, E_ERROR, "k2hpx_get_attr_value: could not allocate memory.");
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
				efree(pattrval);
				is_found = true;
				break;
			}
		}
	}
	if(pattrs) {
		k2h_free_attrpack(pattrs, attrspckcnt);
	}
	if(!is_found) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_get_attr_value: could not find attribute key name.");
		RETURN_FALSE;
	}
}
/* }}} */

/* {{{ proto bool k2hpx_set_value(resource k2hhandle handle, string key, string value[, string subkey = NULL[, string pass=NULL[, int expire=0]]])
 *   Set value */
PHP_FUNCTION(k2hpx_set_value)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * value = NULL;
	size_t value_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rss|ssl", &handle_res, &key, &key_len, &value, &value_len, &subkey, &subkey_len, &pass, &pass_len, &expire) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_set_value: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_set_value: key is empty.");
		RETURN_FALSE;
	}
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	if(!subkey || 0 == subkey_len) {
		if(!k2h_set_str_value_wa(*handle, key, value, pass, ptmexpire)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_set_value: failed to set value for key.");
			RETURN_FALSE;
		}
	} else {
		if(!k2h_add_str_subkey_wa(*handle, key, subkey, value, pass, ptmexpire)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_set_value: failed to set value for subkey in key.");
			RETURN_FALSE;
		}
	}
	RETURN_TRUE;
}
/* }}} k2hpx_set_value */

/* {{{ bool k2hpx_add_subkey(resource k2hhandle handle, string key, string subkey) */
PHP_FUNCTION(k2hpx_add_subkey)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rss", &handle_res, &key, &key_len, &subkey, &subkey_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_subkey: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_subkey: key is empty.");
		RETURN_FALSE;
	}
	if(!subkey || 0 == subkey_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_subkey: subkey is empty.");
		RETURN_FALSE;
	}
	// get now subkeys list
	int			skeypckcnt	= 0;
	// cppcheck-suppress nullPointerRedundantCheck
	PK2HKEYPCK	pskeypck	= k2h_get_direct_subkeys(*handle, (const unsigned char*)key, strlen(key) + 1, &skeypckcnt);
	// make new subkeys list(+1)
	PK2HKEYPCK	pnewpck;
	if(NULL == (pnewpck = (PK2HKEYPCK)calloc((skeypckcnt + 1), sizeof(K2HKEYPCK)))) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_subkey: could not allocation memory.");
		if(pskeypck) {
			k2h_free_keypack(pskeypck, skeypckcnt);
		}
		RETURN_FALSE;
	}
	// set subkey into first entry in new subkeys list
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL == (pnewpck[0].pkey = (unsigned char*)calloc(strlen(subkey) + 1, sizeof(unsigned char)))) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_subkey: could not allocation memory.");
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
		if(0 == strcmp((const char*)pskeypck[cnt].pkey, subkey)) {
			// found same key name
			continue;
		}
		if(NULL == (pnewpck[setpos].pkey = (unsigned char*)calloc(pskeypck[cnt].length, sizeof(unsigned char)))) {
			php_error_docref(NULL, E_ERROR, "k2hpx_add_subkey: could not allocation memory.");
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
	if(!k2h_set_subkeys(*handle, (const unsigned char*)key, strlen(key) + 1, pnewpck, setpos)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_add_subkey: failed to set subkey into key.");
		k2h_free_keypack(pnewpck, setpos);
		RETURN_FALSE;
	}
	k2h_free_keypack(pnewpck, setpos);
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_add_subkeys(resource k2hhandle handle, string key, array& subkeys) */
PHP_FUNCTION(k2hpx_add_subkeys)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	zval * subkeys = NULL;
	HashTable * subkeys_hash = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rsa", &handle_res, &key, &key_len, &subkeys) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	subkeys_hash = Z_ARRVAL_P(subkeys);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_subkeys: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_subkeys: key is empty.");
		RETURN_FALSE;
	}
	int			subkeys_count = zend_hash_num_elements(subkeys_hash);
	PK2HKEYPCK	pnewpck = NULL;
	int			setpos = 0;
	if(0 < subkeys_count) {
		// allocate new subkeys list
		if(NULL == (pnewpck = (PK2HKEYPCK)calloc(subkeys_count, sizeof(K2HKEYPCK)))) {
			php_error_docref(NULL, E_ERROR, "k2hpx_add_subkeys: could not allocation memory.");
			RETURN_FALSE;
		}
		// https://phpinternals.net/docs/zend_hash_foreach_num_key_val
		zend_long lkey;
		zval *val;
		// cppcheck-suppress uninitvar
		ZEND_HASH_FOREACH_NUM_KEY_VAL(subkeys_hash, lkey, val) {
			// for debug
			//php_printf("%d => ", lkey);
			//php_debug_zval_dump(val, 0);
			if(!val || IS_STRING != Z_TYPE_P(val)) {
				php_error_docref(NULL, E_WARNING, "k2hpx_add_subkeys: found unsafe reference zval, skip it.");
				continue;
			}
			char*	subkey = Z_STRVAL_P(val);
			if(!subkey) {
				php_error_docref(NULL, E_WARNING, "k2hpx_add_subkeys: found null element in array, skip it.");
				continue;
			}
			if(NULL == (pnewpck[lkey].pkey = (unsigned char*)calloc(strlen(subkey) + 1, sizeof(unsigned char)))) {
				php_error_docref(NULL, E_ERROR, "k2hpx_add_subkeys: could not allocation memory.");
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
	if(!k2h_set_subkeys(*handle, (const unsigned char*)key, strlen(key) + 1, pnewpck, setpos)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_add_subkeys: failed to set subkeys into key.");
		k2h_free_keypack(pnewpck, setpos);
		RETURN_FALSE;
	}
	k2h_free_keypack(pnewpck, setpos);
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_add_attr(resource k2hhandle handle, string key, string attrkey, string attrval) */
PHP_FUNCTION(k2hpx_add_attr)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * attrkey = NULL;
	size_t attrkey_len = 0;
	const char * attrval = NULL;
	size_t attrval_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rsss", &handle_res, &key, &key_len, &attrkey, &attrkey_len, &attrval, &attrval_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_attr: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_attr: key is empty.");
		RETURN_FALSE;
	}
	if(!attrkey || 0 == attrkey_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_add_attr: attribute key is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_add_str_attr(*handle, key, attrkey, attrval)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_add_attr: failed to add attribute into key.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_remove_all(resource k2hhandle handle, string key) */
PHP_FUNCTION(k2hpx_remove_all)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs", &handle_res, &key, &key_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_remove_all: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_remove_all: key is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_remove_str_all(*handle, key)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_remove_all: failed to remove all for key.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_remove(resource k2hhandle handle, string key[, string subkey = NULL]) */
PHP_FUNCTION(k2hpx_remove)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * subkey = NULL;
	size_t subkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|s", &handle_res, &key, &key_len, &subkey, &subkey_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_remove: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_remove: key is empty.");
		RETURN_FALSE;
	}
	if(!subkey || 0 == subkey_len) {
		if(!k2h_remove_str(*handle, key)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_remove: failed to remove only key.");
			RETURN_FALSE;
		}
	} else {
		if(!k2h_remove_str_subkey(*handle, key, subkey)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_remove: failed to remove subkey from subkey list in key.");
			RETURN_FALSE;
		}
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_rename(resource k2hhandle handle, string key, string newkey) */
PHP_FUNCTION(k2hpx_rename)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * newkey = NULL;
	size_t newkey_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rss", &handle_res, &key, &key_len, &newkey, &newkey_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_rename: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_rename: key is empty.");
		RETURN_FALSE;
	}
	if(!newkey || 0 == newkey_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_rename: new key is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_rename_str(*handle, key, newkey)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_rename: failed to rename key name.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ resource k2hfindhandle k2hpx_find_first(resource k2hhandle handle[, string key = NULL]) */
PHP_FUNCTION(k2hpx_find_first)
{
	k2h_find_h * return_res;
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|s", &handle_res, &key, &key_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_find_first: handle is empty.");
		RETURN_FALSE;
	}
	k2h_find_h	findhandle;
	if(!key || 0 == key_len) {
		findhandle = k2h_find_first(*handle);
	} else {
		findhandle = k2h_find_first_str_subkey(*handle, key);
	}
	if(K2H_INVALID_HANDLE == findhandle) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_find_first: failed to get handle for find.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long)); // TODO どこでfree?
	(*return_res) = findhandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hfindhandle));
}
/* }}} */

/* {{{ resource k2hfindhandle k2hpx_find_next(resource k2hfindhandle findhandle) */
PHP_FUNCTION(k2hpx_find_next)
{
	k2h_find_h * return_res;
	zval * findhandle_res = NULL;
	k2h_find_h * findhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &findhandle_res) == FAILURE) {
		return;
	}
	findhandle = (k2h_find_h*) zend_fetch_resource(Z_RES_P(findhandle_res), RESOURCE_K2H_FINDHANDLE, le_k2hfindhandle);
	if(!findhandle || *findhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_find_next: findhandle is empty.");
		RETURN_FALSE;
	}
	k2h_find_h	nexthandle;
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == (nexthandle = k2h_find_next(*findhandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_find_next: failed to get next find handle.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long)); // TODO どこでfree?
	(*return_res) = nexthandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hfindhandle));
}
/* }}} */

/* {{{ bool k2hpx_find_free(resource k2hfindhandle findhandle) */
PHP_FUNCTION(k2hpx_find_free)
{
	zval * findhandle_res = NULL;
	k2h_find_h * findhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &findhandle_res) == FAILURE) {
		return;
	}
	findhandle = (k2h_find_h*) zend_fetch_resource(Z_RES_P(findhandle_res), RESOURCE_K2H_FINDHANDLE, le_k2hfindhandle);
	if(!findhandle || *findhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_find_free: findhandle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_find_free(*findhandle)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_find_free: failed to free find handle.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ string k2hpx_find_get_key(resource k2hfindhandle findhandle) */
PHP_FUNCTION(k2hpx_find_get_key)
{
	zval * findhandle_res = NULL;
	k2h_find_h * findhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &findhandle_res) == FAILURE) {
		return;
	}
	findhandle = (k2h_find_h*) zend_fetch_resource(Z_RES_P(findhandle_res), RESOURCE_K2H_FINDHANDLE, le_k2hfindhandle);
	if(!findhandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_find_get_key: findhandle is empty.");
		RETURN_FALSE;
	}
	char*	pkey;
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL == (pkey = k2h_find_get_str_key(*findhandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_find_get_key: could not get key string by findhandle.");
		RETURN_FALSE;
	}
	RETVAL_STRING(pkey);
	free(pkey);
}
/* }}} */

/* {{{ proto string k2hpx_find_get_value(resource k2hfindhandle findhandle) */
PHP_FUNCTION(k2hpx_find_get_value)
{
	zval * findhandle_res = NULL;
	k2h_find_h * findhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &findhandle_res) == FAILURE) {
		return;
	}
	findhandle = (k2h_find_h*) zend_fetch_resource(Z_RES_P(findhandle_res), RESOURCE_K2H_FINDHANDLE, le_k2hfindhandle);
	if(!findhandle || *findhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_find_get_value: findhandle is empty.");
		RETURN_FALSE;
	}
	char*	pvalue;
	// cppcheck-suppress nullPointerRedundantCheck
	if(NULL == (pvalue = k2h_find_get_direct_value(*findhandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_find_get_value: could not get value string by findhandle.");
		RETURN_FALSE;
	}
	RETVAL_STRING(pvalue);
	free(pvalue);
}
/* }}} k2hpx_find_get_value */

/* {{{ array k2hpx_find_get_subkeys(resource k2hfindhandle findhandle) */
PHP_FUNCTION(k2hpx_find_get_subkeys)
{
	zval * findhandle_res = NULL;
	k2h_find_h * findhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &findhandle_res) == FAILURE) {
		return;
	}
	findhandle = (k2h_find_h*) zend_fetch_resource(Z_RES_P(findhandle_res), RESOURCE_K2H_FINDHANDLE, le_k2hfindhandle);
	array_init(return_value);
	if(!findhandle || *findhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_find_get_subkeys: findhandle is empty.");
		RETURN_FALSE;
	}
	int		subkey_count;
	char**	pskeyarray = NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(0 != (subkey_count = k2h_find_get_str_subkeys(*findhandle, &pskeyarray))) {
		char**	pptmp;
		for(pptmp = pskeyarray; pptmp && *pptmp; pptmp++) {
			add_next_index_string(return_value, *pptmp);
		}
	}
	if(pskeyarray) {
		k2h_free_keyarray(pskeyarray);
	}
}
/* }}} */

/* {{{ resource k2hdahandle k2hpx_da_get_handle(resource k2hhandle handle, string key, int mode) */
PHP_FUNCTION(k2hpx_da_get_handle)
{
	k2h_da_h * return_res;
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	zend_long mode = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rsl", &handle_res, &key, &key_len, &mode) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle: key is empty.");
		RETURN_FALSE;
	}
	if(K2H_DA_READ != mode && K2H_DA_WRITE != mode && K2H_DA_RW != mode) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle: mode is invalid.");
		RETURN_FALSE;
	}
	k2h_da_h	dahandle;
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == (dahandle = k2h_da_str_handle(*handle, key, mode))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_handle: failed to get handle for direct access.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long));
	(*return_res) = dahandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hdahandle));
}
/* }}} */

/* {{{ resource k2hdahandle k2hpx_da_get_handle_read(resource k2hhandle handle, string key) */
PHP_FUNCTION(k2hpx_da_get_handle_read)
{
	k2h_da_h * return_res;
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs", &handle_res, &key, &key_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle_read: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle_read: key is empty.");
		RETURN_FALSE;
	}
	k2h_da_h	dahandle;
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == (dahandle = k2h_da_str_handle_read(*handle, key))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_handle_read: failed to get readable handle for direct access.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long));
	(*return_res) = dahandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hdahandle));
}
/* }}} */

/* {{{ resource k2hdahandle k2hpx_da_get_handle_write(resource k2hhandle handle, string key) */
PHP_FUNCTION(k2hpx_da_get_handle_write)
{
	k2h_da_h * return_res;
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs", &handle_res, &key, &key_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle_write: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle_write: key is empty.");
		RETURN_FALSE;
	}
	k2h_da_h	dahandle;
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == (dahandle = k2h_da_str_handle_write(*handle, key))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_handle_write: failed to get writable handle for direct access.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long));
	(*return_res) = dahandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hdahandle));
}
/* }}} */

/* {{{ resource k2hdahandle k2hpx_da_get_handle_rw(resource k2hhandle handle, string key) */
PHP_FUNCTION(k2hpx_da_get_handle_rw)
{
	k2h_da_h * return_res;
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs", &handle_res, &key, &key_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle_rw: handle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_handle_rw: key is empty.");
		RETURN_FALSE;
	}
	k2h_da_h	dahandle;
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == (dahandle = k2h_da_str_handle_rw(*handle, key))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_handle_rw: failed to get writable handle for direct access.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long));
	(*return_res) = dahandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hdahandle));
}
/* }}} */

/* {{{ bool k2hpx_da_free(resource k2hdahandle dahandle) */
PHP_FUNCTION(k2hpx_da_free)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &dahandle_res) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_free: handle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_da_free(*dahandle)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_free: failed to free direct access handle.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ int k2hpx_da_get_length(resource k2hdahandle dahandle) */
PHP_FUNCTION(k2hpx_da_get_length)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &dahandle_res) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_length: handle is empty.");
		RETURN_FALSE;
	}
	long	length;
	// cppcheck-suppress nullPointerRedundantCheck
	if(0 > (length = (long)k2h_da_get_length(*dahandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_length: failed to get value length by direct access handle.");
		RETURN_FALSE;
	}
	RETURN_LONG(length);
}
/* }}} */

/* {{{ array k2hpx_da_get_offset(resource k2hdahandle dahandle) */
PHP_FUNCTION(k2hpx_da_get_offset)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &dahandle_res) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	array_init(return_value);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_offset: handle is empty.");
		RETURN_FALSE;
	}
	off_t	roffset;
	off_t	woffset;
	// cppcheck-suppress nullPointerRedundantCheck
	if(-1 == (roffset = k2h_da_get_read_offset(*dahandle)) || -1 == (woffset = k2h_da_get_write_offset(*dahandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_offset: failed to get offset for direct access handle.");
		RETURN_FALSE;
	}
	add_next_index_long(return_value, roffset);
	add_next_index_long(return_value, woffset);
}
/* }}} */

/* {{{ int k2hpx_da_get_read_offset(resource k2hdahandle dahandle) */
PHP_FUNCTION(k2hpx_da_get_read_offset)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &dahandle_res) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_read_offset: handle is empty.");
		RETURN_FALSE;
	}
	off_t	roffset;
	// cppcheck-suppress nullPointerRedundantCheck
	if(-1 == (roffset = k2h_da_get_read_offset(*dahandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_read_offset: failed to get readable offset for direct access handle.");
		RETURN_FALSE;
	}
	RETURN_LONG((long)roffset);
}
/* }}} */

/* {{{ int k2hpx_da_get_write_offset(resource k2hdahandle dahandle) */
PHP_FUNCTION(k2hpx_da_get_write_offset)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &dahandle_res) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_write_offset: handle is empty.");
		RETURN_FALSE;
	}
	off_t	woffset;
	// cppcheck-suppress nullPointerRedundantCheck
	if(-1 == (woffset = k2h_da_get_write_offset(*dahandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_write_offset: failed to get writable offset for direct access handle.");
		RETURN_FALSE;
	}
	RETURN_LONG((long)woffset);
}
/* }}} */

/* {{{ bool k2hpx_da_set_offset(resource k2hdahandle dahandle, array& offsets) */
PHP_FUNCTION(k2hpx_da_set_offset)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	zval * offsets = NULL;
	HashTable * offsets_hash = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ra", &dahandle_res, &offsets) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	offsets_hash = Z_ARRVAL_P(offsets);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_offset: handle is empty.");
		RETURN_FALSE;
	}
	int	offset_count;
	if(2 != (offset_count = zend_hash_num_elements(offsets_hash))) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_offset: offsets value count is invalid.");
		RETURN_FALSE;
	}
	zval*	zval_roffset = zend_hash_index_find(offsets_hash, 0);
	zval*	zval_woffset = zend_hash_index_find(offsets_hash, 1);
	if(NULL == zval_roffset || NULL == zval_woffset) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_offset: failed to convert offsets value.");
		RETURN_FALSE;
	}
	off_t	roffset = (off_t)Z_LVAL_P(zval_roffset);
	off_t	woffset = (off_t)Z_LVAL_P(zval_woffset);
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_da_set_read_offset(*dahandle, roffset) || !k2h_da_set_write_offset(*dahandle, woffset)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_offset: failed to set offsets.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_da_set_read_offset(resource k2hdahandle dahandle, int offset) */
PHP_FUNCTION(k2hpx_da_set_read_offset)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	zend_long offset = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rl", &dahandle_res, &offset) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_read_offset: handle is empty.");
		RETURN_FALSE;
	}
	if(0 > offset) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_read_offset: offset is invalid.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_da_set_read_offset(*dahandle, (off_t)offset)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_read_offset: failed to set readable offset.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool k2hpx_da_set_write_offset(resource k2hdahandle dahandle, int offset) */
PHP_FUNCTION(k2hpx_da_set_write_offset)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	zend_long offset = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rl", &dahandle_res, &offset) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_write_offset: handle is empty.");
		RETURN_FALSE;
	}
	if(0 > offset) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_write_offset: offset is invalid.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_da_set_write_offset(*dahandle, (off_t)offset)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_write_offset: failed to set writable offset.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto string k2hpx_da_get_value(resource k2hdahandle dahandle[, int offset = -1]) */
PHP_FUNCTION(k2hpx_da_get_value)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	zend_long offset = -1;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|l", &dahandle_res, &offset) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_value: handle is empty.");
		RETURN_FALSE;
	}
	if(0 <= offset) {
		if(!k2h_da_set_read_offset(*dahandle, (off_t)offset)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_value: failed to set readable offset.");
			RETURN_FALSE;
		}
	}
	char*	pvalue;
	if(NULL == (pvalue = k2h_da_read_str(*dahandle))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_value: failed to get value.");
		RETURN_FALSE;
	}
	RETVAL_STRING(pvalue);
	free(pvalue);
}
/* }}} */

/* {{{ bool k2hpx_da_get_value_to_file(resource k2hdahandle dahandle, string filepath[, int length = -1[, int offset = -1]]) */
PHP_FUNCTION(k2hpx_da_get_value_to_file)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_long length = -1;
	zend_long offset = -1;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|ll", &dahandle_res, &filepath, &filepath_len, &length, &offset) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_value_to_file: handle is empty.");
		RETURN_FALSE;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_get_value_to_file: filepath is empty.");
		RETURN_FALSE;
	}
	// offset
	if(0 <= offset) {
		if(!k2h_da_set_read_offset(*dahandle, (off_t)offset)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_value_to_file: failed to set readable offset.");
			RETURN_FALSE;
		}
	}
	// length
	if(-1 == length) {
		long	totallength;
		if(0 > (totallength = (long)k2h_da_get_length(*dahandle))) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_value_to_file: failed to get value length.");
			RETURN_FALSE;
		}
		if(-1 == offset) {
			length = totallength;
		} else {
			if(totallength <= offset) {
				php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_value_to_file: the value is not enough length after offset.");
				RETURN_FALSE;
			} else {
				length = totallength - offset;
			}
		}
	}
	// file
	int	fd;
	if(-1 == (fd = open(filepath, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_value_to_file: failed to create(open & truncate) file.");
		RETURN_FALSE;
	}
	// read
	if(!k2h_da_get_value_to_file(*dahandle, fd, (size_t*)(&length))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_get_value_to_file: failed to read value into file.");
		close(fd);
		RETURN_FALSE;
	}
	close(fd);
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_da_set_value(resource k2hdahandle dahandle, string value[, int offset = -1]) */
PHP_FUNCTION(k2hpx_da_set_value)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	const char * value = NULL;
	size_t value_len = 0;
	zend_long offset = -1;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|l", &dahandle_res, &value, &value_len, &offset) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_value: handle is empty.");
		RETURN_FALSE;
	}
	if(!value || 0 == value_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_value: value is empty.");
		RETURN_FALSE;
	}
	if(0 <= offset) {
		if(!k2h_da_set_write_offset(*dahandle, (off_t)offset)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_value: failed to set writable offset.");
			RETURN_FALSE;
		}
	}
	if(!k2h_da_set_value_str(*dahandle, value)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_value: failed to set value.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_da_set_value_from_file(resource k2hdahandle dahandle, string filepath[, int length = -1[, int offset = -1]]) */
PHP_FUNCTION(k2hpx_da_set_value_from_file)
{
	zval * dahandle_res = NULL;
	k2h_da_h * dahandle;
	const char * filepath = NULL;
	size_t filepath_len = 0;
	zend_long length = -1;
	zend_long offset = -1;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|ll", &dahandle_res, &filepath, &filepath_len, &length, &offset) == FAILURE) {
		return;
	}
	dahandle = (k2h_da_h*) zend_fetch_resource(Z_RES_P(dahandle_res), RESOURCE_K2H_DAHANDLE, le_k2hdahandle);
	if(!dahandle || *dahandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_value_from_file: handle is empty.");
		RETURN_FALSE;
	}
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_da_set_value_from_file: filepath is empty.");
		RETURN_FALSE;
	}
	// offset
	if(0 <= offset) {
		if(!k2h_da_set_read_offset(*dahandle, (off_t)offset)) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_value_from_file: failed to set readable offset.");
			RETURN_FALSE;
		}
	}
	// file
	int			fd;
	struct stat	st;
	if(-1 == (fd = open(filepath, O_RDONLY))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_value_from_file: failed to open file.");
		RETURN_FALSE;
	}
	if(-1 == fstat(fd, &st)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_value_from_file: failed to get stat for file.");
		close(fd);
		RETURN_FALSE;
	}
	// length
	if(-1 == length) {
		length = (long)st.st_size;
	} else {
		if((long)st.st_size < length) {
			php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_value_from_file: the file is short to length.");
			close(fd);
			RETURN_FALSE;
		}
	}
	// set
	if(!k2h_da_set_value_from_file(*dahandle, fd, (size_t*)(&length))) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_da_set_value_from_file: failed to set value from file.");
		close(fd);
		RETURN_FALSE;
	}
	close(fd);
	RETURN_TRUE;
}
/* }}} */

/* {{{ resource k2hqhandle k2hpx_q_handle(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]]) */
PHP_FUNCTION(k2hpx_q_handle)
{
	k2h_q_h * return_res;
	zval * handle_res = NULL;
	k2h_h * handle;
	zend_bool is_fifo = true;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|bs", &handle_res, &is_fifo, &prefix, &prefix_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_handle: handle is empty.");
		RETURN_FALSE;
	}
	k2h_q_h	qhandle;
	if(!prefix || 0 == prefix_len) {
		qhandle = k2h_q_handle(*handle, is_fifo);
	} else {
		qhandle = k2h_q_handle_str_prefix(*handle, is_fifo, prefix);
	}
	if(K2H_INVALID_HANDLE == qhandle) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_q_handle: failed to get handle for queue.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long));
	(*return_res) = qhandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hqhandle));
}
/* }}} */

/* {{{ bool k2hpx_q_free(resource k2hqhandle qhandle) */

PHP_FUNCTION(k2hpx_q_free)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &qhandle_res) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	if(!qhandle || *qhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_free: qhandle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_free(*qhandle)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_q_free: failed to free queue handle.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_q_empty(resource k2hqhandle qhandle) */
PHP_FUNCTION(k2hpx_q_empty)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &qhandle_res) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	if(!qhandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_empty: qhandle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_empty(*qhandle)) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ int k2hpx_q_count(resource k2hqhandle qhandle) */
PHP_FUNCTION(k2hpx_q_count)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &qhandle_res) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	if(!qhandle || *qhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_count: qhandle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	int	count = k2h_q_count(*qhandle);
	RETURN_LONG((long)count);
}
/* }}} */

/* {{{ string k2hpx_q_read(resource k2hqhandle qhandle[, int pos = 0[, string pass=NULL]]) */
PHP_FUNCTION(k2hpx_q_read)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	zend_long pos = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|ls", &qhandle_res, &pos, &pass, &pass_len) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	if(!qhandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_read: qhandle is empty.");
		RETURN_FALSE;
	}
	// check parameter
	if(pos < -1) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_q_read: pos must be -1, 0, 1...");
		RETURN_FALSE;
	}
	char*	pdata = NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_str_read_wp(*qhandle, &pdata, (int)pos, pass)) {
		//php_error_docref(NULL, E_NOTICE, "k2hpx_q_read: failed to read data from queue.");
		RETURN_FALSE;
	}
	RETVAL_STRING(pdata);
	free(pdata);
}
/* }}} */

/* {{{ bool k2hpx_q_push(resource k2hqhandle qhandle, string datavalue[, string pass=NULL[, int expire=0]]) */
PHP_FUNCTION(k2hpx_q_push)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	const char * datavalue = NULL;
	size_t datavalue_len = 0;
	const char * pass = NULL;
	zend_long pass_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rs|sl", &qhandle_res, &datavalue, &datavalue_len, &pass, &pass_len, &expire) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	if(!qhandle || *qhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_push: qhandle is empty.");
		RETURN_FALSE;
	}
	if(!datavalue || 0 == datavalue_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_push: datavalue is empty.");
		RETURN_FALSE;
	}
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_str_push_wa(*qhandle, datavalue, NULL, 0, pass, ptmexpire)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_q_push: failed to push datavalue into queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{string k2hpx_q_pop(resource k2hqhandle qhandle[, string pass=NULL]) */
PHP_FUNCTION(k2hpx_q_pop)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|s", &qhandle_res, &pass, &pass_len) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	if(!qhandle || *qhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_pop: qhandle is empty.");
		RETURN_FALSE;
	}
	char*	pdata = NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_str_pop_wa(*qhandle, &pdata, NULL, NULL, pass)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_q_pop: failed to pop data from queue.");
		RETURN_FALSE;
	}
	RETVAL_STRING(pdata);
	free(pdata);
}
/* }}} */

/* {{{ bool k2hpx_q_remove(resource k2hqhandle qhandle, int count[, string pass=NULL]) */
PHP_FUNCTION(k2hpx_q_remove)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	zend_long count = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rl|s", &qhandle_res, &count, &pass, &pass_len) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	if(!qhandle || *qhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_remove: qhandle is empty.");
		RETURN_FALSE;
	}
	if(0 >= count) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_remove: count must be over 0.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_remove_wp(*qhandle, (int)count, pass)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_q_remove: failed to remove count data from queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_q_dump(resource k2hqhandle qhandle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_q_dump)
{
	zval * qhandle_res = NULL;
	k2h_q_h * qhandle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &qhandle_res, &output) == FAILURE) {
		return;
	}
	qhandle = (k2h_q_h*) zend_fetch_resource(Z_RES_P(qhandle_res), RESOURCE_K2H_QHANDLE, le_k2hqhandle);
	php_stream_from_zval(res_output, output);
	if(!qhandle || *qhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_q_dump: qhandle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_q_dump: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_dump(*qhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_q_dump: failed to dump queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ resource k2hkeyqhandle k2hpx_keyq_handle(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]]) */
PHP_FUNCTION(k2hpx_keyq_handle)
{
	k2h_keyq_h * return_res;
	zval * handle_res = NULL;
	k2h_h * handle;
	zend_bool is_fifo = true;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|bs", &handle_res, &is_fifo, &prefix, &prefix_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_handle: handle is empty.");
		RETURN_FALSE;
	}
	k2h_keyq_h	keyqhandle;
	if(!prefix || 0 == prefix_len) {
		keyqhandle = k2h_keyq_handle(*handle, is_fifo);
	} else {
		keyqhandle = k2h_keyq_handle_str_prefix(*handle, is_fifo, prefix);
	}
	if(K2H_INVALID_HANDLE == keyqhandle) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_handle: failed to get handle for key queue.");
		RETURN_FALSE;
	}
	return_res = emalloc(sizeof(long));
	(*return_res) = keyqhandle;
	RETURN_RES(zend_register_resource(return_res, le_k2hkeyqhandle));
}
/* }}} */

/* {{{ proto bool k2hpx_keyq_free(resource k2hkeyqhandle keyqhandle) */
PHP_FUNCTION(k2hpx_keyq_free)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &keyqhandle_res) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	if(!keyqhandle || *keyqhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_free: keyqhandle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_free(*keyqhandle)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_free: failed to free key queue handle.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_keyq_empty(resource k2hkeyqhandle keyqhandle) */
PHP_FUNCTION(k2hpx_keyq_empty)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &keyqhandle_res) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	if(!keyqhandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_empty: keyqhandle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_empty(*keyqhandle)) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ int k2hpx_keyq_count(resource k2hkeyqhandle keyqhandle) */
PHP_FUNCTION(k2hpx_keyq_count)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r", &keyqhandle_res) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	if(!keyqhandle || *keyqhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_count: keyqhandle is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	int	count = k2h_keyq_count(*keyqhandle);
	RETURN_LONG((long)count);
}
/* }}} */

/* {{{ proto array k2hpx_keyq_read(resource k2hkeyqhandle keyqhandle[, int pos = 0[, string pass=NULL]])*/
PHP_FUNCTION(k2hpx_keyq_read)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	zend_long pos = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|ls", &keyqhandle_res, &pos, &pass, &pass_len) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	if(!keyqhandle) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_read: keyqhandle is empty.");
		RETURN_FALSE;
	}
	// check parameter
	if(pos < -1) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_read: pos must be -1, 0, 1...");
		RETURN_FALSE;
	}
	char*	pkey	= NULL;
	char*	pvalue	= NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_str_read_keyval_wp(*keyqhandle, &pkey, &pvalue, (int)pos, pass)) {
		//php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_read: failed to get key and value from key queue.");
		RETURN_FALSE;
	}
	array_init(return_value);
	if(pkey) {
		add_next_index_string(return_value, pkey);
		free(pkey);
	} else {
		add_next_index_string(return_value, "");
	}
	if(pvalue) {
		add_next_index_string(return_value, pvalue);
		free(pvalue);
	} else {
		add_next_index_string(return_value, "");
	}
}
/* }}} */

/* {{{ bool k2hpx_keyq_push(resource k2hkeyqhandle keyqhandle, string key, string value[, string pass=NULL[, int expire=0]]) */
PHP_FUNCTION(k2hpx_keyq_push)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	const char * key = NULL;
	size_t key_len = 0;
	const char * value = NULL;
	size_t value_len = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rss|sl", &keyqhandle_res, &key, &key_len, &value, &value_len, &pass, &pass_len, &expire) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	if(!keyqhandle || *keyqhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_push: keyqhandle is empty.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_push: key is empty.");
		RETURN_FALSE;
	}
	if(!value || 0 == value_len) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_push: value is empty.");
		RETURN_FALSE;
	}
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_str_push_keyval_wa(*keyqhandle, key, value, pass, ptmexpire)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_push: failed to push key and value into key queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto array k2hpx_keyq_pop(resource k2hkeyqhandle keyqhandle[, string pass=NULL]) */
PHP_FUNCTION(k2hpx_keyq_pop)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|s", &keyqhandle_res, &pass, &pass_len) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	array_init(return_value);
	if(!keyqhandle || *keyqhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_pop: keyqhandle is empty.");
		RETURN_FALSE;
	}
	char*	pkey	= NULL;
	char*	pvalue	= NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_str_pop_keyval_wp(*keyqhandle, &pkey, &pvalue, pass)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_pop: failed to pop key and value from queue.");
		RETURN_FALSE;
	}
	if(pkey) {
		add_next_index_string(return_value, pkey);
		free(pkey);
	} else {
		add_next_index_string(return_value, "");
	}
	if(pvalue) {
		add_next_index_string(return_value, pvalue);
		free(pvalue);
	} else {
		add_next_index_string(return_value, "");
	}
}
/* }}} */

/* {{{ bool k2hpx_keyq_remove(resource k2hkeyqhandle keyqhandle, int count[, string pass=NULL]) */
PHP_FUNCTION(k2hpx_keyq_remove)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	zend_long count = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "rl|s", &keyqhandle_res, &count, &pass, &pass_len) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	if(!keyqhandle || *keyqhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_remove: keyqhandle is empty.");
		RETURN_FALSE;
	}
	if(0 >= count) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_remove: count must be over 0.");
		RETURN_FALSE;
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_remove_wp(*keyqhandle, (int)count, pass)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_remove: failed to remove count data from queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_keyq_dump(resource k2hkeyqhandle keyqhandle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_keyq_dump)
{
	zval * keyqhandle_res = NULL;
	k2h_keyq_h * keyqhandle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &keyqhandle_res, &output) == FAILURE) {
		return;
	}
	keyqhandle = (k2h_keyq_h*) zend_fetch_resource(Z_RES_P(keyqhandle_res), RESOURCE_K2H_KEYQHANDLE, le_k2hkeyqhandle);
	php_stream_from_zval(res_output, output);
	if(!keyqhandle || *keyqhandle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_keyq_dump: keyqhandle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_keyq_dump: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_dump(*keyqhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_keyq_dump: failed to dump key queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_dump_head(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_dump_head)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_dump_head: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_dump_head: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_head(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_dump_head: failed to dump head.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_dump_keytable(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_dump_keytable)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_dump_keytable: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_dump_keytable: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_keytable(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_dump_keytable: failed to dump keytable.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_dump_full_keytable(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_dump_full_keytable)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_dump_full_keytable: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_dump_full_keytable: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_full_keytable(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_dump_full_keytable: failed to dump full keytable.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_dump_elementtable(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_dump_elementtable)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_dump_elementtable: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_dump_elementtable: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_elementtable(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_dump_elementtable: failed to dump element table.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool k2hpx_dump_full(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_dump_full)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_dump_full: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_dump_full: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_dump_full(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_dump_full: failed to dump full.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_print_state(resource k2hhandle handle[, stream output = NULL]) */
PHP_FUNCTION(k2hpx_print_state)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|r", &handle_res, &output) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	php_stream_from_zval(res_output, output);
	if(!handle || *handle == K2H_INVALID_HANDLE) {
		php_error_docref(NULL, E_ERROR, "k2hpx_print_state: handle is empty.");
		RETURN_FALSE;
	}
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "k2hpx_print_state: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_print_state(*handle, fp)) {
		php_error_docref(NULL, E_NOTICE, "k2hpx_print_state: failed to dump full.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ bool k2hpx_print_version([stream output = NULL]) */
PHP_FUNCTION(k2hpx_print_version)
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
			php_error_docref(NULL, E_ERROR, "k2hpx_print_version: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	k2h_print_version(fp);
	RETURN_TRUE;
}
/* }}} */

// cppcheck-suppress unknownMacro
ZEND_DECLARE_MODULE_GLOBALS(k2hash)

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
STD_PHP_INI_ENTRY("k2hash.k2hpx_debug", "silent", PHP_INI_ALL, OnUpdateString, k2hpx_debug, zend_k2hash_globals, k2hash_globals)
PHP_INI_END()
/* }}} */

/* {{{ php_k2hash_init_globals
 */
static void php_k2hash_init_globals(zend_k2hash_globals *k2hash_globals)
{
	k2hash_globals->k2hpx_debug = NULL;
}
/* }}} php_k2hash_init_globals */

/* {{{ PHP_MINIT_FUNCTION
 */
static PHP_MINIT_FUNCTION(k2hash)
{
	ZEND_INIT_MODULE_GLOBALS(k2hash, php_k2hash_init_globals, php_k2hash_shutdown_globals)
	REGISTER_INI_ENTRIES();
	REGISTER_LONG_CONSTANT("K2H_DA_READ", K2H_DA_READ, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_DA_WRITE", K2H_DA_WRITE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_DA_RW", K2H_DA_RW, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_DEF_MASK_BIT", K2H_VAL_MASK_BIT, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_DEF_CMASK_BIT", K2H_VAL_CMASK_BIT, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_DEF_ELEMENT", K2H_VAL_ELEMENT, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_DEF_PAGESIZE", K2H_VAL_PAGESIZE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_ATTR_DEFAULT", K2H_VAL_ATTR_DEFAULT, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_ATTR_DISABLE", K2H_VAL_ATTR_DISABLE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("K2H_ATTR_ENABLE", K2H_VAL_ATTR_ENABLE , CONST_PERSISTENT | CONST_CS);
	le_k2hhandle = zend_register_list_destructors_ex(k2hhandle_dtor, NULL, RESOURCE_K2H_HANDLE, module_number);
	le_k2hfindhandle = zend_register_list_destructors_ex(k2hfindhandle_dtor, NULL, RESOURCE_K2H_FINDHANDLE, module_number);
	le_k2hdahandle = zend_register_list_destructors_ex(k2hdahandle_dtor, NULL, RESOURCE_K2H_DAHANDLE, module_number);
	le_k2hqhandle = zend_register_list_destructors_ex(k2hqhandle_dtor, NULL, RESOURCE_K2H_QHANDLE, module_number);
	le_k2hkeyqhandle = zend_register_list_destructors_ex(k2hkeyqhandle_dtor, NULL, RESOURCE_K2H_KEYQHANDLE, module_number);
	class_init_k2hiterator();
	class_init_k2hqueue();
	class_init_k2hkeyqueue();
	class_init_k2hash();
	char*	dbgmode = K2HASH_G(k2hpx_debug);
	if(!dbgmode || 0 == strcmp(dbgmode, "silent")) {
		k2h_set_debug_level_silent();
	} else if(0 == strcmp(dbgmode, "message")) {
		k2h_set_debug_level_message();
	} else if(0 == strcmp(dbgmode, "warning")) {
		k2h_set_debug_level_warning();
	} else if(0 == strcmp(dbgmode, "error")) {
		k2h_set_debug_level_error();
	} else {
		k2h_set_debug_level_silent();
	}
	// for stream
	if (php_register_url_stream_wrapper(K2HDA_STREAM_WRAPPER, &php_stream_k2h_wrapper) == FAILURE) {
		return FAILURE;
	}
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(k2hash)
{
	UNREGISTER_INI_ENTRIES();
	// for stream
	if (php_unregister_url_stream_wrapper(K2HDA_STREAM_WRAPPER) == FAILURE) {
		return FAILURE;
	}
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(k2hash)
{
#if defined(ZTS) && defined(COMPILE_DL_K2HASH)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(k2hash)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "k2hash support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ k2hash_module_entry */
zend_module_entry k2hash_module_entry = {
	STANDARD_MODULE_HEADER,
	"k2hash",					/* Extension name */
	ext_functions,				/* zend_function_entry */
	PHP_MINIT(k2hash),
	PHP_MSHUTDOWN(k2hash),
	PHP_RINIT(k2hash),			/* PHP_RINIT - Request initialization */
	NULL,						/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(k2hash),			/* PHP_MINFO - Module info */
	PHP_K2HASH_VERSION,			/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_K2HASH
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(k2hash)
#endif

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
