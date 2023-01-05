<?php
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
* AUTHOR:   Hirotaka Wakabayashi
* CREATE:   Tue, Feb 22 2022
* REVISION:
*/

/** @generate-function-entries */

function k2hpx_bump_debug_level(): void {}

function k2hpx_set_debug_level_silent(): void {}

function k2hpx_set_debug_level_error(): void {}

function k2hpx_set_debug_level_warning(): void {}

function k2hpx_set_debug_level_message(): void {}

function k2hpx_set_debug_file(string $filepath): bool {}

function k2hpx_unset_debug_file(): void {}

function k2hpx_load_debug_env(): bool {}

function k2hpx_load_hash_library(string $libpath): bool {}

function k2hpx_unload_hash_library(): bool {}

function k2hpx_load_transaction_library(string $libpath): bool {}

function k2hpx_unload_transaction_library(): bool {}

function k2hpx_create(
	 string $filepath,
	 int $maskbitcnt = 8,
	 int $cmaskbitcnt = 4,
	 int $maxelementcnt = 32,
	 int $pagesize = 4096): bool {}

/**
 * @return resource|false
 */
function k2hpx_open(
	 string $filepath,
	 bool $readonly,
	 bool $removefile = false,
	 bool $fullmap = true,
	 int $maskbitcnt = 8,
	 int $cmaskbitcnt = 4,
	 int $maxelementcnt = 32,
	 int $pagesize = 4096) {}

/**
 * @return resource|false
 */
function k2hpx_open_rw(
	 string $filepath,
	 bool $fullmap = true,
	 int $maskbitcnt = 8,
	 int $cmaskbitcnt = 4,
	 int $maxelementcnt = 32,
	 int $pagesize = 4096) {}

/**
 * @return resource|false
 */
function k2hpx_open_ro(
	 string $filepath,
	 bool $fullmap = true,
	 int $maskbitcnt = 8,
	 int $cmaskbitcnt = 4,
	 int $maxelementcnt = 32,
	 int $pagesize = 4096) {}

/**
 * @return resource|false
 */
function k2hpx_open_tempfile(
	 string $filepath,
	 bool $fullmap = true,
	 int $maskbitcnt = 8,
	 int $cmaskbitcnt = 4,
	 int $maxelementcnt = 32,
	 int $pagesize = 4096) {}

/**
 * @return resource|false
 */
function k2hpx_open_mem(
	 int $maskbitcnt = 8,
	 int $cmaskbitcnt = 4,
	 int $maxelementcnt = 32,
	 int $pagesize = 4096) {}

/**
 * @param resource $handle_res
 */
function k2hpx_close($handle_res, int $waitms = 0): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_transaction(
	 $handle_res,
	 bool $enable, 
	 ?string $transfile= null,
	 ?string $prefix= null,
	 ?string $param= null,
	 int $expire = 0): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_enable_transaction(
	 $handle_res,
	 ?string $transfile= null,
	 ?string $prefix= null,
	 ?string $param= null,
	 int $expire = 0): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_disable_transaction($handle_res): bool {}

function k2hpx_get_transaction_thread_pool(): int {}

function k2hpx_set_transaction_thread_pool(int $count): bool {}

function k2hpx_unset_transaction_thread_pool(): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_put_archive($handle_res, string $filepath, bool $errskip = true): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_load_archive($handle_res, string $filepath, bool $errskip = true): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_set_common_attr(
	 $handle_res,
	 int $is_mtime = -1,
	 int $is_history = -1,
	 int $is_encrypt = -1,
	 ?string $passfile = null,
	 int $is_expire = -1,
	 int $expire = 0): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_clean_common_attr($handle_res): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_add_attr_plugin_library($handle_res, string $libfile): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_add_attr_crypt_pass(
	$handle_res,
	string $encpass,
	bool $is_default_encrypt = false): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_print_attr_version($handle_res, $output = null): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_print_attr_information($handle_res, $output = null): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_get_value(
	 $handle_res,
	 string $key,
	 ?string $subkey = null,
	 bool $attrcheck = true,
	 ?string $pass = null): string|false {}

/**
 * @param resource $handle_res
 */
function k2hpx_get_subkeys(
	 $handle_res,
	 string $key,
	 bool $attrcheck = true): array|false {}

/**
 * @param resource $handle_res
*/
function k2hpx_get_attrs(
	 $handle_res,
	 string $key): array|false {}

