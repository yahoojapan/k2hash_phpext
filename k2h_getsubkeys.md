---
layout: contents
language: en-us
title: K2hash::getSubkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getsubkeysja.html
lang_opp_word: To Japanese
prev_url: k2h_getstream.html
prev_string: K2hash::getStream
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_gettransactionthreadpool.html
next_string: K2hash::getTransactionThreadPool
---

# K2hash::getSubkeys
Gets an array of keys associated with the key

## Description

```
public arrayfalseK2hash::getSubkeys ( string $key [, bool $attrcheck ] )
```

Gets an array of the keys associated with the key. 

## Parameters
- key  
Specifies the key.
- attrcheck  
Specifies true if getting subkeys after checking attributes, otherwise false.

## Return Values
Returns an array of keys associated with the key. 

## Examples
- Example 1 - Gets an array of keys associated with a key

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->addSubkeys("test", array("subkey1", "subkey2", "subkey3"));
var_dump($k2hash->getSubkeys("test"));
$k2hash->close();
?>
```

The above example will output:

```
array(3) {
  [0]=>
  string(7) "subkey1"
  [1]=>
  string(7) "subkey2"
  [2]=>
  string(7) "subkey3"
}
```


## See Also
- [K2hash::addSubkey](k2h_addsubkey.html) - Associates the key with the other key
- [K2hash::addSubkeys](k2h_addsubkeys.html) - Adds the subkeys to the key
