--TEST--
k2hpx_q_dump() function
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
$handle = k2hpx_open_mem();
$qhandle = k2hpx_q_handle($handle, true, "test_queue_");
if(false !== $qhandle){
	if(k2hpx_q_push($qhandle, "test_queue_data")){
		$fp = fopen("/tmp/k2hash_q_dump.log", 'w');
		if(false !== k2hpx_q_dump($qhandle, $fp)){
			echo "OK";
		}else{
			echo "NG";
		}
		fclose($fp);
	}else{
		echo "NG";
	}
	k2hpx_q_free($qhandle);
}else{
	echo "NG";
}
k2hpx_close($handle);
?>
--EXPECT--
OK
