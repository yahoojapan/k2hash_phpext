---
layout: contents
language: en-us
title: k2hpx_open
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_openja.html
lang_opp_word: To Japanese
prev_url: k2hpx_open_tempfile.html
prev_string: k2hpx_open_tempfile
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_print_attr_information.html
next_string: k2hpx_print_attr_information
---

# k2hpx_open
Opens the k2hash file

## Description
```
mixed k2hpx_open ( string $filepath , bool $readonly [, bool $removefile [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]]] )
```
Opens the k2hash (`.k2h`) file.

## Parameters
- filepath  
Specifies a k2hash (`.k2h`) file path.
- readonly  
Specifies true if open with read only access, otherwise false.
- removefile  
Specifies true if removing the k2hash (.k2h) file when no process attaches the file.
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
Returns a k2hash (`.k2h`) file handle on success, otherwise false. 

## See Also
- [K2hash::open](k2h_open.html) - Opens the k2h file
