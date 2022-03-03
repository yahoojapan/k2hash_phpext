---
layout: contents
language: ja
title: k2hpx_keyq_empty
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_empty.html
lang_opp_word: To English
prev_url: k2hpx_keyq_dumpja.html
prev_string: k2hpx_keyq_dump
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_keyq_freeja.html
next_string: k2hpx_keyq_free
---

# k2hpx_keyq_empty
K2hKeyQueueキューが空かどうかを判定する

## 説明
```
bool k2hpx_keyq_empty ( mixed $keyqhandle_res )
```
[K2hKeyQueue](k2hkq_classja.html) キューが空かどうかを判定します。 

## パラメータ
- keyqhandle_res  
[K2hKeyQueue](k2hkq_classja.html) ハンドル。 [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) 関数の戻り値。

## 戻り値
[K2hKeyQueue](k2hkq_classja.html) キューが空の場合は、true。そうでなければ、false 

## 参考
- [K2hKeyQueue::isEmpty](k2hkq_isEmptyja.html) - キューが空かどうかを判定する
