---
layout: contents
language: en-us
title: k2hpx_q_empty
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_emptyja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_dump.html
prev_string: k2hpx_q_dump
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_q_free.html
next_string: k2hpx_q_free
---

# k2hpx_q_empty
Returns whether the K2hQueue is empty

## Description

```
bool k2hpx_q_empty ( mixed $qhandle_res )
```

Returns where the [K2hQueue](k2hq_class.html) is empty. 

## Parameters
- qhandle_res  
Specifies the [K2hQueue](k2hq_class.html) file handle that [k2hpx_q_handle](k2hpx_q_handle.html) returns.

## Return Values
Returns true if the [K2hQueue](k2hq_class.html) object is empty, otherwise false.

## See Also
- [K2hQueue::isEmpty](k2hq_isEmpty.html) - Returns whether the K2hQueue is empty
