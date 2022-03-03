---
layout: contents
language: ja
title: K2hIterator::__construct
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_construct.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: k2hiter_classja.html
top_string: K2hIterator Class
next_url: k2hiter_currentja.html
next_string: K2hIterator::current
---

# K2hIterator::__construct
新しい K2hIterator オブジェクトを作成する

## 説明
```
public K2hIterator::__construct ( mixed $handle_res [, string $key ] )
```
新しい [K2hIterator](k2hiter_classja.html) オブジェクトを作成します。このオブジェクトは、k2hashのキーの配列へのポインタです。 

## パラメータ
- handle_res  
k2hファイルハンドル
- key  
イテレーターの開始となるキー。

## 例
- 例 1 - [K2hIterator](k2hiter_classja.html)を取得する
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
$k2hiter = new K2hIterator($handle);
var_dump($k2hiter->key());
unset($k2hiter);

k2hpx_set_value($handle, "test1", "value1", "sub");
$k2hiter = new K2hIterator($handle, "test1");
var_dump($k2hiter->key());
unset($k2hiter);
?>
```
上の例の出力は以下となります。
```
string(5) "test1"
string(3) "sub"
```

## 参考
- [K2hash::getIterator](k2h_getiteratorja.html) - K2hIteratorオブジェクトを取得する
