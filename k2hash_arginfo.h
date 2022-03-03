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

/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 36f05e897b04c61e0e86de9f1099a79d3f51a895 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_bump_debug_level, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_set_debug_level_silent arginfo_k2hpx_bump_debug_level

#define arginfo_k2hpx_set_debug_level_error arginfo_k2hpx_bump_debug_level

#define arginfo_k2hpx_set_debug_level_warning arginfo_k2hpx_bump_debug_level

#define arginfo_k2hpx_set_debug_level_message arginfo_k2hpx_bump_debug_level

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_set_debug_file, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_unset_debug_file arginfo_k2hpx_bump_debug_level

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_load_debug_env, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_load_hash_library, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, libpath, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_unload_hash_library arginfo_k2hpx_load_debug_env

#define arginfo_k2hpx_load_transaction_library arginfo_k2hpx_load_hash_library

#define arginfo_k2hpx_unload_transaction_library arginfo_k2hpx_load_debug_env

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_create, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskbitcnt, IS_LONG, 0, "8")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cmaskbitcnt, IS_LONG, 0, "4")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxelementcnt, IS_LONG, 0, "32")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pagesize, IS_LONG, 0, "4096")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_open, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, readonly, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, removefile, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fullmap, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskbitcnt, IS_LONG, 0, "8")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cmaskbitcnt, IS_LONG, 0, "4")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxelementcnt, IS_LONG, 0, "32")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pagesize, IS_LONG, 0, "4096")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_open_rw, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fullmap, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskbitcnt, IS_LONG, 0, "8")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cmaskbitcnt, IS_LONG, 0, "4")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxelementcnt, IS_LONG, 0, "32")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pagesize, IS_LONG, 0, "4096")
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_open_ro arginfo_k2hpx_open_rw

#define arginfo_k2hpx_open_tempfile arginfo_k2hpx_open_rw

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_open_mem, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskbitcnt, IS_LONG, 0, "8")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cmaskbitcnt, IS_LONG, 0, "4")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxelementcnt, IS_LONG, 0, "32")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pagesize, IS_LONG, 0, "4096")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_close, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, waitms, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_transaction, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, enable, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, transfile, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, param, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_enable_transaction, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, transfile, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, param, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_disable_transaction, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_get_transaction_thread_pool, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_set_transaction_thread_pool, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_unset_transaction_thread_pool arginfo_k2hpx_load_debug_env

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_put_archive, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, errskip, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_load_archive arginfo_k2hpx_put_archive

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_set_common_attr, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_mtime, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_history, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_encrypt, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, passfile, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_expire, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_clean_common_attr arginfo_k2hpx_disable_transaction

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_add_attr_plugin_library, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, libfile, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_add_attr_crypt_pass, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, encpass, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_default_encrypt, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_print_attr_version, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO_WITH_DEFAULT_VALUE(0, output, "null")
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_print_attr_information arginfo_k2hpx_print_attr_version

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_get_value, 0, 2, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkey, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attrcheck, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_get_subkeys, 0, 2, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attrcheck, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_get_attrs, 0, 2, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_get_attr_value, 0, 3, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, attrkey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_set_value, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkey, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_add_subkey, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_add_subkeys, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkeys, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_add_attr, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, attrkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, attrval, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_remove_all, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_remove, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkey, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_rename, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, newkey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_find_first, 0, 0, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, key, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_find_next, 0, 0, 1)
	ZEND_ARG_INFO(0, findhandle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_find_free, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, findhandle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_find_get_key, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, findhandle_res)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_find_get_value arginfo_k2hpx_find_get_key

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_find_get_subkeys, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, findhandle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_da_get_handle, 0, 0, 3)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_da_get_handle_read, 0, 0, 2)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_da_get_handle_write arginfo_k2hpx_da_get_handle_read

#define arginfo_k2hpx_da_get_handle_rw arginfo_k2hpx_da_get_handle_read

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_da_free, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_da_get_length, 0, 1, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_da_get_offset, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_da_get_read_offset arginfo_k2hpx_da_get_length

#define arginfo_k2hpx_da_get_write_offset arginfo_k2hpx_da_get_length

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_da_set_offset, 0, 2, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, dahandle_res)
	ZEND_ARG_TYPE_INFO(0, offsets, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_da_set_read_offset, 0, 2, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, dahandle_res)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_da_set_write_offset arginfo_k2hpx_da_set_read_offset

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_da_get_value, 0, 1, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, dahandle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_da_get_value_to_file, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, dahandle_res)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_da_set_value, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, dahandle_res)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_da_set_value_from_file arginfo_k2hpx_da_get_value_to_file

