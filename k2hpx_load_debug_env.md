---
layout: contents
language: en-us
title: k2hpx_load_debug_env
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_debug_envja.html
lang_opp_word: To Japanese
prev_url: k2hpx_load_archive.html
prev_string: k2hpx_load_archive
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_load_hash_library.html
next_string: k2hpx_load_hash_library
---

# k2hpx_load_debug_env
Loads environment variables

## Description
```
bool k2hpx_load_debug_env ( void )
```
Loads environment variables.

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Loads environment variables
```
<?php
var_dump(k2hpx_load_debug_env());
?>
```
The above example will output:
```
bool(true)
```
