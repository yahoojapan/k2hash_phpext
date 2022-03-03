--TEST--
k2hpx_print_version() function
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
?>
--FILE--
<?php
$fp = fopen("/tmp/k2hash_print_version.log", 'w');
if(false !== k2hpx_print_version($fp)){
	echo "OK";
}else{
	echo "NG";
}
fclose($fp);
?>
--EXPECT--
OK
