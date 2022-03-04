---
layout: contents
language: en-us
title: k2hpx_set_debug_level_message
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_debug_level_messageja.html
lang_opp_word: To Japanese
prev_url: k2hpx_set_debug_level_error.html
prev_string: k2hpx_set_debug_level_error
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_set_debug_level_silent.html
next_string: k2hpx_set_debug_level_silent
---

# k2hpx_set_debug_level_message
Sets log level to info

## Description

```
void k2hpx_set_debug_level_message ( void )
```

Sets log level to 'message' (info) level. 

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples
- Example 1 - Set log level to info

```
<?php
var_dump(k2hpx_set_debug_file("/tmp/k2h.log"));
k2hpx_set_debug_level_message();
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
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silent.html) - Stops logging
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warning.html) - Sets log level to warning
- [k2hpx_unset_debug_file](k2hpx_unset_debug_file.html) - Writes logs to stderr
