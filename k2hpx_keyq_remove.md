---
layout: contents
language: en-us
title: k2hpx_keyq_remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_removeja.html
lang_opp_word: To Japanese
prev_url: k2hpx_keyq_read.html
prev_string: k2hpx_keyq_read
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_load_archive.html
next_string: k2hpx_load_archive
---

# k2hpx_keyq_remove
Removes a key/value pair from the K2hKeyQueue

## Description
```
bool k2hpx_keyq_remove ( mixed $keyqhandle_res , int $count [, stringnull $pass ] )
```
Removes a key/value pair from the [K2hKeyQueue](k2hkq_class.html). 

## Parameters
- keyqhandle_res  
Specifies the [K2hKeyQueue](k2hkq_class.html) file handle that [k2hpx_keyq_handle](k2hpx_keyq_handle.html) returns.
- count  
Specifies the number of elements to remove.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hKeyQueue::remove](k2hkq_remove.html) - Removes a key/value pair from the K2hKeyQueue
