---
layout: contents
language: en-us
title: K2hQueue::read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_readja.html
lang_opp_word: To Japanese
prev_url: k2hq_push.html
prev_string: K2hQueue::push
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: k2hq_remove.html
next_string: K2hQueue::remove
---

# K2hQueue::read
Returns a key/value pair from the K2hQueue

## Description
```
public stringfalseK2hQueue::read ([ int $pos [, string $pass ]] )
```
Returns a value from the [K2hQueue](k2hq_class.html). This operation will not remove the value from the [K2hQueue](k2hq_class.html). 

### Note
This operation will not remove the element from the [K2hQueue](k2hq_class.html). Use [K2hQueue::pop](k2hq_pop.html) to removes and returns the element instead. 

## Parameters
- pos  
Specifies the position of the [K2hQueue](k2hq_class.html).
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns a value. 

## Examples
- Example 1 - Gets a value from a [K2hQueue](k2hq_class.html) instnace
```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_value");
var_dump($k2hqueue->read(0));
unset($k2hqueue);
k2hpx_close($handle);
?>
```
The above example will output:
```
string(16) "test_queue_value"
```

## See Also
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
- [K2hQueue::remove](k2hq_remove.html) - Removes a value from the K2hQueue
