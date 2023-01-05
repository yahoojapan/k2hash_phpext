--TEST--
K2hash::getQueue() member function
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
$k2hash = new K2hash();
if(!$k2hash->openMem()){
	echo "NG";
	exit;
}
$k2hqueue = $k2hash->getQueue();

if($k2hqueue->push("test_queue_data")){
	$value = $k2hqueue->pop();
	if($value == "test_queue_data"){
		echo "OK";
	}else{
		echo "NG";
	}
}else{
	echo "NG";
}
unset($k2hqueue);
$k2hash->close();
?>
--EXPECT--
OK
