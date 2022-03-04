---
layout: contents
language: en-us
title: k2hpx_remove_all
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_remove_allja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_remove.html
prev_string: k2hpx_q_remove
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_remove.html
next_string: k2hpx_remove
---

# k2hpx_remove_all
Removes the key and the keys linked with the key

## Description

```
bool k2hpx_remove_all ( mixed $handle_res , string $key )
```

Removes the key and the keys linked with the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::removeAll](k2h_removeall.html) - Removes the key and the keys associated with the key
