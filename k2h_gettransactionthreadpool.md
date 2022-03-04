---
layout: contents
language: en-us
title: K2hash::getTransactionThreadPool
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_gettransactionthreadpoolja.html
lang_opp_word: To Japanese
prev_url: k2h_getsubkeys.html
prev_string: K2hash::getSubkeys
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getvalue.html
next_string: K2hash::getValue
---

# K2hash::getTransactionThreadPool
Gets the number of transaction workers

## Description

```
 public static int K2hash::getTransactionThreadPool ( void )
```

Gets the number of transaction workers. 

## Parameters
This function has no parameters.

## Return Values
Returns the number of transaction workers

## Examples
- Example 1 - Gets the number of transaction workers

```
<?php
var_dump(K2hash::gettransactionThreadPool());
?>
```

The above example will output:

```
int(0)
```


## See Also
- [K2hash::setTransactionThreadPool](k2h_settransactionthreadpool.html) - Sets the number of transaction workers
