---
layout: contents
language: en-us
title: k2hpx_set_value
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_valueja.html
lang_opp_word: To Japanese
prev_url: k2hpx_set_transaction_thread_pool.html
prev_string: k2hpx_set_transaction_thread_pool
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_transaction.html
next_string: k2hpx_transaction
---

# k2hpx_set_value
Sets the value

## Description

```
bool k2hpx_set_value ( mixed $handle_res , string $key , string $value [, stringnull $subkey [, stringnull $pass [, int $expire ]]] )
```

Sets the value to the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key to set the value.
- value  
Specifies the value.
- subkey  
Specifies the key(subkey) that links with the key.
- pass  
Specifies the password to encrypt the value.
- expire  
Specifies the duration to expire the value.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::setValue](k2h_setvalue.html) - Sets the value associated with the key