/**
 * @param resource $handle_res
 */
function k2hpx_get_attr_value(
	 $handle_res,
	 string $key,
	 string $attrkey): string|false {}

/**
 * @param resource $handle_res
 */
function k2hpx_set_value(
	 $handle_res,
	 string $key,
	 string $value,
	 ?string $subkey = null,
	 ?string $pass = null,
	 int $expire=0): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_add_subkey(
	 $handle_res,
	 string $key,
	 string $subkey): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_add_subkeys(
	 $handle_res,
	 string $key,
	 array $subkeys): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_add_attr(
 	 $handle_res,
	 string $key,
	 string $attrkey,
	 string $attrval): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_remove_all(
 	 $handle_res,
	 string $key): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_remove(
 	 $handle_res,
	 string $key,
	 ?string $subkey = null): bool {}

/**
 * @param resource $handle_res
 */
function k2hpx_rename(
 	 $handle_res,
	 string $key,
	 string $newkey): bool {}

/**
 * @return resource|false
 * @param resource $handle_res
 */
function k2hpx_find_first(
 	 $handle_res,
	 ?string $key = null) {}

/**
 * @return resource|false
 * @param resource $findhandle_res
 */
function k2hpx_find_next(
 	 $findhandle_res) {}

/**
 * @param resource $findhandle_res
 */
function k2hpx_find_free(
 	 $findhandle_res): bool {}

/**
 * @param resource $findhandle_res
 */
function k2hpx_find_get_key(
 	 $findhandle_res): string {}

/**
 * @param resource $findhandle_res
 */
function k2hpx_find_get_value(
 	 $findhandle_res): string {}

/**
 * @param resource $findhandle_res
 */
function k2hpx_find_get_subkeys(
 	 $findhandle_res): array|false {}

/**
 * @return resource|false
 * @param resource $handle_res
 */
function k2hpx_da_get_handle(
	 $handle_res,
	 string $key,
	 int $mode) {}

/**
 * @return resource|false
 * @param resource $handle_res
 */
function k2hpx_da_get_handle_read(
	 $handle_res,
	 string $key) {}

/**
 * @return resource|false
 * @param resource $handle_res
 */
function k2hpx_da_get_handle_write(
	 $handle_res,
	 string $key) {}

/**
 * @return resource|false
 * @param resource $handle_res
 */
