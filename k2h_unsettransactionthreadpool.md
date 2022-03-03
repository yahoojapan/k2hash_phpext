---
layout: contents
language: en-us
title: K2hash::unsetTransactionThreadPool
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_unsettransactionthreadpoolja.html
lang_opp_word: To Japanese
prev_url: k2h_transaction.html
prev_string: K2hash::transaction
top_url: k2h_class.html
top_string: K2hash Class
next_url: 
next_string: 
---

# K2hash::unsetTransactionThreadPool
Stops transaction workers

## Description
```
 public static bool K2hash::unsetTransactionThreadPool ( void )
```
Stops transaction workers. 

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Sets the number of transaction workers
```
<?php
var_dump(K2hash::settransactionThreadPool(1));
var_dump(K2hash::gettransactionThreadPool());
var_dump(K2hash::unsettransactionThreadPool());
?>
```
The above example will output:
```
bool(true)
int(1)
bool(true)
```

## See Also
- [K2hash::getTransactionThreadPool](k2h_gettransactionthreadpool.html) - Gets the number of transaction workers
- [K2hash::setTransactionThreadPool](k2h_settransactionthreadpool.html) - Sets the number of transaction workers
