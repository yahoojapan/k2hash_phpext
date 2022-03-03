---
layout: contents
language: ja
title: k2hpx_keyq_read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_read.html
lang_opp_word: To English
prev_url: k2hpx_keyq_pushja.html
prev_string: k2hpx_keyq_push
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_keyq_removeja.html
next_string: k2hpx_keyq_remove
---

# k2hpx_keyq_read
K2hKeyQueueキューの要素（キーと値のセット）を表示する

## 説明
```
array k2hpx_keyq_read ( mixed $keyqhandle_res [, int $pos [, stringnull $pass ]] )
```
[K2hKeyQueue](k2hkq_classja.html) キューの要素（キーと値のセット）を表示します。キューから要素は削除されません。 

### 注意
キューから要素は削除されません。要素を削除もする場合は、 [k2hpx_keyq_pop](k2hpx_keyq_popja.html) を使ってください。 

## パラメータ
- keyqhandle_res  
[K2hKeyQueue](k2hkq_classja.html) ハンドル。 [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) 関数の戻り値。
- pos  
要素の位置
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
[K2hKeyQueue](k2hkq_classja.html) キューの要素（キーと値のセット） 

## 参考
- [K2hKeyQueue::read](k2hkq_readja.html) - キューの要素（キーと値のセット）を表示する
