---
layout: contents
language: en-us
title: k2hpx_unload_hash_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_unload_hash_libraryja.html
lang_opp_word: To Japanese
prev_url: k2hpx_transaction.html
prev_string: k2hpx_transaction
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_unload_transaction_library.html
next_string: k2hpx_unload_transaction_library
---

# k2hpx_unload_hash_library
Removes the user-defined hash library

## Description

```
bool k2hpx_unload_hash_library ( void )
```

Removes the user-defined hash library that is added by k2hpx_load_hash_library. 

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Removes the user-defined hash library

```
<?php
var_dump(k2hpx_unload_hash_library());
?>
```

The above example will output:

```
bool(true)
```


## See Also
- [k2hpx_load_hash_library](k2hpx_load_hash_library.html) - Loads hash functions from the file
