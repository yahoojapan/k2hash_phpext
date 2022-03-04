---
layout: contents
language: en-us
title: K2hash::getValue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getvalueja.html
lang_opp_word: To Japanese
prev_url: k2h_gettransactionthreadpool.html
prev_string: K2hash::getTransactionThreadPool
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_loadarchive.html
next_string: K2hash::loadArchive
---

# K2hash::getValue
Gets the value associated with the key

## Description

```
public stringfalseK2hash::getValue ( string $key [, string $subkey [, bool $attrcheck [, string $pass ]]] )
```

Gets the value associated with the key. Gets the keys linked with the key if the key is passed. 

## Parameters
- key  
Specifies the key.
- subkey  
Specifies the subkey linked with the key.
- attrcheck  
Specifies true if getting value after checking attributes, otherwise false.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns the value of the key or the subkey, otherwise false. 

## Examples
- Example 1 - Get value associated with a key

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
- [K2hash::setValue](k2h_setvalue.html) - Sets the value associated with the key
