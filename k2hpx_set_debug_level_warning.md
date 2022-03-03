---
layout: contents
language: en-us
title: k2hpx_set_debug_level_warning
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_debug_level_warningja.html
lang_opp_word: To Japanese
prev_url: k2hpx_set_debug_level_silent.html
prev_string: k2hpx_set_debug_level_silent
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_set_transaction_thread_pool.html
next_string: k2hpx_set_transaction_thread_pool
---

# k2hpx_set_debug_level_warning
Sets log level to warning

## Description
```
void k2hpx_set_debug_level_warning ( void )
```
Sets log level to 'warning level. 

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples
- Example 1 - Sets log level to warning
```
<?php
var_dump(k2hpx_set_debug_file("/tmp/k2h.log"));
k2hpx_set_debug_level_warning();
?>
```
The above example will output:
```
NULL
```

## See Also
- [k2hpx_bump_debug_level](k2hpx_bump_debug_level.html) - Changes the log level
- [k2hpx_set_debug_file](k2hpx_set_debug_file.html) - Writes log to the file
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_error.html) - Sets log level to error
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_message.html) - Sets log level to info
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silent.html) - Stops logging
- [k2hpx_unset_debug_file](k2hpx_unset_debug_file.html) - Writes logs to stderr
