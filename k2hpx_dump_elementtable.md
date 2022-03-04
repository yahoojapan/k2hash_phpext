---
layout: contents
language: en-us
title: k2hpx_dump_elementtable
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_elementtableja.html
lang_opp_word: To Japanese
prev_url: k2hpx_disable_transaction.html
prev_string: k2hpx_disable_transaction
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_dump_full_keytable.html
next_string: k2hpx_dump_full_keytable
---

# k2hpx_dump_elementtable
Prints elements of the k2hash's hash table elements

## Description

```
bool k2hpx_dump_elementtable ( mixed $handle_res [, mixed $output ] )
```

Prints elements of the k2hash hashtable elements including headers, hash tables and sub-hash tables. 

## Parameters
- handle_res  
Specifies the k2hash (.k2h) file handle that k2hpx_open returns.
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## See Also
- [K2hash::dumpElementtable](k2h_dumpelementtable.html) - Prints elements of the k2hash's hash table elements