function k2hpx_da_get_handle_rw(
	 $handle_res,
	 string $key) {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_free(
 	 $dahandle_res): bool {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_get_length(
 	 $dahandle_res): int|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_get_offset(
 	 $dahandle_res): array|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_get_read_offset(
 	 $dahandle_res): int|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_get_write_offset(
 	 $dahandle_res): int|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_set_offset(
 	 $dahandle_res,
	 array $offsets): int|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_set_read_offset(
 	 $dahandle_res,
	 int $offset): int|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_set_write_offset(
 	 $dahandle_res,
	 int $offset): int|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_get_value(
 	 $dahandle_res,
	 int $offset = -1): string|false {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_get_value_to_file(
 	 $dahandle_res,
 	 string $filepath,
	 int $length = -1,
	 int $offset = -1): bool {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_set_value(
 	 $dahandle_res,
 	 string $value,
	 int $offset = -1): bool {}

/**
 * @param resource $dahandle_res
 */
function k2hpx_da_set_value_from_file(
 	 $dahandle_res,
 	 string $filepath,
	 int $length = -1,
	 int $offset = -1): bool {}

/**
 * @return resource|false
 * @param resource $handle_res
 */
function k2hpx_q_handle(
	 $handle_res,
	 bool $is_filo = true,
	 ?string $prefix = null) {}

/**
 * @param resource $qhandle_res
 */
function k2hpx_q_free(
	 $qhandle_res): bool {}

/**
 * @param resource $qhandle_res
 */
function k2hpx_q_empty(
	 $qhandle_res): bool {}

/**
 * @param resource $qhandle_res
 */
function k2hpx_q_count(
	 $qhandle_res): int|false {}

/**
 * @param resource $qhandle_res
 */
function k2hpx_q_read(
	 $qhandle_res,
	 int $pos = 0,
	 ?string $pass = null): string|false {}

/**
 * @param resource $qhandle_res
 */
function k2hpx_q_push(
	 $qhandle_res,
	 string $datavalue,
	 ?string $pass = null,
	 int $expire = 0): bool {}

/**
 * @param resource $qhandle_res
 */
function k2hpx_q_pop(
	 $qhandle_res,
	 ?string $pass = null): string|false {}

/**
 * @param resource $qhandle_res
 */
function k2hpx_q_remove(
	 $qhandle_res,
	 int $count,
	 ?string $pass = null): bool {}

/**
 * @param resource $qhandle_res
 * @param resource $output
 */
function k2hpx_q_dump(
	 $qhandle_res,
	 $output = null): bool {}

/**
 * @return resource|false
 * @param resource $handle_res
 */
function k2hpx_keyq_handle(
	 $handle_res,
	 bool $is_filo = true,
	 ?string $prefix = null) {}

/**
 * @param resource $keyqhandle_res
 */
function k2hpx_keyq_free(
	 $keyqhandle_res): bool {}

/**
 * @param resource $keyqhandle_res
 */
function k2hpx_keyq_empty(
	 $keyqhandle_res): bool {}

/**
 * @param resource $keyqhandle_res
 */
function k2hpx_keyq_count(
	 $keyqhandle_res): int {}

/**
 * @param resource $keyqhandle_res
 */
function k2hpx_keyq_read(
	 $keyqhandle_res,
	 int $pos = 0,
	 ?string $pass = null): array|false {}

/**
 * @param resource $keyqhandle_res
 */
function k2hpx_keyq_push(
	 $keyqhandle_res,
	 string $key,
	 string $value,
	 ?string $pass = null,
	 int $expire = 0): bool {}

/**
 * @param resource $keyqhandle_res
 */
function k2hpx_keyq_pop(
	 $keyqhandle_res,
	 ?string $pass = null): array|false {}

/**
 * @param resource $keyqhandle_res
 */
function k2hpx_keyq_remove(
	 $keyqhandle_res,
	 int $count,
	 ?string $pass = null): bool {}

/**
 * @param resource $keyqhandle_res
 * @param resource $output
 */
function k2hpx_keyq_dump(
	 $keyqhandle_res,
	 $output = null): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_dump_head(
	 $handle_res,
	 $output = null): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_dump_keytable(
	 $handle_res,
	 $output = null): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_dump_full_keytable(
	 $handle_res,
	 $output = null): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_dump_elementtable(
	 $handle_res,
	 $output = null): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_dump_full(
	 $handle_res,
	 $output = null): bool {}

/**
 * @param resource $handle_res
 * @param resource $output
 */
function k2hpx_print_state(
	 $handle_res,
	 $output = null): bool {}

/**
 * @param resource $output
 */
function k2hpx_print_version(
	 $output = null): bool {}

class K2hash
{
	public static function create(
		string $filepath,
		int $maskbitcnt = 8,
		int $cmaskbitcnt = 4,
		int $maxelementcnt = 32,
		int $pagesize = 4096): bool {}

	public function open(
		string $filepath,
		bool $readonly,
		bool $removefile = false,
		bool $fullmap = true,
		int $maskbitcnt = 8,
		int $cmaskbitcnt = 4,
		int $maxelementcnt = 32,
		int $pagesize = 4096): bool {}

	public function openRW(
		string $filepath,
		bool $fullmap = true,
		int $maskbitcnt = 8,
		int $cmaskbitcnt = 4,
		int $maxelementcnt = 32,
		int $pagesize = 4096): bool {}

	public function openRO(
		string $filepath,
		bool $fullmap = true,
		int $maskbitcnt = 8,
		int $cmaskbitcnt = 4,
		int $maxelementcnt = 32,
		int $pagesize = 4096): bool {}

	public function openTempfile(
		string $filepath,
		bool $fullmap = true,
		int $maskbitcnt = 8,
		int $cmaskbitcnt = 4,
		int $maxelementcnt = 32,
		int $pagesize = 4096): bool {}

	public function openMem(
		int $maskbitcnt = 8,
		int $cmaskbitcnt = 4,
		int $maxelementcnt = 32,
		int $pagesize = 4096): bool {}

	public function close(int $waitms = 0): bool {}

	public function transaction(
		bool $enable, 
		string $transfile= null,
		string $prefix= null,
		string $param= null,
		int $expire = 0): bool {}

	public function enableTransaction(
		string $transfile= null,
		string $prefix= null,
		string $param= null,
		int $expire = 0): bool {}

	public function disableTransaction(): bool {}

	public static function getTransactionThreadPool(): int {}

	public static function setTransactionThreadPool(int $count): bool {}

	public static function unsetTransactionThreadPool(): bool {}

	public function putArchive(string $filepath, bool $errskip = true): bool {}

	public function loadArchive(string $filepath, bool $errskip = true): bool {}

	public function setCommonAttribute(
		int $is_mtime = -1,
		int $is_history = -1,
		int $is_encrypt = -1,
		string $passfile = null,
		int $is_expire = -1,
		int $expire = 0): bool {}

	public function cleanCommonAttribute(): bool {}

	public function addAttrPluginLib(string $libfile): bool {}

	public function addAttrCryptPass(string $encpass, bool $is_default_encrypt = false): bool {}

	/**
	* @param resource $output
	*/
	public function getAttrVersionInfos($output = null): bool {}

	/**
	* @param resource $output
	*/
	public function getAttrInfos($output = null): bool {}

	public function getValue(
		string $key,
		string $subkey = null,
		bool $attrcheck = true,
		string $pass = null): string|false {}

	public function getSubkeys(string $key, bool $attrcheck = true): array|false {}

	public function getAttrs(string $key): array|false {}

	public function getAttrValue(string $key, string $attrkey): string|false {}

	public function setValue(
		string $key,
		string $value,
		string $subkey = null,
		string $pass = null,
		int $expire=0): bool {}

	public function addSubkey(string $key, string $subkey): bool {}

	public function addSubkeys(string $key, array $subkeys): bool {}

	public function addAttr(
		string $key,
		string $attrkey,
		string $attrval): bool {}

	public function removeAll(string $key): bool {}

	public function remove(string $key, string $subkey = null): bool {}

	public function rename(string $key, string $newkey): bool {}

	/**
	* @return resource|false
	*/
	public function getIterator(string $key) {}

	/**
	* @return resource|false
	*/
	public function getStream(string $key, string $mode) {}

	/**
	* @return resource|false
	*/
	public function getQueue(bool $is_filo = true, string $prefix = null) {}

	/**
	* @return resource|false
	*/
	public function getKeyQueue(bool $is_filo = true, string $prefix = null) {} 

	/**
	* @param resource $output
	*/
	public function dumpHead($output = null): bool {}

	/**
	* @param resource $output
	*/
	public function dumpKeytable($output = null): bool {}

	/**
	* @param resource $output
	*/
	public function dumpFullKeytable($output = null): bool {}

	/**
	* @param resource $output
	*/
	public function dumpElementtable($output = null): bool {}

	/**
	* @param resource $output
	*/
	public function dumpFull($output = null): bool {}

	/**
	* @param resource $output
	*/
	public function printState($output = null): bool {}

	/**
	* @param resource $output
	*/
	public static function printVersion($output = null): bool {}
}

class K2hQueue
{
	/**
	* @param resource $handle_res
	*/
	public function __construct($handle_res, bool $is_fifo = true, string $prefix = null) {}
	/* }}} */

	public function isEmpty(): bool {}

	public function count(): int|false {}

	public function read(int $pos = 0, string $pass = null): string|false {}

	public function push(
		string $datavalue,
		string $pass = null,
		int $expire = 0): bool {}
	 
	public function pop(string $pass = null): string|false {}

	public function remove(int $count, string $pass = null): bool {}

	/**
	* @param resource $output
	*/
	public function dump($output = null): bool {}
}

class K2hKeyQueue
{
	/**
	* @param resource $handle_res
	*/
	public function __construct($handle_res, bool $is_fifo = true, string $prefix = null) {}

	public function isEmpty(): bool {}

	public function count(): int {}

	public function read(int $pos = 0, string $pass = null): array|false {}

	public function push(
		string $key,
		string $value,
		string $pass = null,
		int $expire = 0): bool {}

	public function pop(string $pass = null): array|false {}

	public function remove(int $count, string $pass = null): bool {}

	/**
	* @param resource $output
	*/
	public function dump($output = null): bool {}
}

class K2hIterator
{
	/**
	* @param resource $handle_res
	*/
	public function __construct($handle_res, string $key = null) {}

	public function current(): string|false {}

	public function key(): string|false {}

	public function next(): void {}

	public function rewind(): void {}

	public function valid(): bool {}
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
