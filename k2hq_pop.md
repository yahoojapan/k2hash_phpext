---
layout: contents
language: en-us
title: K2hQueue::pop
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_popja.html
lang_opp_word: To Japanese
prev_url: k2hq_isempty.html
prev_string: K2hQueue::isEmpty
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: k2hq_push.html
next_string: K2hQueue::push
---

# K2hQueue::pop
Removes and returns the removed element from the K2hQueue

## Description
```
 public stringfalseK2hQueue::pop ([ string $pass ] )
```
Removes and gets the removed element from the [K2hQueue](k2hq_class.html). 

## Parameters
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns a value. 

## Examples
- Example 1 - Gets a value from a [K2hQueue](k2hq_class.html) instance
```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_value");
var_dump($k2hqueue->pop());
unset($k2hqueue);
k2hpx_close($handle);
?>
```
The above example will output:
```
array(2) {
  [0]=>
  string(16) "test_queue_value"
}
```

## See Also
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
- [K2hQueue::read](k2hq_read.html) - Returns a key/value pair from the K2hQueue
- [K2hQueue::remove](k2hq_remove.html) - Removes a value from the K2hQueue
