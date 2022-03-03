---
layout: contents
language: en-us
title: k2hpx_print_attr_version
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_print_attr_versionja.html
lang_opp_word: To Japanese
prev_url: k2hpx_print_attr_information.html
prev_string: k2hpx_print_attr_information
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_print_state.html
next_string: k2hpx_print_state
---

# k2hpx_print_attr_version
Prints the attribute library version

## Description
```
bool k2hpx_print_attr_version ( mixed $handle_res [, mixed $output ] )
```
Prints the attribute library version. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
