---
layout: contents
language: en-us
title: K2hQueue::__construct
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: k2hq_count.html
next_string: K2hQueue::count
---

# K2hQueue::__construct
Creates a K2hQueue instance

## Description
```
public K2hQueue::__construct ( mixed $handle_res [, bool $is_fifo [, string $prefix ]] )
```
Creates a [K2hQueue](k2hq_class.html) instance. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that k2hpx_open returns.
- is_fifo  
Specifies true if the order of the [K2hQueue](k2hq_class.html) is FIFO, otherwise false.
- prefix  
Specifies the prefix of the [K2hQueue](k2hq_class.html).

## Examples
- Example 1 - Creates a [K2hQueue](k2hq_class.html) instance
```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
var_dump($k2hqueue->count());
$k2hqueue->push("test_queue_data");
var_dump($k2hqueue->count());
var_dump($k2hqueue->pop());
var_dump($k2hqueue->count());
unset($k2hqueue);
k2hpx_close($handle);
?>
```
The above example will output:
```
int(0)
int(1)
string(15) "test_queue_data"
int(0)
```

## See Also
- [K2hash::getQueue](k2h_getqueue.html) - Gets a K2hQueue object
