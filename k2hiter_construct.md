---
layout: contents
language: en-us
title: K2hIterator::__construct
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: k2hiter_class.html
top_string: K2hIterator Class
next_url: k2hiter_current.html
next_string: K2hIterator::current
---

# K2hIterator::__construct
Creates a K2hIterator instance

## Description
```
public K2hIterator::__construct ( mixed $handle_res [, string $key ] )
```
Creates a [K2hIterator](k2hiter_class.html) instance. [K2hIterator](k2hiter_class.html) represents a pointer of an array of k2hash keys. 

## Parameters
- handle_res  
Specifies the k2hash (`.k2h`) file handle that k2hpx_open returns.
- key  
Specifies the key to search for.

## Examples
- Example 1 - Gets a [K2hIterator](k2hiter_class.html) instance
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
$k2hiter = new K2hIterator($handle);
var_dump($k2hiter->key());
unset($k2hiter);

k2hpx_set_value($handle, "test1", "value1", "sub");
$k2hiter = new K2hIterator($handle, "test1");
var_dump($k2hiter->key());
unset($k2hiter);
?>
```
The above example will output:
```
string(5) "test1"
string(3) "sub"
```

## See Also
- [K2hash::getIterator](k2h_getiterator.html) - Gets a K2hIterator object
