--TEST--
k2hpx_set_value() function
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
if(!k2hpx_set_value($handle, "test", "value")){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(false === ($value = k2hpx_get_value($handle, "test")) || $value != "value"){
	k2hpx_close($handle);
	echo "NG";
	exit;
}

// encrypted value
if(!k2hpx_set_value($handle, "test2", "value", '', "testencryptkey")){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(false === ($value = k2hpx_get_value($handle, "test2", '', true, "testencryptkey")) || $value != "value"){
	k2hpx_close($handle);
	echo "NG";
	exit;
}

// expire value
if(!k2hpx_set_value($handle, "test3", "value", '', '', 1)){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
sleep(2);	// sleep for expire
if(false !== ($value = k2hpx_get_value($handle, "test3"))){
	k2hpx_close($handle);
	echo "NG";
	exit;
}

// subkey normal
if(!k2hpx_set_value($handle, "test4", "value", "subkey1")){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(false === ($value = k2hpx_get_value($handle, "test4", "subkey1")) || $value != "value"){
	k2hpx_close($handle);
	echo "NG";
	exit;
}

// subkey encrypted value
if(!k2hpx_set_value($handle, "test5", "value", "subkey2", "testencryptkey")){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(false === ($value = k2hpx_get_value($handle, "test5", "subkey2", true, "testencryptkey")) || $value != "value"){
	k2hpx_close($handle);
	echo "NG";
	exit;
}

// expire value
if(!k2hpx_set_value($handle, "test6", "value", "subkey3", '', 1)){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
sleep(2);	// sleep for expire
if(false !== ($value = k2hpx_get_value($handle, "test6", "subkey3"))){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
k2hpx_close($handle);
echo "OK";
?>
--EXPECT--
OK