ZEND_BEGIN_ARG_INFO_EX(arginfo_k2hpx_q_handle, 0, 0, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_filo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_q_free, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, qhandle_res)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_q_empty arginfo_k2hpx_q_free

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_q_count, 0, 1, MAY_BE_LONG|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, qhandle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_q_read, 0, 1, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, qhandle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pos, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_q_push, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, qhandle_res)
	ZEND_ARG_TYPE_INFO(0, datavalue, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_q_pop, 0, 1, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, qhandle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_q_remove, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, qhandle_res)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_q_dump, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, qhandle_res)
	ZEND_ARG_INFO_WITH_DEFAULT_VALUE(0, output, "null")
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_keyq_handle arginfo_k2hpx_q_handle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_keyq_free, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keyqhandle_res)
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_keyq_empty arginfo_k2hpx_keyq_free

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_keyq_count, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, keyqhandle_res)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_keyq_read, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, keyqhandle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pos, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_keyq_push, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keyqhandle_res)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_k2hpx_keyq_pop, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, keyqhandle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_keyq_remove, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keyqhandle_res)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_keyq_dump, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keyqhandle_res)
	ZEND_ARG_INFO_WITH_DEFAULT_VALUE(0, output, "null")
ZEND_END_ARG_INFO()

#define arginfo_k2hpx_dump_head arginfo_k2hpx_print_attr_version

#define arginfo_k2hpx_dump_keytable arginfo_k2hpx_print_attr_version

#define arginfo_k2hpx_dump_full_keytable arginfo_k2hpx_print_attr_version

#define arginfo_k2hpx_dump_elementtable arginfo_k2hpx_print_attr_version

#define arginfo_k2hpx_dump_full arginfo_k2hpx_print_attr_version

#define arginfo_k2hpx_print_state arginfo_k2hpx_print_attr_version

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_k2hpx_print_version, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO_WITH_DEFAULT_VALUE(0, output, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hash_create arginfo_k2hpx_create

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_open, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, readonly, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, removefile, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fullmap, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskbitcnt, IS_LONG, 0, "8")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cmaskbitcnt, IS_LONG, 0, "4")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxelementcnt, IS_LONG, 0, "32")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pagesize, IS_LONG, 0, "4096")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_openRW, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fullmap, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskbitcnt, IS_LONG, 0, "8")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cmaskbitcnt, IS_LONG, 0, "4")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxelementcnt, IS_LONG, 0, "32")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pagesize, IS_LONG, 0, "4096")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hash_openRO arginfo_class_K2hash_openRW

#define arginfo_class_K2hash_openTempfile arginfo_class_K2hash_openRW

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_openMem, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maskbitcnt, IS_LONG, 0, "8")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cmaskbitcnt, IS_LONG, 0, "4")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxelementcnt, IS_LONG, 0, "32")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pagesize, IS_LONG, 0, "4096")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_close, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, waitms, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_transaction, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, enable, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, transfile, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, param, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_enableTransaction, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, transfile, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, param, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hash_disableTransaction arginfo_k2hpx_load_debug_env

#define arginfo_class_K2hash_getTransactionThreadPool arginfo_k2hpx_get_transaction_thread_pool

#define arginfo_class_K2hash_setTransactionThreadPool arginfo_k2hpx_set_transaction_thread_pool

#define arginfo_class_K2hash_unsetTransactionThreadPool arginfo_k2hpx_load_debug_env

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_putArchive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, errskip, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hash_loadArchive arginfo_class_K2hash_putArchive

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_setCommonAttribute, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_mtime, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_history, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_encrypt, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, passfile, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_expire, IS_LONG, 0, "-1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hash_cleanCommonAttribute arginfo_k2hpx_load_debug_env

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_addAttrPluginLib, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, libfile, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_addAttrCryptPass, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, encpass, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_default_encrypt, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hash_getAttrVersionInfos arginfo_k2hpx_print_version

