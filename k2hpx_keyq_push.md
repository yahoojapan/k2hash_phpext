---
layout: contents
language: en-us
title: k2hpx_keyq_push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_pushja.html
lang_opp_word: To Japanese
prev_url: k2hpx_keyq_pop.html
prev_string: k2hpx_keyq_pop
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_keyq_read.html
next_string: k2hpx_keyq_read
---

# k2hpx_keyq_push
Adds a key/value pair to the K2hKeyQueue

## Description
```
bool k2hpx_keyq_push ( mixed $keyqhandle_res , string $key , string $value [, stringnull $pass [, int $expire ]] )
```
Adds a key/value pair to the [K2hKeyQueue](k2hkq_class.html). 

## Parameters
- keyqhandle_res  
Specifies the [K2hKeyQueue](k2hkq_class.html) file handle that [k2hpx_keyq_handle](k2hpx_keyq_handle.html) returns.
- key  
Specifies the key.
- value  
Specifies the value.
- pass  
Specifies the password to encrypt the value.
- expire  
Specifies the seconds to expire the value.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
