---
layout: contents
language: ja
title: k2hpx_q_dump
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_dump.html
lang_opp_word: To English
prev_url: k2hpx_q_countja.html
prev_string: k2hpx_q_count
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_emptyja.html
next_string: k2hpx_q_empty
---

# k2hpx_q_dump
K2hQueueキューにある要素を表示する

## 説明
```
bool k2hpx_q_dump ( mixed $qhandle_res [, mixed $output ] )
```
[K2hQueue](k2hq_classja.html)キューにある要素を表示します。 

## パラメータ
- qhandle_res  
[K2hQueue](k2hq_classja.html) ハンドル。 [k2hpx_q_handle](k2hpx_q_handleja.html) 関数の戻り値。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hQueue::dump](k2hq_dumpja.html) - キューにある要素を表示する
