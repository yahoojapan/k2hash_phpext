---
layout: contents
language: en-us
title: K2hash::close
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_closeja.html
lang_opp_word: To Japanese
prev_url: k2h_cleancommonattribute.html
prev_string: K2hash::cleanCommonAttribute
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_create.html
next_string: K2hash::create
---

# K2hash::close
Closes the k2hash file

## Description

```
 public bool K2hash::close ([ int $waitms ] )
```

Closes the k2hash (.k2h) file handle internally opened by K2hash::open and saves the data. 

## Parameters
- waitms  
Specifies microseconds to wait before closing the k2h file.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Closes a k2hash file

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->close());
?>
```

The above example will output:

```
bool(true)
```


## See Also
- [K2hash::open](k2h_open.html) - Opens the k2h file
- [K2hash::openMem](k2h_openmem.html) - Attaches k2hash data segments on memory
- [K2hash::openRO](k2h_openro.html) - Read the k2hash file
- [K2hash::openRW](k2h_openrw.html) - Edit the k2hash file
- [K2hash::openTempfile](k2h_opentempfile.html) - Edit the k2hash file on temporary file system
