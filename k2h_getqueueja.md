---
layout: contents
language: ja
title: K2hash::getQueue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getqueue.html
lang_opp_word: To English
prev_url: k2h_getkeyqueueja.html
prev_string: K2hash::getKeyQueue
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getstreamja.html
next_string: K2hash::getStream
---

# K2hash::getQueue
K2hQueueオブジェクトを取得する

## 説明
```
 public mixed K2hash::getQueue ([ bool $is_filo [, string $prefix ]] )
```
[K2hQueue](k2hq_classja.html)オブジェクトを取得します。[K2hQueue](k2hq_classja.html)は、k2hashを利用したキューを操作するクラスです。キューには、値を一つの要素として格納します。 

## パラメータ
- is_filo  
FIFO(先入先出し)キューならtrue、そうでなければ、false
- prefix  
キューのプレフィックス

## 戻り値
[K2hQueue](k2hq_classja.html)オブジェクト 

## 参考
- [K2hQueue::__construct](k2hq_constructja.html) - 新しいK2hQueueオブジェクトを作成する
