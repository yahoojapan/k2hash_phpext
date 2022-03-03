---
layout: contents
language: ja
title: K2hQueue::isEmpty
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_isempty.html
lang_opp_word: To English
prev_url: k2hq_dumpja.html
prev_string: K2hQueue::dump
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: k2hq_popja.html
next_string: K2hQueue::pop
---

# K2hQueue::isEmpty
キューが空かどうかを判定する

## 説明
```
 public bool K2hQueue::isEmpty ( void )
```
キューが空かどうかを判定します。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
キューが空の場合は、true。そうでなければ、false

## 例
- 例 1 - キューからデータを取り出す
```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
var_dump($k2hqueue->isEmpty());
$k2hqueue->push("test_queue_data");
var_dump($k2hqueue->isEmpty());
var_dump($k2hqueue->pop());
var_dump($k2hqueue->isEmpty());
unset($k2hqueue);
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
bool(true)
bool(false)
string(15) "test_queue_data"
bool(true)
```
