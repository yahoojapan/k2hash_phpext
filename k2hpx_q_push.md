---
layout: contents
language: en-us
title: k2hpx_q_push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_pushja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_pop.html
prev_string: k2hpx_q_pop
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_q_read.html
next_string: k2hpx_q_read
---

# k2hpx_q_push
Adds a value to the K2hQueue

## Description

```
bool k2hpx_q_push ( mixed $qhandle_res , string $datavalue [, stringnull $pass [, int $expire ]] )
```

Adds a value to the [K2hQueue](k2hq_class.html). 

## Parameters
- qhandle_res  
Specifies the [K2hQueue](k2hq_class.html) file handle that [k2hpx_q_handle](k2hpx_q_handle.html) returns.
- datavalue  
Specifies the value.
- pass  
Specifies the password to encrypt the value.
- expire  
Specifies the seconds to expire the value.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
