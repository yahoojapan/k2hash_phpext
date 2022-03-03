---
layout: contents
language: en-us
title: k2hpx_close
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_closeja.html
lang_opp_word: To Japanese
prev_url: k2hpx_clean_common_attr.html
prev_string: k2hpx_clean_common_attr
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_create.html
next_string: k2hpx_create
---

# k2hpx_close
Closes the k2hash file

## Description
```
bool k2hpx_close ( mixed $handle_res [, int $waitms ] )
```
Closes the k2hash (`.k2h`) file and saves the data. 

## Parameters
- handle_res  
Specifies the the k2hash (.k2h) file handle that k2hpx_open returns.
- waitms  
microseconds to wait before closing the k2h file.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::close](k2h_close.html) - Closes the k2h file
