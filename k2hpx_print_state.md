---
layout: contents
language: en-us
title: k2hpx_print_state
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_print_stateja.html
lang_opp_word: To Japanese
prev_url: k2hpx_print_attr_version.html
prev_string: k2hpx_print_attr_version
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_print_version.html
next_string: k2hpx_print_version
---

# k2hpx_print_state
Prints k2hash data statistics

## Description

```
bool k2hpx_print_state ( mixed $handle_res [, mixed $output ] )
```

Prints k2hash data statistics. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that [k2hpx_open](k2hpx_open.html) returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::printState](k2h_printstate.html) - Prints k2hash data statistics
