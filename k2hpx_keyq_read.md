---
layout: contents
language: en-us
title: k2hpx_keyq_read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_readja.html
lang_opp_word: To Japanese
prev_url: k2hpx_keyq_push.html
prev_string: k2hpx_keyq_push
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_keyq_remove.html
next_string: k2hpx_keyq_remove
---

# k2hpx_keyq_read
Returns a key/value pair from the K2hKeyQueue

## Description

```
array k2hpx_keyq_read ( mixed $keyqhandle_res [, int $pos [, stringnull $pass ]] )
```

Returns a key/value pair from the [K2hKeyQueue](k2hkq_class.html). This operation will not remove the key/value pair from the [K2hKeyQueue](k2hkq_class.html). 

### Note
This operation will not remove the element from the [K2hKeyQueue](k2hkq_class.html). Use [k2hpx_keyq_pop](k2hpx_keyq_pop.html) to removes and returns the element instead. 

## Parameters
- keyqhandle_res  
Specifies the [K2hKeyQueue](k2hkq_class.html) file handle that [k2hpx_keyq_handle](k2hpx_keyq_handle.html) returns.
- pos  
Specifies the position of the [K2hKeyQueue](k2hkq_class.html).
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns a key/value pair. 

## See Also
- [K2hQueue::read](k2hq_read.html) - Returns a key/value pair from the K2hQueue
