---
layout: contents
language: ja
title: k2hpx_q_read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_read.html
lang_opp_word: To English
prev_url: k2hpx_q_pushja.html
prev_string: k2hpx_q_push
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_removeja.html
next_string: k2hpx_q_remove
---

# k2hpx_q_read
K2hQueueキューの要素（値）を表示する

## 説明
```
string k2hpx_q_read ( mixed $qhandle_res [, int $pos [, stringnull $pass ]] )
```
[K2hQueue](k2hq_classja.html) キューの要素（値）を表示します。 

### 注意
キューから要素は削除されません。要素を削除もする場合は、 [k2hpx_keyq_pop](k2hpx_keyq_popja.html) を使ってください。 

## パラメータ
- qhandle_res  
[K2hQueue](k2hq_classja.html) ハンドル。 [k2hpx_q_handle](k2hpx_q_handleja.html) 関数の戻り値。
- pos  
要素の位置
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
[K2hQueue](k2hq_classja.html) キューの要素（値） 

## 参考
- [K2hQueue::read](k2hq_readja.html) - キューの要素を表示する
