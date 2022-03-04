---
layout: contents
language: ja
title: K2hash::getKeyQueue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getkeyqueue.html
lang_opp_word: To English
prev_url: k2h_getiteratorja.html
prev_string: K2hash::getIterator
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getqueueja.html
next_string: K2hash::getQueue
---

# K2hash::getKeyQueue
K2hKeyQueueオブジェクトを取得する

## 説明

```
 public mixed K2hash::getKeyQueue ([ bool $is_filo [, string $prefix ]] )
```

[K2hKeyQueue](k2hkq_classja.html)オブジェクトを取得します。[K2hKeyQueue](k2hkq_classja.html)は、k2hashを利用したキューを操作するクラスです。キューには、キーと値を一つの要素として格納します。 

## パラメータ
- is_filo  
FIFO(先入先出し)キューならtrue、そうでなければ、false
- prefix  
キューのプレフィックス

## 戻り値
[K2hKeyQueue](k2hkq_classja.html)オブジェクト 

## 参考
- [K2hKeyQueue::__construct](k2hkq_constructja.html) - 新しいK2hKeyQueueオブジェクトを作成する
