---
layout: contents
language: ja
title: K2hash::cleanCommonAttribute
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_cleancommonattribute.html
lang_opp_word: To English
prev_url: k2h_addsubkeysja.html
prev_string: K2hash::addSubkeys
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_closeja.html
next_string: K2hash::close
---

# K2hash::cleanCommonAttribute
キーの基本属性を初期化する

## 説明
```
public bool K2hash::cleanCommonAttribute ( void )
```
キーの基本属性を初期化します。  

基本属性は次のとおりです。  
- mtime  
設定値がtrueの時に、値の変更時刻を記録します。
- encrypt  
設定値がtrueの時に、値を暗号化します。
- history  
設定値がtrueの時、値の変更履歴を保存します。
- expire  
設定値がtrueの時、値に有効期限が設定されます。

## パラメータ
この関数にはパラメータはありません。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - 基本属性を初期化する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->cleanCommonAttribute());
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
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
