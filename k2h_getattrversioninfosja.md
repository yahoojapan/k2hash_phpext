---
layout: contents
language: ja
title: K2hash::getAttrVersionInfos
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getattrversioninfos.html
lang_opp_word: To English
prev_url: k2h_getattrvalueja.html
prev_string: K2hash::getAttrValue
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getiteratorja.html
next_string: K2hash::getIterator
---

# K2hash::getAttrVersionInfos
属性のライブラリバージョン情報を表示する

## 説明
```
 public bool K2hash::getAttrVersionInfos ([ mixed $output ] )
```
属性のライブラリバージョン情報を表示します。 

## パラメータ
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力。

## 戻り値
成功時はtrue、それ以外はfalse

## 例
- 例 1 -  属性のライブラリバージョン情報を表示する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$fp = fopen("/tmp/k2hash_attrversion_information.log", 'w');
$k2hash->getAttrVersionInfos($fp);
fclose($fp);
$k2hash->close();

$fp = fopen("/tmp/k2hash_attrversion_information.log", 'r');
if ($fp) {
        while (!feof($fp)) {
        if (($buf = fgets($fp, 4096)) !== false) {
            echo $buf;
        }
    }
        fclose($fp);
}
?>
```
上の例の出力は以下となります。
```
K2HASH attribute libraries:  K2H ATTR BUILTIN
```

## 参考
- [K2hash::addAttr](k2h_addattrja.html) - キーに属性を追加する
- [K2hash::addAttrCryptPass](k2h_addattrcryptpassja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
