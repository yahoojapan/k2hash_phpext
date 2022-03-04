---
layout: contents
language: en-us
title: K2hIterator::key
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_keyja.html
lang_opp_word: To Japanese
prev_url: k2hiter_current.html
prev_string: K2hIterator::current
top_url: k2hiter_class.html
top_string: K2hIterator Class
next_url: k2hiter_next.html
next_string: K2hIterator::next
---

# K2hIterator::key
Gets key of the current K2hIterator item

## Description

```
public stringfalseK2hIterator::key ( void )
```

Gets the key in an array of k2hash keys. 

## Parameters
This function has no parameters.

## Return Values
Returns the key. 

## Examples
- Example 1 - Gets a key using [K2hIterator](k2hiter_class.html)

```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
k2hpx_set_value($handle, "test2", "value2");
$k2hiter = new K2hIterator($handle);
var_dump($k2hiter->key());
unset($k2hiter);
?>
```

The above example will output:

```
string(5) "test2"
```


## See Also
- [K2hIterator::current](k2hiter_current.html) - Gets value of the current K2hIterator item
- [K2hIterator::next](k2hiter_next.html) - Advances the internal array pointer of k2hash keys
- [K2hIterator::rewind](k2hiter_rewind.html) - Rewinds the internal array pointer of k2hash keys
