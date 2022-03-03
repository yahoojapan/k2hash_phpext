---
layout: contents
language: en-us
title: K2hash::transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_transactionja.html
lang_opp_word: To Japanese
prev_url: k2h_setvalue.html
prev_string: K2hash::setValue
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_unsettransactionthreadpool.html
next_string: K2hash::unsetTransactionThreadPool
---

# K2hash::transaction
Changes transaction settings

## Description
```
 public bool K2hash::transaction ( bool $enable [, string $transfile [, string $prefix [, string $param [, int $expire ]]]] )
```
Changes transaction settings. 

## Parameters
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
Returns true on success or false on failure. 

## Examples
- Example 1 - Starts transaction
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->transaction(true, "/tmp/test_k2h_trans", "trans_prefix_", "myparam"));
$k2hash->close();
?>
```
The above example will output:
```
bool(true)
```

## See Also
- [K2hash::disableTransaction](k2h_disabletransaction.html) - Stops a transaction
- [K2hash::enableTransaction](k2h_enabletransaction.html) - Starts a transaction
