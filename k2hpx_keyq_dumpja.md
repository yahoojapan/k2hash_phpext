---
layout: contents
language: ja
title: k2hpx_keyq_dump
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_dump.html
lang_opp_word: To English
prev_url: k2hpx_keyq_countja.html
prev_string: k2hpx_keyq_count
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_keyq_emptyja.html
next_string: k2hpx_keyq_empty
---

# k2hpx_keyq_dump
K2hKeyQueueキューにある要素を表示する

## 説明

```
bool k2hpx_keyq_dump ( mixed $keyqhandle_res [, mixed $output ] )
```

[K2hKeyQueue](k2hkq_classja.html) キューにある要素（キーと値のセット）を表示します。 

## パラメータ
- keyqhandle_res  
[K2hKeyQueue](k2hkq_classja.html) ハンドル。 [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) 関数の戻り値。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hKeyQueue::dump](k2hkq_dumpja.html) - キューにある要素を表示する