#define arginfo_class_K2hash_getAttrInfos arginfo_k2hpx_print_version

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hash_getValue, 0, 1, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkey, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attrcheck, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hash_getSubkeys, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attrcheck, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hash_getAttrs, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hash_getAttrValue, 0, 2, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, attrkey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_setValue, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkey, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_addSubkey, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_addSubkeys, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subkeys, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_addAttr, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, attrkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, attrval, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_removeAll, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_remove, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, subkey, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hash_rename, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, newkey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getIterator, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getStream, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getQueue, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_filo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hash_getKeyQueue arginfo_class_K2hash_getQueue

#define arginfo_class_K2hash_dumpHead arginfo_k2hpx_print_version

#define arginfo_class_K2hash_dumpKeytable arginfo_k2hpx_print_version

#define arginfo_class_K2hash_dumpFullKeytable arginfo_k2hpx_print_version

#define arginfo_class_K2hash_dumpElementtable arginfo_k2hpx_print_version

#define arginfo_class_K2hash_dumpFull arginfo_k2hpx_print_version

#define arginfo_class_K2hash_printState arginfo_k2hpx_print_version

#define arginfo_class_K2hash_printVersion arginfo_k2hpx_print_version

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_fifo, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hQueue_isEmpty arginfo_k2hpx_load_debug_env

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hQueue_count, 0, 0, MAY_BE_LONG|MAY_BE_FALSE)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hQueue_read, 0, 0, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pos, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hQueue_push, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, datavalue, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hQueue_pop, 0, 0, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hQueue_remove, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hQueue_dump arginfo_k2hpx_print_version

#define arginfo_class_K2hKeyQueue___construct arginfo_class_K2hQueue___construct

#define arginfo_class_K2hKeyQueue_isEmpty arginfo_k2hpx_load_debug_env

#define arginfo_class_K2hKeyQueue_count arginfo_k2hpx_get_transaction_thread_pool

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hKeyQueue_read, 0, 0, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pos, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_K2hKeyQueue_push, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, expire, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hKeyQueue_pop, 0, 0, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pass, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_K2hKeyQueue_remove arginfo_class_K2hQueue_remove

#define arginfo_class_K2hKeyQueue_dump arginfo_k2hpx_print_version

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hIterator___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, key, IS_STRING, 0, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_K2hIterator_current, 0, 0, MAY_BE_STRING|MAY_BE_FALSE)
ZEND_END_ARG_INFO()

#define arginfo_class_K2hIterator_key arginfo_class_K2hIterator_current

#define arginfo_class_K2hIterator_next arginfo_k2hpx_bump_debug_level

#define arginfo_class_K2hIterator_rewind arginfo_k2hpx_bump_debug_level

