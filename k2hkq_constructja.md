---
layout: contents
language: ja
title: K2hKeyQueue::__construct
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_construct.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: k2hkq_classja.html
top_string: K2hKeyQueue Class
next_url: k2hkq_countja.html
next_string: K2hKeyQueue::count
---

# K2hKeyQueue::__construct
新しいK2hKeyQueueオブジェクトを作成する

## 説明

```
public K2hKeyQueue::__construct ( mixed $handle_res [, bool $is_fifo [, string $prefix ]] )
```

新しい[K2hKeyQueue](k2hkq_classja.html)オブジェクトを作成します。 

## パラメータ
- handle_res  
k2hashファイルハンドル
- is_fifo  
FIFO(先入先出し)キューならtrue、そうでなければ、false
- prefix  
キューのプレフィックス

## 例
- 例 1 - [K2hKeyQueue](k2hkq_classja.html)を取得する

```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
var_dump($k2hkeyqueue);
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
object(K2hKeyQueue)#1 (0) {
}
```


## 参考
- [K2hash::getKeyQueue](k2h_getkeyqueueja.html) - K2hKeyQueueオブジェクトを取得する
