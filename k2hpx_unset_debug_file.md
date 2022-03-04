---
layout: contents
language: en-us
title: k2hpx_unset_debug_file
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_unset_debug_fileja.html
lang_opp_word: To Japanese
prev_url: k2hpx_unload_transaction_library.html
prev_string: k2hpx_unload_transaction_library
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_unset_transaction_thread_pool.html
next_string: k2hpx_unset_transaction_thread_pool
---

# k2hpx_unset_debug_file
Set log output  to stderr

## Description

```
void k2hpx_unset_debug_file ( void )
```

Set log output  to stderr.

## Parameters
This function has no parameters.

## Examples
- Example 1 - Set log output  to stderr

```
<?php
var_dump(k2hpx_unset_debug_file());
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
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warning.html) - Sets log level to warning
