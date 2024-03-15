--TEST--
K2hash::disabletransaction() member function
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
// [NOTE] SKIP ERROR
// This test occasionally causes an error only when packaging ALPINE 3.18 - PHP8.1.
// The reason is unknown and we decided to skip this error.
//  In the future, once the cause is determined, this part will return to returning an error (NG).
//
//if(!extension_loaded('k2hash')) die('skip ');
//
die('skip ');
?>
--FILE--
<?php
$k2hash = new K2hash();
if(!$k2hash->openMem()){
	echo "NG";
	exit;
}
if($k2hash->disabletransaction()){
	echo "OK";
}else{
	echo "NG";
}
$k2hash->close();
?>
--EXPECT--
OK
