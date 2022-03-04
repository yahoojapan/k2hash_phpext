---
layout: contents
language: en-us
title: K2hash::create
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_createja.html
lang_opp_word: To Japanese
prev_url: k2h_close.html
prev_string: K2hash::close
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_disabletransaction.html
next_string: K2hash::disableTransaction
---

# K2hash::create
Creates the k2hash file

## Description

```
 public static bool K2hash::create ( string $filepath [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
```

Creates the k2hash (.k2h) file.

## Parameters
- filepath  
Specifies the path to the k2hash (.k2h) file.
- maskbitcnt  
Specifies key mask bit. The default value is 8.
- cmaskbitcnt  
Specifies key collision mask bit. The default value is 4.
- maxelementcnt  
Specifies the max number of duplicated elements if a hash collision occurs. The default value is 1024(bytes).
- pagesize  
Specifies a block size of data. The default value is 512(bytes).

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Creates a k2hash file

```
<?php
var_dump(K2hash::create("/tmp/test_k2hash.k2h"));
?>
```

The above example will output:

```
bool(true)
```

