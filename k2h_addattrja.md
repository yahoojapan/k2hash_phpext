---
layout: contents
language: ja
title: K2hash::addAttr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addattr.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_addattrcryptpassja.html
next_string: K2hash::addAttrCryptPass
---

# K2hash::addAttr
キーに属性を追加する

## 説明

```
public bool K2hash::addAttr ( string $key , string $attrkey , string $attrval )
```

キーに属性を追加します。属性とは、該当キーに対する設定（更新時刻保持の有無、暗号化の有無、履歴情報保持の有無など）です。 

## パラメータ
- key  
属性と紐付けるキー
- attrkey  
属性名
- attrval  
属性値

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

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
- [K2hash::addAttrCryptPass](k2h_addattrcryptpassja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
