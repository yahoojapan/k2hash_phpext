---
layout: contents
language: ja
title: K2hIterator::rewind
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_rewind.html
lang_opp_word: To English
prev_url: k2hiter_nextja.html
prev_string: K2hIterator::next
top_url: k2hiter_classja.html
top_string: K2hIterator Class
next_url: k2hiter_validja.html
next_string: K2hIterator::valid
---

# K2hIterator::rewind
配列のポインタを巻き戻します。

## 説明
```
 public void K2hIterator::rewind ( void )
```
k2hashのキー配列のポインタを巻き戻します。

## パラメータ
この関数にはパラメータはありません。

## 戻り値
値を返しません。 

## 例
- 例 1 - キー配列のポインタを巻き戻します。
```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
k2hpx_set_value($handle, "test2", "value2");
$k2hiter = new K2hIterator($handle);
$k2hiter->next();
$k2hiter->rewind();
var_dump($k2hiter->key());
unset($k2hiter);
?>
```
上の例の出力は以下となります。
```
string(5) "test1"
```

## 参考
- [K2hIterator::current](k2hiter_currentja.html) - 配列内の現在の要素を取得する
- [K2hIterator::key](k2hiter_keyja.html) - 配列からキーを取得する
- [K2hIterator::next](k2hiter_nextja.html) - 配列のポインタを一つ進める
