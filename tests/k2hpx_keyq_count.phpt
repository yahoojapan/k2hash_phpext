--TEST--
k2hpx_keyq_count() function
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
$keyqhandle = k2hpx_keyq_handle($handle, true, "test_queue_");
if(false !== $keyqhandle){
	$count = k2hpx_keyq_count($keyqhandle);
	if(0 == $count){
		echo "OK";
	}else{
		echo "NG";
	}
	k2hpx_keyq_free($keyqhandle);
}else{
	echo "NG";
}
k2hpx_close($handle);
?>
--EXPECT--
OK
