---
layout: contents
language: ja
title: k2hpx_q_remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_remove.html
lang_opp_word: To English
prev_url: k2hpx_q_readja.html
prev_string: k2hpx_q_read
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_remove_allja.html
next_string: k2hpx_remove_all
---

# k2hpx_q_remove
K2hQueueキューから要素を削除する

## 説明
```
bool k2hpx_q_remove ( mixed $qhandle_res , int $count [, stringnull $pass ] )
```
[K2hQueue](k2hq_classja.html) キューから要素（値）を削除します。 

## パラメータ
- qhandle_res  
[K2hQueue](k2hq_classja.html) ハンドル。 [k2hpx_q_handle](k2hpx_q_handleja.html) 関数の戻り値。
- count  
削除する要素の数
- pass  
暗号化されている値を復号化するためのパスワード（共有鍵）。

## 戻り値
成功時は、true。それ以外の場合は、false

## 参考
- [K2hQueue::remove](k2hq_removeja.html) - キューから要素を削除する
