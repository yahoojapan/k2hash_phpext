/*
* K2HASH PHP Extension library
*
* Copyright 2015 Yahoo! JAPAN corporation.
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

extern int le_k2hhandle;
zend_class_entry * php_k2hkeyqueue_ce = NULL;
static zend_object_handlers k2hkeyqueue_object_handlers;

/* {{{ Class K2hKeyQueue */

/* {{{ Methods */

/* {{{ proto void __construct(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]])
  K2hKeyQueue::__construct method */

PHP_METHOD(K2hKeyQueue, __construct)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	zend_bool is_fifo = true;
	const char * prefix = NULL;
	size_t prefix_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|bs", &handle_res, &is_fifo, &prefix, &prefix_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	// open a handle
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	if(!handle) {
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::__construct: handle is empty.");
		*res_k2hkeyqhandle = K2H_INVALID_HANDLE;
	} else {
		// open k2h_keyq_h handle
		if(!prefix || 0 == prefix_len) {
			*res_k2hkeyqhandle = k2h_keyq_handle(*handle, is_fifo);
		} else {
			*res_k2hkeyqhandle = k2h_keyq_handle_str_prefix(*handle, is_fifo, prefix);
		}
	}
	RETURN_TRUE;
}
/* }}} __construct */

/* {{{ proto bool isEmpty()
  K2hKeyQueue::isEmpty method */

PHP_METHOD(K2hKeyQueue, isEmpty)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	if(!res_k2hkeyqhandle || K2H_INVALID_HANDLE == *res_k2hkeyqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// push
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_empty(*res_k2hkeyqhandle)) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} isEmpty */

/* {{{ proto int count()
  K2hKeyQueue::count method */

PHP_METHOD(K2hKeyQueue, count)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	// TODO k2hk2hkeyqhandle or k2hkeyqhandle?
	if(!res_k2hkeyqhandle || K2H_INVALID_HANDLE == *res_k2hkeyqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::count: object is not initialized.");
		RETURN_FALSE;
	}
	// get
	// cppcheck-suppress nullPointerRedundantCheck
	int	count = k2h_keyq_count(*res_k2hkeyqhandle);
	RETURN_LONG((long)count);
}
/* }}} count */

/* {{{ proto array read([int pos = 0[, string pass=NULL]])
  K2hKeyQueue::read method */

