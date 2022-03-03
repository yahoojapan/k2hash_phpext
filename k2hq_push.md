---
layout: contents
language: en-us
title: K2hQueue::push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_pushja.html
lang_opp_word: To Japanese
prev_url: k2hq_pop.html
prev_string: K2hQueue::pop
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: k2hq_read.html
next_string: K2hQueue::read
---

# K2hQueue::push
Adds a value to the K2hQueue

## Description
```
 public bool K2hQueue::push ( string $datavalue [, string $pass [, int $expire ]] )
```
Adds a value to the [K2hQueue](k2hq_class.html). 

## Parameters
- datavalue  
Specifies the value.
- pass  
Specifies the password to encrypt the value.
- expire  
Specifies the seconds to expire the value.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Adds a value to a [K2hQueue](k2hq_class.html) instance
```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
var_dump($k2hqueue->push("test_queue_value"));
var_dump($k2hqueue->pop());
unset($k2hqueue);
k2hpx_close($handle);
?>
```
The above example will output:
```
bool(true)
string(16) "test_queue_value"
```

## See Also
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
- [K2hQueue::read](k2hq_read.html) - Returns a key/value pair from the K2hQueue
- [K2hQueue::remove](k2hq_remove.html) - Removes a value from the K2hQueue
