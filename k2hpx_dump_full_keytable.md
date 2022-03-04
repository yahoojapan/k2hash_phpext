---
layout: contents
language: en-us
title: k2hpx_dump_full_keytable
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_full_keytableja.html
lang_opp_word: To Japanese
prev_url: k2hpx_dump_elementtable.html
prev_string: k2hpx_dump_elementtable
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_dump_full.html
next_string: k2hpx_dump_full
---

# k2hpx_dump_full_keytable
Prints details of the k2hash's hash tables

## Description

```
bool k2hpx_dump_full_keytable ( mixed $handle_res [, mixed $output ] )
```

 Prints details of the k2hash's hash tables including headers, hash tables and sub-hash tables. 

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that k2hpx_open returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::dumpFullKeytable](k2h_dumpfullkeytable.html) - Prints details of the k2hash's hash tables
