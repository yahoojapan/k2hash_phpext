---
layout: contents
language: en-us
title: K2hash::remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_removeja.html
lang_opp_word: To Japanese
prev_url: k2h_putarchive.html
prev_string: K2hash::putArchive
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_removeall.html
next_string: K2hash::removeAll
---

# K2hash::remove
Removes the key

## Description

```
 public bool K2hash::remove ( string $key [, string $subkey ] )
```

Removes the key. 

## Parameters
- key  
Specifies the key to remove.
- subkey  
Specifies the key associated with the key.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Removes the key

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value");
$k2hash->setValue("sub1", "sub-value");
$k2hash->addSubkey("test1", "sub1");

$k2hash->remove("test1");
var_dump($k2hash->getValue("test1"));
var_dump($k2hash->getValue("sub1"));
?>
```

The above example will output:

```
bool(false)
string(9) "sub-value"
```


- Example 2 - Remove the keys linked with a key

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value");
$k2hash->setValue("sub1", "sub-value");
$k2hash->addSubkey("test1", "sub1");
$k2hash->remove("test1", "sub1");
var_dump($k2hash->getValue("test1"));
var_dump($k2hash->getValue("sub1"));
?>
```

The above example will output:

```
string(5) "value"
bool(false)
```


## See Also
- [K2hash::removeAll](k2h_removeall.html) - Removes the key and the keys associated with the key
- [K2hash::setValue](k2h_setvalue.html) - Sets the value associated with the key
