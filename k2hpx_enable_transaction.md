---
layout: contents
language: en-us
title: k2hpx_enable_transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_enable_transactionja.html
lang_opp_word: To Japanese
prev_url: k2hpx_dump_keytable.html
prev_string: k2hpx_dump_keytable
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_find_first.html
next_string: k2hpx_find_first
---

# k2hpx_enable_transaction
Starts a transaction

## Description

```
bool k2hpx_enable_transaction ( mixed $handle_res [, stringnull $transfile [, stringnull $prefix [, stringnull $param [, int $expire ]]]] )
```

Starts a transaction. 

## Parameters
- handle_res  
Specifies the k2h file handle that [k2hpx_open](k2hpx_open.html) returns.
- transfile  
Specifies the transaction log file path.
- prefix  
Specifies the prefix of transaction log entry.
- param  
Specifies the parameter string to pass to a transaction processing handler.
- expire  
Specifies the duration in second to expire a transaction log entry.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::enableTransaction](k2h_enabletransaction.html) - Starts a transaction
