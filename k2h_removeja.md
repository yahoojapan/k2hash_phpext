---
layout: contents
language: ja
title: K2hash::remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_remove.html
lang_opp_word: To English
prev_url: k2h_putarchiveja.html
prev_string: K2hash::putArchive
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_removeallja.html
next_string: K2hash::removeAll
---

# K2hash::remove
キーを削除する

## 説明
```
 public bool K2hash::remove ( string $key [, string $subkey ] )
```
キーを削除します。キーに紐づけられたキーをサブキーと呼びます。サブキーに紐づけられたキーを親キーと呼びます。  
親キーのみを指定した場合は、サブキーは削除されません。  
サブキーを指定した場合は、サブキーは削除され、親キーは削除されません。  

## パラメータ
- key  
キー（親キー）
- subkey  
キーに紐付けられたキー（サブキー）

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

$k2hash->remove("test1");
var_dump($k2hash->getValue("test1"));
var_dump($k2hash->getValue("sub1"));
?>
```
上の例の出力は以下となります。
```
bool(false)
string(9) "sub-value"
```

- 例 2 - キー（親キー）に紐づけられたキー（サブキー）を削除する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value");
$k2hash->setValue("sub1", "sub-value");
$k2hash->addSubkey("test1", "sub1");

$k2hash->remove("test1", "sub1");
var_dump($k2hash->getValue("test1"));
var_dump($k2hash->getValue("sub1"));
?>
```
上の例の出力は以下となります。
```
string(5) "value"
bool(false)
```

## 参考
- [K2hash::removeAll](k2h_removeallja.html) - キーと、キーに紐づけられているキー（サブキー）を削除する
- [K2hash::setValue](k2h_setvalueja.html) - キーに値を設定する
