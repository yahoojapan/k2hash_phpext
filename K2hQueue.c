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
zend_class_entry * php_k2hqueue_ce = NULL;
static zend_object_handlers k2hqueue_object_handlers;

/* {{{ Class K2hQueue */

/* {{{ Methods */

/* {{{ proto void __construct(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]])
  K2hQueue::__construct method */
PHP_METHOD(K2hQueue, __construct)
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
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if (!res_k2hqhandle) {
		php_error_docref(NULL, E_ERROR, "K2hQueue::__construct: custom object init error.");
		RETURN_FALSE;
	}
	if(!handle) {
		php_error_docref(NULL, E_ERROR, "K2hQueue::__construct: handle is empty.");
		*res_k2hqhandle = K2H_INVALID_HANDLE;
	} else {
		// open k2h_q_h handle
		if(!prefix || 0 == prefix_len) {
			*res_k2hqhandle = k2h_q_handle(*handle, is_fifo);
		} else {
			*res_k2hqhandle = k2h_q_handle_str_prefix(*handle, is_fifo, prefix);
		}
	}
	RETURN_TRUE;
}
/* }}} __construct */

/* {{{ proto bool isEmpty()
  K2hQueue::isEmpty method */
PHP_METHOD(K2hQueue, isEmpty)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if(!res_k2hqhandle || K2H_INVALID_HANDLE == *res_k2hqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// check
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_empty(*res_k2hqhandle)) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} isEmpty */

/* {{{ proto int count()
  K2hQueue::count method */
PHP_METHOD(K2hQueue, count)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if(!res_k2hqhandle || K2H_INVALID_HANDLE == *res_k2hqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// get
	// cppcheck-suppress nullPointerRedundantCheck
	int	count = k2h_q_count(*res_k2hqhandle);
	RETURN_LONG((long)count);
}
/* }}} count */

/* {{{ proto string read([int pos = 0[, string pass=NULL]])
  K2hQueue::read method */
PHP_METHOD(K2hQueue, read)
{
	zend_long pos = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|ls", &pos, &pass, &pass_len) == FAILURE) {
		return;
	}
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if(!res_k2hqhandle || K2H_INVALID_HANDLE == *res_k2hqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	if(pos < -1) {
		php_error_docref(NULL, E_NOTICE, "K2hQueue::read: pos must be -1, 0, 1...");
		RETURN_FALSE;
	}
	// get
	char*	pdata = NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_str_read_wp(*res_k2hqhandle, &pdata, (int)pos, pass)) {
		//php_error_docref(NULL, E_NOTICE, "K2hQueue::read: failed to read data from queue.");
		RETURN_FALSE;
	}
	RETVAL_STRING(pdata);
	free(pdata);
}
/* }}} read */

/* {{{ proto bool push(string datavalue[, string pass=NULL[, int expire=0]])
  K2hQueue::push method */
