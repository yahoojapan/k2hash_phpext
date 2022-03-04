---
layout: contents
language: en-us
title: K2hKeyQueue::push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_pushja.html
lang_opp_word: To Japanese
prev_url: k2hkq_pop.html
prev_string: K2hKeyQueue::pop
top_url: k2hkq_class.html
top_string: K2hKeyQueue Class
next_url: k2hkq_read.html
next_string: K2hKeyQueue::read
---

# K2hKeyQueue::push
Adds a key/value pair to the K2hKeyQueue

## Description

```
 public bool K2hKeyQueue::push ( string $key , string $value [, string $pass [, int $expire ]] )
```

Adds a key/value pair to the [K2hKeyQueue](k2hkq_class.html). 

## Parameters
- key  
Specifies the key.
- value  
Specifies the value.
- pass  
Specifies the password to encrypt the value.
- expire  
Specifies the seconds to expire the value.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Gets an element from a [K2hKeyQueue](k2hkq_class.html) instance

```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
var_dump($k2hkeyqueue->push("test_queue_key", "test_queue_value"));
var_dump($k2hkeyqueue->pop());
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

The above example will output:

```
bool(true)
array(2) {
  [0]=>
  string(14) "test_queue_key"
  [1]=>
  string(16) "test_queue_value"
}
```


## See Also
- [K2hKeyQueue::pop](k2hkq_pop.html) - Removes and returns the removed element from the K2hKeyQueue
- [K2hKeyQueue::read](k2hkq_read.html) - Returns a key/value pair from the K2hKeyQueue
- [K2hKeyQueue::remove](k2hkq_remove.html) - Removes a key/value pair from the K2hKeyQueue
