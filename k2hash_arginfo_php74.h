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

/* {{{ proto void k2hpx_bump_debug_level()
  Bump up debugging level */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_bump_debug_level_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_bump_debug_level */

/* {{{ proto void k2hpx_set_debug_level_silent()
  Set debugging level silent */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_debug_level_silent_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_debug_level_silent */

/* {{{ proto void k2hpx_set_debug_level_error()
  Set debugging level error */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_debug_level_error_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_debug_level_error */

/* {{{ proto void k2hpx_set_debug_level_warning()
  Set debugging level warning */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_debug_level_warning_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_debug_level_warning */

/* {{{ proto void k2hpx_set_debug_level_message()
  Set debugging level message */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_debug_level_message_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_debug_level_message */

/* {{{ proto bool k2hpx_set_debug_file(string filepath)
  Set debugging message file path */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_debug_file_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_debug_file */

/* {{{ proto bool k2hpx_unset_debug_file()
  Unset debugging message file path */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_unset_debug_file_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_unset_debug_file */

/* {{{ proto bool k2hpx_load_debug_env()
  Load environment for k2hash debugging */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_load_debug_env_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_load_debug_env */

/* {{{ proto bool k2hpx_load_hash_library(string libpath)
  Load external hashing function */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_load_hash_library_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, libpath)
ZEND_END_ARG_INFO()
/* }}} k2hpx_load_hash_library */

/* {{{ proto bool k2hpx_unload_hash_library()
  Unload external hashing function */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_unload_hash_library_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_unload_hash_library */

/* {{{ proto bool k2hpx_load_transaction_library(string libpath)
  Load external transaction function */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_load_transaction_library_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, libpath)
ZEND_END_ARG_INFO()
/* }}} k2hpx_load_transaction_library */

/* {{{ proto bool k2hpx_unload_transaction_library()
  Unload external transaction function */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_unload_transaction_library_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_unload_transaction_library */

/* {{{ proto bool k2hpx_create(string filepath[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]])
  create k2hash file */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_create_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()
/* }}} k2hpx_create */

/* {{{ proto resource k2hhandle k2hpx_open(string filepath, bool readonly[, bool removefile = false[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]]])
  open k2hash file */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_open_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, readonly)
ZEND_ARG_INFO(0, removefile)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()
/* }}} k2hpx_open */

/* {{{ proto resource k2hhandle k2hpx_open_rw(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  open k2hash file with read/write mode */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_open_rw_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()
/* }}} k2hpx_open_rw */

/* {{{ proto resource k2hhandle k2hpx_open_ro(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  open k2hash file with read only mode */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_open_ro_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()
/* }}} k2hpx_open_ro */

/* {{{ proto resource k2hhandle k2hpx_open_tempfile(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  open k2hash temporary file */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_open_tempfile_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()
/* }}} k2hpx_open_tempfile */

/* {{{ proto resource k2hhandle k2hpx_open_mem([int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]])
  open k2hash on memory */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_open_mem_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()
/* }}} k2hpx_open_mem */

/* {{{ proto bool k2hpx_close(resource k2hhandle handle[, int waitms = 0])
  close k2hash file or memory */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_close_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, waitms)
ZEND_END_ARG_INFO()
/* }}} k2hpx_close */

/* {{{ proto bool k2hpx_transaction(resource k2hhandle handle, bool enable[, string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]])
  Set transaction file and prefix with dis/enable */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_transaction_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, enable)
ZEND_ARG_INFO(0, transfile)
ZEND_ARG_INFO(0, prefix)
ZEND_ARG_INFO(0, param)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()
/* }}} k2hpx_transaction */

/* {{{ proto bool k2hpx_enable_transaction(resource k2hhandle handle[, string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]])
  Set transaction file and prefix with enable */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_enable_transaction_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, transfile)
ZEND_ARG_INFO(0, prefix)
ZEND_ARG_INFO(0, param)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()
/* }}} k2hpx_enable_transaction */

/* {{{ proto bool k2hpx_disable_transaction(resource k2hhandle handle)
  Disable transaction */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_disable_transaction_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_END_ARG_INFO()
/* }}} k2hpx_disable_transaction */

/* {{{ proto int k2hpx_get_transaction_thread_pool()
  Get transaction thread pool count */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_get_transaction_thread_pool_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_get_transaction_thread_pool */

/* {{{ proto bool k2h_set_transaction_thread_pool(int count)
  Set transaction thread pool count */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_transaction_thread_pool_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_transaction_thread_pool */

/* {{{ proto bool k2h_unset_transaction_thread_pool()
  Unset transaction thread pool(no pool) */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_unset_transaction_thread_pool_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
/* }}} k2hpx_unset_transaction_thread_pool */

/* {{{ proto bool k2hpx_put_archive(resource k2hhandle handle, string filepath, bool errskip)
  Output archive file */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_put_archive_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, errskip)
ZEND_END_ARG_INFO()
/* }}} k2hpx_put_archive */

/* {{{ proto bool k2hpx_load_archive(resource k2hhandle handle, string filepath, bool errskip)
  Load archive file */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_load_archive_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, errskip)
ZEND_END_ARG_INFO()
/* }}} k2hpx_load_archive */

