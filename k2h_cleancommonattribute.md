---
layout: contents
language: en-us
title: K2hash::cleanCommonAttribute
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_cleancommonattributeja.html
lang_opp_word: To Japanese
prev_url: k2h_addsubkeys.html
prev_string: K2hash::addSubkeys
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_close.html
next_string: K2hash::close
---

# K2hash::cleanCommonAttribute
Initializes the common attributes

## Description

```
public bool K2hash::cleanCommonAttribute ( void )
```

Initializes the common attributes.
Common attributes are:
- mtime  
true when keeping the last timestamp to modify values.
- encrypt  
true to encrypt values.
- history  
true to track values changes.
- expire  
true to expire values.

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Initializes the common attribute

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->cleanCommonAttribute());
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
- [K2hash::addAttrPluginLib](k2h_addattrpluginlib.html) - Adds the user-defined library to handle attributes
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
