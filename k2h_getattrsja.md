---
layout: contents
language: ja
title: K2hash::getAttrs
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getattrs.html
lang_opp_word: To English
prev_url: k2h_getattrinfosja.html
prev_string: K2hash::getAttrInfos
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getattrvalueja.html
next_string: K2hash::getAttrValue
---

# K2hash::getAttrs
キーに設定されている属性を取得する

## 説明

```
public arrayfalseK2hash::getAttrs ( string $key )
```

キーに設定されている属性を取得します。 

## パラメータ
- key  
キー

## 戻り値
キーに設定された属性が存在する場合は、属性の配列、それ以外はfalse

## 例
- 例 1 - 属性を取得する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test", "value");
$k2hash->addAttr("test", "testattr", "testattrvalue");

var_dump($k2hash->getAttrs("test"));
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
array(1) {
  [0]=>
  string(8) "testattr"
}
```


## 参考
- [K2hash::addAttr](k2h_addattrja.html) - キーに属性を追加する
- [K2hash::addAttrCryptPass](k2h_addattrcryptpassja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
