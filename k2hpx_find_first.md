---
layout: contents
language: en-us
title: k2hpx_find_first
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_find_firstja.html
lang_opp_word: To Japanese
prev_url: k2hpx_enable_transaction.html
prev_string: k2hpx_enable_transaction
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_find_free.html
next_string: k2hpx_find_free
---

# k2hpx_find_first
Gets the k2hash file handle to search for the key

## Description
```
mixed k2hpx_find_first ( mixed $handle_res [, stringnull $key ] )
```
Gets the k2hash file handle to searchf for the key. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- key  
Specifies the key to search for.

## Return Values
Returns the k2hash file handle to search for the key.

## Examples
- Example 1 - Gets the k2hash file handle to search for the key
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
$findhandle = k2hpx_find_first($handle);
var_dump($findhandle);
k2hpx_find_free($findhandle);
k2hpx_close($handle);
?>
```
The above example will output:
```
resource(5) of type (k2hfindhandle)
```

## See Also
- [k2hpx_find_free](k2hpx_find_free.html) - Releases resources of the k2h file handle to search for keys
- [k2hpx_find_get_key](k2hpx_find_get_key.html) - Gets keys using the k2h file handle to search for keys
- [k2hpx_find_get_subkeys](k2hpx_find_get_subkeys.html) - Gets keys using the k2h file handle to search for keys with linked with each key
- [k2hpx_find_get_value](k2hpx_find_get_value.html) - Gets value using the k2h file handle to search for keys
- [k2hpx_find_next](k2hpx_find_next.html) - Advances the internal pointer of the k2h file handle to search for keys
