---
layout: contents
language: en-us
title: k2hpx_q_read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_readja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_push.html
prev_string: k2hpx_q_push
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_q_remove.html
next_string: k2hpx_q_remove
---

# k2hpx_q_read
Returns a key/value pair from the K2hQueue

## Description
```
string k2hpx_q_read ( mixed $qhandle_res [, int $pos [, stringnull $pass ]] )
```
Returns a value from the [K2hQueue](k2hq_class.html). This operation will not remove the value from the [K2hQueue](k2hq_class.html). 

### Note
This operation will not remove the element from the [K2hQueue](k2hq_class.html). Use [k2hpx_keyq_pop](k2hpx_keyq_pop.html) to removes and returns the element instead. 

## Parameters
- qhandle_res  
Specifies the [K2hQueue](k2hq_class.html) file handle that [k2hpx_q_handle](k2hpx_q_handle.html) returns.
- pos  
Specifies the position of the [K2hQueue](k2hq_class.html).
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns a value. 

## See Also
- [K2hQueue::read](k2hq_read.html) - Returns a key/value pair from the K2hQueue
