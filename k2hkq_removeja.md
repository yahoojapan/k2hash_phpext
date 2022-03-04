---
layout: contents
language: ja
title: K2hKeyQueue::remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_remove.html
lang_opp_word: To English
prev_url: k2hkq_readja.html
prev_string: K2hKeyQueue::read
top_url: k2hkq_classja.html
top_string: K2hKeyQueue Class
next_url: 
next_string: 
---

# K2hKeyQueue::remove
キューから要素（キーと値のセット）を削除する

## 説明

```
 public bool K2hKeyQueue::remove ( int $count [, string $pass ] )
```

キューから要素（キーと値のセット）を削除します。 

## パラメータ
- count  
削除する要素の数
- pass  
暗号化されている値を復号化するためのパスワード（共有鍵）。

## 戻り値
成功時は、true。それ以外の場合は、false

## 例
- 例 1 - キューから要素を削除する

```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
$k2hkeyqueue->push("test_queue_key1", "test_queue_value1");
$k2hkeyqueue->push("test_queue_key2", "test_queue_value2");
var_dump($k2hkeyqueue->count());
var_dump($k2hkeyqueue->remove(1));
var_dump($k2hkeyqueue->count());
unset($k2hkeyqueue);
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
- [K2hKeyQueue::pop](k2hkq_popja.html) - キューから要素（キーと値のセット）を取得する
- [K2hKeyQueue::push](k2hkq_pushja.html) - キューに要素（キーと値のセット）を追加する
- [K2hKeyQueue::read](k2hkq_readja.html) - キューの要素（キーと値のセット）を表示する
