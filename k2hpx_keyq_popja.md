---
layout: contents
language: ja
title: k2hpx_keyq_pop
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_pop.html
lang_opp_word: To English
prev_url: k2hpx_keyq_handleja.html
prev_string: k2hpx_keyq_handle
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_keyq_pushja.html
next_string: k2hpx_keyq_push
---

# k2hpx_keyq_pop
K2hKeyQueueキューから要素（キーと値のセット）を取得する

## 説明

```
array k2hpx_keyq_pop ( mixed $keyqhandle_res [, stringnull $pass ] )
```

[K2hKeyQueue](k2hkq_classja.html) キューから要素（キーと値のセット）を取得します。 

## パラメータ
- keyqhandle_res  
[K2hKeyQueue](k2hkq_classja.html) ハンドル。 [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) 関数の戻り値。
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
[K2hKeyQueue](k2hkq_classja.html) キューの要素（キーと値のセット） 

## 参考
- [K2hKeyQueue::pop](k2hkq_popja.html) - キューから要素（キーと値のセット）を取得する
