--TEST--
K2hQueue::push() member function
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
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
if(!$k2hqueue->push("test_queue_data")){
	unset($k2hqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
$value = $k2hqueue->read(0);
if($value != "test_queue_data"){
	unset($k2hqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
unset($k2hqueue);

// encrypt
$k2hqueue = new K2hQueue($handle, true, "test_queue2_");
if(!$k2hqueue->push("test_queue_data", "testqueuekey")){
	unset($k2hqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
$value = $k2hqueue->read(0, "testqueuekey");
if($value != "test_queue_data"){
	unset($k2hqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
unset($k2hqueue);

// expire
$k2hqueue = new K2hQueue($handle, true, "test_queue3_");
if(!$k2hqueue->push("test_queue_data", '', 1)){
	unset($k2hqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
sleep(2);	// for expire
if(false !== ($value = $k2hqueue->read(0))){
	unset($k2hqueue);
	k2hpx_close($handle);
	echo "NG";
	exit;
}
unset($k2hqueue);

k2hpx_close($handle);
echo "OK";
?>
--EXPECT--
OK
