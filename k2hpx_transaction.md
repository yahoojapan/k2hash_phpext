---
layout: contents
language: en-us
title: k2hpx_transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_transactionja.html
lang_opp_word: To Japanese
prev_url: k2hpx_set_value.html
prev_string: k2hpx_set_value
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_unload_hash_library.html
next_string: k2hpx_unload_hash_library
---

# k2hpx_transaction
Changes transaction settings

## Description
```
bool k2hpx_transaction ( mixed $handle_res , bool $enable [, stringnull $transfile [, stringnull $prefix [, stringnull $param [, int $expire ]]]] )
```
Changes transaction settings. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- enable  
Specifies true to enable transaction, otherwise false.
- transfile  
Specifies the transaction log file path.
- prefix  
Specifies the prefix of transaction log entry.
- param  
Specifies the parameter string to pass to a transaction processing handler.
- expire  
Specifies the duration in second to expire a transaction log entry.

## Return Values
Returns true on success or false on failure..

## See Also
- [K2hash::transaction](k2h_transaction.html) - Changes transaction settings
s