#define arginfo_class_K2hIterator_valid arginfo_k2hpx_load_debug_env

ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);
ZEND_FUNCTION(k2hpx_bump_debug_level);
ZEND_FUNCTION(k2hpx_set_debug_level_silent);
ZEND_FUNCTION(k2hpx_set_debug_level_error);
ZEND_FUNCTION(k2hpx_set_debug_level_warning);
ZEND_FUNCTION(k2hpx_set_debug_level_message);
ZEND_FUNCTION(k2hpx_set_debug_file);
ZEND_FUNCTION(k2hpx_unset_debug_file);
ZEND_FUNCTION(k2hpx_load_debug_env);
ZEND_FUNCTION(k2hpx_load_hash_library);
ZEND_FUNCTION(k2hpx_unload_hash_library);
ZEND_FUNCTION(k2hpx_load_transaction_library);
ZEND_FUNCTION(k2hpx_unload_transaction_library);
ZEND_FUNCTION(k2hpx_create);
ZEND_FUNCTION(k2hpx_open);
ZEND_FUNCTION(k2hpx_open_rw);
ZEND_FUNCTION(k2hpx_open_ro);
ZEND_FUNCTION(k2hpx_open_tempfile);
ZEND_FUNCTION(k2hpx_open_mem);
ZEND_FUNCTION(k2hpx_close);
ZEND_FUNCTION(k2hpx_transaction);
ZEND_FUNCTION(k2hpx_enable_transaction);
ZEND_FUNCTION(k2hpx_disable_transaction);
ZEND_FUNCTION(k2hpx_get_transaction_thread_pool);
ZEND_FUNCTION(k2hpx_set_transaction_thread_pool);
ZEND_FUNCTION(k2hpx_unset_transaction_thread_pool);
ZEND_FUNCTION(k2hpx_put_archive);
ZEND_FUNCTION(k2hpx_load_archive);
ZEND_FUNCTION(k2hpx_set_common_attr);
ZEND_FUNCTION(k2hpx_clean_common_attr);
ZEND_FUNCTION(k2hpx_add_attr_plugin_library);
ZEND_FUNCTION(k2hpx_add_attr_crypt_pass);
ZEND_FUNCTION(k2hpx_print_attr_version);
ZEND_FUNCTION(k2hpx_print_attr_information);
ZEND_FUNCTION(k2hpx_get_value);
ZEND_FUNCTION(k2hpx_get_subkeys);
ZEND_FUNCTION(k2hpx_get_attrs);
ZEND_FUNCTION(k2hpx_get_attr_value);
ZEND_FUNCTION(k2hpx_set_value);
ZEND_FUNCTION(k2hpx_add_subkey);
ZEND_FUNCTION(k2hpx_add_subkeys);
ZEND_FUNCTION(k2hpx_add_attr);
ZEND_FUNCTION(k2hpx_remove_all);
ZEND_FUNCTION(k2hpx_remove);
ZEND_FUNCTION(k2hpx_rename);
ZEND_FUNCTION(k2hpx_find_first);
ZEND_FUNCTION(k2hpx_find_next);
ZEND_FUNCTION(k2hpx_find_free);
ZEND_FUNCTION(k2hpx_find_get_key);
ZEND_FUNCTION(k2hpx_find_get_value);
ZEND_FUNCTION(k2hpx_find_get_subkeys);
ZEND_FUNCTION(k2hpx_da_get_handle);
ZEND_FUNCTION(k2hpx_da_get_handle_read);
ZEND_FUNCTION(k2hpx_da_get_handle_write);
ZEND_FUNCTION(k2hpx_da_get_handle_rw);
ZEND_FUNCTION(k2hpx_da_free);
ZEND_FUNCTION(k2hpx_da_get_length);
ZEND_FUNCTION(k2hpx_da_get_offset);
ZEND_FUNCTION(k2hpx_da_get_read_offset);
ZEND_FUNCTION(k2hpx_da_get_write_offset);
ZEND_FUNCTION(k2hpx_da_set_offset);
ZEND_FUNCTION(k2hpx_da_set_read_offset);
ZEND_FUNCTION(k2hpx_da_set_write_offset);
ZEND_FUNCTION(k2hpx_da_get_value);
ZEND_FUNCTION(k2hpx_da_get_value_to_file);
ZEND_FUNCTION(k2hpx_da_set_value);
ZEND_FUNCTION(k2hpx_da_set_value_from_file);
ZEND_FUNCTION(k2hpx_q_handle);
ZEND_FUNCTION(k2hpx_q_free);
ZEND_FUNCTION(k2hpx_q_empty);
ZEND_FUNCTION(k2hpx_q_count);
ZEND_FUNCTION(k2hpx_q_read);
ZEND_FUNCTION(k2hpx_q_push);
ZEND_FUNCTION(k2hpx_q_pop);
ZEND_FUNCTION(k2hpx_q_remove);
ZEND_FUNCTION(k2hpx_q_dump);
ZEND_FUNCTION(k2hpx_keyq_handle);
ZEND_FUNCTION(k2hpx_keyq_free);
ZEND_FUNCTION(k2hpx_keyq_empty);
ZEND_FUNCTION(k2hpx_keyq_count);
ZEND_FUNCTION(k2hpx_keyq_read);
ZEND_FUNCTION(k2hpx_keyq_push);
ZEND_FUNCTION(k2hpx_keyq_pop);
ZEND_FUNCTION(k2hpx_keyq_remove);
ZEND_FUNCTION(k2hpx_keyq_dump);
ZEND_FUNCTION(k2hpx_dump_head);
ZEND_FUNCTION(k2hpx_dump_keytable);
ZEND_FUNCTION(k2hpx_dump_full_keytable);
ZEND_FUNCTION(k2hpx_dump_elementtable);
ZEND_FUNCTION(k2hpx_dump_full);
ZEND_FUNCTION(k2hpx_print_state);
ZEND_FUNCTION(k2hpx_print_version);
ZEND_METHOD(K2hash, create);
ZEND_METHOD(K2hash, open);
ZEND_METHOD(K2hash, openRW);
ZEND_METHOD(K2hash, openRO);
ZEND_METHOD(K2hash, openTempfile);
ZEND_METHOD(K2hash, openMem);
ZEND_METHOD(K2hash, close);
ZEND_METHOD(K2hash, transaction);
ZEND_METHOD(K2hash, enableTransaction);
ZEND_METHOD(K2hash, disableTransaction);
ZEND_METHOD(K2hash, getTransactionThreadPool);
ZEND_METHOD(K2hash, setTransactionThreadPool);
ZEND_METHOD(K2hash, unsetTransactionThreadPool);
ZEND_METHOD(K2hash, putArchive);
ZEND_METHOD(K2hash, loadArchive);
ZEND_METHOD(K2hash, setCommonAttribute);
ZEND_METHOD(K2hash, cleanCommonAttribute);
ZEND_METHOD(K2hash, addAttrPluginLib);
ZEND_METHOD(K2hash, addAttrCryptPass);
ZEND_METHOD(K2hash, getAttrVersionInfos);
ZEND_METHOD(K2hash, getAttrInfos);
ZEND_METHOD(K2hash, getValue);
ZEND_METHOD(K2hash, getSubkeys);
ZEND_METHOD(K2hash, getAttrs);
ZEND_METHOD(K2hash, getAttrValue);
ZEND_METHOD(K2hash, setValue);
ZEND_METHOD(K2hash, addSubkey);
ZEND_METHOD(K2hash, addSubkeys);
ZEND_METHOD(K2hash, addAttr);
ZEND_METHOD(K2hash, removeAll);
ZEND_METHOD(K2hash, remove);
ZEND_METHOD(K2hash, rename);
ZEND_METHOD(K2hash, getIterator);
ZEND_METHOD(K2hash, getStream);
ZEND_METHOD(K2hash, getQueue);
ZEND_METHOD(K2hash, getKeyQueue);
ZEND_METHOD(K2hash, dumpHead);
ZEND_METHOD(K2hash, dumpKeytable);
ZEND_METHOD(K2hash, dumpFullKeytable);
ZEND_METHOD(K2hash, dumpElementtable);
ZEND_METHOD(K2hash, dumpFull);
ZEND_METHOD(K2hash, printState);
ZEND_METHOD(K2hash, printVersion);
ZEND_METHOD(K2hQueue, __construct);
ZEND_METHOD(K2hQueue, isEmpty);
ZEND_METHOD(K2hQueue, count);
ZEND_METHOD(K2hQueue, read);
ZEND_METHOD(K2hQueue, push);
ZEND_METHOD(K2hQueue, pop);
ZEND_METHOD(K2hQueue, remove);
ZEND_METHOD(K2hQueue, dump);
ZEND_METHOD(K2hKeyQueue, __construct);
ZEND_METHOD(K2hKeyQueue, isEmpty);
ZEND_METHOD(K2hKeyQueue, count);
ZEND_METHOD(K2hKeyQueue, read);
ZEND_METHOD(K2hKeyQueue, push);
ZEND_METHOD(K2hKeyQueue, pop);
ZEND_METHOD(K2hKeyQueue, remove);
ZEND_METHOD(K2hKeyQueue, dump);
ZEND_METHOD(K2hIterator, __construct);
ZEND_METHOD(K2hIterator, current);
ZEND_METHOD(K2hIterator, key);
ZEND_METHOD(K2hIterator, next);
ZEND_METHOD(K2hIterator, rewind);
ZEND_METHOD(K2hIterator, valid);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(k2hpx_bump_debug_level, arginfo_k2hpx_bump_debug_level)
	ZEND_FE(k2hpx_set_debug_level_silent, arginfo_k2hpx_set_debug_level_silent)
	ZEND_FE(k2hpx_set_debug_level_error, arginfo_k2hpx_set_debug_level_error)
	ZEND_FE(k2hpx_set_debug_level_warning, arginfo_k2hpx_set_debug_level_warning)
	ZEND_FE(k2hpx_set_debug_level_message, arginfo_k2hpx_set_debug_level_message)
	ZEND_FE(k2hpx_set_debug_file, arginfo_k2hpx_set_debug_file)
	ZEND_FE(k2hpx_unset_debug_file, arginfo_k2hpx_unset_debug_file)
	ZEND_FE(k2hpx_load_debug_env, arginfo_k2hpx_load_debug_env)
	ZEND_FE(k2hpx_load_hash_library, arginfo_k2hpx_load_hash_library)
	ZEND_FE(k2hpx_unload_hash_library, arginfo_k2hpx_unload_hash_library)
	ZEND_FE(k2hpx_load_transaction_library, arginfo_k2hpx_load_transaction_library)
	ZEND_FE(k2hpx_unload_transaction_library, arginfo_k2hpx_unload_transaction_library)
	ZEND_FE(k2hpx_create, arginfo_k2hpx_create)
	ZEND_FE(k2hpx_open, arginfo_k2hpx_open)
	ZEND_FE(k2hpx_open_rw, arginfo_k2hpx_open_rw)
	ZEND_FE(k2hpx_open_ro, arginfo_k2hpx_open_ro)
	ZEND_FE(k2hpx_open_tempfile, arginfo_k2hpx_open_tempfile)
	ZEND_FE(k2hpx_open_mem, arginfo_k2hpx_open_mem)
	ZEND_FE(k2hpx_close, arginfo_k2hpx_close)
	ZEND_FE(k2hpx_transaction, arginfo_k2hpx_transaction)
	ZEND_FE(k2hpx_enable_transaction, arginfo_k2hpx_enable_transaction)
	ZEND_FE(k2hpx_disable_transaction, arginfo_k2hpx_disable_transaction)
	ZEND_FE(k2hpx_get_transaction_thread_pool, arginfo_k2hpx_get_transaction_thread_pool)
	ZEND_FE(k2hpx_set_transaction_thread_pool, arginfo_k2hpx_set_transaction_thread_pool)
	ZEND_FE(k2hpx_unset_transaction_thread_pool, arginfo_k2hpx_unset_transaction_thread_pool)
	ZEND_FE(k2hpx_put_archive, arginfo_k2hpx_put_archive)
	ZEND_FE(k2hpx_load_archive, arginfo_k2hpx_load_archive)
	ZEND_FE(k2hpx_set_common_attr, arginfo_k2hpx_set_common_attr)
	ZEND_FE(k2hpx_clean_common_attr, arginfo_k2hpx_clean_common_attr)
	ZEND_FE(k2hpx_add_attr_plugin_library, arginfo_k2hpx_add_attr_plugin_library)
	ZEND_FE(k2hpx_add_attr_crypt_pass, arginfo_k2hpx_add_attr_crypt_pass)
	ZEND_FE(k2hpx_print_attr_version, arginfo_k2hpx_print_attr_version)
	ZEND_FE(k2hpx_print_attr_information, arginfo_k2hpx_print_attr_information)
	ZEND_FE(k2hpx_get_value, arginfo_k2hpx_get_value)
	ZEND_FE(k2hpx_get_subkeys, arginfo_k2hpx_get_subkeys)
	ZEND_FE(k2hpx_get_attrs, arginfo_k2hpx_get_attrs)
	ZEND_FE(k2hpx_get_attr_value, arginfo_k2hpx_get_attr_value)
	ZEND_FE(k2hpx_set_value, arginfo_k2hpx_set_value)
	ZEND_FE(k2hpx_add_subkey, arginfo_k2hpx_add_subkey)
	ZEND_FE(k2hpx_add_subkeys, arginfo_k2hpx_add_subkeys)
	ZEND_FE(k2hpx_add_attr, arginfo_k2hpx_add_attr)
	ZEND_FE(k2hpx_remove_all, arginfo_k2hpx_remove_all)
	ZEND_FE(k2hpx_remove, arginfo_k2hpx_remove)
	ZEND_FE(k2hpx_rename, arginfo_k2hpx_rename)
	ZEND_FE(k2hpx_find_first, arginfo_k2hpx_find_first)
	ZEND_FE(k2hpx_find_next, arginfo_k2hpx_find_next)
	ZEND_FE(k2hpx_find_free, arginfo_k2hpx_find_free)
	ZEND_FE(k2hpx_find_get_key, arginfo_k2hpx_find_get_key)
	ZEND_FE(k2hpx_find_get_value, arginfo_k2hpx_find_get_value)
	ZEND_FE(k2hpx_find_get_subkeys, arginfo_k2hpx_find_get_subkeys)
	ZEND_FE(k2hpx_da_get_handle, arginfo_k2hpx_da_get_handle)
	ZEND_FE(k2hpx_da_get_handle_read, arginfo_k2hpx_da_get_handle_read)
	ZEND_FE(k2hpx_da_get_handle_write, arginfo_k2hpx_da_get_handle_write)
	ZEND_FE(k2hpx_da_get_handle_rw, arginfo_k2hpx_da_get_handle_rw)
	ZEND_FE(k2hpx_da_free, arginfo_k2hpx_da_free)
	ZEND_FE(k2hpx_da_get_length, arginfo_k2hpx_da_get_length)
	ZEND_FE(k2hpx_da_get_offset, arginfo_k2hpx_da_get_offset)
	ZEND_FE(k2hpx_da_get_read_offset, arginfo_k2hpx_da_get_read_offset)
	ZEND_FE(k2hpx_da_get_write_offset, arginfo_k2hpx_da_get_write_offset)
	ZEND_FE(k2hpx_da_set_offset, arginfo_k2hpx_da_set_offset)
	ZEND_FE(k2hpx_da_set_read_offset, arginfo_k2hpx_da_set_read_offset)
	ZEND_FE(k2hpx_da_set_write_offset, arginfo_k2hpx_da_set_write_offset)
	ZEND_FE(k2hpx_da_get_value, arginfo_k2hpx_da_get_value)
	ZEND_FE(k2hpx_da_get_value_to_file, arginfo_k2hpx_da_get_value_to_file)
	ZEND_FE(k2hpx_da_set_value, arginfo_k2hpx_da_set_value)
	ZEND_FE(k2hpx_da_set_value_from_file, arginfo_k2hpx_da_set_value_from_file)
	ZEND_FE(k2hpx_q_handle, arginfo_k2hpx_q_handle)
	ZEND_FE(k2hpx_q_free, arginfo_k2hpx_q_free)
	ZEND_FE(k2hpx_q_empty, arginfo_k2hpx_q_empty)
	ZEND_FE(k2hpx_q_count, arginfo_k2hpx_q_count)
	ZEND_FE(k2hpx_q_read, arginfo_k2hpx_q_read)
	ZEND_FE(k2hpx_q_push, arginfo_k2hpx_q_push)
	ZEND_FE(k2hpx_q_pop, arginfo_k2hpx_q_pop)
	ZEND_FE(k2hpx_q_remove, arginfo_k2hpx_q_remove)
	ZEND_FE(k2hpx_q_dump, arginfo_k2hpx_q_dump)
	ZEND_FE(k2hpx_keyq_handle, arginfo_k2hpx_keyq_handle)
	ZEND_FE(k2hpx_keyq_free, arginfo_k2hpx_keyq_free)
	ZEND_FE(k2hpx_keyq_empty, arginfo_k2hpx_keyq_empty)
	ZEND_FE(k2hpx_keyq_count, arginfo_k2hpx_keyq_count)
	ZEND_FE(k2hpx_keyq_read, arginfo_k2hpx_keyq_read)
	ZEND_FE(k2hpx_keyq_push, arginfo_k2hpx_keyq_push)
	ZEND_FE(k2hpx_keyq_pop, arginfo_k2hpx_keyq_pop)
	ZEND_FE(k2hpx_keyq_remove, arginfo_k2hpx_keyq_remove)
	ZEND_FE(k2hpx_keyq_dump, arginfo_k2hpx_keyq_dump)
	ZEND_FE(k2hpx_dump_head, arginfo_k2hpx_dump_head)
	ZEND_FE(k2hpx_dump_keytable, arginfo_k2hpx_dump_keytable)
	ZEND_FE(k2hpx_dump_full_keytable, arginfo_k2hpx_dump_full_keytable)
	ZEND_FE(k2hpx_dump_elementtable, arginfo_k2hpx_dump_elementtable)
	ZEND_FE(k2hpx_dump_full, arginfo_k2hpx_dump_full)
	ZEND_FE(k2hpx_print_state, arginfo_k2hpx_print_state)
	ZEND_FE(k2hpx_print_version, arginfo_k2hpx_print_version)
	ZEND_FE_END
};

