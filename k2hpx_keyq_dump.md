---
layout: contents
language: en-us
title: k2hpx_keyq_dump
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_dumpja.html
lang_opp_word: To Japanese
prev_url: k2hpx_keyq_count.html
prev_string: k2hpx_keyq_count
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_keyq_empty.html
next_string: k2hpx_keyq_empty
---

# k2hpx_keyq_dump
Gets the elements in the K2hKeyQueue object

## Description
```
bool k2hpx_keyq_dump ( mixed $keyqhandle_res [, mixed $output ] )
```
Gets the elements in the [K2hKeyQueue](k2hkq_class.html) object. 

## Parameters
- keyqhandle_res  
Specifies the [K2hKeyQueue](k2hkq_class.html) file handle that [k2hpx_keyq_handle](k2hpx_keyq_handle.html) returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hQueue::dump](k2hq_dump.html) - Prints the elements in the K2hQueue object
