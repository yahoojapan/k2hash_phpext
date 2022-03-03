---
layout: contents
language: en-us
title: k2hpx_load_transaction_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_transaction_libraryja.html
lang_opp_word: To Japanese
prev_url: k2hpx_load_hash_library.html
prev_string: k2hpx_load_hash_library
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_open_mem.html
next_string: k2hpx_open_mem
---

# k2hpx_load_transaction_library
Loads functions of k2hash transaction usage from the file

## Description
```
bool k2hpx_load_transaction_library ( string $libpath )
```
Loads functions of k2hash transaction usage from the file. 

## Parameters
- libpath  
Specifies the file path of k2hash transaction functions defined.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Loads functions of k2hash transaction usage from the file
```
<?php
var_dump(k2hpx_load_transaction_library("/usr/lib/libk2htestlib.so"));
?>
```
The above example will output:
```
bool(true)
```

## See Also
- [k2hpx_unload_transaction_library](k2hpx_unload_transaction_library.html) - Removes the user-defined transaction library