/* {{{ proto bool k2hpx_set_common_attr(resource k2hhandle handle[, int is_mtime = K2H_ATTR_DEFAULT[, int is_history = K2H_ATTR_DEFAULT[, int is_encrypt = K2H_ATTR_DEFAULT, string passfile = NULL[, int is_expire = K2H_ATTR_DEFAULT, int expire = 0]]]])
  Set common attributes */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_common_attr_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, is_mtime)
ZEND_ARG_INFO(0, is_history)
ZEND_ARG_INFO(0, is_encrypt)
ZEND_ARG_INFO(0, passfile)
ZEND_ARG_INFO(0, is_expire)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_common_attr */

/* {{{ proto bool k2hpx_clean_common_attr(resource k2hhandle handle)
  Clear common attributes setting */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_clean_common_attr_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_END_ARG_INFO()
/* }}} k2hpx_clean_common_attr */

/* {{{ proto bool k2hpx_add_attr_plugin_library(resource k2hhandle handle, string libfile)
  Add plugin attribute module */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_add_attr_plugin_library_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, libfile)
ZEND_END_ARG_INFO()
/* }}} k2hpx_add_attr_plugin_library */

/* {{{ proto bool k2hpx_add_attr_crypt_pass(resource k2hhandle handle, string encpass[, bool is_default_encrypt = false])
  Add encrypt pass phrase */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_add_attr_crypt_pass_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, encpass)
ZEND_ARG_INFO(0, is_default_encrypt)
ZEND_END_ARG_INFO()
/* }}} k2hpx_add_attr_crypt_pass */

/* {{{ proto bool k2hpx_print_attr_version(resource k2hhandle handle[, stream output = NULL])
  Print all attributes version */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_print_attr_version_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_print_attr_version */

/* {{{ proto bool k2hpx_print_attr_information(resource k2hhandle handle[, stream output = NULL])
  Print attributes information */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_print_attr_information_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_print_attr_information */

/* {{{ proto string k2hpx_get_value(resource k2hhandle handle, string key[, string subkey = NULL[, bool attrcheck = true[, string pass = NULL]]])
  Get value */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_get_value_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, subkey)
ZEND_ARG_INFO(0, attrcheck)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()
/* }}} k2hpx_get_value */

/* {{{ proto array k2hpx_get_subkeys(resource k2hhandle handle, string key[, bool attrcheck = true])
  Get subkeys */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_get_subkeys_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, attrcheck)
ZEND_END_ARG_INFO()
/* }}} k2hpx_get_subkeys */

/* {{{ proto array k2hpx_get_attrs(resource k2hhandle handle, string key)
  Get attribute key names */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_get_attrs_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()
/* }}} k2hpx_get_attrs */

/* {{{ proto string k2hpx_get_attr_value(resource k2hhandle handle, string key, string attrkey)
  Get attribute value */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_get_attr_value_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, attrkey)
ZEND_END_ARG_INFO()
/* }}} k2hpx_get_attr_value */

/* {{{ proto bool k2hpx_set_value(resource k2hhandle handle, string key, string value[, string subkey = NULL[, string pass=NULL[, int expire=0]]])
  Set value */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_set_value_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, value)
ZEND_ARG_INFO(0, subkey)
ZEND_ARG_INFO(0, pass)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()
/* }}} k2hpx_set_value */

/* {{{ proto bool k2hpx_add_subkey(resource k2hhandle handle, string key, string subkey)
  Set subkey */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_add_subkey_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, subkey)
ZEND_END_ARG_INFO()
/* }}} k2hpx_add_subkey */

/* {{{ proto bool k2hpx_add_subkeys(resource k2hhandle handle, string key, array& subkeys)
  Set subkeys */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_add_subkeys_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_ARRAY_INFO(1, subkeys, 1)
ZEND_END_ARG_INFO()
/* }}} k2hpx_add_subkeys */

/* {{{ proto bool k2hpx_add_attr(resource k2hhandle handle, string key, string attrkey, string attrval)
  Add attribute */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_add_attr_arg_info, 0, ZEND_RETURN_VALUE, 4)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, attrkey)
ZEND_ARG_INFO(0, attrval)
ZEND_END_ARG_INFO()
/* }}} k2hpx_add_attr */

/* {{{ proto bool k2hpx_remove_all(resource k2hhandle handle, string key)
  remove key */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_remove_all_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()
/* }}} k2hpx_remove_all */

/* {{{ proto bool k2hpx_remove(resource k2hhandle handle, string key[, string subkey = NULL])
  remove key or subkey in key */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_remove_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, subkey)
ZEND_END_ARG_INFO()
/* }}} k2hpx_remove */

/* {{{ proto bool k2hpx_rename(resource k2hhandle handle, string key, string newkey)
  rename key name */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_rename_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, newkey)
ZEND_END_ARG_INFO()
/* }}} k2hpx_rename */

/* {{{ proto resource k2hfindhandle k2hpx_find_first(resource k2hhandle handle[, string key = NULL])
  Get resource k2hfindhandle handle for searching key(or subkey) */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_find_first_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()
/* }}} k2hpx_find_first */

