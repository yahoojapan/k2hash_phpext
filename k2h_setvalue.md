---
layout: contents
language: en-us
title: K2hash::setValue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_setvalueja.html
lang_opp_word: To Japanese
prev_url: k2h_settransactionthreadpool.html
prev_string: K2hash::setTransactionThreadPool
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_transaction.html
next_string: K2hash::transaction
---

# K2hash::setValue
Sets the value associated with the key

## Description
```
 public bool K2hash::setValue ( string $key , string $value [, string $subkey [, string $pass [, int $expire ]]] )
```
Sets the value associated with the key. 

## Parameters
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

## Examples
- Example 1 - Sets a value to a key
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("key1", "value1");
var_dump($k2hash->getValue("key1"));
$k2hash->close();
?>
```
The above example will output:
```
string(6) "value1"
```

## See Also
- [K2hash::getValue](k2h_getvalue.html) - Gets the value associated with the key