PHP_METHOD(K2hQueue, push)
{
	const char * datavalue = NULL;
	size_t datavalue_len = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	zend_long expire = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|sl", &datavalue, &datavalue_len, &pass, &pass_len, &expire) == FAILURE) {
		return;
	}
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if(!res_k2hqhandle || K2H_INVALID_HANDLE == *res_k2hqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	if(!datavalue || 0 == datavalue_len) {
		php_error_docref(NULL, E_ERROR, "K2hQueue::push: datavalue is empty.");
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
	if(!k2h_q_str_push_wa(*res_k2hqhandle, datavalue, NULL, 0, pass, ptmexpire)) {
		php_error_docref(NULL, E_NOTICE, "K2hQueue::push: failed to push datavalue into queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} push */

/* {{{ proto string pop([string pass=NULL])
  K2hQueue::pop method */
PHP_METHOD(K2hQueue, pop)
{
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|s", &pass, &pass_len) == FAILURE) {
		return;
	}
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if(!res_k2hqhandle || K2H_INVALID_HANDLE == *res_k2hqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// pop
	char*	pdata = NULL;
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_str_pop_wa(*res_k2hqhandle, &pdata, NULL, NULL, pass)) {
		php_error_docref(NULL, E_NOTICE, "K2hQueue::pop: failed to pop data from queue.");
		RETURN_FALSE;
	}
	RETVAL_STRING(pdata);
	free(pdata);
}
/* }}} pop */

/* {{{ proto bool remove(int count[, string pass=NULL])
  K2hQueue::remove method */
PHP_METHOD(K2hQueue, remove)
{
	zend_long count = 0;
	const char * pass = NULL;
	size_t pass_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "l|s", &count, &pass, &pass_len) == FAILURE) {
		return;
	}
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if(!res_k2hqhandle || K2H_INVALID_HANDLE == *res_k2hqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	if(0 >= count) {
		php_error_docref(NULL, E_ERROR, "K2hQueue::remove: count must be over 0.");
		RETURN_FALSE;
	}
	// remove
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_remove_wp(*res_k2hqhandle, count, pass)) {
		php_error_docref(NULL, E_NOTICE, "K2hQueue::remove: failed to remove data from queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} remove */

/* {{{ proto bool dump([stream output = NULL])
  K2hQueue::dump method */
PHP_METHOD(K2hQueue, dump)
{
	zval * output = NULL;
	php_stream * res_output = NULL;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|r", &output) == FAILURE) {
		return;
	}
	php_stream_from_zval(res_output, output);
	php_k2hqueue_object* intern = Z_K2HQUEUE_OBJECT_P(getThis());
	k2h_q_h* res_k2hqhandle = intern->handle;
	if(!res_k2hqhandle || K2H_INVALID_HANDLE == *res_k2hqhandle) {
		// this case is that object is not initialized.
		php_error_docref(NULL, E_ERROR, "K2hQueue::isEmpty: object is not initialized.");
		RETURN_FALSE;
	}
	// check parameter
	FILE*	fp = NULL;
	if(res_output) {
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)) {
			php_error_docref(NULL, E_ERROR, "K2hQueue::dump: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	// remove
	// cppcheck-suppress nullPointerRedundantCheck
	if(!k2h_q_dump(*res_k2hqhandle, fp)) {
		php_error_docref(NULL, E_NOTICE, "K2hQueue::dump: failed to dump queue.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} dump */

/* }}} Methods */

static void php_k2hqueue_object_free(zend_object *object)
{
	// 1. get custom object from zend_object.
	php_k2hqueue_object *intern = get_php_k2hqueue_object(object);
	if (!intern) {
		return;
	}
	// 2. efree handle.
	if (intern->handle != NULL) {
		if(*intern->handle != K2H_INVALID_HANDLE) {
			k2h_keyq_free(*intern->handle);
		}
		efree(intern->handle);
	}
	// 3. dtor zend_object
	zend_object_std_dtor(&intern->std);
}

// create_object handler takes class entry and return zend_object.
static zend_object * php_k2hqueue_object_alloc(zend_class_entry *class_type)
{
	// The variable name of custom object is conventionaly intern.
	php_k2hqueue_object *intern;
	// 1. allocate intern.
	intern = ecalloc(1, sizeof(php_k2hqueue_object) + zend_object_properties_size(class_type));
	intern->handle = emalloc(sizeof(long));
	*intern->handle = K2H_INVALID_HANDLE;
	// 2. zend_object intialize(std).
	zend_object_std_init(&intern->std, class_type);
	// set properties for possible subclasses.
	object_properties_init(&intern->std, class_type);
	// set handlers.
	intern->std.handlers = &k2hqueue_object_handlers;

	// 3. return zend_object pointer.
	return &intern->std;
}

void class_init_k2hqueue(void)
{
	zend_class_entry ce;
	// 1. initialize zend_object handlers
	memcpy(&k2hqueue_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	k2hqueue_object_handlers.free_obj = php_k2hqueue_object_free;
	k2hqueue_object_handlers.offset = XtOffsetOf(php_k2hqueue_object, std);
	
	// 2. initialize a local class entry variable and set a create object handler to it.
	INIT_CLASS_ENTRY(ce, "K2hQueue", class_K2hQueue_methods);
	ce.create_object = php_k2hqueue_object_alloc; // k2hqueue_object_handlers used in create_object
	
	// The local class entry is registered in zend_register_internal_class.
	// The final class entry is stored in the global class entry
	php_k2hqueue_ce = zend_register_internal_class(&ce);
}

/* }}} Class K2hQueue */

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
