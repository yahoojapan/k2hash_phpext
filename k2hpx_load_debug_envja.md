---
layout: contents
language: ja
title: k2hpx_load_debug_env
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_debug_env.html
lang_opp_word: To English
prev_url: k2hpx_load_archiveja.html
prev_string: k2hpx_load_archive
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_load_hash_libraryja.html
next_string: k2hpx_load_hash_library
---

# k2hpx_load_debug_env
環境変数を読み込む

## 説明
```
bool k2hpx_load_debug_env ( void )
```
環境変数を読み込みます。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - 環境変数を読み込む
```
<?php
var_dump(k2hpx_load_debug_env());
?>
```
上の例の出力は以下となります。
```
bool(true)
```
