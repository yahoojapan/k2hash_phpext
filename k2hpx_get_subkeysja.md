---
layout: contents
language: ja
title: k2hpx_get_subkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_subkeys.html
lang_opp_word: To English
prev_url: k2hpx_get_attrsja.html
prev_string: k2hpx_get_attrs
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_get_transaction_thread_poolja.html
next_string: k2hpx_get_transaction_thread_pool
---

# k2hpx_get_subkeys
キーに紐づけられたキー（サブキー）の一覧を取得する

## 説明

```
array k2hpx_get_subkeys ( mixed $handle_res , string $key [, bool $attrcheck ] )
```

キーに紐づけられたキー（サブキー）の一覧を取得します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
キー
- attrcheck  
キーの属性を確認してから取得する場合は、true、そうでなければ、false

## 戻り値
引数で指定されたキーと紐づけられたキーの一覧。 

## 参考
- [K2hash::getSubkeys](k2h_getsubkeysja.html) - キーに紐づけられたキー（サブキー）の一覧を取得する
