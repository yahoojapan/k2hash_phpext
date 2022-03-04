---
layout: contents
language: ja
title: K2hKeyQueue::isEmpty
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_isempty.html
lang_opp_word: To English
prev_url: k2hkq_dumpja.html
prev_string: K2hKeyQueue::dump
top_url: k2hkq_classja.html
top_string: K2hKeyQueue Class
next_url: k2hkq_popja.html
next_string: K2hKeyQueue::pop
---

# K2hKeyQueue::isEmpty
キューが空かどうかを判定する

## 説明

```
 public bool K2hKeyQueue::isEmpty ( void )
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
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
var_dump($k2hkeyqueue->count());
$k2hkeyqueue->push("test_queue_key", "test_queue_value");
var_dump($k2hkeyqueue->count());
var_dump($k2hkeyqueue->pop());
var_dump($k2hkeyqueue->count());
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
int(0)
int(1)
array(2) {
  [0]=>
  string(14) "test_queue_key"
  [1]=>
  string(16) "test_queue_value"
}
int(0)
```

