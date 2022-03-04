---
layout: contents
language: en-us
title: k2hpx_get_attrs
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_attrsja.html
lang_opp_word: To Japanese
prev_url: k2hpx_get_attr_value.html
prev_string: k2hpx_get_attr_value
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_get_subkeys.html
next_string: k2hpx_get_subkeys
---

# k2hpx_get_attrs
Gets attributes of the key

## Description

```
array k2hpx_get_attrs ( mixed $handle_res , string $key )
```

Gets attributes of the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key.

## Return Values
Returns attributes of the key, otherwise false. 

## See Also
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
