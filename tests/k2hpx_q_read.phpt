--TEST--
k2hpx_q_read() function
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
$qhandle = k2hpx_q_handle($handle, true, "test_queue_");
if(false === $qhandle){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!k2hpx_q_push($qhandle, "test_queue_data")){
	k2hpx_q_free($qhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(false === ($value = k2hpx_q_read($qhandle, 0))){
	k2hpx_q_free($qhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
k2hpx_q_free($qhandle);

// pass phrase
$qhandle = k2hpx_q_handle($handle, true, "test_queue2_");
if(false === $qhandle){
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(!k2hpx_q_push($qhandle, "test_queue2_data", "testqueuekey")){
	k2hpx_q_free($qhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if(false === ($value = k2hpx_q_read($qhandle, 0, "testqueuekey"))){
	k2hpx_q_free($qhandle);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
k2hpx_q_free($qhandle);

k2hpx_close($handle);
echo "OK";
?>
--EXPECT--
OK
