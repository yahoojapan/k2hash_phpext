---
layout: contents
language: ja
title: k2hpx_load_transaction_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_transaction_library.html
lang_opp_word: To English
prev_url: k2hpx_load_hash_libraryja.html
prev_string: k2hpx_load_hash_library
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_open_memja.html
next_string: k2hpx_open_mem
---

# k2hpx_load_transaction_library
トランザクション用ライブラリを読み込む

## 説明
```
bool k2hpx_load_transaction_library ( string $libpath )
```


## パラメータ
- libpath  
共有ライブラリファイルのパス

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - トランザクション用ライブラリを読み込む
```
<?php
var_dump(k2hpx_load_transaction_library("/usr/lib/libk2htestlib.so"));
?>
```
上の例の出力は以下となります。
```
bool(true)
```

## 参考
- [k2hpx_unload_transaction_library](k2hpx_unload_transaction_libraryja.html) - トランザクション用ライブラリを無効にする
