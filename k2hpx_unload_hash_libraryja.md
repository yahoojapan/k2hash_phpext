---
layout: contents
language: ja
title: k2hpx_unload_hash_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_unload_hash_library.html
lang_opp_word: To English
prev_url: k2hpx_transactionja.html
prev_string: k2hpx_transaction
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_unload_transaction_libraryja.html
next_string: k2hpx_unload_transaction_library
---

# k2hpx_unload_hash_library
ハッシュ関数ライブラリを取り外す

## 説明
```
bool k2hpx_unload_hash_library ( void )
```
k2hpx_load_hash_libraryでロードした共有ライブラリファイルを取り外します。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ハッシュ関数用ライブラリを取り外す
```
<?php
var_dump(k2hpx_unload_hash_library());
?>
```
上の例の出力は以下となります。
```
bool(true)
```

## 参考
- [k2hpx_load_hash_library](k2hpx_load_hash_libraryja.html) - ハッシュ関数を有効にする
