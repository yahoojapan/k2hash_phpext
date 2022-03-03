---
layout: contents
language: en-us
title: k2hpx_print_attr_information
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_print_attr_informationja.html
lang_opp_word: To Japanese
prev_url: k2hpx_open.html
prev_string: k2hpx_open
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_print_attr_version.html
next_string: k2hpx_print_attr_version
---

# k2hpx_print_attr_information
Prints the attribute information

## Description
```
bool k2hpx_print_attr_information ( mixed $handle_res [, mixed $output ] )
```
Prints the attribute information. 

## Parameters
- handle_res
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Prints the attribute information
```
<?php
$handle = k2hpx_open_mem();
$fp = fopen("/tmp/k2hpx_print_attr_information.log", 'w');
k2hpx_print_attr_information($handle, $fp);
fclose($fp);
k2hpx_close($handle);
?>
```
The above example will output:
```
K2HASH attribute libraries:  K2H ATTR BUILTIN
```
