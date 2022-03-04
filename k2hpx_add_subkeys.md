---
layout: contents
language: en-us
title: k2hpx_add_subkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_subkeysja.html
lang_opp_word: To Japanese
prev_url: k2hpx_add_subkey.html
prev_string: k2hpx_add_subkey
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_bump_debug_level.html
next_string: k2hpx_bump_debug_level
---

# k2hpx_add_subkeys
Adds the subkeys to the key

## Description

```
bool k2hpx_add_subkeys ( mixed $handle_res , string $key , array $subkeys )
```

Associates the keys with the other key. The key that is added to the other key is called 'subkey'. The key that adds the other key to is 'parent key'. A parent key can associates many subkeys.

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that k2hpx_open returns.
- key  
Specifies the key that link with the subkeys.
- subkeys  
Specifies the array of keys(subkeys) that link with the key.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::addSubkeys](k2h_addsubkeys.html) - Adds the subkeys to the key
