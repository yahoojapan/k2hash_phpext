---
layout: contents
language: en-us
title: K2hash::openMem
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_openmemja.html
lang_opp_word: To Japanese
prev_url: k2h_open.html
prev_string: K2hash::open
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_openro.html
next_string: K2hash::openRO
---

# K2hash::openMem
Open k2hash as volatile(on memory).

## Description
```
 public bool K2hash::openMem ([ int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
```
Open k2hash as volatile(on memory).

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
Returns true on success or false on failure. 

## See Also
- [K2hash::open](k2h_open.html) - Opens the k2h file
- [K2hash::openRO](k2h_openro.html) - Read the k2hash file
- [K2hash::openRW](k2h_openrw.html) - Edit the k2hash file
- [K2hash::openTempfile](k2h_opentempfile.html) - Edit the k2hash file on temporary file system
