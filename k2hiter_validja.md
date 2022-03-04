---
layout: contents
language: ja
title: K2hIterator::valid
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_valid.html
lang_opp_word: To English
prev_url: k2hiter_rewindja.html
prev_string: K2hIterator::rewind
top_url: k2hiter_classja.html
top_string: K2hIterator Class
next_url: 
next_string: 
---

# K2hIterator::valid
ポインタの有効性を調べる

## 説明

```
 public bool K2hIterator::valid ( void )
```

k2hashのキー配列へのポインタが有効かどうかを調べます。ポインタが配列の要素を指している場合は、有効です。

## パラメータ
この関数にはパラメータはありません。

## 戻り値
k2hashのキー配列のポインタが有効な場合にtrue、そうでない場合にfalse

## 例
- 例 1 - k2hashのキー配列のポインタが有効かどうかを調べる

```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
$k2hiter = new K2hIterator($handle);
var_dump($k2hiter->valid());
unset($k2hiter);
?>
```

上の例の出力は以下となります。

```
bool(true)
```

