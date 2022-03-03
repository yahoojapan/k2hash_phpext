---
layout: contents
language: en-us
title: k2hpx_find_get_subkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_find_get_subkeysja.html
lang_opp_word: To Japanese
prev_url: k2hpx_find_get_key.html
prev_string: k2hpx_find_get_key
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_find_get_value.html
next_string: k2hpx_find_get_value
---

# k2hpx_find_get_subkeys
Gets keys using the k2hash file handle to search for keys with linked with each key

## Description
```
array k2hpx_find_get_subkeys ( mixed $findhandle_res )
```
Gets keys using the k2hash file handle to search for keys with linked with each key. 

## Parameters
- findhandle_res  
Specifies the k2hash file handle that k2hpx_find_first returns.

## Return Values
Returns an array of keys that is lnked with each keys. 

## Examples
- Example 1 - Gets keys using the k2hash file handle to search for keys with linked with each key
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
k2hpx_set_value($handle, "subkey1", "sub-value1");
k2hpx_add_subkey($handle, "test1", "subkey1");
$findhandle = k2hpx_find_first($handle);
var_dump($findhandle);
var_dump(k2hpx_find_get_subkeys($findhandle));
k2hpx_find_free($findhandle);
k2hpx_close($handle);
?>
```
The above example will output:
```
resource(5) of type (k2hfindhandle)
array(1) {
  [0]=>
  string(7) "subkey1"
}
```

## See Also
- [k2hpx_find_first](k2hpx_find_first.html) - Gets the k2h file handle to search for the key
- [k2hpx_find_free](k2hpx_find_free.html) - Releases resources of the k2h file handle to search for keys
- [k2hpx_find_get_key](k2hpx_find_get_key.html) - Gets keys using the k2h file handle to search for keys
- [k2hpx_find_get_value](k2hpx_find_get_value.html) - Gets value using the k2h file handle to search for keys
- [k2hpx_find_next](k2hpx_find_next.html) - Advances the internal pointer of the k2h file handle to search for keys
