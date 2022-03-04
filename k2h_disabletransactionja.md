---
layout: contents
language: ja
title: K2hash::disableTransaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_disabletransaction.html
lang_opp_word: To English
prev_url: k2h_createja.html
prev_string: K2hash::create
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_dumpelementtableja.html
next_string: K2hash::dumpElementtable
---

# K2hash::disableTransaction
トランザクションを停止する

## 説明

```
 public bool K2hash::disableTransaction ( void )
```

トランザクションを停止します。

## パラメータ
この関数にはパラメータはありません。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - トランザクションを停止する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->disableTransaction());
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
bool(true)
```


## 参考
- [K2hash::enableTransaction](k2h_enabletransactionja.html) - トランザクションを開始する
