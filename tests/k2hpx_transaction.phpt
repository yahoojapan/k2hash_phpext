--TEST--
k2hpx_transaction() function
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
// must set transfile for default transaction plugin
if(k2hpx_transaction($handle, true, "/tmp/test_k2h_trans")){
	if(k2hpx_transaction($handle, true, "/tmp/test_k2h_trans", "trans_queue_", "myparam")){
		echo "OK";
	}else{
		echo "NG";
	}
}else{
	echo "NG";
}
k2hpx_close($handle);
?>
--EXPECT--
OK
