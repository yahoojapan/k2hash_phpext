---
layout: contents
language: ja
title: K2hash::addAttrCryptPass
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_addattrcryptpass.html
lang_opp_word: To English
prev_url: k2h_addattrja.html
prev_string: K2hash::addAttr
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_addattrpluginlibja.html
next_string: K2hash::addAttrPluginLib
---

# K2hash::addAttrCryptPass
値を暗号化するパスワード（暗号鍵）を追加する

## 説明

```
public bool K2hash::addAttrCryptPass ( string $encpass [, bool $is_default_encrypt ] )
```

値を暗号化するパスワードを追加します。パスワードは、AES256共通鍵として使われます。 

## パラメータ
- encpass  
値を暗号化するためのパスワード文字列
- is_default_encrypt  
値を常時暗号化する場合は、true。それ以外はfalse（デフォルトはfalse）。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - 暗号化パスワードを追加する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->addAttrCryptPass("testkey", true));
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
bool(true)
```


## 参考
- [K2hash::addAttr](k2h_addattrja.html) - キーに属性を追加する
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
