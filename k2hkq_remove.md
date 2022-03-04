---
layout: contents
language: en-us
title: K2hKeyQueue::remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_removeja.html
lang_opp_word: To Japanese
prev_url: k2hkq_read.html
prev_string: K2hKeyQueue::read
top_url: k2hkq_class.html
top_string: K2hKeyQueue Class
next_url: 
next_string: 
---

# K2hKeyQueue::remove
Removes a key/value pair from the K2hKeyQueue

## Description

```
 public bool K2hKeyQueue::remove ( int $count [, string $pass ] )
```

Removes a key/value pair from the [K2hKeyQueue](k2hkq_class.html). 

## Parameters
- count  
Specifies the number of elements to remove.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Gets an element from a [K2hKeyQueue](k2hkq_class.html) instance 

```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
$k2hkeyqueue->push("test_queue_key1", "test_queue_value1");
$k2hkeyqueue->push("test_queue_key2", "test_queue_value2");
var_dump($k2hkeyqueue->count());
var_dump($k2hkeyqueue->remove(1));
var_dump($k2hkeyqueue->count());
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

The above example will output:

```
int(2)
bool(true)
int(1)
```


## See Also
- [K2hKeyQueue::pop](k2hkq_pop.html) - Removes and returns the removed element from the K2hKeyQueue
- [K2hKeyQueue::push](k2hkq_push.html) - Adds a key/value pair to the K2hKeyQueue
- [K2hKeyQueue::read](k2hkq_read.html) - Returns a key/value pair from the K2hKeyQueue
