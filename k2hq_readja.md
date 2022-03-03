---
layout: contents
language: ja
title: K2hQueue::read
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_read.html
lang_opp_word: To English
prev_url: k2hq_pushja.html
prev_string: K2hQueue::push
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: k2hq_removeja.html
next_string: K2hQueue::remove
---

# K2hQueue::read
キューの要素を表示する

## 説明
```
public stringfalseK2hQueue::read ([ int $pos [, string $pass ]] )
```
キューの要素を表示します。 

### 注意
キューから要素は削除されません。要素を削除もする場合は、 [K2hQueue::push](k2hq_pushja.html) を使ってください。 

## パラメータ
- pos  
要素の位置
- pass  
パスワード（暗号化されている値を復号化するための鍵）

## 戻り値
要素 

## 例
- 例 1 - キューの要素を表示する
```
<?php
$handle = k2hpx_open_mem();
$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_value");
var_dump($k2hqueue->read(0));
unset($k2hqueue);
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
string(16) "test_queue_value"
```

## 参考
- [K2hQueue::pop](k2hq_popja.html) - キューから要素を取得する
- [K2hQueue::push](k2hq_pushja.html) - キューに要素を追加する
- [K2hQueue::remove](k2hq_removeja.html) - キューから要素を削除する
