---
layout: contents
language: en-us
title: K2hQueue::isEmpty
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_isemptyja.html
lang_opp_word: To Japanese
prev_url: k2hq_dump.html
prev_string: K2hQueue::dump
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: k2hq_pop.html
next_string: K2hQueue::pop
---

# K2hQueue::isEmpty
Returns whether the K2hQueue is empty

## Description

```
 public bool K2hQueue::isEmpty ( void )
```

Returns where the [K2hQueue](k2hq_class.html) is empty. 

## Parameters
This function has no parameters.

## Return Values
Returns true if the [K2hQueue](k2hq_class.html) object is empty, otherwise false. 

## Examples
- Example 1 - Gets an element of a [K2hQueue](k2hq_class.html) instance

```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
var_dump($k2hqueue->isEmpty());
$k2hqueue->push("test_queue_data");
var_dump($k2hqueue->isEmpty());
var_dump($k2hqueue->pop());
var_dump($k2hqueue->isEmpty());
unset($k2hqueue);
k2hpx_close($handle);
?>
```

The above example will output:

```
bool(true)
bool(false)
string(15) "test_queue_data"
bool(true)
```

