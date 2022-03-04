---
layout: contents
language: en-us
title: k2hpx_create
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_createja.html
lang_opp_word: To Japanese
prev_url: k2hpx_close.html
prev_string: k2hpx_close
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_da_free.html
next_string: k2hpx_da_free
---

# k2hpx_create
Creates the k2hash file

## Description

```
bool k2hpx_create ( string $filepath [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
```

Creates the k2hash (`.k2h`) file. 

## Parameters
- filepath  
Specifies the path to the k2hash (`.k2h`) file.
- maskbitcnt  
Specifies key mask bit. The default value is 8.
- cmaskbitcnt  
Specifies key collision mask bit. The default value is 4.
- maxelementcnt  
Specifies the max number of duplicated elements if a hash collision occurs. The default value is 1024(bytes).
- pagesize  
Specifies a block size of data. The default value is 512(bytes).

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::create](k2h_create.html) - Creates the k2h file
