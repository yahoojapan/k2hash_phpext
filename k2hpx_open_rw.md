---
layout: contents
language: en-us
title: k2hpx_open_rw
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_open_rwja.html
lang_opp_word: To Japanese
prev_url: k2hpx_open_ro.html
prev_string: k2hpx_open_ro
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_open_tempfile.html
next_string: k2hpx_open_tempfile
---

# k2hpx_open_rw
Opens the k2hash file with read and write access

## Description

```
mixed k2hpx_open_rw ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] )
```

Opens the the k2hash (`.k2h`) file with read and write access. 

## Parameters
- filepath  
Specifies a k2hash (`.k2h`) file path.
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
- [K2hash::openRW](k2h_openrw.html) - Edit the k2hash file
