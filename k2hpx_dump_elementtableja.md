---
layout: contents
language: ja
title: k2hpx_dump_elementtable
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_elementtable.html
lang_opp_word: To English
prev_url: k2hpx_disable_transactionja.html
prev_string: k2hpx_disable_transaction
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_dump_full_keytableja.html
next_string: k2hpx_dump_full_keytable
---

# k2hpx_dump_elementtable
k2hashのハッシュテーブル内部の要素などを表示する

## 説明

```
bool k2hpx_dump_elementtable ( mixed $handle_res [, mixed $output ] )
```

k2hashのハッシュテーブル内部の要素などを表示します。k2hashのヘッダ、ハッシュテーブル、サブハッシュテーブルなども含まれます。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 k2hpx_open 関数の戻り値を指定。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::dumpElementtable](k2h_dumpelementtableja.html) - k2hashのハッシュテーブル内部の要素などを表示する
