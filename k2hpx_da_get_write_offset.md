---
layout: contents
language: en-us
title: k2hpx_da_get_write_offset
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_da_get_write_offsetja.html
lang_opp_word: To Japanese
prev_url: k2hpx_da_get_value.html
prev_string: k2hpx_da_get_value
top_url: k2hpx.html
top_string: k2hash Functions
next_url: k2hpx_da_set_offset.html
next_string: k2hpx_da_set_offset
---

# k2hpx_da_get_write_offset
Gets the k2hash direct access file offset with write access mode

## Description

```
int k2hpx_da_get_write_offset ( mixed $dahandle_res )
```

Gets the k2hash direct access file offset with write access mode. 

### Note
The [k2hash direct access](https://pages.ghe.corp.yahoo.co.jp/yjcore/k2hash_phpext/en/function.k2hpx-da-free.html) handle is a handler to provide quick access to the specific part of large data using offset. 

## Parameters
- dahandle_res  
Specifies the k2hash direct access file handle that [k2hpx_da_get_handle](k2hpx_da_get_handle.html) returns.

## Return Values
Returns the k2hash direct access file offset with write access mode. 

## Examples
- Example 1 - Returns the k2hash direct access file offset with write access mode

```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test", "value");
$dahandle = k2hpx_da_get_handle_rw($handle, "test");
var_dump(k2hpx_da_get_write_offset($dahandle));
k2hpx_da_free($dahandle);
k2hpx_close($handle);
?>
```

The above example will output:

```
int(0)
```


## See Also
- [k2hpx_da_get_handle_read](k2hpx_da_get_handle_read.html) - Reads data
- [k2hpx_da_get_handle_rw](k2hpx_da_get_handle_rw.html) - Gets the k2h direct access file handle with read-write only mode
- [k2hpx_da_get_handle_write](k2hpx_da_get_handle_write.html) - Gets the k2h direct access file handle with write only mode
- [k2hpx_da_get_handle](k2hpx_da_get_handle.html) - Gets the k2h direct access file handle
- [k2hpx_da_get_length](k2hpx_da_get_length.html) - Gets the data length
- [k2hpx_da_get_offset](k2hpx_da_get_offset.html) - Gets the k2h direct access file offset with read-write access mode
- [k2hpx_da_get_read_offset](k2hpx_da_get_read_offset.html) - Gets the k2h direct access file offset with read access mode
- [k2hpx_da_get_value_to_file](k2hpx_da_get_value_to_file.html) - Reads value using the offset and write it to the file
- [k2hpx_da_get_value](k2hpx_da_get_value.html) - Reads value using the offset
- [k2hpx_da_set_offset](k2hpx_da_set_offset.html) - Sets the offset to modify the data
- [k2hpx_da_set_read_offset](k2hpx_da_set_read_offset.html) - Sets the offset to read the data
- [k2hpx_da_set_value_from_file](k2hpx_da_set_value_from_file.html) - Sets value using the offset reading data from the file with length
- [k2hpx_da_set_value](k2hpx_da_set_value.html) - Sets value
- [k2hpx_da_set_write_offset](k2hpx_da_set_write_offset.html) - Sets value using the offset
