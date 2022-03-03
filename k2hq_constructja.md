---
layout: contents
language: ja
title: K2hQueue::__construct
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_construct.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: k2hq_countja.html
next_string: K2hQueue::count
---

# K2hQueue::__construct
新しいK2hQueueオブジェクトを作成する

## 説明
```
public K2hQueue::__construct ( mixed $handle_res [, bool $is_fifo [, string $prefix ]] )
```
新しい[K2hQueue](k2hq_classja.html)オブジェクトを作成します。 

## パラメータ
- handle_res  
k2hファイルハンドル
- is_fifo  
FIFO(先入先出し)キューならtrue、そうでなければ、false
- prefix  
キューのプレフィックス

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
- [K2hash::getQueue](k2h_getqueueja.html) - K2hQueueオブジェクトを取得する
