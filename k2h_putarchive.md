---
layout: contents
language: en-us
title: K2hash::putArchive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_putarchiveja.html
lang_opp_word: To Japanese
prev_url: k2h_printversion.html
prev_string: K2hash::printVersion
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_remove.html
next_string: K2hash::remove
---

# K2hash::putArchive
Saves data as the archive file

## Description
```
 public bool K2hash::putArchive ( string $filepath [, bool $errskip ] )
```
Saves the k2hash (`.k2h`) file as an archive file. 

## Parameters
- filepath  
Specifies the path to an archive file.
- errskip  
Specifies true if a dump process continues on errors.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Saves data as the archive file
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("key1", "value1");
var_dump($k2hash->putArchive("/tmp/test_k2h_archive", true));
$k2hash->close();

$k2hash2 = new K2hash();
$k2hash2->openMem();
$k2hash2->loadArchive("/tmp/test_k2h_archive", true);
var_dump($k2hash2->getValue("key1"));
$k2hash2->close();
?>
```
The above example will output:
```
bool(true)
string(6) "value1"
```

## See Also
- [K2hash::loadArchive](k2h_loadarchive.html) - Loads data from the file
