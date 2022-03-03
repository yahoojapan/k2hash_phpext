---
layout: contents
language: en-us
title: K2hIterator::rewind
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_rewindja.html
lang_opp_word: To Japanese
prev_url: k2hiter_next.html
prev_string: K2hIterator::next
top_url: k2hiter_class.html
top_string: K2hIterator Class
next_url: k2hiter_valid.html
next_string: K2hIterator::valid
---

# K2hIterator::rewind
Rewinds the internal array pointer of k2hash keys

## Description
```
 public void K2hIterator::rewind ( void )
```
Rewinds the internal array pointer of k2hash keys. 

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples
- Example 1 - Rewinds the internal array pointer of k2hash keys
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
k2hpx_set_value($handle, "test2", "value2");
$k2hiter = new K2hIterator($handle);
$k2hiter->next();
$k2hiter->rewind();
var_dump($k2hiter->key());
unset($k2hiter);
?>
```
The above example will output:
```
string(5) "test1"
```

## See Also
- [K2hIterator::current](k2hiter_current.html) - Gets value of the current K2hIterator item
- [K2hIterator::key](k2hiter_key.html) - Gets key of the current K2hIterator item
- [K2hIterator::next](k2hiter_next.html) - Advances the internal array pointer of k2hash keys
