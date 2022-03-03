---
layout: contents
language: ja
title: k2hpx_load_hash_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_hash_library.html
lang_opp_word: To English
prev_url: k2hpx_load_debug_envja.html
prev_string: k2hpx_load_debug_env
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_load_transaction_libraryja.html
next_string: k2hpx_load_transaction_library
---

# k2hpx_load_hash_library
ハッシュ関数を有効にする

## 説明
```
bool k2hpx_load_hash_library ( string $libpath )
```
ハッシュ関数を有効にします。 

## パラメータ
- libpath  
共有ライブラリファイルのパス

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ハッシュ関数用ライブラリを読み込む
```
<?php
var_dump(k2hpx_load_hash_library("/usr/lib/libk2htest.so"));
?>
```
上の例の出力は以下となります。
```
bool(true)
```

## 参考
- [k2hpx_unload_hash_library](k2hpx_unload_hash_libraryja.html) - ハッシュ関数ライブラリを取り外す
