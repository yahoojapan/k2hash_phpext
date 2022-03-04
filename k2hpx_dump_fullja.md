---
layout: contents
language: ja
title: k2hpx_dump_full
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_dump_full.html
lang_opp_word: To English
prev_url: k2hpx_dump_full_keytableja.html
prev_string: k2hpx_dump_full_keytable
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_dump_headja.html
next_string: k2hpx_dump_head
---

# k2hpx_dump_full
k2hashのハッシュテーブル内部のデータなどを表示する

## 説明

```
bool k2hpx_dump_full ( mixed $handle_res [, mixed $output ] )
```

k2hashのハッシュテーブル内部のデータなどを表示します。k2hashのヘッダ、ハッシュテーブル、サブハッシュテーブル、テーブル内部の要素なども含まれます。

## パラメータ
- handle_res  
k2hash (.k2h) ファイルハンドル。 k2hpx_open 関数の戻り値を指定。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::dumpFull](k2h_dumpfullja.html) - k2hashのハッシュテーブル内部のデータなどを表示する
