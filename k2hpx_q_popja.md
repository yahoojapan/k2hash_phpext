---
layout: contents
language: ja
title: k2hpx_q_pop
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_pop.html
lang_opp_word: To English
prev_url: k2hpx_q_handleja.html
prev_string: k2hpx_q_handle
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_pushja.html
next_string: k2hpx_q_push
---

# k2hpx_q_pop
K2hQueueキューから要素を取得する

## 説明
```
string k2hpx_q_pop ( mixed $qhandle_res [, stringnull $pass ] )
```
[K2hQueue](k2hq_classja.html) キューから要素を取得します。 

## パラメータ
- qhandle_res  
[K2hQueue](k2hq_classja.html) ハンドル。 [k2hpx_q_handle](k2hpx_q_handleja.html) 関数の戻り値。
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
[K2hQueue](k2hq_classja.html) キューの要素（値） 

## 参考
- [K2hQueue::pop](k2hq_popja.html) - キューから要素を取得する
