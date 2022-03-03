---
layout: contents
language: en-us
title: K2hash::addAttrPluginLib
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addattrpluginlibja.html
lang_opp_word: To Japanese
prev_url: k2h_addattrcryptpass.html
prev_string: K2hash::addAttrCryptPass
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_addsubkey.html
next_string: K2hash::addSubkey
---

# K2hash::addAttrPluginLib
Adds the user-defined library to handle attributes

## Description
```
public bool K2hash::addAttrPluginLib ( string $libfile )
```
Adds the user-defined library to handle attributes. k2hash supports for adding user-defined attributes to keys by using this method. 

## Parameters
- libfile  
Specifies the path to the dynamic linked library.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Adds the user-defined library to handle attributes
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->addAttrPluginLib("/tmp/libk2htestattr.so"));
$k2hash->close();
?>
```
The above example will output:
```
bool(true)
```

## See Also
- [K2hash::addAttr](k2h_addattr.html) - Adds the attribute to the key
- [K2hash::addAttrCryptPass](k2h_addattrcryptpass.html) - Adds the password to encrypt values
- [K2hash::cleanCommonAttribute](k2h_cleancommonattribute.html) - Initializes the common attributes
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
