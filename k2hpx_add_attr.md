---
layout: contents
language: en-us
title: k2hpx_add_attr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_attrja.html
lang_opp_word: To Japanese
prev_url: k2hpx_add_attr_plugin_library.html
prev_string: k2hpx_add_attr_plugin_library
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_add_subkey.html
next_string: k2hpx_add_subkey
---

# k2hpx_add_attr
Adds the attribute to the key

## Description
```
 bool k2hpx_add_attr ( mixed $handle_res , string $key , string $attrkey , string $attrval )
```
Adds the attribute to the key. Attributes represent configurations to keep timestamps of data modification, data encryptions or histories. 

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that k2hpx_open returns.
- key  
Specifies the key that links with the attribute.
- attrkey  
Specifies the name of the attribute.
- attrval  
Specifies the value of the attribute.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::addAttr](k2h_addattr.html) - Adds the attribute to the key
