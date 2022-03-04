---
layout: contents
language: en-us
title: K2hash::getQueue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getqueueja.html
lang_opp_word: To Japanese
prev_url: k2h_getkeyqueue.html
prev_string: K2hash::getKeyQueue
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getstream.html
next_string: K2hash::getStream
---

# K2hash::getQueue
Gets a K2hQueue object

## Description

```
 public mixed K2hash::getQueue ([ bool $is_filo [, string $prefix ]] )
```

Gets a [K2hQueue](k2hq_class.html) object. [K2hQueue](k2hq_class.html) is a class to handle [K2hQueue](k2hq_class.html) object that holds key/value pairs as elements. 

## Parameters
- is_filo  
Specifies true if the order of elements is FIFO, otherwise false.
- prefix  
Specifies the prefix of the [K2hQueue](k2hq_class.html).

## Return Values
Gets a [K2hQueue](k2hq_class.html) object. 

## See Also
- [K2hQueue::__construct](k2hq_construct.html) - Creates a K2hQueue instance