/* {{{ proto resource k2hfindhandle k2hpx_find_next(resource k2hfindhandle findhandle)
  Get next resource k2hfindhandle handle for searching key(or subkey) */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_find_next_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, findhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_find_next */

/* {{{ proto bool k2hpx_find_free(resource k2hfindhandle findhandle)
  close resource k2hfindhandle handle */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_find_free_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, findhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_find_free */

/* {{{ proto string k2hpx_find_get_key(resource k2hfindhandle findhandle)
  Get key by resource k2hfindhandle handle */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_find_get_key_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, findhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_find_get_key */

/* {{{ proto string k2hpx_find_get_value(resource k2hfindhandle findhandle)
  Get value by resource k2hfindhandle handle */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_find_get_value_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, findhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_find_get_value */

/* {{{ proto array k2hpx_find_get_subkeys(resource k2hfindhandle findhandle)
  Get subkeys by resource k2hfindhandle handle */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_find_get_subkeys_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, findhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_find_get_subkeys */

/* {{{ proto resource k2hdahandle k2hpx_da_get_handle(resource k2hhandle handle, string key, int mode)
  Get key handle for accessing directly */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_handle_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_handle */

/* {{{ proto resource k2hdahandle k2hpx_da_get_handle_read(resource k2hhandle handle, string key)
  Get key handle for readable accessing directly */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_handle_read_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_handle_read */

/* {{{ proto resource k2hdahandle k2hpx_da_get_handle_write(resource k2hhandle handle, string key)
  Get key handle for writable accessing directly */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_handle_write_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_handle_write */

/* {{{ proto resource k2hdahandle k2hpx_da_get_handle_rw(resource k2hhandle handle, string key)
  Get key handle for readable and writable accessing directly */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_handle_rw_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_handle_rw */

/* {{{ proto bool k2hpx_da_free(resource k2hdahandle dahandle)
  close key handle for accessing directly */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_free_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_free */

/* {{{ proto int k2hpx_da_get_length(resource k2hdahandle dahandle)
  Get value length */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_length_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_length */

/* {{{ proto array k2hpx_da_get_offset(resource k2hdahandle dahandle)
  Get offset for reading/writing pos */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_offset_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_offset */

/* {{{ proto int k2hpx_da_get_read_offset(resource k2hdahandle dahandle)
  Get offset for reading pos */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_read_offset_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_read_offset */

/* {{{ proto int k2hpx_da_get_write_offset(resource k2hdahandle dahandle)
  Get offset for reading pos */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_write_offset_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_write_offset */

/* {{{ proto bool k2hpx_da_set_offset(resource k2hdahandle dahandle, array& offsets)
  Set offset for reading/writing pos */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_set_offset_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_ARG_ARRAY_INFO(1, offsets, 1)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_set_offset */

/* {{{ proto bool k2hpx_da_set_read_offset(resource k2hdahandle dahandle, int offset)
  Set offset for reading pos */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_set_read_offset_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_set_read_offset */

/* {{{ proto bool k2hpx_da_set_write_offset(resource k2hdahandle dahandle, int offset)
  Set offset for writing pos */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_set_write_offset_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_set_write_offset */

/* {{{ proto string k2hpx_da_get_value(resource k2hdahandle dahandle[, int offset = -1])
  Get value from offset */

ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_value_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_value */

/* {{{ proto bool k2hpx_da_get_value_to_file(resource k2hdahandle dahandle, string filepath[, int length = -1[, int offset = -1]])
  Get value into the file from offset */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_get_value_to_file_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, length)
ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_get_value_to_file */

/* {{{ proto bool k2hpx_da_set_value(resource k2hdahandle dahandle, string value[, int offset = -1])
  Set value from offset */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_set_value_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_ARG_INFO(0, value)
ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_set_value */

/* {{{ proto bool k2hpx_da_set_value_from_file(resource k2hdahandle dahandle, string filepath[, int length = -1[, int offset = -1]])
  Set value from the file into offset */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_da_set_value_from_file_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, dahandle_res)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, length)
ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()
/* }}} k2hpx_da_set_value_from_file */

/* {{{ proto resource k2hqhandle k2hpx_q_handle(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]])
  Get resource k2hqhandle for k2hash */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_handle_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, is_fifo)
ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_handle */

/* {{{ proto bool k2hpx_q_free(resource k2hqhandle qhandle)
  close resource k2hqhandle handle */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_free_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, qhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_free */

/* {{{ proto bool k2hpx_q_empty(resource k2hqhandle qhandle)
  Check queue empty */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_empty_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, qhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_empty */

/* {{{ proto int k2hpx_q_count(resource k2hqhandle qhandle)
  Get data count in queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_count_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, qhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_count */

/* {{{ proto string k2hpx_q_read(resource k2hqhandle qhandle[, int pos = 0[, string pass=NULL]])
  Get data from queue at position without removing */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_read_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, qhandle)
ZEND_ARG_INFO(0, pos)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_read */

/* {{{ proto bool k2hpx_q_push(resource k2hqhandle qhandle, string datavalue[, string pass=NULL[, int expire=0]])
  push data to queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_push_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, qhandle)
ZEND_ARG_INFO(0, datavalue)
ZEND_ARG_INFO(0, pass)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_push */

