---
layout: contents
language: en-us
title: k2hpx_load_hash_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_hash_libraryja.html
lang_opp_word: To Japanese
prev_url: k2hpx_load_debug_env.html
prev_string: k2hpx_load_debug_env
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_load_transaction_library.html
next_string: k2hpx_load_transaction_library
---

# k2hpx_load_hash_library
Loads hash functions from the file

## Description
```
bool k2hpx_load_hash_library ( string $libpath )
```
Loads hash functions from the file. 

## Parameters
- libpath  
Specifies the file path of hash functions defined.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Loads hash functions from the file
```
<?php
var_dump(k2hpx_load_hash_library("/usr/lib/libk2htest.so"));
?>
```
The above example will output:
```
bool(true)
```

## See Also
- [k2hpx_unload_hash_library](k2hpx_unload_hash_library.html) - Removes the user-defined hash library
