---
layout: contents
language: en-us
title: k2hpx_keyq_free
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_freeja.html
lang_opp_word: To Japanese
prev_url: k2hpx_keyq_empty.html
prev_string: k2hpx_keyq_empty
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_keyq_handle.html
next_string: k2hpx_keyq_handle
---

# k2hpx_keyq_free
Frees resources of the K2hKeyQueue handle

## Description
```
bool k2hpx_keyq_free ( mixed $keyqhandle_res )
```
Frees resources of the [K2hKeyQueue](k2hkq_class.html) file handle. 

## Parameters
- keyqhandle_res  
Specifies the [K2hKeyQueue](k2hkq_class.html) file handle that [k2hpx_keyq_handle](k2hpx_keyq_handle.html) returns.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Frees resource of the [K2hKeyQueue](k2hkq_class.html) file handle
```
<?php
$handle = k2hpx_open_mem();
$keyqhandle = k2hpx_keyq_handle($handle, true, "test_queue_");
var_dump(k2hpx_keyq_free($keyqhandle));
k2hpx_close($handle);
?>
```
The above example will output:
```
bool(true)
```
