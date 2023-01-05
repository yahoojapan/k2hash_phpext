--TEST--
k2hpx_keyq_remove() function
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
$keyqhandle = k2hpx_keyq_handle($handle, true, "test_queue_");
if(false === $keyqhandle){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!k2hpx_keyq_push($keyqhandle, "test_queue_key", "test_queue_value")){
	k2hpx_keyq_free($keyqhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!k2hpx_keyq_remove($keyqhandle, 1)){
	k2hpx_keyq_free($keyqhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
k2hpx_keyq_free($keyqhandle);

// pass phrase
$keyqhandle = k2hpx_keyq_handle($handle, true, "test_queue2_");
if(false === $keyqhandle){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!k2hpx_keyq_push($keyqhandle, "test_queue2_key", "test_queue_value", "testqueuekey")){
	k2hpx_keyq_free($keyqhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!k2hpx_keyq_remove($keyqhandle, 1, "testqueuekey")){
	k2hpx_keyq_free($keyqhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
k2hpx_keyq_free($keyqhandle);

k2hpx_close($handle);
echo "OK";
?>
--EXPECT--
OK
