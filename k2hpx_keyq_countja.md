---
layout: contents
language: ja
title: k2hpx_keyq_count
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_count.html
lang_opp_word: To English
prev_url: k2hpx_get_valueja.html
prev_string: k2hpx_get_value
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_keyq_dumpja.html
next_string: k2hpx_keyq_dump
---

# k2hpx_keyq_count
K2hKeyQueueキューにある要素の数を取得する

## 説明

```
int k2hpx_keyq_count ( mixed $keyqhandle_res )
```

[K2hKeyQueue](k2hkq_classja.html) キューにある要素（キーと値のセット）の数を取得します。 

## パラメータ
- keyqhandle_res  
[K2hKeyQueue](k2hkq_classja.html) ハンドル。 [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) 関数の戻り値。

## 戻り値
[K2hKeyQueue](k2hkq_classja.html) キューにある要素（キーと値のセット）の数 

## 参考
- [K2hKeyQueue::count](k2hkq_countja.html) - キューにある要素の数を取得する