/* {{{ proto string k2hpx_q_pop(resource k2hqhandle qhandle[, string pass=NULL])
  pop data from queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_pop_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, qhandle)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_pop */

/* {{{ proto bool k2hpx_q_remove(resource k2hqhandle qhandle, int count[, string pass=NULL])
  remove count data from queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_remove_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, qhandle)
ZEND_ARG_INFO(0, count)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_remove */

/* {{{ proto bool k2hpx_q_dump(resource k2hqhandle qhandle[, stream output = NULL])
  dump queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_q_dump_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, qhandle)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_q_dump */

/* {{{ proto resource k2hkeyqhandle k2hpx_keyq_handle(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]])
  Get resource k2hkeyqhandle for k2hash */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_handle_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, is_fifo)
ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_handle */

/* {{{ proto bool k2hpx_keyq_free(resource k2hkeyqhandle keyqhandle)
  close resource k2hkeyqhandle handle */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_free_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_free */

/* {{{ proto bool k2hpx_keyq_empty(resource k2hkeyqhandle keyqhandle)
  Check key queue empty */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_empty_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_empty */

/* {{{ proto int k2hpx_keyq_count(resource k2hkeyqhandle keyqhandle)
  Get data count in key queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_count_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_count */

/* {{{ proto array k2hpx_keyq_read(resource k2hkeyqhandle keyqhandle[, int pos = 0[, string pass=NULL]])
  Get key and value from key queue at position without removing. */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_read_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_ARG_INFO(0, pos)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_read */

/* {{{ proto bool k2hpx_keyq_push(resource k2hkeyqhandle keyqhandle, string key, string value[, string pass=NULL[, int expire=0]])
  push key and value to key queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_push_arg_info, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, value)
ZEND_ARG_INFO(0, pass)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_push */

/* {{{ proto array k2hpx_keyq_pop(resource k2hkeyqhandle keyqhandle[, string pass=NULL])
  pop key and value from queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_pop_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_pop */

/* {{{ proto bool k2hpx_keyq_remove(resource k2hkeyqhandle keyqhandle, int count[, string pass=NULL])
  remove count data from queue by k2hkeyqhandle */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_remove_arg_info, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_ARG_INFO(0, count)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_remove */

/* {{{ proto bool k2hpx_keyq_dump(resource k2hkeyqhandle keyqhandle[, stream output = NULL])
  dump key queue */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_keyq_dump_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, keyqhandle)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_keyq_dump */

/* {{{ proto bool k2hpx_dump_head(resource k2hhandle handle[, stream output = NULL])
  dump k2hash internal head area */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_dump_head_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_dump_head */

/* {{{ proto bool k2hpx_dump_keytable(resource k2hhandle handle[, stream output = NULL])
  dump k2hash internal keytable area */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_dump_keytable_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_dump_keytable */

/* {{{ proto bool k2hpx_dump_full_keytable(resource k2hhandle handle[, stream output = NULL])
  dump k2hash internal full keytable area */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_dump_full_keytable_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_dump_full_keytable */

/* {{{ proto bool k2hpx_dump_elementtable(resource k2hhandle handle[, stream output = NULL])
  dump k2hash internal elementtable area */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_dump_elementtable_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_dump_elementtable */

/* {{{ proto bool k2hpx_dump_full(resource k2hhandle handle[, stream output = NULL])
  dump k2hash internal hole area */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_dump_full_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_dump_full */

/* {{{ proto bool k2hpx_print_state(resource k2hhandle handle[, stream output = NULL])
  Print k2hash data status */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_print_state_arg_info, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_print_state */

/* {{{ proto bool k2hpx_print_version([stream output = NULL])
  Print k2hash library version */
