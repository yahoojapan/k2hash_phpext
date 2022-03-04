---
layout: contents
language: en-us
title: K2hash::setTransactionThreadPool
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_settransactionthreadpoolja.html
lang_opp_word: To Japanese
prev_url: k2h_setcommonattribute.html
prev_string: K2hash::setCommonAttribute
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_setvalue.html
next_string: K2hash::setValue
---

# K2hash::setTransactionThreadPool
Sets the number of transaction workers

## Description

```
 public static bool K2hash::setTransactionThreadPool ( int $count )
```

Sets the number of transaction workers.

## Parameters
- count  
Specifies the number of transaction workers.

## Return Values
Returns true on success or false on failure.

## Examples
- Example 1 - Specifies the number of transaction workers

```
<?php
var_dump(K2hash::settransactionThreadPool(1));
var_dump(K2hash::gettransactionThreadPool());
?>
```

The above example will output:

```
bool(true)
int(1)
```


## See Also
- [K2hash::getTransactionThreadPool](k2h_gettransactionthreadpool.html) - Gets the number of transaction workers
