---
layout: contents
language: en-us
title: k2hpx_dump_head
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_headja.html
lang_opp_word: To Japanese
prev_url: k2hpx_dump_full.html
prev_string: k2hpx_dump_full
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_dump_keytable.html
next_string: k2hpx_dump_keytable
---

# k2hpx_dump_head
Prints the k2hash's headers

## Description
```
bool k2hpx_dump_head ( mixed $handle_res [, mixed $output ] )
```
Prints the k2hash's headers. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that k2hpx_open returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::dumpHead](k2h_dumphead.html) - Prints the k2hash's headers
