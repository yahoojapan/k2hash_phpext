---
layout: contents
language: en-us
title: k2hpx_q_remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_removeja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_read.html
prev_string: k2hpx_q_read
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_remove_all.html
next_string: k2hpx_remove_all
---

# k2hpx_q_remove
Removes a value from the K2hQueue

## Description
```
bool k2hpx_q_remove ( mixed $qhandle_res , int $count [, stringnull $pass ] )
```
Removes a value from the [K2hQueue](k2hq_class.html). 

## Parameters
- qhandle_res  
Specifies the [K2hQueue](k2hq_class.html) file handle that [k2hpx_q_handle](k2hpx_q_handle.html) returns.
- count  
Specifies the number of elements to remove.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hQueue::remove](k2hq_remove.html) - Removes a value from the K2hQueue
