---
layout: contents
language: ja
title: K2hash::getSubkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getsubkeys.html
lang_opp_word: To English
prev_url: k2h_getstreamja.html
prev_string: K2hash::getStream
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_gettransactionthreadpoolja.html
next_string: K2hash::getTransactionThreadPool
---

# K2hash::getSubkeys
キーに紐づけられたキー（サブキー）の一覧を取得する

## 説明

```
public arrayfalseK2hash::getSubkeys ( string $key [, bool $attrcheck ] )
```

キーに紐づけられたキー（サブキー）の一覧を取得します。 

## パラメータ
- key  
サブキーの一覧が紐づいているキー
- attrcheck  
キーの属性を確認してから取得する場合は、true、そうでなければ、false

## 戻り値
引数で指定されたキーと紐づけられたキーの一覧。 

## 例
- 例 1 - サブキーの一覧を取得する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->addSubkeys("test", array("subkey1", "subkey2", "subkey3"));
var_dump($k2hash->getSubkeys("test"));
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
array(3) {
  [0]=>
  string(7) "subkey1"
  [1]=>
  string(7) "subkey2"
  [2]=>
  string(7) "subkey3"
}
```


## 参考
- [K2hash::addSubkey](k2h_addsubkeyja.html) - キーを紐づける
- [K2hash::addSubkeys](k2h_addsubkeysja.html) - 複数のキーを紐づける
