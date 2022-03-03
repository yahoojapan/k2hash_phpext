---
layout: contents
language: en-us
title: K2hash::addSubkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addsubkeysja.html
lang_opp_word: To Japanese
prev_url: k2h_addsubkey.html
prev_string: K2hash::addSubkey
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_cleancommonattribute.html
next_string: K2hash::cleanCommonAttribute
---

# K2hash::addSubkeys
Adds the subkeys to the key

## Description
```
public bool K2hash::addSubkeys ( string $key , array $subkeys )
```
Associates the keys with the other key. The key that is added to the other key is called 'subkey'. The key that adds the other key to is 'parent key'. A parent key can associates many subkeys. 

## Parameters
- key  
Specifies the key that link with the subkeys.
- subkeys  
Specifies the array of keys(subkeys) that link with the key.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Adds subkeys to a key
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
- [K2hash::getSubkeys](k2h_getsubkeys.html) - Gets an array of keys associated with the key
