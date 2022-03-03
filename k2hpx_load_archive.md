---
layout: contents
language: en-us
title: k2hpx_load_archive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_archiveja.html
lang_opp_word: To Japanese
prev_url: k2hpx_keyq_remove.html
prev_string: k2hpx_keyq_remove
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_load_debug_env.html
next_string: k2hpx_load_debug_env
---

# k2hpx_load_archive
Loads data from the file

## Description
```
bool k2hpx_load_archive ( mixed $handle_res , string $filepath [, bool $errskip ] )
```
Loads data from the file. The file should be either a transaction file or an archive file.

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that [k2hpx_open](k2hpx_open.html) returns.
- filepath  
Specifies a file to load.
- errskip  
Specifies true if skipping errors in loading the data from the file.

## Return Values
Returns true on success or false on failure.. 

## See Also
- [K2hash::loadArchive](k2h_loadarchive.html) - Loads data from the file
