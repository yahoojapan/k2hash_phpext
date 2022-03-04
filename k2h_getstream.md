---
layout: contents
language: en-us
title: K2hash::getStream
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getstreamja.html
lang_opp_word: To Japanese
prev_url: k2h_getqueue.html
prev_string: K2hash::getQueue
top_url: k2h_class.html
top_string: K2hash Class
next_url: k2h_getsubkeys.html
next_string: K2hash::getSubkeys
---

# K2hash::getStream
Gets a k2hash file stream

## Description

```
 public mixed K2hash::getStream ( string $key , string $mode )
```

Gets a k2hash file stream. 

## Parameters
- key  
Specifies the key that the k2hash stream points to.
- mode  
Specifies how to handle the stream. See [fopen](http://docs.php.net/manual/en/function.fopen.php) for details.

## Return Values
Returns a h2hash file stream. 

## Examples
- Example 1 - Gets value using the k2hash file stream

```
<?php
K2hash::create("/tmp/test_k2hash.k2h");
$k2hash = new K2hash();
$k2hash->openRW("/tmp/test_k2hash.k2h");
$k2hash->setValue("test1", "value1");
$stream = $k2hash->getStream("test1", "r+");
var_dump(fread($stream, 6));
while (!feof($stream)) {
      if (($buf = fgets($stream, 4096)) !== false) {
           echo $buf;
      }
}
fclose($stream);
$k2hash->close();
?>
```

The above example will output:

```
string(6) "value1"
```

