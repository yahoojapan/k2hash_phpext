---
layout: contents
language: en-us
title: k2hpx_add_attr_plugin_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_attr_plugin_libraryja.html
lang_opp_word: To Japanese
prev_url: k2hpx_add_attr_crypt_pass.html
prev_string: k2hpx_add_attr_crypt_pass
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_add_attr.html
next_string: k2hpx_add_attr
---

# k2hpx_add_attr_plugin_library
Adds the user-defined library to handle attributes

## Description

```
bool k2hpx_add_attr_plugin_library ( mixed $handle_res , string $libfile )
```

Adds the user-defined library to handle attributes. k2hash supports for adding user-defined attributes to keys by using this method. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that k2hpx_open returns.
- libfile  
Specifies the path to the dynamic linked library.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::addAttrPluginLib](k2h_addattrpluginlib.html) - Adds the user-defined library to handle attributes
