---
layout: contents
language: en-us
title: K2hash::disableTransaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_disabletransactionja.html
lang_opp_word: To Japanese
prev_url: k2h_create.html
prev_string: K2hash::create
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_dumpelementtable.html
next_string: K2hash::dumpElementtable
---

# K2hash::disableTransaction
Stops a transaction

## Description

```
 public bool K2hash::disableTransaction ( void )
```

Stops a transaction. 

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Stops a transaction

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->disableTransaction());
$k2hash->close();
?>
```

The above example will output:

```
bool(true)
```


## See Also
- [K2hash::enableTransaction](k2h_enabletransaction.html) - Starts a transaction
