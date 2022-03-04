---
layout: contents
language: ja
title: k2hpx_remove_all
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_remove_all.html
lang_opp_word: To English
prev_url: k2hpx_q_removeja.html
prev_string: k2hpx_q_remove
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_removeja.html
next_string: k2hpx_remove
---

# k2hpx_remove_all
キーと、キーに紐づけられているキー（サブキー）を削除する

## 説明

```
bool k2hpx_remove_all ( mixed $handle_res , string $key )
```

キーと、キーに紐づけられているキー（サブキー）を削除します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
キー

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::removeAll](k2h_removeallja.html) - キーと、キーに紐づけられているキー（サブキー）を削除する
