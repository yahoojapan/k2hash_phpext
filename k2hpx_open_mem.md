---
layout: contents
language: en-us
title: k2hpx_open_mem
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_open_memja.html
lang_opp_word: To Japanese
prev_url: k2hpx_load_transaction_library.html
prev_string: k2hpx_load_transaction_library
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_open_ro.html
next_string: k2hpx_open_ro
---

# k2hpx_open_mem
Opens k2hash as volatile(on memory).

## Description
```
mixed k2hpx_open_mem ([ int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
```
Opens k2hash as volatile(on memory).

## Parameters
- maskbitcnt  
Specifies the key mask bit. The default value is 8.
- cmaskbitcnt  
Specifies the key collision mask bit. The default value is 4.
- maxelementcnt  
Specifies the max number of duplicated elements if a hash collision occurs. The default value is 1024(bytes).
- pagesize  
Specifies the block size of data. The default value is 512(bytes).

## Return Values
Returns a k2hash (`.k2h`) file handle on success, otherwise false. 

## See Also
- [K2hash::openMem](k2h_openmem.html) - Opens k2hash as volatile(on memory)
