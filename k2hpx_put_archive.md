---
layout: contents
language: en-us
title: k2hpx_put_archive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_put_archiveja.html
lang_opp_word: To Japanese
prev_url: k2hpx_print_version.html
prev_string: k2hpx_print_version
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_q_count.html
next_string: k2hpx_q_count
---

# k2hpx_put_archive
Saves a k2hash file as an archive file

## Description

```
bool k2hpx_put_archive ( mixed $handle_res , string $filepath [, bool $errskip ] )
```

Saves the k2hash (`.k2h`) file as an archive file. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that k2hpx_open returns.
- filepath  
Specifies the path to an archive file.
- errskip  
Specifies true if a dump process continues on errors.

## Return Values
Returns true on success or false on failure.. 

## See Also
- [K2hash::putArchive](k2h_putarchive.html) - Saves data as the archive file
