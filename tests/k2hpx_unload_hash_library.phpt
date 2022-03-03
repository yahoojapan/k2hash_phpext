--TEST--
k2hpx_unload_hash_library() function
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

if(!file_exists("/usr/lib/libk2htesthash.so") && !file_exists("/usr/lib/x86_64-linux-gnu/libk2htesthash.so")){
	die("skip testing load hash function, because test hash library does not exist.");
}
?>
--FILE--
<?php
if(file_exists("/usr/lib/libk2htesthash.so") && !k2hpx_load_hash_library("/usr/lib/libk2htesthash.so")){
	echo "NG";
	exit;
}else if(file_exists("/usr/lib/x86_64-linux-gnu/libk2htesthash.so") && !k2hpx_load_hash_library("/usr/lib/x86_64-linux-gnu/libk2htesthash.so")){
	echo "NG";
	exit;
}
if(k2hpx_unload_hash_library()){
	echo "OK";
}else{
	echo "NG";
}
?>
--EXPECT--
OK
