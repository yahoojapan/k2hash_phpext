---
layout: contents
language: ja
title: k2hpx_da_get_value
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_da_get_value.html
lang_opp_word: To English
prev_url: k2hpx_da_get_value_to_fileja.html
prev_string: k2hpx_da_get_value_to_file
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_da_get_write_offsetja.html
next_string: k2hpx_da_get_write_offset
---

# k2hpx_da_get_value
データを読み取る

## 説明

```
string k2hpx_da_get_value ( mixed $dahandle_res [, int $offset ] )
```

データを読み取ります。 

### ヒント
[ダイレクトアクセスハンドル](https://k2hash.antpick.ax/developerja.html#DIRECTACCESS)は 、サイズの大きいデータに対して、オフセットを指定して、データを読み書きするためのハンドラです。 

## パラメータ
- dahandle_res  
k2hash ダイレクトアクセスハンドル（[k2hpx_da_get_handle](k2hpx_da_get_handleja.html) 関数の戻り値）。
- offset  
データを読みとる位置

## 戻り値
読み取った文字列

## 例
- 例 1 - データを読みとる

```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test", "value");
$dahandle = k2hpx_da_get_handle_rw($handle, "test");
var_dump(k2hpx_da_get_value($dahandle, 2));
k2hpx_da_free($dahandle);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
string(3) "lue"
```


## 参考
- [k2hpx_da_free](k2hpx_da_free.html) - Frees resources of k2hash direct access handle
- [k2hpx_da_get_handle_read](k2hpx_da_get_handle_read.html) - Reads data
- [k2hpx_da_get_handle_rw](k2hpx_da_get_handle_rw.html) - Gets the k2h direct access file handle with read-write only mode
- [k2hpx_da_get_handle_write](k2hpx_da_get_handle_write.html) - Gets the k2h direct access file handle with write only mode
- [k2hpx_da_get_handle](k2hpx_da_get_handle.html) - Gets the k2h direct access file handle
- [k2hpx_da_get_length](k2hpx_da_get_length.html) - Gets the data length
- [k2hpx_da_get_offset](k2hpx_da_get_offset.html) - Gets the k2h direct access file offset with read-write access mode
- [k2hpx_da_get_read_offset](k2hpx_da_get_read_offset.html) - Gets the k2h direct access file offset with read access mode
- [k2hpx_da_get_value_to_file](k2hpx_da_get_value_to_file.html) - Reads value using the offset and write it to the file
- [k2hpx_da_get_write_offset](k2hpx_da_get_write_offset.html) - Gets the k2h direct access file offset with write access mode
- [k2hpx_da_set_offset](k2hpx_da_set_offset.html) - Sets the offset to modify the data
- [k2hpx_da_set_read_offset](k2hpx_da_set_read_offset.html) - Sets the offset to read the data
- [k2hpx_da_set_value_from_file](k2hpx_da_set_value_from_file.html) - Sets value using the offset reading data from the file with length
- [k2hpx_da_set_value](k2hpx_da_set_value.html) - Sets value
- [k2hpx_da_set_write_offset](k2hpx_da_set_write_offset.html) - Sets value using the offset
