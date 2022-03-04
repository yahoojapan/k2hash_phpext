---
layout: contents
language: en-us
title: K2hKeyQueue::__construct
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: k2hkq_class.html
top_string: K2hKeyQueue Class
next_url: k2hkq_count.html
next_string: K2hKeyQueue::count
---

# K2hKeyQueue::__construct
Creates a K2hKeyQueue instance

## Description

```
public K2hKeyQueue::__construct ( mixed $handle_res [, bool $is_fifo [, string $prefix ]] )
```

Creates a [K2hKeyQueue](k2hkq_class.html) instance. 

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that k2hpx_open returns.
- is_fifo  
Specifies true if the order of the [K2hKeyQueue](k2hkq_class.html) is FIFO, otherwise false.
- prefix  
Specifies the prefix of the [K2hKeyQueue](k2hkq_class.html).

## Examples
- Example 1 - Creates a [K2hKeyQueue](k2hkq_class.html) instance

```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
var_dump($k2hkeyqueue);
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

The above example will output:

```
object(K2hKeyQueue)#1 (0) {
}
```


## See Also
- [K2hash::getKeyQueue](k2h_getkeyqueue.html) - Gets a K2hKeyQueue object
