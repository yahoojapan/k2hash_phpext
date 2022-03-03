---
layout: contents
language: ja
title: k2hpx_add_attr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_attr.html
lang_opp_word: To English
prev_url: k2hpx_add_attr_plugin_libraryja.html
prev_string: k2hpx_add_attr_plugin_library
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_add_subkeyja.html
next_string: k2hpx_add_subkey
---

# k2hpx_add_attr
キーに属性を追加する

## 説明
```
 bool k2hpx_add_attr ( mixed $handle_res , string $key , string $attrkey , string $attrval )
```
キーに属性を追加します。属性とは、該当キーに対する設定（更新時刻保持の有無、暗号化の有無、履歴情報保持の有無など）です。 

## パラメータ
- handle_res  
k2hash (.k2h) ファイルハンドル。 k2hpx_open 関数の戻り値。
- key  
属性と紐付けるキー
- attrkey  
属性名
- attrval  
属性値

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::addAttr](k2h_addattrja.html) - キーに属性を追加する
