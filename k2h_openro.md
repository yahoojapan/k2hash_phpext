---
layout: contents
language: en-us
title: K2hash::openRO
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_openroja.html
lang_opp_word: To Japanese
prev_url: k2h_openmem.html
prev_string: K2hash::openMem
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_openrw.html
next_string: K2hash::openRW
---

# K2hash::openRO
Read the k2hash file

## Description
```
 public bool K2hash::openRO ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] )
```
Opens the the k2hash (.k2h) file with read only access. 

## Parameters
- filepath  
Specifies a k2hash (.k2h) file path.
- fullmap  
Specifies true if the whole data of the file maps to memory.
- maskbitcnt  
Specifies key mask bit. The default value is 8.
- cmaskbitcnt  
Specifies the key collision mask bit. The default value is 4.
- maxelementcnt  
Specifies the max number of duplicated elements if a hash collision occurs. The default value is 1024(bytes).
- pagesize  
Specifies the block size of data. The default value is 512(bytes).

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::close](k2h_close.html) - Closes the k2h file
- [K2hash::open](k2h_open.html) - Opens the k2h file
- [K2hash::openMem](k2h_openmem.html) - Open k2hash as volatile(on memory)
- [K2hash::openRW](k2h_openrw.html) - Edit the k2hash file
- [K2hash::openTempfile](k2h_opentempfile.html) - Edit the k2hash file on temporary file system
