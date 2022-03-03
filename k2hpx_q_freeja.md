---
layout: contents
language: ja
title: k2hpx_q_free
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_q_free.html
lang_opp_word: To English
prev_url: k2hpx_q_emptyja.html
prev_string: k2hpx_q_empty
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_handleja.html
next_string: k2hpx_q_handle
---

# k2hpx_q_free
K2hQueueキューハンドルを解放する

## 説明
```
bool k2hpx_q_free ( mixed $qhandle_res )
```
[K2hQueue](k2hq_classja.html)キューハンドルを解放します。 

## パラメータ
- qhandle_res  
[K2hQueue](k2hq_classja.html) ハンドル。 [k2hpx_q_handle](k2hpx_q_handleja.html) 関数の戻り値。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - [K2hQueue](k2hq_classja.html)ハンドルを解放する
```
<?php
$handle = k2hpx_open_mem();
$qhandle = k2hpx_q_handle($handle, true, "test_queue_");
var_dump(k2hpx_q_free($qhandle));
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
bool(true)
```
