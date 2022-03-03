---
layout: contents
language: en-us
title: K2hash::rename
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_renameja.html
lang_opp_word: To Japanese
prev_url: k2h_removeall.html
prev_string: K2hash::removeAll
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_setcommonattribute.html
next_string: K2hash::setCommonAttribute
---

# K2hash::rename
Renames the key

## Description
```
 public bool K2hash::rename ( string $key , string $newkey )
```
Renames the key

## Parameters
- key  
Specifies the old key name.
- newkey  
Specifies the new key name.

## Return Values
Returns true on success or false on failure.

## Examples
- Example 1 - Renames a key
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value");
var_dump($k2hash->rename("test1", "test2"));
var_dump($k2hash->getValue("test2"));
?>
```
The above example will output:
```
bool(true)
string(5) "value"
```

## See Also
- [K2hash::getValue](k2h_getvalue.html) - Gets the value associated with the key
- [K2hash::setValue](k2h_setvalue.html) - Sets the value associated with the key
