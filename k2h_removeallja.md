---
layout: contents
language: ja
title: K2hash::removeAll
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_removeall.html
lang_opp_word: To English
prev_url: k2h_removeja.html
prev_string: K2hash::remove
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_renameja.html
next_string: K2hash::rename
---

# K2hash::removeAll
キーと、キーに紐づけられているキー（サブキー）を削除する

## 説明

```
 public bool K2hash::removeAll ( string $key )
```

キーと、キーに紐づけられているキー（サブキー）を削除します。 

## パラメータ
- key  
キー

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - 親キーを削除する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value");
$k2hash->setValue("sub1", "sub-value");
$k2hash->addSubkey("test1", "sub1");

$k2hash->removeAll("test1");
var_dump($k2hash->getValue("test1"));
var_dump($k2hash->getValue("sub1"));
?>
```

上の例の出力は以下となります。

```
bool(false)
bool(false)
```


## 参考
- [K2hash::remove](k2h_removeja.html) - キーを削除する
- [K2hash::setValue](k2h_setvalueja.html) - キーに値を設定する
