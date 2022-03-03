---
layout: contents
language: ja
title: k2hpx_get_attrs
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_attrs.html
lang_opp_word: To English
prev_url: k2hpx_get_attr_valueja.html
prev_string: k2hpx_get_attr_value
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_get_subkeysja.html
next_string: k2hpx_get_subkeys
---

# k2hpx_get_attrs
キーに設定されている属性を取得する

## 説明
```
array k2hpx_get_attrs ( mixed $handle_res , string $key )
```
キーに設定されている属性を取得します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
キー

## 戻り値
キーに設定された属性が存在する場合は、属性の配列、それ以外はfalse

## 参考
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
