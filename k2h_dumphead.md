---
layout: contents
language: en-us
title: K2hash::dumpHead
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_dumpheadja.html
lang_opp_word: To Japanese
prev_url: k2h_dumpfullkeytable.html
prev_string: K2hash::dumpFullKeytable
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_dumpkeytable.html
next_string: K2hash::dumpKeytable
---

# K2hash::dumpHead
Prints the k2hash's headers

## Description
```
 public bool K2hash::dumpHead ([ mixed $output ] )
```
 Prints the k2hash's headers. 

## Parameters
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Prints k2hash headers
```
<?php
K2hash::create("/tmp/test_k2hash.k2h");
$k2hash = new K2hash();
$k2hash->openRO("/tmp/test_k2hash.k2h");
$fp = fopen("/tmp/k2hash_dump_head.log", 'w');
$k2hash->dumpHead($fp);
fclose($fp);
$k2hash->close();

$fp = fopen("/tmp/k2hash_dump_head.log", 'r');
if ($fp) {
        while (!feof($fp)) {
                if (($buf = fgets($fp, 4096)) !== false) {
                        echo $buf;
                }
        }
        fclose($fp);
}
?>
```
The above example will output:
```
...
  Last area update {
    Date                    = Fri Jan  7 06:25:32 2022
    sec                     = 1641536732
    usec                    = 787684
  }
```

## See Also
- [K2hash::dumpElementtable](k2h_dumpelementtable.html) - Prints elements of the k2hash's hash table elements
- [K2hash::dumpFull](k2h_dumpfull.html) - Prints the k2hash's hash tables in details
- [K2hash::dumpFullKeytable](k2h_dumpfullkeytable.html) - Prints details of the k2hash's hash tables
- [K2hash::dumpKeytable](k2h_dumpkeytable.html) - Prints the k2hash's hash tables
