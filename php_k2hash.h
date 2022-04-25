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
* AUTHOR:   Hirotaka Wakabayashi
* CREATE:   Tue, Feb 22 2022
* REVISION:
*/

#ifndef PHP_K2HASH_H
#define PHP_K2HASH_H

#include <k2hash.h>
#include <fcntl.h>
#include "config.h"

extern zend_module_entry k2hash_module_entry;

/* {{{ k2hash object */
typedef struct php_k2hash_object_ {
	k2h_h* handle;		// handle tied with the object.
	zend_object std;
} php_k2hash_object;

// inline function to get the object's object
static inline php_k2hash_object * get_php_k2hash_object(zend_object *obj)
{
	return (php_k2hash_object *)(php_k2hash_object *)((char*)(obj) - XtOffsetOf(php_k2hash_object, std));
}

// macros to fetch php_k2hash_object object
#define Z_K2HASH_OBJECT_P(zv) get_php_k2hash_object(Z_OBJ_P((zv)))
/* }}} */

/* {{{ k2hiterator object */
typedef struct php_k2hiterator_object_ {
	k2h_find_h* handle;	// handle tied with the object.
	zend_object std;
} php_k2hiterator_object;

// inline function to get the object's object
static inline php_k2hiterator_object * get_php_k2hiterator_object(zend_object *obj)
{
	return (php_k2hiterator_object *)(php_k2hiterator_object *)((char*)(obj) - XtOffsetOf(php_k2hiterator_object, std));
}

// macros to fetch php_k2hiterator_object object
#define Z_K2HITERATOR_OBJECT_P(zv) get_php_k2hiterator_object(Z_OBJ_P((zv)))
/* }}} */

/* {{{ k2hqueue object */
typedef struct php_k2hqueue_object_ {
	k2h_q_h* handle;	// handle tied with the object.
	zend_object std;
} php_k2hqueue_object;

// inline function to get the object's object
static inline php_k2hqueue_object * get_php_k2hqueue_object(zend_object *obj)
{
	return (php_k2hqueue_object *)(php_k2hqueue_object *)((char*)(obj) - XtOffsetOf(php_k2hqueue_object, std));
}

// macros to fetch php_k2hqueue_object object
#define Z_K2HQUEUE_OBJECT_P(zv) get_php_k2hqueue_object(Z_OBJ_P((zv)))
/* }}} */

/* {{{ k2hkeyqueue object */
typedef struct php_k2hkeyqueue_object_ {
	k2h_keyq_h* handle;	// handle tied with the object.
	zend_object std;
} php_k2hkeyqueue_object;

// inline function to get the object's object
static inline php_k2hkeyqueue_object * get_php_k2hkeyqueue_object(zend_object *obj)
{
	return (php_k2hkeyqueue_object *)(php_k2hkeyqueue_object *)((char*)(obj) - XtOffsetOf(php_k2hkeyqueue_object, std));
}

// macros to fetch php_k2hkeyqueue_object object
#define Z_K2HKEYQUEUE_OBJECT_P(zv) get_php_k2hkeyqueue_object(Z_OBJ_P((zv)))
/* }}} */

/* {{{ symbols for constants */
#define	K2H_VAL_ATTR_DEFAULT			-1
#define	K2H_VAL_ATTR_DISABLE			0
#define	K2H_VAL_ATTR_ENABLE				1

#define K2HASH_UNUSED( var ) var;
#if ZEND_DEBUG
K2HASH_UNUSED( __php_stream_call_depth ); // [NOTE] In rare cases, __php_stream_call_depth was not defined. (No problem now)
K2HASH_UNUSED( __zend_orig_filename );
K2HASH_UNUSED( __zend_filename );
K2HASH_UNUSED( __zend_orig_lineno );
K2HASH_UNUSED( __zend_lineno );
#endif

#define PHP_K2HASH_CLASS_NAME "K2hash"

#define RESOURCE_K2H_HANDLE "k2hhandle"
#define RESOURCE_K2H_FINDHANDLE "k2hfindhandle"
#define RESOURCE_K2H_DAHANDLE "k2hdahandle"
#define RESOURCE_K2H_QHANDLE "k2hqhandle"
#define RESOURCE_K2H_KEYQHANDLE "k2hkeyqhandle"

//------------------------------------------------------------
// PHP_STREAM wrapper functions for k2hash
//------------------------------------------------------------
// opener
//
// [Usage: open file]
// 		$fp = fopen("k2h://<file path>#key", "r");
//
//		$opt	= array('k2h' => array('k2hhandle' => resource k2hhandle) );
//		$context= stream_context_create($opt);
//		$fp		= fopen("k2h://<file path>#key", "r", false, $context);
//
//		$opt	= array('k2h' => array('fullmap' => no) );
//		$context= stream_context_create($opt);
//		$fp		= fopen("k2h://<file path>#key", "r", false, $context);
//
// [Context]
//	'k2hhandle'		=> resource k2hhahdle	: specify alreay opened handle. if there is not, open(attach) file
//	'fullmap'		=> bool					: full mapping or not when open file.(default true)
//	'maskbitcnt'	=> int					: maskbit count when create file.(default K2H_DEF_MASK_BIT)
//	'cmaskbitcnt'	=> int					: cmaskbit count when create file.(default K2H_DEF_CMASK_BIT)
//	'maxelementcnt'	=> int					: maximum element count when create file.(default K2H_DEF_ELEMENT)
//	'pagesize'		=> int					: pagesize when create file.(default K2H_DEF_PAGESIZE)
//
#define	K2HDA_STREAM_URL_PREFIX				"k2h://"
#define	K2HDA_STREAM_URL_PREFIX_LENGTH		strlen(K2HDA_STREAM_URL_PREFIX)
#define	K2HDA_STREAM_CTX_NAME				"k2h"
#define	K2HDA_STREAM_CTX_HANDLE				"k2hhandle"
#define	K2HDA_STREAM_CTX_FULLMAP			"fullmap"
#define	K2HDA_STREAM_CTX_MBITCNT			"maskbitcnt"
#define	K2HDA_STREAM_CTX_CMBITCNT			"cmaskbitcnt"
#define	K2HDA_STREAM_CTX_MECNT				"maxelementcnt"
#define	K2HDA_STREAM_CTX_PSIZE				"pagesize"
#define	K2HDA_STREAMTYPE					"k2hda"
#define	K2HDA_STREAM_WRAPPER				"k2h"

/* }}} symbols for constants */

/* {{{ k2hash symbles from cpp */
#define	K2H_VAL_MASK_BIT					8
#define	K2H_VAL_CMASK_BIT					4
#define	K2H_VAL_ELEMENT						32
#define	K2H_VAL_PAGESIZE					4096
/* }}} k2hash symbles from cpp */

// class initializers
void class_init_k2hiterator(void);
void class_init_k2hqueue(void);
void class_init_k2hkeyqueue(void);
void class_init_k2hash(void);

#define K2HASH_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(k2hash, v)

ZEND_BEGIN_MODULE_GLOBALS(k2hash)
char *k2hpx_debug;
// cppcheck-suppress unknownMacro
ZEND_END_MODULE_GLOBALS(k2hash)

# if defined(ZTS) && defined(COMPILE_DL_K2HASH)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_K2HASH_H */

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
