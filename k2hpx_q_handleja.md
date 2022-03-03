---
layout: contents
language: ja
title: k2hpx_q_handle
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_handle.html
lang_opp_word: To English
prev_url: k2hpx_q_freeja.html
prev_string: k2hpx_q_free
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_popja.html
next_string: k2hpx_q_pop
---

# k2hpx_q_handle
K2hQueueハンドルを取得する

## 説明
```
mixed k2hpx_q_handle ( mixed $handle_res [, bool $is_filo [, stringnull $prefix ]] )
```
[K2hQueue](k2hq_classja.html) ハンドルを取得します。

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- is_filo  
[K2hQueue](k2hq_classja.html)キューをFIFO(先入先出し)キューとする場合はtrue、そうでなければ、false
- prefix  
[K2hQueue](k2hq_classja.html)キューのプレフィックス

## 戻り値
[K2hQueue](k2hq_classja.html)ハンドル 

## 例
- 例 1 - [K2hQueue](k2hq_classja.html)ハンドルを取得する
```
<?php
$handle = k2hpx_open_mem();
$qhandle = k2hpx_q_handle($handle, true, "test_queue_");
var_dump($qhandle);
k2hpx_q_free($qhandle);
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
resource(5) of type (k2hqhandle)
```

## 参考
- [K2hQueue::__construct](k2hq_constructja.html) - 新しいK2hQueueオブジェクトを作成する
