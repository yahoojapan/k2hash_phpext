---
layout: contents
language: ja
title: K2hKeyQueue::read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_read.html
lang_opp_word: To English
prev_url: k2hkq_pushja.html
prev_string: K2hKeyQueue::push
top_url: k2hkq_classja.html
top_string: K2hKeyQueue Class
next_url: k2hkq_removeja.html
next_string: K2hKeyQueue::remove
---

# K2hKeyQueue::read
キューの要素（キーと値のセット）を表示する

## 説明

```
public arrayfalseK2hKeyQueue::read ([ int $pos [, string $pass ]] )
```

キューの要素（キーと値のセット）を表示します。

### 注意
キューから要素は削除されません。要素を削除もする場合は、 [K2hKeyQueue::pop](k2hkq_popja.html) を使ってください。

## パラメータ
- pos  
要素の位置
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
要素（キーと値のセット） 

## 例
- 例 1 - キューから要素を取得する

```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
$k2hkeyqueue->push("test_queue_key", "test_queue_value");
var_dump($k2hkeyqueue->read(0));
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
array(2) {
  [0]=>
  string(14) "test_queue_key"
  [1]=>
  string(16) "test_queue_value"
}
```


## 参考
- [K2hKeyQueue::pop](k2hkq_popja.html) - キューから要素（キーと値のセット）を取得する
- [K2hKeyQueue::push](k2hkq_pushja.html) - キューに要素（キーと値のセット）を追加する
- [K2hKeyQueue::remove](k2hkq_removeja.html) - キューから要素（キーと値のセット）を削除する
