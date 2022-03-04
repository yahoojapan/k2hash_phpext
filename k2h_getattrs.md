---
layout: contents
language: en-us
title: K2hash::getAttrs
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getattrsja.html
lang_opp_word: To Japanese
prev_url: k2h_getattrinfos.html
prev_string: K2hash::getAttrInfos
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getattrvalue.html
next_string: K2hash::getAttrValue
---

# K2hash::getAttrs
Gets attributes of the key

## Description

```
public arrayfalseK2hash::getAttrs ( string $key )
```

Gets attributes of the key. 

## Parameters
- key  
Specifies the key.

## Return Values
Returns attributes of the key, otherwise false. 

## Examples
- Example 1 - Get attributes of a key

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test", "value");
$k2hash->addAttr("test", "testattr", "testattrvalue");

var_dump($k2hash->getAttrs("test"));
$k2hash->close();
?>
```

The above example will output:

```
array(1) {
  [0]=>
  string(8) "testattr"
}
```


## See Also
- [K2hash::addAttr](k2h_addattr.html) - Adds the attribute to the key
- [K2hash::addAttrCryptPass](k2h_addattrcryptpass.html) - Adds the password to encrypt values
- [K2hash::addAttrPluginLib](k2h_addattrpluginlib.html) - Adds the user-defined library to handle attributes
- [K2hash::cleanCommonAttribute](k2h_cleancommonattribute.html) - Initializes the common attributes
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
