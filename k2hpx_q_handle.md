---
layout: contents
language: en-us
title: k2hpx_q_handle
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_handleja.html
lang_opp_word: To Japanese
prev_url: k2hpx_q_free.html
prev_string: k2hpx_q_free
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_q_pop.html
next_string: k2hpx_q_pop
---

# k2hpx_q_handle
Gets the K2hQueue file handle

## Description

```
mixed k2hpx_q_handle ( mixed $handle_res [, bool $is_filo [, stringnull $prefix ]] )
```

Gets the [K2hQueue](k2hq_class.html) handle. 

## Parameters
- handle_res  
Specifies the k2h file handle that [k2hpx_open](k2hpx_open.html) returns.
- is_filo  
Specifies true if the order of the [K2hQueue](k2hq_class.html) is FIFO, otherwise false.
- prefix  
Specifies the prefix of the [K2hQueue](k2hq_class.html).

## Return Values
Returns the [K2hQueue](k2hq_class.html) file handle. 

## Examples
- Example 1 - Gets the [K2hQueue](k2hq_class.html) file handle

```
<?php
$handle = k2hpx_open_mem();
$qhandle = k2hpx_q_handle($handle, true, "test_queue_");
var_dump($qhandle);
k2hpx_q_free($qhandle);
k2hpx_close($handle);
?>
```

The above example will output:

```
resource(5) of type (k2hqhandle)
```


## See Also
- [K2hQueue::__construct](k2hq_construct.html) - Creates a K2hQueue instance
