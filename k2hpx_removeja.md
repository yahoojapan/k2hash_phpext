---
layout: contents
language: ja
title: k2hpx_remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_remove.html
lang_opp_word: To English
prev_url: k2hpx_remove_allja.html
prev_string: k2hpx_remove_all
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_renameja.html
next_string: k2hpx_rename
---

# k2hpx_remove
キーを削除する

## 説明
```
bool k2hpx_remove ( mixed $handle_res , string $key [, stringnull $subkey ] )
```
キーを削除します。キーに紐づけられたキーをサブキーと呼びます。サブキーに紐づけられたキーを親キーと呼びます。  
親キーのみを指定した場合は、サブキーは削除されません。  
サブキーを指定した場合は、サブキーは削除され、親キーは削除されません。  

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
キー（親キー）
- subkey  
キーに紐付けられたキー（サブキー）

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::remove](k2h_removeja.html) - キーを削除する
