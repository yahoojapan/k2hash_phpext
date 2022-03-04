---
layout: contents
language: en-us
title: k2hpx_q_free
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_freeja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_empty.html
prev_string: k2hpx_q_empty
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_q_handle.html
next_string: k2hpx_q_handle
---

# k2hpx_q_free
Frees resources of the K2hQueue handle

## Description

```
bool k2hpx_q_free ( mixed $qhandle_res )
```

Frees resources of the [K2hQueue](k2hq_class.html) file handle. 

## Parameters
- qhandle_res  
Specifies the [K2hQueue](k2hq_class.html) file handle that k2hpx_keyq_handle returns.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Frees resource of the [K2hQueue](k2hq_class.html) file handle

```
<?php
$handle = k2hpx_open_mem();
$qhandle = k2hpx_q_handle($handle, true, "test_queue_");
var_dump(k2hpx_q_free($qhandle));
k2hpx_close($handle);
?>
```

The above example will output:

```
bool(true)
```

