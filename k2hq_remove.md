---
layout: contents
language: en-us
title: K2hQueue::remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_removeja.html
lang_opp_word: To Japanese
prev_url: k2hq_read.html
prev_string: K2hQueue::read
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: 
next_string: 
---

# K2hQueue::remove
Removes a value from the K2hQueue

## Description

```
 public bool K2hQueue::remove ( int $count [, string $pass ] )
```

Removes a value from the [K2hQueue](k2hq_class.html). 

## Parameters
- count  
Specifies the number of elements to remove.
- pass  
Specifies the password to decrypt the value.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Remove value from queue

```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_value1");
$k2hqueue->push("test_queue_value2");
var_dump($k2hqueue->count());
var_dump($k2hqueue->remove(1));
var_dump($k2hqueue->count());
unset($k2hqueue);
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
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
- [K2hQueue::read](k2hq_read.html) - Returns a key/value pair from the K2hQueue
