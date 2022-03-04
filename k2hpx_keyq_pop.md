---
layout: contents
language: en-us
title: k2hpx_keyq_pop
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_popja.html
lang_opp_word: To Japanese
prev_url: k2hpx_keyq_handle.html
prev_string: k2hpx_keyq_handle
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_keyq_push.html
next_string: k2hpx_keyq_push
---

# k2hpx_keyq_pop
Removes and returns the removed element from the K2hKeyQueue

## Description

```
array k2hpx_keyq_pop ( mixed $keyqhandle_res [, stringnull $pass ] )
```

Removes and gets the removed element from the [K2hKeyQueue](k2hkq_class.html). 

## Parameters
- keyqhandle_res  
Specifies the [K2hKeyQueue](k2hkq_class.html) file handle that [k2hpx_keyq_handle](k2hpx_keyq_handle.html) returns.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns a key/value pair. 

## See Also
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
