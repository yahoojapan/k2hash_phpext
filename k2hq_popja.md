---
layout: contents
language: ja
title: K2hQueue::pop
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_pop.html
lang_opp_word: To English
prev_url: k2hq_isemptyja.html
prev_string: K2hQueue::isEmpty
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: k2hq_pushja.html
next_string: K2hQueue::push
---

# K2hQueue::pop
キューから要素を取得する

## 説明

```
public stringfalseK2hQueue::pop ([ string $pass ] )
```

キューから要素を取得します。 

## パラメータ
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
要素 

## 例
- 例 1 - キューから要素を取得する

```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_value");
var_dump($k2hqueue->pop());
unset($k2hqueue);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
array(2) {
  [0]=>
  string(16) "test_queue_value"
}
```


## 参考
- [K2hQueue::push](k2hq_pushja.html) - キューに要素を追加する
- [K2hQueue::read](k2hq_readja.html) - キューの要素を表示する
- [K2hQueue::remove](k2hq_removeja.html) - キューから要素を削除する
