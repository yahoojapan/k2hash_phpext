---
layout: contents
language: en-us
title: K2hash::getIterator
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getiteratorja.html
lang_opp_word: To Japanese
prev_url: k2h_getattrversioninfos.html
prev_string: K2hash::getAttrVersionInfos
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getkeyqueue.html
next_string: K2hash::getKeyQueue
---

# K2hash::getIterator
Gets a K2hIterator object

## Description
```
 public mixed K2hash::getIterator ( string $key )
```
Gets a [K2hIterator](k2hiter_class.html) object that points to the first element of keys. [K2hIterator](k2hiter_class.html) is a class to handle the array of k2hash keys. 

## Parameters
- key  
Specifies the key to search for in the array of k2hash keys.

## Return Values
Returns a [K2hIterator](k2hiter_class.html) object. 

## Examples
- Example 1 - Gets a [K2hIterator](k2hiter_class.html) object
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value1");
$k2hash->setValue("test2", "value2");
$k2hash->setValue("test3", "value3");
$iterator = $k2hash->getIterator();
$count = 0;
foreach($iterator as $val){
    $count++;
}
echo $count;
?>
```
The above example will output:
```
3
```

## See Also
- [K2hIterator::__construct](k2hiter_construct.html) - Creates a K2hIterator instance
