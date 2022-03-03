---
layout: contents
language: en-us
title: K2hash::removeAll
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_removeallja.html
lang_opp_word: To Japanese
prev_url: k2h_remove.html
prev_string: K2hash::remove
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_rename.html
next_string: K2hash::rename
---

# K2hash::removeAll
Removes the key and the keys associated with the key

## Description
```
 public bool K2hash::removeAll ( string $key )
```
Removes the key and the keys associated with the key. 

## Parameters
- key  
Specifies the key.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Remove the key
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value");
$k2hash->setValue("sub1", "sub-value");
$k2hash->addSubkey("test1", "sub1");

$k2hash->removeAll("test1");
var_dump($k2hash->getValue("test1"));
var_dump($k2hash->getValue("sub1"));
?>
```
The above example will output:
```
bool(false)
bool(false)
```

## See Also
- [K2hash::remove](k2h_remove.html) - Removes the key
- [K2hash::setValue](k2h_setvalue.html) - Sets the value associated with the key