static const zend_function_entry class_K2hash_methods[] = {
	ZEND_ME(K2hash, create, arginfo_class_K2hash_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(K2hash, open, arginfo_class_K2hash_open, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, openRW, arginfo_class_K2hash_openRW, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, openRO, arginfo_class_K2hash_openRO, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, openTempfile, arginfo_class_K2hash_openTempfile, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, openMem, arginfo_class_K2hash_openMem, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, close, arginfo_class_K2hash_close, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, transaction, arginfo_class_K2hash_transaction, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, enableTransaction, arginfo_class_K2hash_enableTransaction, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, disableTransaction, arginfo_class_K2hash_disableTransaction, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getTransactionThreadPool, arginfo_class_K2hash_getTransactionThreadPool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(K2hash, setTransactionThreadPool, arginfo_class_K2hash_setTransactionThreadPool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(K2hash, unsetTransactionThreadPool, arginfo_class_K2hash_unsetTransactionThreadPool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(K2hash, putArchive, arginfo_class_K2hash_putArchive, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, loadArchive, arginfo_class_K2hash_loadArchive, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, setCommonAttribute, arginfo_class_K2hash_setCommonAttribute, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, cleanCommonAttribute, arginfo_class_K2hash_cleanCommonAttribute, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, addAttrPluginLib, arginfo_class_K2hash_addAttrPluginLib, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, addAttrCryptPass, arginfo_class_K2hash_addAttrCryptPass, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getAttrVersionInfos, arginfo_class_K2hash_getAttrVersionInfos, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getAttrInfos, arginfo_class_K2hash_getAttrInfos, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getValue, arginfo_class_K2hash_getValue, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getSubkeys, arginfo_class_K2hash_getSubkeys, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getAttrs, arginfo_class_K2hash_getAttrs, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getAttrValue, arginfo_class_K2hash_getAttrValue, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, setValue, arginfo_class_K2hash_setValue, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, addSubkey, arginfo_class_K2hash_addSubkey, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, addSubkeys, arginfo_class_K2hash_addSubkeys, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, addAttr, arginfo_class_K2hash_addAttr, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, removeAll, arginfo_class_K2hash_removeAll, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, remove, arginfo_class_K2hash_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, rename, arginfo_class_K2hash_rename, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getIterator, arginfo_class_K2hash_getIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getStream, arginfo_class_K2hash_getStream, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getQueue, arginfo_class_K2hash_getQueue, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, getKeyQueue, arginfo_class_K2hash_getKeyQueue, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, dumpHead, arginfo_class_K2hash_dumpHead, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, dumpKeytable, arginfo_class_K2hash_dumpKeytable, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, dumpFullKeytable, arginfo_class_K2hash_dumpFullKeytable, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, dumpElementtable, arginfo_class_K2hash_dumpElementtable, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, dumpFull, arginfo_class_K2hash_dumpFull, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, printState, arginfo_class_K2hash_printState, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hash, printVersion, arginfo_class_K2hash_printVersion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_K2hQueue_methods[] = {
	ZEND_ME(K2hQueue, __construct, arginfo_class_K2hQueue___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hQueue, isEmpty, arginfo_class_K2hQueue_isEmpty, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hQueue, count, arginfo_class_K2hQueue_count, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hQueue, read, arginfo_class_K2hQueue_read, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hQueue, push, arginfo_class_K2hQueue_push, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hQueue, pop, arginfo_class_K2hQueue_pop, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hQueue, remove, arginfo_class_K2hQueue_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hQueue, dump, arginfo_class_K2hQueue_dump, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_K2hKeyQueue_methods[] = {
	ZEND_ME(K2hKeyQueue, __construct, arginfo_class_K2hKeyQueue___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hKeyQueue, isEmpty, arginfo_class_K2hKeyQueue_isEmpty, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hKeyQueue, count, arginfo_class_K2hKeyQueue_count, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hKeyQueue, read, arginfo_class_K2hKeyQueue_read, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hKeyQueue, push, arginfo_class_K2hKeyQueue_push, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hKeyQueue, pop, arginfo_class_K2hKeyQueue_pop, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hKeyQueue, remove, arginfo_class_K2hKeyQueue_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hKeyQueue, dump, arginfo_class_K2hKeyQueue_dump, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_K2hIterator_methods[] = {
	ZEND_ME(K2hIterator, __construct, arginfo_class_K2hIterator___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hIterator, current, arginfo_class_K2hIterator_current, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hIterator, key, arginfo_class_K2hIterator_key, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hIterator, next, arginfo_class_K2hIterator_next, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hIterator, rewind, arginfo_class_K2hIterator_rewind, ZEND_ACC_PUBLIC)
	ZEND_ME(K2hIterator, valid, arginfo_class_K2hIterator_valid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/

