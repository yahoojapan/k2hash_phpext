---
layout: contents
language: en-us
title: k2hpx_set_debug_file
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_debug_fileja.html
lang_opp_word: To Japanese
prev_url: k2hpx_set_common_attr.html
prev_string: k2hpx_set_common_attr
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_set_debug_level_error.html
next_string: k2hpx_set_debug_level_error
---

# k2hpx_set_debug_file
Writes log to the file

## Description
```
bool k2hpx_set_debug_file ( string $filepath )
```
Writes log to the file. 

## Parameters
- filepath  
Specifies path to the file where to write logs.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Write log to a file
```
<?php
var_dump(k2hpx_set_debug_file("/tmp/k2h.log"));
?>
```
The above example will output:
```
NULL
```

## See Also
- [k2hpx_bump_debug_level](k2hpx_bump_debug_level.html) - Changes the log level
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_error.html) - Sets log level to error
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_message.html) - Sets log level to info
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silent.html) - Stops logging
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warning.html) - Sets log level to warning
- [k2hpx_unset_debug_file](k2hpx_unset_debug_file.html) - Writes logs to stderr
