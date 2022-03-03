---
layout: contents
language: en-us
title: k2hpx_remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_removeja.html
lang_opp_word: To Japanese
prev_url: k2hpx_remove_all.html
prev_string: k2hpx_remove_all
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_rename.html
next_string: k2hpx_rename
---

# k2hpx_remove
Removes the key

## Description
```
bool k2hpx_remove ( mixed $handle_res , string $key [, stringnull $subkey ] )
```
Removes the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key to remove.
- subkey  
Specifies the key(subkey) that links with the key.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::remove](k2h_remove.html) - Removes the key
