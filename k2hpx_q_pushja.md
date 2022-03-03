---
layout: contents
language: ja
title: k2hpx_q_push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_push.html
lang_opp_word: To English
prev_url: k2hpx_q_popja.html
prev_string: k2hpx_q_pop
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_readja.html
next_string: k2hpx_q_read
---

# k2hpx_q_push
K2hQueueキューに要素を追加する

## 説明
```
bool k2hpx_q_push ( mixed $qhandle_res , string $datavalue [, stringnull $pass [, int $expire ]] )
```
[K2hQueue](k2hq_classja.html) キューに要素を追加します。

## パラメータ
- qhandle_res  
[K2hQueue](k2hq_classja.html) ハンドル。 k2hpx_q_handle 関数の戻り値。
- datavalue  
値
- pass  
パスワード（値を暗号化するための鍵）
- expire  
有効期限（単位：秒）

## 戻り値
成功時は、true。それ以外の場合は、false

## 参考
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
