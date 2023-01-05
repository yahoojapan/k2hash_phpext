--TEST--
k2hpx_load_transaction_library() function
--DESCRIPTION--
K2HASH PHP Extension library

Copyright 2015 Yahoo Japan Corporation.

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

if(!file_exists("/usr/lib/libk2htesttrans.so") && !file_exists("/usr/lib/x86_64-linux-gnu/libk2htesttrans.so")){
	die("skip testing load transaction function, because test transaction library does not exist.");
}
?>
--FILE--
<?php
if(file_exists("/usr/lib/libk2htesttrans.so") && k2hpx_load_transaction_library("/usr/lib/libk2htesttrans.so")){
	echo "OK";
}else if(file_exists("/usr/lib/x86_64-linux-gnu/libk2htesttrans.so") &&  k2hpx_load_transaction_library("/usr/lib/x86_64-linux-gnu/libk2htesttrans.so")){
	echo "OK";
}else{
	echo "NG";
}
?>
--EXPECT--
OK
