---
layout: contents
language: en-us
title: k2hpx_get_subkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_subkeysja.html
lang_opp_word: To Japanese
prev_url: k2hpx_get_attrs.html
prev_string: k2hpx_get_attrs
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_get_transaction_thread_pool.html
next_string: k2hpx_get_transaction_thread_pool
---

# k2hpx_get_subkeys
Gets the array of the keys(subkeys) linked with the key

## Description

```
array k2hpx_get_subkeys ( mixed $handle_res , string $key [, bool $attrcheck ] )
```

Gets the array of the keys(subkeys) linked with the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key.
- attrcheck  
Specifies true if getting subkeys after checking attributes, otherwise false.

## Return Values
Returns keys linked with the key(subkeys). 

## See Also
- [K2hash::getSubkeys](k2h_getsubkeys.html) - Gets an array of keys associated with the key
