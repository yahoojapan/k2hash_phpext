---
layout: contents
language: ja
title: k2hpx_get_value
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_get_value.html
lang_opp_word: To English
prev_url: k2hpx_get_transaction_thread_poolja.html
prev_string: k2hpx_get_transaction_thread_pool
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_keyq_countja.html
next_string: k2hpx_keyq_count
---

# k2hpx_get_value
キーの値を取得する

## 説明
```
string k2hpx_get_value ( mixed $handle_res , string $key [, stringnull $subkey [, bool $attrcheck [, stringnull $pass ]]] )
```
キーの値を取得します。キーと紐づけられたキー（サブキー）が指定された場合は、サブキーの値を取得します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
キー
- subkey  
キーに紐づけられているキー（サブキー）
- attrcheck  
キーの属性を確認してから取得する場合は、true、そうでなければ、false
- pass  
暗号化されている値を復号化するためのパスワード（共有鍵）。

## 戻り値
成功時は指定されたキーの値、そうでなければ、false

## 参考
- [K2hash::getValue](k2h_getvalueja.html) - 値を取得する