ZEND_BEGIN_ARG_INFO_EX(k2hpx_print_version_arg_info, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()
/* }}} k2hpx_print_version */

/* {{{ proto bool create(string filepath[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]])
  K2hash::create method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_create, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()

/* }}} create */

/* {{{ proto bool open(string filepath, bool readonly[, bool removefile = false[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]]])
  K2hash::open method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_open, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, readonly)
ZEND_ARG_INFO(0, removefile)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()

/* }}} open */

/* {{{ proto bool openRW(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  K2hash::openRW method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_openRW, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()

/* }}} openRW */

/* {{{ proto bool openRO(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  K2hash::openRO method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_openRO, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()

/* }}} openRO */

/* {{{ proto bool openTempfile(string filepath[, bool fullmap = true[, int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]]])
  K2hash::openTempfile method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_openTempfile, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, fullmap)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()

/* }}} openTempfile */

/* {{{ proto bool openMem([int maskbitcnt = K2H_DEF_MASK_BIT[, int cmaskbitcnt = K2H_DEF_CMASK_BIT[, int maxelementcnt = K2H_DEF_ELEMENT[, int pagesize = K2H_DEF_PAGESIZE]]]])
  K2hash::openMem method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_openMem, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, maskbitcnt)
ZEND_ARG_INFO(0, cmaskbitcnt)
ZEND_ARG_INFO(0, maxelementcnt)
ZEND_ARG_INFO(0, pagesize)
ZEND_END_ARG_INFO()

/* }}} openMem */

/* {{{ proto bool close([int waitms = 0])
  K2hash::close method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_close, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, waitms)
ZEND_END_ARG_INFO()

/* }}} close */

/* {{{ proto bool transaction(bool enable[, string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]])
  K2hash::transaction method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_transaction, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, enable)
ZEND_ARG_INFO(0, transfile)
ZEND_ARG_INFO(0, prefix)
ZEND_ARG_INFO(0, param)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

/* }}} transaction */

/* {{{ proto bool enableTransaction([string transfile = NULL[, string prefix = NULL[, string param = NULL[, int expire = 0]]]])
  K2hash::enableTransaction method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_enableTransaction, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, transfile)
ZEND_ARG_INFO(0, prefix)
ZEND_ARG_INFO(0, param)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

/* }}} enableTransaction */

/* {{{ proto bool disableTransaction()
  K2hash::disableTransaction method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_disableTransaction, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} disableTransaction */

/* {{{ proto int getTransactionThreadPool()
  K2hash::getTransactionThreadPool method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getTransactionThreadPool, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} getTransactionThreadPool */

/* {{{ proto bool setTransactionThreadPool(int count)
  K2hash::getTransactionThreadPool method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_setTransactionThreadPool, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()

/* }}} setTransactionThreadPool */

/* {{{ proto bool unsetTransactionThreadPool()
  K2hash::unsetTransactionThreadPool method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_unsetTransactionThreadPool, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} unsetTransactionThreadPool */

/* {{{ proto bool putArchive(string filepath[, bool errskip = true])
  K2hash::putArchive method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_putArchive, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, errskip)
ZEND_END_ARG_INFO()

/* }}} putArchive */

/* {{{ proto bool loadArchive(string filepath[, bool errskip = true])
  K2hash::loadArchive method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_loadArchive, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, filepath)
ZEND_ARG_INFO(0, errskip)
ZEND_END_ARG_INFO()

/* }}} loadArchive */

/* {{{ proto bool setCommonAttribute([int is_mtime = K2H_ATTR_DEFAULT[, int is_history = K2H_ATTR_DEFAULT[, int is_encrypt = K2H_ATTR_DEFAULT, string passfile = NULL[, int is_expire = K2H_ATTR_DEFAULT, int expire = 0]]]])
  K2hash::setCommonAttribute method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_setCommonAttribute, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, is_mtime)
ZEND_ARG_INFO(0, is_history)
ZEND_ARG_INFO(0, is_encrypt)
ZEND_ARG_INFO(0, passfile)
ZEND_ARG_INFO(0, is_expire)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

/* }}} setCommonAttribute */

/* {{{ proto bool cleanCommonAttribute()
  K2hash::cleanCommonAttribute method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_cleanCommonAttribute, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} cleanCommonAttribute */

/* {{{ proto bool addAttrPluginLib(string libfile)
  K2hash::addAttrPluginLib method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_addAttrPluginLib, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, libfile)
ZEND_END_ARG_INFO()

/* }}} addAttrPluginLib */

/* {{{ proto bool addAttrCryptPass(string encpass[, bool is_default_encrypt = false])
  K2hash::addAttrCryptPass method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_addAttrCryptPass, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, encpass)
ZEND_ARG_INFO(0, is_default_encrypt)
ZEND_END_ARG_INFO()

/* }}} addAttrCryptPass */

/* {{{ proto bool getAttrVersionInfos([stream output = NULL])
  K2hash::getAttrVersionInfos method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getAttrVersionInfos, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} getAttrVersionInfos */

/* {{{ proto bool getAttrInfos([stream output = NULL])
  K2hash::getAttrInfos method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getAttrInfos, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} getAttrInfos */

/* {{{ proto string getValue(string key[, string subkey = NULL[, bool attrcheck = true[, string pass = NULL]]])
  K2hash::getValue method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getValue, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, subkey)
ZEND_ARG_INFO(0, attrcheck)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

/* }}} getValue */

/* {{{ proto array getSubkeys(string key[, bool attrcheck = true])
  K2hash::getSubkeys method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getSubkeys, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, attrcheck)
ZEND_END_ARG_INFO()

/* }}} getSubkeys */

/* {{{ proto array getAttrs(string key)
  K2hash::getAttrs method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getAttrs, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

/* }}} getAttrs */

/* {{{ proto string getAttrValue(string key, string attrkey)
  K2hash::getAttrValue method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getAttrValue, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, attrkey)
ZEND_END_ARG_INFO()
/* }}} getAttrValue */

/* {{{ proto bool setValue(string key, string value[, string subkey = NULL[, string pass=NULL[, int expire=0]]])
  K2hash::setValue method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_setValue, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, value)
ZEND_ARG_INFO(0, subkey)
ZEND_ARG_INFO(0, pass)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

/* }}} setValue */

/* {{{ proto bool addSubkey(string key, string subkey)
  K2hash::addSubkey method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_addSubkey, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, subkey)
ZEND_END_ARG_INFO()

/* }}} addSubkey */

/* {{{ proto bool addSubkeys(string key, array &subkeys)
  K2hash::addSubkeys method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_addSubkeys, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_ARRAY_INFO(1, subkeys, 1)
ZEND_END_ARG_INFO()

/* }}} addSubkeys */

/* {{{ proto bool addAttr(string key, string attrkey, string attrval)
  K2hash::addAttr method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_addAttr, 0, ZEND_RETURN_VALUE, 3)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, attrkey)
ZEND_ARG_INFO(0, attrval)
ZEND_END_ARG_INFO()

/* }}} addAttr */

/* {{{ proto bool removeAll(string key)
  K2hash::removeAll method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_removeAll, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

/* }}} removeAll */

/* {{{ proto bool remove(string key[, string subkey = NULL])
  K2hash::remove method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_remove, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, subkey)
ZEND_END_ARG_INFO()

/* }}} remove */

/* {{{ proto bool rename(string key, string newkey)
  K2hash::rename method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_rename, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, newkey)
ZEND_END_ARG_INFO()

/* }}} rename */

/* {{{ proto object getIterator([string key = NULL])
  K2hash::getIterator method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getIterator, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

/* }}} getIterator */

/* {{{ proto stream getStream(string key, string mode)
  K2hash::getStream method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getStream, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

/* }}} getStream */

/* {{{ proto object getQueue([bool is_fifo = true[, string prefix = NULL]])
  K2hash::getQueue method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getQueue, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, is_fifo)
ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

/* }}} getQueue */

/* {{{ proto object getKeyQueue([bool is_fifo = true[, string prefix = NULL]])
  K2hash::getKeyQueue method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_getKeyQueue, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, is_fifo)
ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

/* }}} getKeyQueue */

/* {{{ proto bool dumpHead([stream output = NULL])
  K2hash::dumpHead method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_dumpHead, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} dumpHead */

/* {{{ proto bool dumpKeytable([stream output = NULL])
  K2hash::dumpKeytable method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_dumpKeytable, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} dumpKeytable */

/* {{{ proto bool dumpFullKeytable([stream output = NULL])
  K2hash::dumpFullKeytable method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_dumpFullKeytable, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} dumpFullKeytable */

/* {{{ proto bool dumpElementtable([stream output = NULL])
  K2hash::dumpElementtable method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_dumpElementtable, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} dumpElementtable */

/* {{{ proto bool dumpFull([stream output = NULL])
  K2hash::dumpFull method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_dumpFull, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} dumpFull */

/* {{{ proto bool printState([stream output = NULL])
  K2hash::printState method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_printState, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} printState */

/* {{{ proto bool printVersion([stream output = NULL])
  K2hash::printVersion method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hash_printVersion, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} printVersion */

/* {{{ proto void __construct(resource k2hhandle handle[, string key = NULL])
  K2hIterator::__construct method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hIterator___construct, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

/* }}} __construct */

/* {{{ proto string current()
  K2hIterator::current method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hIterator_current, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} current */

/* {{{ proto string key()
  K2hIterator::key method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hIterator_key, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} key */

/* {{{ proto void next()
  K2hIterator::next method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hIterator_next, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} next */

/* {{{ proto void rewind()
  K2hIterator::rewind method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hIterator_rewind, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} rewind */

/* {{{ proto bool valid()
  K2hIterator::valid method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hIterator_valid, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} valid */

/* {{{ proto void __construct(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]])
  K2hKeyQueue::__construct method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue___construct, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, is_fifo)
ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

/* }}} __construct */

/* {{{ proto bool isEmpty()
  K2hKeyQueue::isEmpty method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue_isEmpty, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} isEmpty */

/* {{{ proto int count()
  K2hKeyQueue::count method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue_count, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} count */

/* {{{ proto array read([int pos = 0[, string pass=NULL]])
  K2hKeyQueue::read method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue_read, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, pos)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

/* }}} read */

/* {{{ proto bool push(string key, string value[, string pass=NULL[, int expire=0]])
  K2hKeyQueue::push method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue_push, 0, ZEND_RETURN_VALUE, 2)
ZEND_ARG_INFO(0, key)
ZEND_ARG_INFO(0, value)
ZEND_ARG_INFO(0, pass)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

/* }}} push */

/* {{{ proto array pop([string pass=NULL])
  K2hKeyQueue::pop method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue_pop, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

/* }}} pop */

/* {{{ proto bool remove(int count[, string pass=NULL])
  K2hKeyQueue::remove method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue_remove, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, count)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

/* }}} remove */

/* {{{ proto bool dump([stream output = NULL])
  K2hKeyQueue::dump method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hKeyQueue_dump, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} dump */

/* {{{ proto void __construct(resource k2hhandle handle[, bool is_fifo = true[, string prefix = NULL]])
  K2hQueue::__construct method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue___construct, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, handle_res)
ZEND_ARG_INFO(0, is_fifo)
ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

/* }}} __construct */

/* {{{ proto bool isEmpty()
  K2hQueue::isEmpty method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue_isEmpty, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} isEmpty */

/* {{{ proto int count()
  K2hQueue::count method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue_count, 0, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

/* }}} count */

/* {{{ proto string read([int pos = 0[, string pass=NULL]])
  K2hQueue::read method */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue_read, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, pos)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

