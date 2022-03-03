---
layout: contents
language: en-us
title: K2hash::enableTransaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_enabletransactionja.html
lang_opp_word: To Japanese
prev_url: k2h_dumpkeytable.html
prev_string: K2hash::dumpKeytable
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getattrinfos.html
next_string: K2hash::getAttrInfos
---

# K2hash::enableTransaction
Starts a transaction

## Description
```
 public bool K2hash::enableTransaction ([ string $transfile [, string $prefix [, string $param [, int $expire ]]]] )
```
Starts a transaction. 

## Parameters
- transfile  
Specifies the transaction log file path.
- prefix  
Specifies the prefix of transaction log entry.
- param  
Specifies the parameter string to pass to a transaction processing handler.
- expire  
Specifies the duration in second to expire a transaction log entry.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Starts a transaction
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->enabletransaction("/tmp/test_k2h_trans", "trans_prefix_", "myparam"));
$k2hash->close();
?>
```
The above example will output:
```
bool(true)
```

## See Also
- [K2hash::disableTransaction](k2h_disabletransaction.html) - Stops a transaction
