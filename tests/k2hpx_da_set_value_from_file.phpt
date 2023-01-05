--TEST--
k2hpx_da_set_value_from_file() function
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
if(!file_exists("/tmp/test_k2hash_da_set_value")){
	file_put_contents("/tmp/test_k2hash_da_set_value", "file_file_file_file_file");
}
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test", "value");
$dahandle = k2hpx_da_get_handle_rw($handle, "test");
if(false !== $dahandle){
	if(false !== k2hpx_da_set_value_from_file($dahandle, "/tmp/test_k2hash_da_set_value", 20)){
		echo "OK";
	}else{
		echo "NG";
	}
	k2hpx_da_free($dahandle);
}else{
	echo "NG";
}
k2hpx_close($handle);
?>
--EXPECT--
OK
