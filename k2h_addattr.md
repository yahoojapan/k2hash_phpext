---
layout: contents
language: en-us
title: K2hash::addAttr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addattrja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_addattrcryptpass.html
next_string: K2hash::addAttrCryptPass
---

# K2hash::addAttr
Adds the attribute to the key

## Description
```
public bool K2hash::addAttr ( string $key , string $attrkey , string $attrval )
```
Adds the attribute to the key. Attributes represent configurations to keep timestamps of data modification, data encryptions or histories. 

## Parameters
- key  
Specifies the key that links with the attribute.
- attrkey  
Specifies the name of the attribute.
- attrval  
Specifies the value of the attribute.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Adds an attribute and get it
```
<?php

$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test", "value");
$k2hash->addAttr("test", "testattr", "testattrvalue");

var_dump($k2hash->getAttrValue("test", "testattr"));
$k2hash->close();
?>
```
The above example will output:
```
string(13) "testattrvalue"
```

## See Also
- [K2hash::addAttrCryptPass](k2h_addattrcryptpass.html) - Adds the password to encrypt values
- [K2hash::addAttrPluginLib](k2h_addattrpluginlib.html) - Adds the user-defined library to handle attributes
- [K2hash::cleanCommonAttribute](k2h_cleancommonattribute.html) - Initializes the common attributes
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
