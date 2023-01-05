--TEST--
K2hash::openRO() member function
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
?>
--FILE--
<?php
if(!file_exists("/tmp/test_k2hash.k2h")){
	if(!K2hash::create("/tmp/test_k2hash.k2h")){
		echo "NG";
		exit;
	}
}
$k2hash = new K2hash();
if($k2hash->openRO("/tmp/test_k2hash.k2h")){
	$k2hash->close();
	echo "OK";
}else{
	echo "NG";
}
?>
--EXPECT--
OK
