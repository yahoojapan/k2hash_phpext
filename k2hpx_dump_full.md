---
layout: contents
language: en-us
title: k2hpx_dump_full
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_fullja.html
lang_opp_word: To Japanese
prev_url: k2hpx_dump_full_keytable.html
prev_string: k2hpx_dump_full_keytable
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_dump_head.html
next_string: k2hpx_dump_head
---

# k2hpx_dump_full
Prints the k2hash's hash tables in details

## Description
```
bool k2hpx_dump_full ( mixed $handle_res [, mixed $output ] )
```
Prints the k2hash's hash tables in details including headers, hash tables and sub-hash tables. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that k2hpx_open returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::dumpFull](k2h_dumpfull.html) - Prints the k2hash's hash tables in details
