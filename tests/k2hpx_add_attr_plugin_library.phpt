--TEST--
k2hpx_add_attr_plugin_library() function
--DESCRIPTION--
K2HASH PHP Extension library

Copyright 2015 Yahoo! JAPAN corporation.

K2HASH is key-valuew store base libraries.
K2HASH is made for the purpose of the construction of
original KVS system and the offer of the library.
The characteristic is this KVS library which Key can
layer. And can support multi-processing and multi-thread,
and is provided safely as available KVS.

For the full copyright and license information, please view
the LICENSE file that was distributed with this source code.
--SKIPIF--
<?php 
if(!extension_loaded('k2hash')) die('skip ');

if(!file_exists("/tmp/libk2htestattr.so")){
	die("skip testing load plugin attribute library function, because test file does not exist.");
}
?>
--FILE--
<?php
$handle = k2hpx_open_mem();
if(k2hpx_add_attr_plugin_library($handle, "/tmp/libk2htestattr.so")){
	echo "OK";
}else{
	echo "NG";
}
k2hpx_close($handle);
?>
--EXPECT--
OK
