---
layout: contents
language: en-us
title: K2hIterator::valid
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_validja.html
lang_opp_word: To Japanese
prev_url: k2hiter_rewind.html
prev_string: K2hIterator::rewind
top_url: k2hiter_class.html
top_string: K2hIterator Class
next_url: 
next_string: 
---

# K2hIterator::valid
Returns whether the current K2hIterator item is valid

## Description
```
 public bool K2hIterator::valid ( void )
```
Returns whether the current pointer to an element of k2hash keys is valid. 

## Parameters
This function has no parameters.

## Return Values
Returns true if the current pointer to an element of k2hash keys is valid, otherwise false. 

## Examples
- Example 1 - Returns whether the current pointer to an element of k2hash keys is valid
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
$k2hiter = new K2hIterator($handle);
var_dump($k2hiter->valid());
unset($k2hiter);
?>
```
The above example will output:
```
bool(true)
```
