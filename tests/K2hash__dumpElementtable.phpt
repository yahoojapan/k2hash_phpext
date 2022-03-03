--TEST--
K2hash::dumpElementtable() member function
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
if(!file_exists("/tmp/test_k2hash.k2h")){
	K2hash::create("/tmp/test_k2hash.k2h");
}
$k2hash = new K2hash();
if($k2hash->openRO("/tmp/test_k2hash.k2h")){
	$fp = fopen("/tmp/k2hash_dump_elementtable.log", 'w');
	if($k2hash->dumpElementtable($fp)){
		echo "OK";
	}else{
		echo "NG";
	}
	fclose($fp);
	$k2hash->close();
}else{
	echo "NG";
}
?>
--EXPECT--
OK
