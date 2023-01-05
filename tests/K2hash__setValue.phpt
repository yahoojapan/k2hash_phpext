--TEST--
K2hash::setValue() member function
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
// normal
$k2hash->setValue("test", "value");
$value = $k2hash->getValue("test");
if(false === $value || $value != "value"){
	$k2hash->close();
	echo "NG";
}

// encrypt
$k2hash->setValue("test2", "value", '', "testencryptkey");
$value = $k2hash->getValue("test2", '', true, "testencryptkey");
if(false === $value || $value != "value"){
	$k2hash->close();
	echo "NG";
}

// expire
$k2hash->setValue("test3", "value", '', '', 1);
sleep(2);	// sleep for expire
$value = $k2hash->getValue("test3");
if(false !== $value){
	$k2hash->close();
	echo "NG";
}

// subkey normal
$k2hash->setValue("test4", "value", "subkey1");
$value = $k2hash->getValue("test4", "subkey1");
if(false === $value || $value != "value"){
	$k2hash->close();
	echo "NG";
}

// subkey encrypt
$k2hash->setValue("test5", "value", "subkey2", "testencryptkey");
$value = $k2hash->getValue("test5", "subkey2", true, "testencryptkey");
if(false === $value || $value != "value"){
	$k2hash->close();
	echo "NG";
}

// subkey expire
$k2hash->setValue("test6", "value", "subkey3", '', 1);
sleep(2);	// sleep for expire
$value = $k2hash->getValue("test6", "subkey3");
if(false !== $value){
	$k2hash->close();
	echo "NG";
}

$k2hash->close();
echo "OK";
?>
--EXPECT--
OK
