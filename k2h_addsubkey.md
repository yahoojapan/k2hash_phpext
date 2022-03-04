---
layout: contents
language: en-us
title: K2hash::addSubkey
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addsubkeyja.html
lang_opp_word: To Japanese
prev_url: k2h_addattrpluginlib.html
prev_string: K2hash::addAttrPluginLib
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_addsubkeys.html
next_string: K2hash::addSubkeys
---

# K2hash::addSubkey
Associates the key with the other key

## Description

```
public bool K2hash::addSubkey ( string $key , string $subkey )
```

Associates the key with the other key. The key that is added to the other key is called 'subkey'. The key that adds the other key to is 'parent key'. A parent key can associates many subkeys.

## Parameters
- key  
Specifies the key that link with the subkey.
- subkey  
Specifies the subkey that link with the key.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Adds the subkey to the key

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->addSubkey("test", "sub");
var_dump($k2hash->getSubkeys("test"));
$k2hash->close();
?>
```

The above example will output:

```
array(1) {
  [0]=>
  string(3) "sub"
}
```


## See Also
- [K2hash::addSubkeys](k2h_addsubkeys.html) - Adds the subkeys to the key
- [K2hash::getSubkeys](k2h_getsubkeys.html) - Gets an array of keys associated with the key
