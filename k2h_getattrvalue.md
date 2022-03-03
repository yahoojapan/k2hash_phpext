---
layout: contents
language: en-us
title: K2hash::getAttrValue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getattrvalueja.html
lang_opp_word: To Japanese
prev_url: k2h_getattrs.html
prev_string: K2hash::getAttrs
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getattrversioninfos.html
next_string: K2hash::getAttrVersionInfos
---

# K2hash::getAttrValue
Gets an attribute value of the attribute key of the key

## Description
```
public stringfalseK2hash::getAttrValue ( string $key , string $attrkey )
```
Gets an attribute value of the attribute key of the key. 

## Parameters
- key  
Specifies the key.
- attrkey  
Specifies the attribute key.

## Return Values
Returns the value of the attribute of the key, otherwise false. 

## Examples
- Example 1 - Adds an attribute to a key and get it
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
- [K2hash::addAttr](k2h_addattr.html) - Adds the attribute to the key
- [K2hash::addAttrCryptPass](k2h_addattrcryptpass.html) - Adds the password to encrypt values
- [K2hash::addAttrPluginLib](k2h_addattrpluginlib.html) - Adds the user-defined library to handle attributes
- [K2hash::cleanCommonAttribute](k2h_cleancommonattribute.html) - Initializes the common attributes
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
