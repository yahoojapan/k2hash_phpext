---
layout: contents
language: en-us
title: k2hpx_disable_transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_disable_transactionja.html
lang_opp_word: To Japanese
prev_url: k2hpx_da_set_write_offset.html
prev_string: k2hpx_da_set_write_offset
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_dump_elementtable.html
next_string: k2hpx_dump_elementtable
---

# k2hpx_disable_transaction
Stops a transaction

## Description

```
bool k2hpx_disable_transaction ( mixed $handle_res )
```

Stops a transaction. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that k2hpx_open returns.

## Return Values
Returns true on success or false on failure.

## See Also
- [K2hash::disableTransaction](k2h_disabletransaction.html) - Stops a transaction
