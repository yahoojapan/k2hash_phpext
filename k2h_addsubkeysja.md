---
layout: contents
language: ja
title: K2hash::addSubkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addsubkeys.html
lang_opp_word: To English
prev_url: k2h_addsubkeyja.html
prev_string: K2hash::addSubkey
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_cleancommonattributeja.html
next_string: K2hash::cleanCommonAttribute
---

# K2hash::addSubkeys
複数のキーを紐づける

## 説明

```
public bool K2hash::addSubkeys ( string $key , array $subkeys )
```

キーに複数のキーを紐付けます。紐づけるキーは、紐づけられるキーの「サブキー」と呼びます。 

## パラメータ
- key  
サブキーを追加されるキー
- subkeys  
サブキーの配列

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - サブキーを追加する

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
- [K2hash::getSubkeys](k2h_getsubkeysja.html) - キーに紐づけられたキー（サブキー）の一覧を取得する
