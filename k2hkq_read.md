---
layout: contents
language: en-us
title: K2hKeyQueue::read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_readja.html
lang_opp_word: To Japanese
prev_url: k2hkq_push.html
prev_string: K2hKeyQueue::push
top_url: k2hkq_class.html
top_string: K2hKeyQueue Class
next_url: k2hkq_remove.html
next_string: K2hKeyQueue::remove
---

# K2hKeyQueue::read
Returns a key/value pair from the K2hKeyQueue

## Description

```
public arrayfalseK2hKeyQueue::read ([ int $pos [, string $pass ]] )
```

Returns a key/value pair from the [K2hKeyQueue](k2hkq_class.html). 

### Note
This operation will not remove the element from the [K2hKeyQueue](k2hkq_class.html). Use [K2hKeyQueue::pop](k2hkq_pop.html) to removes and returns the element instead. 

## Parameters
- pos  
Specifies the position of the [K2hKeyQueue](k2hkq_class.html).
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
var_dump($k2hkeyqueue->read(0));
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
- [K2hKeyQueue::pop](k2hkq_pop.html) - Removes and returns the removed element from the K2hKeyQueue
- [K2hKeyQueue::push](k2hkq_push.html) - Adds a key/value pair to the K2hKeyQueue
- [K2hKeyQueue::remove](k2hkq_remove.html) - Removes a key/value pair from the K2hKeyQueue
