---
layout: contents
language: ja
title: K2hIterator::current
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_current.html
lang_opp_word: To English
prev_url: k2hiter_constructja.html
prev_string: K2hIterator::__construct
top_url: k2hiter_classja.html
top_string: K2hIterator Class
next_url: k2hiter_keyja.html
next_string: K2hIterator::key
---

# K2hIterator::current
配列内の現在の要素を取得する

## 説明
```
public stringfalseK2hIterator::current ( void )
```
k2hashのキー配列内の現在の要素の値を取得します。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
キーの値 

## 例
- 例 1 - k2hashのキー配列内の現在の要素の値を取得する
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
k2hpx_set_value($handle, "test2", "value2");
$k2hiter = new K2hIterator($handle);
var_dump($k2hiter->current());
var_dump($k2hiter->key());
var_dump($k2hiter->next());
var_dump($k2hiter->current());
var_dump($k2hiter->key());
?>
```
上の例の出力は以下となります。
```
string(6) "value1"
string(5) "test1"
NULL
string(6) "value2"
string(5) "test2"
```

## 参考
- [K2hIterator::key](k2hiter_keyja.html) - 配列からキーを取得する
- [K2hIterator::next](k2hiter_nextja.html) - 配列のポインタを一つ進める
- [K2hIterator::rewind](k2hiter_rewindja.html) - 配列のポインタを先頭に戻す
