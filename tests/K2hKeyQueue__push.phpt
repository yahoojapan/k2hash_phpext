--TEST--
K2hKeyQueue::push() member function
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
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
if(!$k2hkeyqueue->push("test_queue_key", "test_queue_value")){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
$popedkeyval = $k2hkeyqueue->read(0);
if(!is_array($popedkeyval) || count($popedkeyval) != 2){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if($popedkeyval[0] != "test_queue_key" || $popedkeyval[1] != "test_queue_value"){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
unset($k2hkeyqueue);

// encrypt
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue2_");
if(!$k2hkeyqueue->push("test_queue2_key", "test_queue_value", "testqueuekey")){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
$popedkeyval = $k2hkeyqueue->read(0, "testqueuekey");
if(!is_array($popedkeyval) || count($popedkeyval) != 2){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
if($popedkeyval[0] != "test_queue2_key" || $popedkeyval[1] != "test_queue_value"){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
unset($k2hkeyqueue);

// expire
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue3_");
if(!$k2hkeyqueue->push("test_queue3_key", "test_queue_value", '', 1)){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
sleep(2);	// for expire
$popedkeyval = $k2hkeyqueue->read(0);
if(is_array($popedkeyval)){
	unset($k2hkeyqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
unset($k2hkeyqueue);

k2hpx_close($handle);
echo "OK";
?>
--EXPECT--
OK
