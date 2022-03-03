---
layout: contents
language: en-us
title: k2hash Functions
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpxja.html
lang_opp_word: To Japanese
prev_url: k2hiter_class.html
prev_string: K2hIterator Class
top_url: developer.html
top_string: Developer
next_url: 
next_string: 
---

# k2hash Functions
The K2HASH PHP Extension provides the following functions for operation to [K2HASH](https://k2hash.antpick.ax/).

## Function list

- [k2hpx_add_attr_crypt_pass](k2hpx_add_attr_crypt_pass.html) - Adds the password to encrypt values
- [k2hpx_add_attr_plugin_library](k2hpx_add_attr_plugin_library.html) - Adds the user-defined library to handle attributes
- [k2hpx_add_attr](k2hpx_add_attr.html) - Adds the attribute to the key
- [k2hpx_add_subkey](k2hpx_add_subkey.html) - Associates the key with the other key
- [k2hpx_add_subkeys](k2hpx_add_subkeys.html) - Adds the subkeys to the key
- [k2hpx_bump_debug_level](k2hpx_bump_debug_level.html) - Changes the log level
- [k2hpx_clean_common_attr](k2hpx_clean_common_attr.html) - Initializes the common attributes
- [k2hpx_close](k2hpx_close.html) - Closes the k2h file
- [k2hpx_create](k2hpx_create.html) - Creates the k2h file
- [k2hpx_da_free](k2hpx_da_free.html) - Frees resources of k2hash direct access handle
- [k2hpx_da_get_handle_read](k2hpx_da_get_handle_read.html) - Reads data
- [k2hpx_da_get_handle_rw](k2hpx_da_get_handle_rw.html) - Gets the k2h direct access file handle with read-write only mode
- [k2hpx_da_get_handle_write](k2hpx_da_get_handle_write.html) - Gets the k2h direct access file handle with write only mode
- [k2hpx_da_get_handle](k2hpx_da_get_handle.html) - Gets the k2h direct access file handle
- [k2hpx_da_get_length](k2hpx_da_get_length.html) - Gets the data length
- [k2hpx_da_get_offset](k2hpx_da_get_offset.html) - Gets the k2h direct access file offset with read-write access mode
- [k2hpx_da_get_read_offset](k2hpx_da_get_read_offset.html) - Gets the k2h direct access file offset with read access mode
- [k2hpx_da_get_value_to_file](k2hpx_da_get_value_to_file.html) - Reads value using the offset and write it to the file
- [k2hpx_da_get_value](k2hpx_da_get_value.html) - Reads value using the offset
- [k2hpx_da_get_write_offset](k2hpx_da_get_write_offset.html) - Gets the k2h direct access file offset with write access mode
- [k2hpx_da_set_offset](k2hpx_da_set_offset.html) - Sets the offset to modify the data
- [k2hpx_da_set_read_offset](k2hpx_da_set_read_offset.html) - Sets the offset to read the data
- [k2hpx_da_set_value_from_file](k2hpx_da_set_value_from_file.html) - Sets value using the offset reading data from the file with length
- [k2hpx_da_set_value](k2hpx_da_set_value.html) - Sets value
- [k2hpx_da_set_write_offset](k2hpx_da_set_write_offset.html) - Sets value using the offset
- [k2hpx_disable_transaction](k2hpx_disable_transaction.html) - Stops a transaction
- [k2hpx_dump_elementtable](k2hpx_dump_elementtable.html) - Prints elements of the k2hash's hash table elements
- [k2hpx_dump_full_keytable](k2hpx_dump_full_keytable.html) - Prints details of the k2hash's hash tables
- [k2hpx_dump_full](k2hpx_dump_full.html) - Prints the k2hash's hash tables in details
- [k2hpx_dump_head](k2hpx_dump_head.html) - Prints the k2hash's headers
- [k2hpx_dump_keytable](k2hpx_dump_keytable.html) - Prints the k2hash's hash tables
- [k2hpx_enable_transaction](k2hpx_enable_transaction.html) - Starts a transaction
- [k2hpx_find_first](k2hpx_find_first.html) - Gets the k2h file handle to search for the key
- [k2hpx_find_free](k2hpx_find_free.html) - Releases resources of the k2h file handle to search for keys
- [k2hpx_find_get_key](k2hpx_find_get_key.html) - Gets keys using the k2h file handle to search for keys
- [k2hpx_find_get_subkeys](k2hpx_find_get_subkeys.html) - Gets keys using the k2h file handle to search for keys with linked with each key
- [k2hpx_find_get_value](k2hpx_find_get_value.html) - Gets value using the k2h file handle to search for keys
- [k2hpx_find_next](k2hpx_find_next.html) - Advances the internal pointer of the k2h file handle to search for keys
- [k2hpx_get_attr_value](k2hpx_get_attr_value.html) - Gets an attribute value of the key
- [k2hpx_get_attrs](k2hpx_get_attrs.html) - Gets attributes of the key
- [k2hpx_get_subkeys](k2hpx_get_subkeys.html) - Gets the array of the keys(subkeys) linked with the key
- [k2hpx_get_transaction_thread_pool](k2hpx_get_transaction_thread_pool.html) - Gets the number of transaction workers
- [k2hpx_get_value](k2hpx_get_value.html) - Gets the value of the key
- [k2hpx_keyq_count](k2hpx_keyq_count.html) - Counts elements in the K2hKeyQueue object
- [k2hpx_keyq_dump](k2hpx_keyq_dump.html) - Gets the elements in the K2hKeyQueue object
- [k2hpx_keyq_empty](k2hpx_keyq_empty.html) - Returns whether the K2hKeyQueue is empty
- [k2hpx_keyq_free](k2hpx_keyq_free.html) - Frees resources of the K2hKeyQueue handle
- [k2hpx_keyq_handle](k2hpx_keyq_handle.html) - Gets the K2hKeyQueue file handle
- [k2hpx_keyq_pop](k2hpx_keyq_pop.html) - Removes and returns the removed element from the K2hKeyQueue
- [k2hpx_keyq_push](k2hpx_keyq_push.html) - Adds a key/value pair to the K2hKeyQueue
- [k2hpx_keyq_read](k2hpx_keyq_read.html) - Returns a key/value pair from the K2hKeyQueue
- [k2hpx_keyq_remove](k2hpx_keyq_remove.html) - Removes a key/value pair from the K2hKeyQueue
- [k2hpx_load_archive](k2hpx_load_archive.html) - Loads data from the file
- [k2hpx_load_debug_env](k2hpx_load_debug_env.html) - Loads environment variables
- [k2hpx_load_hash_library](k2hpx_load_hash_library.html) - Loads hash functions from the file
- [k2hpx_load_transaction_library](k2hpx_load_transaction_library.html) - Loads functions of k2hash transaction usage from the file
- [k2hpx_open_mem](k2hpx_open_mem.html) - Attaches k2h data segments on memory
- [k2hpx_open_ro](k2hpx_open_ro.html) - Read the k2hash file
- [k2hpx_open_rw](k2hpx_open_rw.html) - Edit the k2hash file
- [k2hpx_open_tempfile](k2hpx_open_tempfile.html) - Edit the k2hash file on temporary file system
- [k2hpx_open](k2hpx_open.html) - Opens the k2h file
- [k2hpx_print_attr_information](k2hpx_print_attr_information.html) - Prints the attribute information
- [k2hpx_print_attr_version](k2hpx_print_attr_version.html) - Prints the attribute library version
- [k2hpx_print_state](k2hpx_print_state.html) - Prints k2hash data statistics
- [k2hpx_print_version](k2hpx_print_version.html) - Prints the library version
- [k2hpx_put_archive](k2hpx_put_archive.html) - Saves a k2h file as an archive file
- [k2hpx_q_count](k2hpx_q_count.html) - Counts elements in the K2hQueue object
- [k2hpx_q_dump](k2hpx_q_dump.html) - Prints the elements in the K2hQueue object
- [k2hpx_q_empty](k2hpx_q_empty.html) - Returns whether the K2hQueue is empty
- [k2hpx_q_free](k2hpx_q_free.html) - Frees resources of the K2hQueue handle
- [k2hpx_q_handle](k2hpx_q_handle.html) - Gets the K2hQueue file handle
- [k2hpx_q_pop](k2hpx_q_pop.html) - Removes and returns the removed element from the K2hQueue
- [k2hpx_q_push](k2hpx_q_push.html) - Adds a value to the K2hQueue
- [k2hpx_q_read](k2hpx_q_read.html) - Returns a key/value pair from the K2hQueue
- [k2hpx_q_remove](k2hpx_q_remove.html) - Removes a value from the K2hQueue
- [k2hpx_remove_all](k2hpx_remove_all.html) - Removes the key and the keys linked with the key
- [k2hpx_remove](k2hpx_remove.html) - Removes the key
- [k2hpx_rename](k2hpx_rename.html) - Renames the key
- [k2hpx_set_common_attr](k2hpx_set_common_attr.html) - Sets the common attributes
- [k2hpx_set_debug_file](k2hpx_set_debug_file.html) - Writes log to the file
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_error.html) - Sets log level to error
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_message.html) - Sets log level to info
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silent.html) - Stops logging
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warning.html) - Sets log level to warning
- [k2hpx_set_transaction_thread_pool](k2hpx_set_transaction_thread_pool.html) - Sets the number of transaction workers
- [k2hpx_set_value](k2hpx_set_value.html) - Sets the value
- [k2hpx_transaction](k2hpx_transaction.html) - Changes transaction settings
- [k2hpx_unload_hash_library](k2hpx_unload_hash_library.html) - Removes the user-defined hash library
- [k2hpx_unload_transaction_library](k2hpx_unload_transaction_library.html) - Removes the user-defined transaction library
- [k2hpx_unset_debug_file](k2hpx_unset_debug_file.html) - Writes logs to stderr
- [k2hpx_unset_transaction_thread_pool](k2hpx_unset_transaction_thread_pool.html) - Stops transaction workers
