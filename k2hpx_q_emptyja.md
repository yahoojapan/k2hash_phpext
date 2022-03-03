---
layout: contents
language: ja
title: k2hpx_q_empty
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_empty.html
lang_opp_word: To English
prev_url: k2hpx_q_dumpja.html
prev_string: k2hpx_q_dump
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_freeja.html
next_string: k2hpx_q_free
---

# k2hpx_q_empty
K2hQueueキューが空かどうかを判定する

## 説明
```
bool k2hpx_q_empty ( mixed $qhandle_res )
```
[K2hQueue](k2hq_classja.html) キューが空かどうかを判定します。 

## パラメータ
- qhandle_res  
[K2hQueue](k2hq_classja.html) ハンドル。 [k2hpx_q_handle](k2hpx_q_handleja.html) 関数の戻り値。

## 戻り値
[K2hQueue](k2hq_classja.html) キューが空の場合は、true。そうでなければ、false 

## 参考
- [K2hQueue::isEmpty](k2hq_isEmptyja.html) - キューが空かどうかを判定する