PHP_METHOD(K2hKeyQueue, read)
{
	zend_long pos = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|ls", &pos, &pass, &pass_len) == FAILURE) {
		return;
	}
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	// TODO k2hk2hkeyqhandle or k2hkeyqhandle?
	if(!res_k2hkeyqhandle || K2H_INVALID_HANDLE == *res_k2hkeyqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::count: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	if(pos < -1) {
		php_error_docref(NULL, E_NOTICE, "K2hKeyQueue::read: pos must be -1, 0, 1...");
		RETURN_FALSE;
	}
	// get
	char*	pkey	= NULL;
	char*	pvalue	= NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_str_read_keyval_wp(*res_k2hkeyqhandle, &pkey, &pvalue, (int)pos, pass)) {
		//php_error_docref(NULL, E_NOTICE, "K2hKeyQueue::read: failed to read key and value from key queue.");
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
/* }}} read */

/* {{{ proto bool push(string key, string value[, string pass=NULL[, int expire=0]])
  K2hKeyQueue::push method */

PHP_METHOD(K2hKeyQueue, push)
{
	const char * key = NULL;
	size_t key_len = 0;
	const char * value = NULL;
	size_t value_len = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss|sl", &key, &key_len, &value, &value_len, &pass, &pass_len, &expire) == FAILURE) {
		return;
	}
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	// TODO k2hk2hkeyqhandle or k2hkeyqhandle?
	if(!res_k2hkeyqhandle || K2H_INVALID_HANDLE == *res_k2hkeyqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::count: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	if(!key || 0 == key_len) {
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::push: key is empty.");
		RETURN_FALSE;
	}
	if(!value || 0 == value_len) {
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::push: value is empty.");
		RETURN_FALSE;
	}
	// cppcheck-suppress unreadVariable
	time_t	tmexpire	= 0;
	time_t*	ptmexpire	= NULL;
	if(0 < expire) {
		tmexpire	= expire;
		ptmexpire	= &tmexpire;
	}
	// push
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_str_push_keyval_wa(*res_k2hkeyqhandle, key, value, pass, ptmexpire)) {
		php_error_docref(NULL, E_NOTICE, "K2hKeyQueue::push: failed to push key and value into queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} push */

/* {{{ proto array pop([string pass=NULL])
  K2hKeyQueue::pop method */

PHP_METHOD(K2hKeyQueue, pop)
{
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|s", &pass, &pass_len) == FAILURE) {
		return;
	}
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	// TODO k2hk2hkeyqhandle or k2hkeyqhandle?
	if(!res_k2hkeyqhandle || K2H_INVALID_HANDLE == *res_k2hkeyqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::pop: object is not initialized.");
		RETURN_FALSE;
	}
	// pop
	char*	pkey	= NULL;
	char*	pvalue	= NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_str_pop_keyval_wp(*res_k2hkeyqhandle, &pkey, &pvalue, pass)) {
		php_error_docref(NULL, E_NOTICE, "K2hKeyQueue::pop: failed to pop key and value from queue.");
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
/* }}} pop */

/* {{{ proto bool remove(int count[, string pass=NULL])
  K2hKeyQueue::remove method */

PHP_METHOD(K2hKeyQueue, remove)
{
	zend_long count = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "l|s", &count, &pass, &pass_len) == FAILURE) {
		return;
	}
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	if(!res_k2hkeyqhandle || K2H_INVALID_HANDLE == *res_k2hkeyqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::remove: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	if(0 >= count) {
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::remove: count must be over 0.");
		RETURN_FALSE;
	}
	// remove
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_remove_wp(*res_k2hkeyqhandle, (int)count, pass)) {
		php_error_docref(NULL, E_NOTICE, "K2hKeyQueue::remove: failed to remove data from queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} remove */

/* {{{ proto bool dump([stream output = NULL])
  K2hKeyQueue::dump method */

PHP_METHOD(K2hKeyQueue, dump)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hkeyqueue_object* intern = Z_K2HKEYQUEUE_OBJECT_P(getThis());
	k2h_keyq_h* res_k2hkeyqhandle = intern->handle;
	if(!res_k2hkeyqhandle || K2H_INVALID_HANDLE == *res_k2hkeyqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hKeyQueue::remove: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "K2hKeyQueue::dump: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// remove
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_keyq_dump(*res_k2hkeyqhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hKeyQueue::dump: failed to dump queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} dump */

/* }}} Methods */

static void php_k2hkeyqueue_object_free(zend_object *object)
{
	// get custom object
	php_k2hkeyqueue_object *intern = get_php_k2hkeyqueue_object(object);
	if (!intern) {
		return;
	}
	// free handle
	if (intern->handle != NULL) {
		if(*intern->handle != K2H_INVALID_HANDLE) {
			k2h_keyq_free(*intern->handle);
		}
		efree(intern->handle);
	}
	// free zend_object
	zend_object_std_dtor(&intern->std);
}

// takes the class entry pointer and returns a zend_object pointer.
static zend_object * php_k2hkeyqueue_object_alloc(zend_class_entry *class_type)
{
	// The variable name of custom object is conventionally intern.
	php_k2hkeyqueue_object *intern;
	intern = ecalloc(1, sizeof(php_k2hkeyqueue_object) + zend_object_properties_size(class_type));
	intern->handle = emalloc(sizeof(long));
	*intern->handle = K2H_INVALID_HANDLE;

	// 2. initialize std(std is a zend_object).
	zend_object_std_init(&intern->std, class_type);
	// initialize properties for subclass.
	object_properties_init(&intern->std, class_type);
	// initialize handlers
	intern->std.handlers = &k2hkeyqueue_object_handlers;
	
	// return zend_object.
	return &intern->std;
}

void class_init_k2hkeyqueue(void)
{
	zend_class_entry ce;
	// 1. initialize zend_object handlers
	memcpy(&k2hkeyqueue_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	k2hkeyqueue_object_handlers.free_obj = php_k2hkeyqueue_object_free;
	k2hkeyqueue_object_handlers.offset = XtOffsetOf(php_k2hkeyqueue_object, std);

	// 2. initialize a local class entry variable and set a create object handler to it.
	INIT_CLASS_ENTRY(ce, "K2hKeyQueue", class_K2hKeyQueue_methods);
	ce.create_object = php_k2hkeyqueue_object_alloc; // k2hkeyqueue_object_handlers used in create_object
	
	// The local class entry is registered in zend_register_internal_class.
	// The final class entry is stored in the global class entry
	php_k2hkeyqueue_ce = zend_register_internal_class(&ce);
}

/* }}} Class K2hKeyQueue */

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
