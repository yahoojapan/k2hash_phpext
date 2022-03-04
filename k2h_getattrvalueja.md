---
layout: contents
language: ja
title: K2hash::getAttrValue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getattrvalue.html
lang_opp_word: To English
prev_url: k2h_getattrsja.html
prev_string: K2hash::getAttrs
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getattrversioninfosja.html
next_string: K2hash::getAttrVersionInfos
---

# K2hash::getAttrValue
キーに設定されている属性値を取得する

## 説明

```
public stringfalseK2hash::getAttrValue ( string $key , string $attrkey )
```

キーに設定されている属性値を取得します。 

## パラメータ
- key  
キー
- attrkey  
キーに設定されている属性名

## 戻り値
キーに設定された属性名が存在する場合は、属性値、それ以外はfalse

## 例
- 例 1 - 属性を追加し、取得する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test", "value");
$k2hash->addAttr("test", "testattr", "testattrvalue");

var_dump($k2hash->getAttrValue("test", "testattr"));
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
string(13) "testattrvalue"
```


## 参考
- [K2hash::addAttr](k2h_addattrja.html) - キーに属性を追加する
- [K2hash::addAttrCryptPass](k2h_addattrcryptpassja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
