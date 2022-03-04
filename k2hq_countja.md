---
layout: contents
language: ja
title: K2hQueue::count
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_count.html
lang_opp_word: To English
prev_url: k2hq_constructja.html
prev_string: K2hQueue::__construct
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: k2hq_dumpja.html
next_string: K2hQueue::dump
---

# K2hQueue::count
キューにある要素の数を取得する

## 説明

```
public intfalseK2hQueue::count ( void )
```

キューにある要素の数を取得します。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
キューにある要素の数 

## 例
- 例 1 - キューからデータを取り出す

```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
var_dump($k2hqueue->count());
$k2hqueue->push("test_queue_data");
var_dump($k2hqueue->count());
var_dump($k2hqueue->pop());
var_dump($k2hqueue->count());
unset($k2hqueue);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
int(0)
int(1)
string(15) "test_queue_data"
int(0)
```


## 参考
- [K2hQueue::pop](k2hq_popja.html) - キューから要素を取得する
- [K2hQueue::push](k2hq_pushja.html) - キューに要素を追加する
