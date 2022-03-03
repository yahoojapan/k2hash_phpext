---
layout: contents
language: ja
title: k2hpx_add_attr_plugin_library
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_attr_plugin_library.html
lang_opp_word: To English
prev_url: k2hpx_add_attr_crypt_passja.html
prev_string: k2hpx_add_attr_crypt_pass
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_add_attrja.html
next_string: k2hpx_add_attr
---

# k2hpx_add_attr_plugin_library
ユーザ定義の動的ライブラリを追加する

## 説明
```
bool k2hpx_add_attr_plugin_library ( mixed $handle_res , string $libfile )
```
ユーザ定義の動的ライブラリを追加します。k2hashは、キーに対して任意の属性を付与できます。本メソッドは、ユーザ定義の動的ライブラリを追加し、キーに属性を追加します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 k2hpx_open 関数の戻り値。
- libfile  
動的ライブラリのパス

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
