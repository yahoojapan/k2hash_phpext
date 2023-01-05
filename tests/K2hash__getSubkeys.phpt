--TEST--
K2hash::getSubkeys() member function
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
$putsubkeys = array("subkey1", "subkey2", "subkey3");
$k2hash->addSubkeys("test", $putsubkeys);

$getsubkeys = $k2hash->getSubkeys("test");
if(!is_array($getsubkeys) || count($putsubkeys) != count($getsubkeys)){
	$k2hash->close();
	echo "NG";
	exit;
}
foreach($getsubkeys as $getvalue){
	$isFound = false;
	foreach($putsubkeys as $putvalue){
		if($getvalue == $putvalue){
			$isFound = true;
			break;
		}
	}
	if(false == $isFound){
		$k2hash->close();
		echo "NG";
		exit;
	}
}

// expire key
$getsubkeys = $k2hash->setValue("test2", "value", '', '', 1);
$putsubkeys = array("subkey4");
$k2hash->addSubkeys("test2", $putsubkeys);
sleep(2);	// sleep for expire

$getsubkeys = $k2hash->getSubkeys("test2");
if(is_array($getsubkeys)){
	foreach($getsubkeys as $getvalue){
		if($getvalue == "subkey4"){
			$k2hash->close();
			echo "NG";
			exit;
		}
	}
}
$k2hash->close();
echo "OK";
?>
--EXPECT--
OK
