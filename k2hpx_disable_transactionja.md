---
layout: contents
language: ja
title: k2hpx_disable_transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_disable_transaction.html
lang_opp_word: To English
prev_url: k2hpx_da_set_write_offsetja.html
prev_string: k2hpx_da_set_write_offset
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_dump_elementtableja.html
next_string: k2hpx_dump_elementtable
---

# k2hpx_disable_transaction
トランザクションを停止する

## 説明

```
bool k2hpx_disable_transaction ( mixed $handle_res )
```

トランザクションを停止します

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 k2hpx_open 関数の戻り値を指定。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::disableTransaction](k2h_disabletransactionja.html) - トランザクションを停止する
