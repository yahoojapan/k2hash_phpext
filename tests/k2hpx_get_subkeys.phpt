--TEST--
k2hpx_get_subkeys() function
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
$handle = k2hpx_open_mem();
// normal
$putsubkeys = array("subkey1", "subkey2", "subkey3");
if(!k2hpx_add_subkeys($handle, "test", $putsubkeys)){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(false === ($getsubkeys = k2hpx_get_subkeys($handle, "test"))){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!is_array($getsubkeys) || count($putsubkeys) != count($getsubkeys)){
	k2hpx_close($handle);
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
		k2hpx_close($handle);
		echo "NG";
		exit;
	}
}
// expire key
if(!k2hpx_set_value($handle, "test2", "value", '', '', 1)){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!k2hpx_add_subkey($handle, "test2", "subkey4")){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
sleep(2);	// sleep for expire
$getsubkeys = k2hpx_get_subkeys($handle, "test2");
if(is_array($getsubkeys)){
	foreach($getsubkeys as $getvalue){
		if($getvalue == "subkey4"){
			k2hpx_close($handle);
			echo "NG";
			exit;
		}
	}
}
k2hpx_close($handle);
echo "OK";
?>
--EXPECT--
OK
