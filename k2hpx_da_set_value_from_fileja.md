---
layout: contents
language: ja
title: k2hpx_da_set_value_from_file
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_da_set_value_from_file.html
lang_opp_word: To English
prev_url: k2hpx_da_set_read_offsetja.html
prev_string: k2hpx_da_set_read_offset
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_da_set_valueja.html
next_string: k2hpx_da_set_value
---

# k2hpx_da_set_value_from_file
ファイルから書き込むデータを読み込み、直接データを書きこむ位置を指定し、書き込む

## 説明
```
bool k2hpx_da_set_value_from_file ( mixed $dahandle_res , string $filepath [, int $length [, int $offset ]] )
```
ファイルから書き込むデータを読み込み、直接データを書きこむ位置を指定し、書き込みます。 

### ヒント
[ダイレクトアクセスハンドル](https://k2hash.antpick.ax/developerja.html#DIRECTACCESS)は 、サイズの大きいデータに対して、オフセットを指定して、データを読み書きするためのハンドラです。 

## パラメータ
- dahandle_res  
k2hash ダイレクトアクセスハンドル（[k2hpx_da_get_handle](k2hpx_da_get_handleja.html) 関数の戻り値）。
- filepath  
書き込むデータが保存されたファイルのパス
- length  
読み書きするデータ長
- offset  
データを読み書きする位置

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ファイルから書き込むデータを読み込み、直接データを書きこむ位置を指定し、書き込む
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test", "value");
$dahandle = k2hpx_da_get_handle_rw($handle, "test");
file_put_contents("/tmp/test_k2hash_da_set_value", "test");
var_dump(k2hpx_da_set_value_from_file($dahandle, "/tmp/test_k2hash_da_set_value", 2)));
k2hpx_da_free($dahandle);
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
bool(true)
```

## 参考
- [k2hpx_da_free](k2hpx_da_freeja.html) - データアクセスハンドルを解放する
- [k2hpx_da_get_handle_read](k2hpx_da_get_handle_readja.html) - ダイレクトアクセスハンドル(データ読み出し専用)を取得する
- [k2hpx_da_get_handle_rw](k2hpx_da_get_handle_rwja.html) - ダイレクトアクセスハンドル(データ編集用)を取得する
- [k2hpx_da_get_handle_write](k2hpx_da_get_handle_writeja.html) - ダイレクトアクセスハンドル(データ書き込み専用)を取得する
- [k2hpx_da_get_handle](k2hpx_da_get_handleja.html) - ファイル操作方法を指定して、ダイレクトアクセスハンドルを取得する
- [k2hpx_da_get_length](k2hpx_da_get_lengthja.html) - データ長を取得する
- [k2hpx_da_get_offset](k2hpx_da_get_offsetja.html) - データを読み書き開始する位置を取得する
- [k2hpx_da_get_read_offset](k2hpx_da_get_read_offsetja.html) - データを読みとり開始する位置を取得する
- [k2hpx_da_get_value_to_file](k2hpx_da_get_value_to_fileja.html) - 読み取った値をファイルに書き出す
- [k2hpx_da_get_value](k2hpx_da_get_valueja.html) - データを読み取る
- [k2hpx_da_get_write_offset](k2hpx_da_get_write_offsetja.html) - データの書き込み開始する位置を取得する
- [k2hpx_da_set_offset](k2hpx_da_set_offsetja.html) - データを読み込むまたは書き込む位置を指定する
- [k2hpx_da_set_read_offset](k2hpx_da_set_read_offsetja.html) - データを読み込む位置を指定する
- [k2hpx_da_set_value](k2hpx_da_set_valueja.html) - データを書きこむ位置を指定し、書き込む
- [k2hpx_da_set_write_offset](k2hpx_da_set_write_offsetja.html) - データを書き込む位置を指定する
