---
layout: contents
language: ja
title: K2hash::getIterator
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getiterator.html
lang_opp_word: To English
prev_url: k2h_getattrversioninfosja.html
prev_string: K2hash::getAttrVersionInfos
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getkeyqueueja.html
next_string: K2hash::getKeyQueue
---

# K2hash::getIterator
K2hIteratorオブジェクトを取得する

## 説明

```
 public mixed K2hash::getIterator ( string $key )
```

指定されたキーを先頭にした [K2hIterator](k2hiter_classja.html) オブジェクトを取得します。 [K2hIterator](k2hiter_classja.html) は、k2hashのキーの配列へのポインタを操作するクラスです。

## パラメータ
- key  
イテレーターの開始となるキー。キーの指定がない場合は、 [K2hIterator](k2hiter_classja.html) オブジェクトは、配列の先頭を指します。

## 戻り値
[K2hIterator](k2hiter_classja.html) オブジェクト 

## 例
- 例 1 - [K2hIterator](k2hiter_classja.html) オブジェクトを取得する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value1");
$k2hash->setValue("test2", "value2");
$k2hash->setValue("test3", "value3");
$iterator = $k2hash->getIterator();
$count = 0;
foreach($iterator as $val){
    $count++;
}
echo $count;
?>
```

上の例の出力は以下となります。

```
3
```


## 参考
- [K2hIterator::__construct](k2hiter_constructja.html) - 新しい K2hIterator オブジェクトを作成する
