--TEST--
K2hash::remove() member function
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
if(!$k2hash->setValue("test1", "value") || !$k2hash->setValue("sub1", "sub-value") || !$k2hash->addSubkey("test1", "sub1")){
	$k2hash->close();
	echo "NG";
	exit;
}
if(!$k2hash->remove("test1", "sub1") || "value" != $k2hash->getValue("test1") || false !== $k2hash->getValue("sub1")){
	$k2hash->close();
	echo "NG";
	exit;
}

if(!$k2hash->setValue("test2", "value") || !$k2hash->setValue("sub2", "sub-value") || !$k2hash->addSubkey("test2", "sub2")){
	$k2hash->close();
	echo "NG";
	exit;
}
if(!$k2hash->remove("test2") || false !== $k2hash->getValue("test2") || "sub-value" !== $k2hash->getValue("sub2")){
	echo "NG";
}else{
	echo "OK";
}
$k2hash->close();
?>
--EXPECT--
OK
