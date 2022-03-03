---
layout: contents
language: ja
title: K2hQueue::remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_remove.html
lang_opp_word: To English
prev_url: k2hq_readja.html
prev_string: K2hQueue::read
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: 
next_string: 
---

# K2hQueue::remove
キューから要素を削除する

## 説明
```
 public bool K2hQueue::remove ( int $count [, string $pass ] )
```
キューから要素を削除します。 

## パラメータ
- count  
削除する要素の数
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
成功時は、true。それ以外の場合は、false

## 例
- 例 1 - キューの要素を削除する
```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_value1");
$k2hqueue->push("test_queue_value2");
var_dump($k2hqueue->count());
var_dump($k2hqueue->remove(1));
var_dump($k2hqueue->count());
unset($k2hqueue);
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
int(2)
bool(true)
int(1)
```

## 参考
- [K2hQueue::pop](k2hq_popja.html) - キューから要素を取得する
- [K2hQueue::push](k2hq_pushja.html) - キューに要素を追加する
- [K2hQueue::read](k2hq_readja.html) - キューの要素を表示する
