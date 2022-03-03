---
layout: contents
language: ja
title: k2hpx_dump_keytable
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_keytable.html
lang_opp_word: To English
prev_url: k2hpx_dump_headja.html
prev_string: k2hpx_dump_head
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_enable_transactionja.html
next_string: k2hpx_enable_transaction
---

# k2hpx_dump_keytable
k2hashのハッシュテーブルを表示する

## 説明
```
bool k2hpx_dump_keytable ( mixed $handle_res [, mixed $output ] )
```
k2hashのハッシュテーブルなどを表示します。k2hashのヘッダ、ハッシュテーブルなども含まれます。 

## パラメータ
- handle_res  
k2hash (.k2h) ファイルハンドル。 k2hpx_open 関数の戻り値を指定。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::dumpKeytable](k2h_dumpkeytableja.html) - k2hashのハッシュテーブルを表示する
