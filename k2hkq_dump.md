---
layout: contents
language: en-us
title: K2hKeyQueue::dump
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_dumpja.html
lang_opp_word: To Japanese
prev_url: k2hkq_count.html
prev_string: K2hKeyQueue::count
top_url: k2hkq_class.html
top_string: K2hKeyQueue Class
next_url: k2hkq_isempty.html
next_string: K2hKeyQueue::isEmpty
---

# K2hKeyQueue::dump
Prints the elements in the K2hKeyQueue object

## Description

```
 public bool K2hKeyQueue::dump ([ mixed $output ] )
```

Gets the elements in the [K2hKeyQueue](k2hkq_class.html) object. 

## Parameters
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Gets the elements in the [K2hKeyQueue](k2hkq_class.html) object

```
<?php
$handle = k2hpx_open_mem();

$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
$k2hkeyqueue->push("test_queue_key", "test_queue_value");
$fp = fopen("/tmp/k2hkeyqueue_dump.log", 'w');
$k2hkeyqueue->dump($fp);
fclose($fp);
$fp = fopen("/tmp/k2hkeyqueue_dump.log", 'r');
if ($fp) {
        while (!feof($fp)) {
                if (($buf = fgets($fp, 4096)) !== false) {
                        echo $buf;
                }
        }
        fclose($fp);
}
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

The above example will output:

```
bool(true)
MARKER(test_queue_MARKER)= {
        START KEY               = test_queue_00000000000071EC_0000000061D9D54D_0000000031DD32D2
        END KEY                 = test_queue_00000000000071EC_0000000061D9D54D_0000000031DD32D2
}
[0]                    = test_queue_00000000000071EC_0000000061D9D54D_0000000031DD32D2
```

