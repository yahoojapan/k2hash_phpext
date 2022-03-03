---
layout: contents
language: en-us
title: K2hIterator::current
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_currentja.html
lang_opp_word: To Japanese
prev_url: k2hiter_construct.html
prev_string: K2hIterator::__construct
top_url: k2hiter_class.html
top_string: K2hIterator Class
next_url: k2hiter_key.html
next_string: K2hIterator::key
---

# K2hIterator::current
Gets value of the current K2hIterator item

## Description
```
public stringfalseK2hIterator::current ( void )
```
Gets the value of the current element in an array of k2hash keys. 

## Parameters
This function has no parameters.

## Return Values
Returns the value of the current element in an array of k2hash keys. 

## Examples
- Example 1 - Gets a key/value pair using [K2hIterator](k2hiter_class.html)
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
k2hpx_set_value($handle, "test2", "value2");
$k2hiter = new K2hIterator($handle);
var_dump($k2hiter->current());
var_dump($k2hiter->key());
var_dump($k2hiter->next());
var_dump($k2hiter->current());
var_dump($k2hiter->key());
?>
```
The above example will output:
```
string(6) "value1"
string(5) "test1"
NULL
string(6) "value2"
string(5) "test2"
```

## See Also
- [K2hIterator::key](k2hiter_key.html) - Gets key of the current K2hIterator item
- [K2hIterator::next](k2hiter_next.html) - Advances the internal array pointer of k2hash keys
- [K2hIterator::rewind](k2hiter_rewind.html) - Rewinds the internal array pointer of k2hash keys
