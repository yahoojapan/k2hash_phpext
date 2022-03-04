---
layout: contents
language: en-us
title: k2hpx_rename
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_renameja.html
lang_opp_word: To Japanese
prev_url: k2hpx_remove.html
prev_string: k2hpx_remove
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_set_common_attr.html
next_string: k2hpx_set_common_attr
---

# k2hpx_rename
Renames the key

## Description

```
bool k2hpx_rename ( mixed $handle_res , string $key , string $newkey )
```

Renames the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the old key name.
- newkey  
Specifies the new key name.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::rename](k2h_rename.html) - Renames the key
