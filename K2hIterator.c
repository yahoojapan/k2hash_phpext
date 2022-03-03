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
zend_class_entry * php_k2hiterator_ce = NULL;
static zend_object_handlers k2hiterator_object_handlers;

/* {{{ Class K2hIterator */

/* {{{ proto void __construct(resource k2hhandle handle[, string key = NULL])
  K2hIterator::__construct method */
PHP_METHOD(K2hIterator, __construct)
{
	zval * handle_res = NULL;
	k2h_h * handle;
	const char * key = NULL;
	size_t key_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "r|s", &handle_res, &key, &key_len) == FAILURE) {
		return;
	}
	handle = (k2h_h*) zend_fetch_resource(Z_RES_P(handle_res), RESOURCE_K2H_HANDLE, le_k2hhandle);
	if(!handle) {
		php_error_docref(NULL, E_ERROR, "K2hIterator::__construct: handle is empty.");
		RETURN_FALSE;
	}
	// open findhandle
	php_k2hiterator_object* intern = Z_K2HITERATOR_OBJECT_P(getThis());
	k2h_find_h* res_findhandle = intern->handle;
	if (res_findhandle == NULL) {
		php_error_docref(NULL, E_NOTICE, "K2hiterator::__construct: custom object initialize error.");
		RETURN_FALSE;
	}
	if(!key || 0 == key_len) {
		*res_findhandle = k2h_find_first(*handle);
	} else {
		*res_findhandle = k2h_find_first_str_subkey(*handle, key);
	}
	RETURN_TRUE;
}
/* }}} __construct */

/* {{{ proto string current()
  K2hIterator::current method */
PHP_METHOD(K2hIterator, current)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	// get value
	php_k2hiterator_object* intern = Z_K2HITERATOR_OBJECT_P(getThis());
	k2h_find_h* res_findhandle = intern->handle;
	if (res_findhandle == NULL) {
		php_error_docref(NULL, E_NOTICE, "K2hiterator::current: custom object initialize error.");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	char*	value = k2h_find_get_direct_value(*res_findhandle);
	if(!value) {
		RETURN_FALSE;
	}
	RETVAL_STRING(value);
	free(value);
}
/* }}} current */

/* {{{ proto string key()
  K2hIterator::key method */
PHP_METHOD(K2hIterator, key)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	php_k2hiterator_object* intern = Z_K2HITERATOR_OBJECT_P(getThis());
	k2h_find_h* res_findhandle = intern->handle;
	if (res_findhandle == NULL) {
		php_error_docref(NULL, E_ERROR, "K2hiterator::current: custom object initialize error.");
		RETURN_FALSE;
	}
	// get key
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	char*	key = k2h_find_get_str_key(*res_findhandle);
	if(!key) {
		php_error_docref(NULL, E_NOTICE, "K2hIterator::current: there is no key.");
		RETURN_FALSE;
	}
	RETVAL_STRING(key);
	free(key);
}
/* }}} key */

/* {{{ proto void next()
  K2hIterator::next method */
PHP_METHOD(K2hIterator, next)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hiterator_object* intern = Z_K2HITERATOR_OBJECT_P(getThis());
	k2h_find_h* res_findhandle = intern->handle;
	if (res_findhandle == NULL) {
		php_error_docref(NULL, E_NOTICE, "K2hiterator::current: custom object initialize error.");
		RETURN_FALSE;
	}
	// set next handle
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*res_findhandle = k2h_find_next(*res_findhandle);
}
/* }}} next */

/* {{{ proto void rewind()
  K2hIterator::rewind method */
PHP_METHOD(K2hIterator, rewind)
{
	//php_error_docref(NULL, E_NOTICE, "K2hIterator::rewind: this method does not support..");
	return;
}
/* }}} rewind */

/* {{{ proto bool valid()
  K2hIterator::valid method */
PHP_METHOD(K2hIterator, valid)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_k2hiterator_object* intern = Z_K2HITERATOR_OBJECT_P(getThis());
	k2h_find_h* res_findhandle = intern->handle;
	if (res_findhandle == NULL) {
		php_error_docref(NULL, E_NOTICE, "K2hiterator::current: custom object initialize error.");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	if(K2H_INVALID_HANDLE == *res_findhandle) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} valid */

/* }}} Methods */

static void php_k2hiterator_object_free(zend_object *object)
{
	// get custom object
	php_k2hiterator_object *intern = get_php_k2hiterator_object(object);
	if (!intern) {
		return;
	}
	if (intern->handle != NULL) {
		// free handle
		if(*intern->handle != K2H_INVALID_HANDLE) {
			k2h_find_free(*intern->handle);
		}
		efree(intern->handle);
	}
	// free zend_object
	zend_object_std_dtor(&intern->std);
}

static zend_object * php_k2hiterator_object_alloc(zend_class_entry *class_type)
{
	// allocate custom object
	php_k2hiterator_object *intern;
	intern = ecalloc(1, sizeof(php_k2hiterator_object) + zend_object_properties_size(class_type));
	intern->handle = emalloc(sizeof(long));
	*intern->handle = K2H_INVALID_HANDLE;

	// initialize zend_object and set handlers
	zend_object_std_init(&intern->std, class_type);
	object_properties_init(&intern->std, class_type);
	intern->std.handlers = &k2hiterator_object_handlers;
	
	// return zend_object pointer
	return &intern->std;
}

void class_init_k2hiterator(void)
{
	zend_class_entry ce;
	
	// 1. initialize zend_object handlers
	memcpy(&k2hiterator_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	k2hiterator_object_handlers.free_obj = php_k2hiterator_object_free;
	k2hiterator_object_handlers.offset = XtOffsetOf(php_k2hiterator_object, std);
	
	// 2. initialize a local class entry variable and set a create object handler to it.
	INIT_CLASS_ENTRY(ce, "K2hIterator", class_K2hIterator_methods);
	ce.create_object = php_k2hiterator_object_alloc; // k2hiterator_object_handlers used in create_object
	
	// The local class entry is registered in zend_register_internal_class.
	// The final class entry is stored in the global class entry
	php_k2hiterator_ce = zend_register_internal_class(&ce);

	// Iterator as a class
	zend_class_entry *tmp;
	zend_string* cname = zend_string_init("iterator", sizeof("iterator")-1, 0);
	tmp = zend_hash_find_ptr(CG(class_table), cname);
	if (tmp != NULL) {
		zend_class_implements(php_k2hiterator_ce, 1, tmp);
	} else {
		php_error_docref(NULL, E_WARNING, "Couldn't find interface 'Iterator' while setting up class 'K2hIterator', skipped");
	}
}
/* }}} Class K2hIterator */

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
