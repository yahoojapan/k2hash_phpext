--TEST--
K2hash::getStream() member function
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
if(file_exists("/tmp/test_k2hash.k2h")){
	unlink("/tmp/test_k2hash.k2h");
}
if(!K2hash::create("/tmp/test_k2hash.k2h")){
	echo "NG";
	exit;
}

//------------------------
// K2hash::getStream
//------------------------
$k2hash = new K2hash();
if(!$k2hash->openRW("/tmp/test_k2hash.k2h")){
	echo "NG";
	exit;
}
$k2hash->setValue("test1", "value1");
$k2hash->setValue("test2", "value2");
$k2hash->setValue("test3", "value3");

// "r+" mode
if(null == ($stream = $k2hash->getStream("test1", "r+"))){
	$k2hash->close();
	echo "NG";
	exit;
}
$val3 = fread($stream, 3);
if("val" != $val3){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
if(false === fwrite($stream, "-changed-1")){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fseek($stream, 0);
$val13 = fread($stream, 13);
if("val-changed-1" != $val13){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fclose($stream);

// "w+" mode
if(null == ($stream = $k2hash->getStream("test2", "w+"))){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
if(false === fwrite($stream, "val-changed-2")){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fseek($stream, 0);
$val13 = fread($stream, 13);
if("val-changed-2" != $val13){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fclose($stream);

// "a+" mode
if(null == ($stream = $k2hash->getStream("test3", "a+"))){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fseek($stream, -1,  SEEK_END);
if(false === fwrite($stream, "-changed-3")){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fseek($stream, 0);
$val16 = fread($stream, 16);
if("value3-changed-3" != $val16){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fclose($stream);

// "c+" mode
if(null == ($stream = $k2hash->getStream("test4", "c+"))){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
if(false === fwrite($stream, "val-changed-4")){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fseek($stream, 0);
$val13 = fread($stream, 13);
if("val-changed-4" != $val13){
	fclose($stream);
	$k2hash->close();
	echo "NG";
	exit;
}
fclose($stream);
$k2hash->close();

//------------------------
// check for open stream directly
//------------------------
// normal(r+)
if(false === ($stream = fopen("k2h:///tmp/test_k2hash.k2h#test1", "r+"))){
	echo "NG";
	exit;
}
$val3 = fread($stream, 3);
if("val" != $val3){
	fclose($stream);
	echo "NG";
	exit;
}
if(false === fwrite($stream, "-fopened-1")){
	fclose($stream);
	echo "NG";
	exit;
}
fseek($stream, 0);
$val13 = fread($stream, 13);
if("val-fopened-1" != $val13){
	fclose($stream);
	echo "NG";
	exit;
}
fclose($stream);

// with opend handle(w+)
if(false === ($k2hhandle = k2hpx_open_rw("/tmp/test_k2hash.k2h"))){
	echo "NG";
	exit;
}
$ctx = stream_context_create(array('k2h' => array('k2hhandle' => $k2hhandle, 'fullmap' => true)));
if(false === ($stream = fopen("k2h:///tmp/test_k2hash.k2h#test2", "w+", false, $ctx))){
	k2hpx_close($k2hhandle);
	echo "NG";
	exit;
}
if(false === fwrite($stream, "val-fopened-2")){
	fclose($stream);
	k2hpx_close($k2hhandle);
	echo "NG";
	exit;
}
fseek($stream, 0);
$val13 = fread($stream, 13);
if("val-fopened-2" != $val13){
	fclose($stream);
	k2hpx_close($k2hhandle);
	echo "NG";
	exit;
}
fclose($stream);
k2hpx_close($k2hhandle);

// new create file(c+)
if(file_exists("/tmp/test_fp_k2hash.k2h")){
	unlink("/tmp/test_fp_k2hash.k2h");
}
$ctx = stream_context_create(array('k2h' => array(	'fullmap'		=> true,
													'maskbitcnt'	=> K2H_DEF_MASK_BIT,
													'cmaskbitcnt'	=> K2H_DEF_CMASK_BIT,
													'maxelementcnt'	=> K2H_DEF_ELEMENT,
													'pagesize'		=> K2H_DEF_PAGESIZE)));
if(false === ($stream = fopen("k2h:///tmp/test_fp_k2hash.k2h#test", "c+", false, $ctx))){
	echo "NG";
	exit;
}
if(false === fwrite($stream, "new_value")){
	fclose($stream);
	echo "NG";
	exit;
}
fseek($stream, 0);
$val9 = fread($stream, 9);
if("new_value" != $val9){
	fclose($stream);
	echo "NG";
	exit;
}
fclose($stream);

echo "OK";
?>
--EXPECT--
OK
