---
layout: contents
language: en-us
title: k2hpx_set_common_attr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_common_attrja.html
lang_opp_word: To Japanese
prev_url: k2hpx_rename.html
prev_string: k2hpx_rename
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_set_debug_file.html
next_string: k2hpx_set_debug_file
---

# k2hpx_set_common_attr
Sets the common attributes

## Description

```
bool k2hpx_set_common_attr ( mixed $handle_res [, int $is_mtime [, int $is_history [, int $is_encrypt [, stringnull $passfile [, int $is_expire [, int $expire ]]]]]] )
```

Sets the common attributes. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- is_mtime  
Specifies true when keeping the last timestamp to modify the value, otherwise false.
- is_history  
Specifies true to track changes, otherwise false.
- is_encrypt  
Specifies true to encrypt the value, otherwise false.
- passfile  
Specifies the file path that contains the password to encrypt the value.
- is_expire  
Specifies true to expire values, otherwise false.
- expire  
Specifies the duration in second to expire values.

## Return Values
Returns true on success or false on failure.. 

## See Also
- [K2hash::setCommonAttribute](k2h_setcommonattribute.html) - Sets the common attributes
