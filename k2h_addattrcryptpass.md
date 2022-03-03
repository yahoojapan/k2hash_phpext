---
layout: contents
language: en-us
title: K2hash::addAttrCryptPass
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addattrcryptpassja.html
lang_opp_word: To Japanese
prev_url: k2h_addattr.html
prev_string: K2hash::addAttr
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_addattrpluginlib.html
next_string: K2hash::addAttrPluginLib
---

# K2hash::addAttrCryptPass
Adds the password to encrypt values

## Description
```
public bool K2hash::addAttrCryptPass ( string $encpass [, bool $is_default_encrypt ] )
```
Adds the password to encrypt values. The encrption algorithm is AES256. 

## Parameters
- encpass  
Specifies the password.
- is_default_encrypt  
Specifies true if always encrypt values, otherwise false.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Adds a password to encypt values
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->addAttrCryptPass("testkey", true));
$k2hash->close();
?>
```
The above example will output:
```
bool(true)
```

## See Also
- [K2hash::addAttr](k2h_addattr.html) - Adds the attribute to the key
- [K2hash::addAttrPluginLib](k2h_addattrpluginlib.html) - Adds the user-defined library to handle attributes
- [K2hash::cleanCommonAttribute](k2h_cleancommonattribute.html) - Initializes the common attributes
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