/* }}} read */

/* {{{ proto bool push(string datavalue[, string pass=NULL[, int expire=0]])
  K2hQueue::push method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue_push, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, datavalue)
ZEND_ARG_INFO(0, pass)
ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

/* }}} push */

/* {{{ proto string pop([string pass=NULL])
  K2hQueue::pop method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue_pop, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

/* }}} pop */

/* {{{ proto bool remove(int count[, string pass=NULL])
  K2hQueue::remove method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue_remove, 0, ZEND_RETURN_VALUE, 1)
ZEND_ARG_INFO(0, count)
ZEND_ARG_INFO(0, pass)
ZEND_END_ARG_INFO()

/* }}} remove */

/* {{{ proto bool dump([stream output = NULL])
  K2hQueue::dump method */
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_K2hQueue_dump, 0, ZEND_RETURN_VALUE, 0)
ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

/* }}} dump */

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

/* {{{ k2hash_phpext_functions[]
 *
 * Every user visible function must have an entry in k2hash_phpext_functions[].
 */
static const zend_function_entry ext_functions[] = {
	PHP_FE(k2hpx_bump_debug_level, k2hpx_bump_debug_level_arg_info)
	PHP_FE(k2hpx_set_debug_level_silent, k2hpx_set_debug_level_silent_arg_info)
	PHP_FE(k2hpx_set_debug_level_error, k2hpx_set_debug_level_error_arg_info)
	PHP_FE(k2hpx_set_debug_level_warning, k2hpx_set_debug_level_warning_arg_info)
	PHP_FE(k2hpx_set_debug_level_message, k2hpx_set_debug_level_message_arg_info)
	PHP_FE(k2hpx_set_debug_file, k2hpx_set_debug_file_arg_info)
	PHP_FE(k2hpx_unset_debug_file, k2hpx_unset_debug_file_arg_info)
	PHP_FE(k2hpx_load_debug_env, k2hpx_load_debug_env_arg_info)
	PHP_FE(k2hpx_load_hash_library, k2hpx_load_hash_library_arg_info)
	PHP_FE(k2hpx_unload_hash_library, k2hpx_unload_hash_library_arg_info)
	PHP_FE(k2hpx_load_transaction_library, k2hpx_load_transaction_library_arg_info)
	PHP_FE(k2hpx_unload_transaction_library, k2hpx_unload_transaction_library_arg_info)
	PHP_FE(k2hpx_create        , k2hpx_create_arg_info)
	PHP_FE(k2hpx_open          , k2hpx_open_arg_info)
	PHP_FE(k2hpx_open_rw       , k2hpx_open_rw_arg_info)
	PHP_FE(k2hpx_open_ro       , k2hpx_open_ro_arg_info)
	PHP_FE(k2hpx_open_tempfile , k2hpx_open_tempfile_arg_info)
	PHP_FE(k2hpx_open_mem      , k2hpx_open_mem_arg_info)
	PHP_FE(k2hpx_close         , k2hpx_close_arg_info)
	PHP_FE(k2hpx_transaction   , k2hpx_transaction_arg_info)
	PHP_FE(k2hpx_enable_transaction, k2hpx_enable_transaction_arg_info)
	PHP_FE(k2hpx_disable_transaction, k2hpx_disable_transaction_arg_info)
	PHP_FE(k2hpx_get_transaction_thread_pool, k2hpx_get_transaction_thread_pool_arg_info)
	PHP_FE(k2hpx_set_transaction_thread_pool, k2hpx_set_transaction_thread_pool_arg_info)
	PHP_FE(k2hpx_unset_transaction_thread_pool, k2hpx_unset_transaction_thread_pool_arg_info)
	PHP_FE(k2hpx_put_archive   , k2hpx_put_archive_arg_info)
	PHP_FE(k2hpx_load_archive  , k2hpx_load_archive_arg_info)
	PHP_FE(k2hpx_set_common_attr, k2hpx_set_common_attr_arg_info)
	PHP_FE(k2hpx_clean_common_attr, k2hpx_clean_common_attr_arg_info)
	PHP_FE(k2hpx_add_attr_plugin_library, k2hpx_add_attr_plugin_library_arg_info)
	PHP_FE(k2hpx_add_attr_crypt_pass, k2hpx_add_attr_crypt_pass_arg_info)
	PHP_FE(k2hpx_print_attr_version, k2hpx_print_attr_version_arg_info)
	PHP_FE(k2hpx_print_attr_information, k2hpx_print_attr_information_arg_info)
	PHP_FE(k2hpx_get_value     , k2hpx_get_value_arg_info)
	PHP_FE(k2hpx_get_subkeys   , k2hpx_get_subkeys_arg_info)
	PHP_FE(k2hpx_get_attrs     , k2hpx_get_attrs_arg_info)
	PHP_FE(k2hpx_get_attr_value, k2hpx_get_attr_value_arg_info)
	PHP_FE(k2hpx_set_value     , k2hpx_set_value_arg_info)
	PHP_FE(k2hpx_add_subkey    , k2hpx_add_subkey_arg_info)
	PHP_FE(k2hpx_add_subkeys   , k2hpx_add_subkeys_arg_info)
	PHP_FE(k2hpx_add_attr      , k2hpx_add_attr_arg_info)
	PHP_FE(k2hpx_remove_all    , k2hpx_remove_all_arg_info)
	PHP_FE(k2hpx_remove        , k2hpx_remove_arg_info)
	PHP_FE(k2hpx_rename        , k2hpx_rename_arg_info)
	PHP_FE(k2hpx_find_first    , k2hpx_find_first_arg_info)
	PHP_FE(k2hpx_find_next     , k2hpx_find_next_arg_info)
	PHP_FE(k2hpx_find_free     , k2hpx_find_free_arg_info)
	PHP_FE(k2hpx_find_get_key  , k2hpx_find_get_key_arg_info)
	PHP_FE(k2hpx_find_get_value, k2hpx_find_get_value_arg_info)
	PHP_FE(k2hpx_find_get_subkeys, k2hpx_find_get_subkeys_arg_info)
	PHP_FE(k2hpx_da_get_handle , k2hpx_da_get_handle_arg_info)
	PHP_FE(k2hpx_da_get_handle_read, k2hpx_da_get_handle_read_arg_info)
	PHP_FE(k2hpx_da_get_handle_write, k2hpx_da_get_handle_write_arg_info)
	PHP_FE(k2hpx_da_get_handle_rw, k2hpx_da_get_handle_rw_arg_info)
	PHP_FE(k2hpx_da_free       , k2hpx_da_free_arg_info)
	PHP_FE(k2hpx_da_get_length , k2hpx_da_get_length_arg_info)
	PHP_FE(k2hpx_da_get_offset , k2hpx_da_get_offset_arg_info)
	PHP_FE(k2hpx_da_get_read_offset, k2hpx_da_get_read_offset_arg_info)
	PHP_FE(k2hpx_da_get_write_offset, k2hpx_da_get_write_offset_arg_info)
	PHP_FE(k2hpx_da_set_offset , k2hpx_da_set_offset_arg_info)
	PHP_FE(k2hpx_da_set_read_offset, k2hpx_da_set_read_offset_arg_info)
	PHP_FE(k2hpx_da_set_write_offset, k2hpx_da_set_write_offset_arg_info)
	PHP_FE(k2hpx_da_get_value  , k2hpx_da_get_value_arg_info)
	PHP_FE(k2hpx_da_get_value_to_file, k2hpx_da_get_value_to_file_arg_info)
	PHP_FE(k2hpx_da_set_value  , k2hpx_da_set_value_arg_info)
	PHP_FE(k2hpx_da_set_value_from_file, k2hpx_da_set_value_from_file_arg_info)
	PHP_FE(k2hpx_q_handle      , k2hpx_q_handle_arg_info)
	PHP_FE(k2hpx_q_free        , k2hpx_q_free_arg_info)
	PHP_FE(k2hpx_q_empty       , k2hpx_q_empty_arg_info)
	PHP_FE(k2hpx_q_count       , k2hpx_q_count_arg_info)
	PHP_FE(k2hpx_q_read        , k2hpx_q_read_arg_info)
	PHP_FE(k2hpx_q_push        , k2hpx_q_push_arg_info)
	PHP_FE(k2hpx_q_pop         , k2hpx_q_pop_arg_info)
	PHP_FE(k2hpx_q_remove      , k2hpx_q_remove_arg_info)
	PHP_FE(k2hpx_q_dump        , k2hpx_q_dump_arg_info)
	PHP_FE(k2hpx_keyq_handle   , k2hpx_keyq_handle_arg_info)
	PHP_FE(k2hpx_keyq_free     , k2hpx_keyq_free_arg_info)
	PHP_FE(k2hpx_keyq_empty    , k2hpx_keyq_empty_arg_info)
	PHP_FE(k2hpx_keyq_count    , k2hpx_keyq_count_arg_info)
	PHP_FE(k2hpx_keyq_read     , k2hpx_keyq_read_arg_info)
	PHP_FE(k2hpx_keyq_push     , k2hpx_keyq_push_arg_info)
	PHP_FE(k2hpx_keyq_pop      , k2hpx_keyq_pop_arg_info)
	PHP_FE(k2hpx_keyq_remove   , k2hpx_keyq_remove_arg_info)
	PHP_FE(k2hpx_keyq_dump     , k2hpx_keyq_dump_arg_info)
	PHP_FE(k2hpx_dump_head     , k2hpx_dump_head_arg_info)
	PHP_FE(k2hpx_dump_keytable , k2hpx_dump_keytable_arg_info)
	PHP_FE(k2hpx_dump_full_keytable, k2hpx_dump_full_keytable_arg_info)
	PHP_FE(k2hpx_dump_elementtable, k2hpx_dump_elementtable_arg_info)
	PHP_FE(k2hpx_dump_full     , k2hpx_dump_full_arg_info)
	PHP_FE(k2hpx_print_state   , k2hpx_print_state_arg_info)
	PHP_FE(k2hpx_print_version , k2hpx_print_version_arg_info)
	PHP_FE_END	/* Must be the last line in k2hash_phpext_functions[] */
};
/* }}} */

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
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
