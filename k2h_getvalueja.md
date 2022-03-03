---
layout: contents
language: ja
title: K2hash::getValue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getvalue.html
lang_opp_word: To English
prev_url: k2h_gettransactionthreadpoolja.html
prev_string: K2hash::getTransactionThreadPool
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_loadarchiveja.html
next_string: K2hash::loadArchive
---

# K2hash::getValue
値を取得する

## 説明
```
public stringfalseK2hash::getValue ( string $key [, string $subkey [, bool $attrcheck [, string $pass ]]] )
```
キーの値を取得します。キーと紐づけられたキー（サブキー）が指定された場合は、サブキーの値を取得します。 

## パラメータ
- key  
キー
- subkey  
キーに紐づけられているキー（サブキー）
- attrcheck  
キーの属性を確認してから取得する場合は、true、そうでなければ、false
- pass  
暗号化されている値を復号化するためのパスワード（共有鍵）。

## 戻り値
成功時は値、そうでなければ、false

## 例
- 例 1 - 値を取得する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("key1", "value1");
var_dump($k2hash->getValue("key1"));
$k2hash->close();
?>
```
上の例の出力は以下となります。
```
string(6) "value1"
```

## 参考
- [K2hash::setValue](k2h_setvalueja.html) - キーに値を設定する
