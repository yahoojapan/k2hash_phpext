---
layout: contents
language: en-us
title: k2hpx_dump_keytable
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_keytableja.html
lang_opp_word: To Japanese
prev_url: k2hpx_dump_head.html
prev_string: k2hpx_dump_head
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_enable_transaction.html
next_string: k2hpx_enable_transaction
---

# k2hpx_dump_keytable
Prints the k2hash's hash tables

## Description
```
bool k2hpx_dump_keytable ( mixed $handle_res [, mixed $output ] )
```
Prints the k2hash's hash tables including k2hash headers. 

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that k2hpx_open returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::dumpKeytable](k2h_dumpkeytable.html) - Prints the k2hash's hash tables
