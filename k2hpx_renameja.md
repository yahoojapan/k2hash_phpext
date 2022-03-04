---
layout: contents
language: ja
title: k2hpx_rename
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_rename.html
lang_opp_word: To English
prev_url: k2hpx_removeja.html
prev_string: k2hpx_remove
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_set_common_attrja.html
next_string: k2hpx_set_common_attr
---

# k2hpx_rename
キー名を変更する

## 説明

```
bool k2hpx_rename ( mixed $handle_res , string $key , string $newkey )
```

キー名を変更します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
現在のキー名
- newkey  
変更後のキー名

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::rename](k2h_renameja.html) - キー名を変更する
