--TEST--
K2hash::getIterator() member function
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
$k2hash->setValue("test1", "value1");
$k2hash->setValue("test2", "value2");
$k2hash->setValue("test3", "value3");

$iterator = $k2hash->getIterator();
$count = 0;
foreach($iterator as $val){
	$count++;
}
unset($iterator);

$k2hash->setValue("parent", "sub-value1", "child1");
$k2hash->setValue("parent", "sub-value2", "child2");
$k2hash->setValue("parent", "sub-value3", "child3");

$iterator = $k2hash->getIterator("parent");
$pcount = 0;

foreach($iterator as $val){
	$pcount++;
}
unset($iterator);

if(3 == $count && 3 == $pcount){
	echo "OK";
}else{
	echo "NG";
}
$k2hash->close();
?>
--EXPECT--
OK
