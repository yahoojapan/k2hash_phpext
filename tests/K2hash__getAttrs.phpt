--TEST--
K2hash::getAttrs() member function
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
$k2hash = new K2hash();
if(!$k2hash->openMem()){
	echo "NG";
	exit;
}
$k2hash->setValue("test", "value");
$k2hash->addAttr("test", "testattr", "testattrvalue");
if(false == ($attrs = $k2hash->getAttrs("test"))){
	$k2hash->close();
	echo "NG";
}
if(!is_array($attrs)){
	$k2hash->close();
	echo "NG";
	exit;
}
foreach($attrs as $getattr){
	if($getattr != "testattr"){
		$k2hash->close();
		echo "NG";
		exit;
	}
}
$k2hash->close();
echo "OK";
?>
--EXPECT--
OK
