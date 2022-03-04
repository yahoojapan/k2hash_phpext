---
layout: contents
language: ja
title: K2hash::addSubkey
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addsubkey.html
lang_opp_word: To English
prev_url: k2h_addattrpluginlibja.html
prev_string: K2hash::addAttrPluginLib
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_addsubkeysja.html
next_string: K2hash::addSubkeys
---

# K2hash::addSubkey
キーを紐づける

## 説明

```
public bool K2hash::addSubkey ( string $key , string $subkey )
```

キーに他のキーを紐付けます。紐づけるキーは、紐づけられるキーの「サブキー」と呼びます。 

## パラメータ
- key  
サブキーを追加されるキー
- subkey  
サブキー

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - サブキーを追加する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->addSubkey("test", "sub");
var_dump($k2hash->getSubkeys("test"));
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
array(1) {
  [0]=>
  string(3) "sub"
}
```


## 参考
- [K2hash::addSubkeys](k2h_addsubkeysja.html) - 複数のキーを紐づける
- [K2hash::getSubkeys](k2h_getsubkeysja.html) - キーに紐づけられたキー（サブキー）の一覧を取得する
