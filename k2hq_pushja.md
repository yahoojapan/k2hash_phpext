---
layout: contents
language: ja
title: K2hQueue::push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_push.html
lang_opp_word: To English
prev_url: k2hq_popja.html
prev_string: K2hQueue::pop
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: k2hq_readja.html
next_string: K2hQueue::read
---

# K2hQueue::push
キューに要素を追加する

## 説明

```
 public bool K2hQueue::push ( string $datavalue [, string $pass [, int $expire ]] )
```

キューに要素を追加します。

## パラメータ
- datavalue  
値
- pass  
パスワード（値を暗号化するための鍵）
- expire  
有効期限（単位：秒）

## 戻り値
成功時は、true。それ以外の場合は、false

## 例
- 例 1 - キューの要素を表示する

```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
var_dump($k2hqueue->push("test_queue_value"));
var_dump($k2hqueue->pop());
unset($k2hqueue);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
bool(true)
string(16) "test_queue_value"
```


## 参考
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
- [K2hQueue::read](k2hq_read.html) - Returns a key/value pair from the K2hQueue
- [K2hQueue::remove](k2hq_remove.html) - Removes a value from the K2hQueue
