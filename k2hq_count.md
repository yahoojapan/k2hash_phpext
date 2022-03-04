---
layout: contents
language: en-us
title: K2hQueue::count
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_countja.html
lang_opp_word: To Japanese
prev_url: k2hq_construct.html
prev_string: K2hQueue::__construct
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: k2hq_dump.html
next_string: K2hQueue::dump
---

# K2hQueue::count
Counts elements in the K2hQueue object

## Description

```
public intfalseK2hQueue::count ( void )
```

Counts the number of elements in the [K2hQueue](k2hq_class.html) object. 

## Parameters
This function has no parameters.

## Return Values
Returns the number of elements in the [K2hQueue](k2hq_class.html). 

## Examples
- Example 1 - Gets a element from [K2hQueue](k2hq_class.html)

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
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
