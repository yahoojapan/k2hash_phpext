---
layout: contents
language: en-us
title: K2hash::printState
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_printstateja.html
lang_opp_word: To Japanese
prev_url: k2h_opentempfile.html
prev_string: K2hash::openTempfile
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_printversion.html
next_string: K2hash::printVersion
---

# K2hash::printState
Prints k2hash data statistics

## Description
```
 public bool K2hash::printState ([ mixed $output ] )
```
Prints k2hash data statistics. 

## Parameters
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Prints k2hash data statistics
```
<?php
K2hash::create("/tmp/test_k2hash.k2h");
$k2hash = new K2hash();
$k2hash->openRO("/tmp/test_k2hash.k2h");
$fp = fopen("/tmp/k2hash_print_state.log", 'w');
$k2hash->printState($fp);
fclose($fp);
$k2hash->close();

$fp = fopen("/tmp/k2hash_print_state.log", 'r');
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

Total Key count         = 16384
System usage            = 2695168 byte
Total real data size    = 133431296 byte
real data ratio         = 98 %
}
```
