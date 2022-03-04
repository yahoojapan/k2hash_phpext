---
layout: contents
language: en-us
title: K2hash::getKeyQueue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getkeyqueueja.html
lang_opp_word: To Japanese
prev_url: k2h_getiterator.html
prev_string: K2hash::getIterator
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getqueue.html
next_string: K2hash::getQueue
---

# K2hash::getKeyQueue
Gets a K2hKeyQueue object

## Description

```
 public mixed K2hash::getKeyQueue ([ bool $is_filo [, string $prefix ]] )
```

Gets a [K2hKeyQueue](k2hkq_class.html) object. [K2hKeyQueue](k2hkq_class.html) is a class to handle [K2hKeyQueue](k2hkq_class.html) object that holds key/value pairs as elements

## Parameters
- is_filo  
Specifies true if the order of elements is FIFO, otherwise false.
- prefix  
Specifies the prefix of the [K2hKeyQueue](k2hkq_class.html).

## Return Values
Gets a K2hKeyQueue object. 

## See Also
- [K2hKeyQueue::__construct](k2hkq_construct.html) - Creates a K2hKeyQueue instance
