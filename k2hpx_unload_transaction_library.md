---
layout: contents
language: en-us
title: k2hpx_unload_transaction_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_unload_transaction_libraryja.html
lang_opp_word: To Japanese
prev_url: k2hpx_unload_hash_library.html
prev_string: k2hpx_unload_hash_library
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_unset_debug_file.html
next_string: k2hpx_unset_debug_file
---

# k2hpx_unload_transaction_library
Removes the user-defined transaction library

## Description

```
bool k2hpx_unload_transaction_library ( void )
```

Removes the user-defined transaction library that is added by [k2hpx_load_transaction_library](k2hpx_load_transaction_library.html). 

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Removes the user-defined transaction library

```
<?php
var_dump(k2hpx_unload_transaction_library());
?>
```

The above example will output:

```
bool(true)
```


## See Also
- [k2hpx_load_transaction_library](k2hpx_load_transaction_library.html) - Loads functions of k2hash transaction usage from the file
