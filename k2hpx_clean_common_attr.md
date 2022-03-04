---
layout: contents
language: en-us
title: k2hpx_clean_common_attr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_clean_common_attrja.html
lang_opp_word: To Japanese
prev_url: k2hpx_bump_debug_level.html
prev_string: k2hpx_bump_debug_level
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_close.html
next_string: k2hpx_close
---

# k2hpx_clean_common_attr
Initializes the common attributes

## Description

```
bool k2hpx_clean_common_attr ( mixed $handle_res )
```

Initializes the common attributes.

Common attributes are :
- mtime  
true when keeping the last timestamp to modify values.
- encrypt  
true to encrypt values.
- history  
true to track values changes.
- expire  
true to expire values.

## Parameters
- handle_res  
Specifies the k2h file handle that k2hpx_open returns.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::cleanCommonAttribute](k2h_cleancommonattribute.html) - Initializes the common attributes
