---
layout: contents
language: en-us
title: k2hpx_add_attr_crypt_pass
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_attr_crypt_passja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_add_attr_plugin_library.html
next_string: k2hpx_add_attr_plugin_library
---

# k2hpx_add_attr_crypt_pass
Adds the password to encrypt values

## Description

```
 bool k2hpx_add_attr_crypt_pass ( mixed $handle_res , string $encpass [, bool $is_default_encrypt ] )
```

Adds the password to encrypt values. The encrption algorithm is AES256. 

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that k2hpx_open returns.
- encpass  
Specifies the password.
- is_default_encrypt  
Specifies true if always encrypt values, otherwise false  

## Return Values
Returns true on success or false on failure.. 

## See Also
- [K2hash::addAttrCryptPass](k2h_addattrcryptpass.html) - Adds the password to encrypt values
