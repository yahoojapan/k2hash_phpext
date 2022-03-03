---
layout: contents
language: en-us
title: K2hash::printVersion
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_printversionja.html
lang_opp_word: To Japanese
prev_url: k2h_printstate.html
prev_string: K2hash::printState
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_putarchive.html
next_string: K2hash::putArchive
---

# K2hash::printVersion
Prints the k2hash library version

## Description
```
 public static bool K2hash::printVersion ([ mixed $output ] )
```
Prints the k2hash library version. 

## Parameters
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure

## Examples
- Example 1 - Prints the library version
```
<?php
$k2hash = new K2hash();
$fp = fopen("/tmp/k2hash_print_version.log", 'w');
$k2hash->printVersion($fp);
fclose($fp);

$fp = fopen("/tmp/k2hash_print_version.log", 'r');
if ($fp) {
        while (!feof($fp)) {
                if (($buf = fgets($fp, 4096)) !== false) {
                        echo $buf;
                }
        }
        fclose($fp);
}
?>
```
The above example will output:
```
K2HASH library Version 1.0.83 (commit: 143975d) with NSS

Copyright(C) 2013 Yahoo Japan Corporation.

K2HASH is key-valuew store base libraries. K2HASH is made for
the purpose of the construction of original KVS system and the
offer of the library. The characteristic is this KVS library
which Key can layer. And can support multi-processing and
multi-thread, and is provided safely as available KVS.


FULLOCK Version 1.0.44 (commit: 20ce073)

Copyright(C) 2015 Yahoo Japan Corporation.

FULLOCK is fast locking library on user level by Yahoo! JAPAN.
FULLOCK is following specifications.
```
