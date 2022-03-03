---
layout: contents
language: en-us
title: K2hash::setCommonAttribute
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_setcommonattributeja.html
lang_opp_word: To Japanese
prev_url: k2h_rename.html
prev_string: K2hash::rename
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_settransactionthreadpool.html
next_string: K2hash::setTransactionThreadPool
---

# K2hash::setCommonAttribute
Sets the common attributes

## Description
```
 public bool K2hash::setCommonAttribute ([ int $is_mtime [, int $is_history [, int $is_encrypt [, string $passfile [, int $is_expire [, int $expire ]]]]]] )
```
Sets the common attributes. See the attributes in the parameters section. 

## Parameters
- is_mtime  
Specifies true when keeping the last timestamp to modify the value, otherwise false.
- is_history  
Specifies true to track changes, otherwise false.
- is_encrypt  
Specifies true to encrypt the value, otherwise false.
- passfile  
Specifies the file path that contains the password to encrypt the value.
- is_expire  
Specifies true to expire values, otherwise false.
- expire  
Specifies the duration in second to expire values.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Sets the common attributes
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->setCommonAttribute(K2H_ATTR_ENABLE, K2H_ATTR_ENABLE, K2H_ATTR_DEFAULT, '', K2H_ATTR_ENABLE, 300));
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
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
