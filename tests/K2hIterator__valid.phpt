--TEST--
K2hIterator::valid() member function
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
k2hpx_set_value($handle, "test", "value");

$k2hiter = new K2hIterator($handle);
$k2hiter->next();
if($k2hiter->valid()){
	echo "NG";
}else{
	echo "OK";
}
unset($k2hiter);
k2hpx_close($handle);
?>
--EXPECT--
OK
