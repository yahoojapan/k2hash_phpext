---
layout: contents
language: en-us
title: k2hpx_get_attr_value
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_attr_valueja.html
lang_opp_word: To Japanese
prev_url: k2hpx_find_next.html
prev_string: k2hpx_find_next
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_get_attrs.html
next_string: k2hpx_get_attrs
---

# k2hpx_get_attr_value
Gets an attribute value of the key

## Description
```
string k2hpx_get_attr_value ( mixed $handle_res , string $key , string $attrkey )
```
Gets an attribute value of the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key.
- attrkey  
Specifies the attribute key.

## Return Values
Returns the value of the attribute of the key, otherwise false. 

## See Also
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
