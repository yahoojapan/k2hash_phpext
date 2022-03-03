---
layout: contents
language: en-us
title: k2hpx_find_next
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_find_nextja.html
lang_opp_word: To Japanese
prev_url: k2hpx_find_get_value.html
prev_string: k2hpx_find_get_value
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_get_attr_value.html
next_string: k2hpx_get_attr_value
---

# k2hpx_find_next
Advances the internal pointer of the k2hash file handle to search for keys

## Description
```
mixed k2hpx_find_next ( mixed $findhandle_res )
```
Advances the internal pointer of the k2hash file handle to search for keys. 

## Parameters
- findhandle_res  
Specifies the k2hash file handle that [k2hpx_find_first](k2hpx_find_first.html) returns.

## Return Values
Returns the pointer to the next key. 

## Examples
- Example 1 - Gets the key and the value using the k2hash file handle that [k2hpx_find_first](k2hpx_find_first.html) returns
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
k2hpx_set_value($handle, "test2", "value2");
$findhandle = k2hpx_find_first($handle);
var_dump($findhandle);
var_dump(k2hpx_find_get_key($findhandle));
var_dump(k2hpx_find_next($findhandle));
var_dump(k2hpx_find_get_key($findhandle));
k2hpx_find_free($findhandle);
k2hpx_close($handle);
?>
```
The above example will output:
```
resource(5) of type (k2hfindhandle)
string(5) "test1"
resource(6) of type (k2hfindhandle)
string(5) "test2"
```

## See Also
- [k2hpx_find_first](k2hpx_find_first.html) - Gets the k2h file handle to search for the key
- [k2hpx_find_free](k2hpx_find_free.html) - Releases resources of the k2h file handle to search for keys
- [k2hpx_find_get_key](k2hpx_find_get_key.html) - Gets keys using the k2h file handle to search for keys
- [k2hpx_find_get_subkeys](k2hpx_find_get_subkeys.html) - Gets keys using the k2h file handle to search for keys with linked with each key
- [k2hpx_find_get_value](k2hpx_find_get_value.html) - Gets value using the k2h file handle to search for keys
