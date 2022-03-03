---
layout: contents
language: en-us
title: K2hKeyQueue::pop
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_popja.html
lang_opp_word: To Japanese
prev_url: k2hkq_isempty.html
prev_string: K2hKeyQueue::isEmpty
top_url: k2hkq_class.html
top_string: K2hKeyQueue Class
next_url: k2hkq_push.html
next_string: K2hKeyQueue::push
---

# K2hKeyQueue::pop
Removes and returns the removed element from the K2hKeyQueue

## Description
```
public arrayfalseK2hKeyQueue::pop ([ string $pass ] )
```
Removes and gets the removed element from the [K2hKeyQueue](k2hkq_class.html). 

## Parameters
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns a key/value pair. 

## Examples
- Example 1 - Gets an element from a [K2hKeyQueue](k2hkq_class.html) instance
```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
$k2hkeyqueue->push("test_queue_key", "test_queue_value");
var_dump($k2hkeyqueue->pop());
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```
The above example will output:
```
array(2) {
  [0]=>
  string(14) "test_queue_key"
  [1]=>
  string(16) "test_queue_value"
}
```

## See Also
- [K2hKeyQueue::push](k2hkq_push.html) - Adds a key/value pair to the K2hKeyQueue
- [K2hKeyQueue::read](k2hkq_read.html) - Returns a key/value pair from the K2hKeyQueue
- [K2hKeyQueue::remove](k2hkq_remove.html) - Removes a key/value pair from the K2hKeyQueue
