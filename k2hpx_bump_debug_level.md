---
layout: contents
language: en-us
title: k2hpx_bump_debug_level
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_bump_debug_levelja.html
lang_opp_word: To Japanese
prev_url: k2hpx_add_subkeys.html
prev_string: k2hpx_add_subkeys
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_clean_common_attr.html
next_string: k2hpx_clean_common_attr
---

# k2hpx_bump_debug_level
Changes the log level

## Description

```
void k2hpx_bump_debug_level ( void )
```

Changes the log level by each call. The order is 'error' , 'warning' , 'message' (info), 'dump' (debug), 'silent' (no logging). The log level turns 'error' when calling the function in the 'silent' level. 

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples
- Example 1 - Changes the log level

```
<?php
var_dump(k2hpx_bump_debug_level());
?>
```

The above example will output:

```
NULL
```


## See Also
- [k2hpx_set_debug_file](k2hpx_set_debug_file.html) - Writes log to the file
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_error.html) - Sets log level to error
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_message.html) - Sets log level to info
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silent.html) - Stops logging
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warning.html) - Sets log level to warning
- [k2hpx_unset_debug_file](k2hpx_unset_debug_file.html) - Writes logs to stderr
