---
layout: contents
language: ja
title: k2hpx_get_attr_value
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_attr_value.html
lang_opp_word: To English
prev_url: k2hpx_find_nextja.html
prev_string: k2hpx_find_next
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_get_attrsja.html
next_string: k2hpx_get_attrs
---

# k2hpx_get_attr_value
キーに設定されている属性値を取得する

## 説明
```
string k2hpx_get_attr_value ( mixed $handle_res , string $key , string $attrkey )
```
キーに設定されている属性値を取得します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
キー
- attrkey  
キーに設定されている属性名

## 戻り値
キーに設定された属性名が存在する場合は、属性値。それ以外は false

## 参考
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
