---
layout: contents
language: ja
title: K2hash::addAttrPluginLib
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addattrpluginlib.html
lang_opp_word: To English
prev_url: k2h_addattrcryptpassja.html
prev_string: K2hash::addAttrCryptPass
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_addsubkeyja.html
next_string: K2hash::addSubkey
---

# K2hash::addAttrPluginLib
ユーザ定義の動的ライブラリを追加する

## 説明
```
public bool K2hash::addAttrPluginLib ( string $libfile )
```
ユーザ定義の動的ライブラリを追加します。k2hashは、キーに対して任意の属性を付与できます。本メソッドは、ユーザ定義の動的ライブラリを追加し、キーに属性を追加します。 

## パラメータ
- libfile  
動的ライブラリのパス

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ユーザ定義の動的ライブラリを追加する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->addAttrPluginLib("/tmp/libk2htestattr.so"));
$k2hash->close();
?>
```
上の例の出力は以下となります。
```
bool(true)
```

## 参考
- [K2hash::addAttr](k2h_addattrja.html) - キーに属性を追加する
- [K2hash::addAttrCryptPass](k2h_addattrcryptpassja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
