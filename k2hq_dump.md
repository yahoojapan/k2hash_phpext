---
layout: contents
language: en-us
title: K2hQueue::dump
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_dumpja.html
lang_opp_word: To Japanese
prev_url: k2hq_count.html
prev_string: K2hQueue::count
top_url: k2hq_class.html
top_string: K2hQueue Class
next_url: k2hq_isempty.html
next_string: K2hQueue::isEmpty
---

# K2hQueue::dump
Prints the elements in the K2hQueue object

## Description

```
public bool K2hQueue::dump ([ mixed $output ] )
```

Gets the elements in the [K2hQueue](k2hq_class.html) object. 

## Parameters
- output  
Specifies a file stream of data to be written.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Prints elements in the [K2hQueue](k2hq_class.html) object

```
<?php
$handle = k2hpx_open_mem();

$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_key", "test_queue_value");
$fp = fopen("/tmp/k2hqueue_dump.log", 'w');
var_dump($k2hqueue->dump($fp));
fclose($fp);
$fp = fopen("/tmp/k2hqueue_dump.log", 'r');
if ($fp) {
        while (!feof($fp)) {
                if (($buf = fgets($fp, 4096)) !== false) {
                        echo $buf;
                }
        }
        fclose($fp);
}
unset($k2hqueue);
k2hpx_close($handle);
?>
```

The above example will output:

```
bool(true)
MARKER(test_queue_MARKER)= {
	START KEY               = test_queue_000000000000758C_0000000061D9E5C9_0000000006108B76
	END KEY                 = test_queue_000000000000758C_0000000061D9E5C9_0000000006108B76
}
[0]                    = test_queue_000000000000758C_0000000061D9E5C9_0000000006108B76
```

