---
layout: contents
language: en-us
title: K2hKeyQueue::count
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_countja.html
lang_opp_word: To Japanese
prev_url: k2hkq_construct.html
prev_string: K2hKeyQueue::__construct
top_url: k2hkq_class.html
top_string: K2hKeyQueue Class
next_url: k2hkq_dump.html
next_string: K2hKeyQueue::dump
---

# K2hKeyQueue::count
Counts elements in the K2hKeyQueue object

## Description

```
 public int K2hKeyQueue::count ( void )
```

Counts the number of elements in the [K2hKeyQueue](k2hkq_class.html) object. 

## Parameters
This function has no parameters.

## Return Values
Returns the number of elements in the [K2hKeyQueue](k2hkq_class.html).

## Examples
- Example 1 - Counts elements from [K2hKeyQueue](k2hkq_class.html)

```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
var_dump($k2hkeyqueue->count());
$k2hkeyqueue->push("test_queue_key", "test_queue_value");
var_dump($k2hkeyqueue->count());
var_dump($k2hkeyqueue->pop());
var_dump($k2hkeyqueue->count());
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

The above example will output:

```
int(0)
int(1)
array(2) {
  [0]=>
  string(14) "test_queue_key"
  [1]=>
  string(16) "test_queue_value"
}
int(0)
```

