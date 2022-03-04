---
layout: contents
language: en-us
title: k2hpx_get_value
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_valueja.html
lang_opp_word: To Japanese
prev_url: k2hpx_get_transaction_thread_pool.html
prev_string: k2hpx_get_transaction_thread_pool
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_keyq_count.html
next_string: k2hpx_keyq_count
---

# k2hpx_get_value
Gets the value of the key

## Description

```
string k2hpx_get_value ( mixed $handle_res , string $key [, stringnull $subkey [, bool $attrcheck [, stringnull $pass ]]] )
```

Gets the value of the key. Gets the keys linked with the key if the key is passed. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key.
- subkey  
Specifies the subkey linked with the key.
- attrcheck  
Specifies true if getting value after checking attributes, otherwise false.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::getValue](k2h_getvalue.html) - Gets the value associated with the key
