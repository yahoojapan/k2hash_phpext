---
layout: contents
language: en-us
title: K2hash::loadArchive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_loadarchiveja.html
lang_opp_word: To Japanese
prev_url: k2h_getvalue.html
prev_string: K2hash::getValue
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_open.html
next_string: K2hash::open
---

# K2hash::loadArchive
Loads data from the file

## Description
```
 public bool K2hash::loadArchive ( string $filepath [, bool $errskip ] )
```
Loads data from the file. The file should be either a transaction file or an archive file. 

## Parameters
- filepath  
Specifies a file to load.
- errskip  
Specifies true if continue loading data on errors.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Creates an archive file and loads it
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
- [K2hash::enableTransaction](k2h_enabletransaction.html) - Starts a transaction
- [K2hash::putArchive](k2h_putarchive.html) - Saves data as the archive file
- [K2hash::transaction](k2h_transaction.html) - Changes transaction settings
