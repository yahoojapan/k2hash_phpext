---
layout: contents
language: en-us
title: k2hpx_q_pop
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_popja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_handle.html
prev_string: k2hpx_q_handle
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_q_push.html
next_string: k2hpx_q_push
---

# k2hpx_q_pop
Removes and returns the removed element from the K2hQueue

## Description

```
string 2hpx_q_pop ( mixed $qhandle_res [, stringnull $pass ] )
```

Removes and gets the removed element from the [K2hQueue](k2hq_class.html). 

## Parameters
- qhandle_res  
Specifies the [K2hQueue](k2hq_class.html) file handle that [k2hpx_q_handle](k2hpx_q_handle.html) returns.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns a value. 

## See Also
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
