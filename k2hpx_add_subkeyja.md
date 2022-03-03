---
layout: contents
language: ja
title: k2hpx_add_subkey
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_subkey.html
lang_opp_word: To English
prev_url: k2hpx_add_attrja.html
prev_string: k2hpx_add_attr
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_add_subkeysja.html
next_string: k2hpx_add_subkeys
---

# k2hpx_add_subkey
キーを紐づける

## 説明
```
bool k2hpx_add_subkey ( mixed $handle_res , string $key , string $subkey )
```
キーに他のキーを紐付けます。紐づけるキーは、紐づけられるキーの「サブキー」と呼びます。 

## パラメータ
- handle_res  
k2hash (.k2h) ファイルハンドル。 k2hpx_open 関数の戻り値。
- key  
サブキーを追加されるキー
- subkey  
サブキー

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::addSubkey](k2h_addsubkeyja.html) - キーを紐づける
