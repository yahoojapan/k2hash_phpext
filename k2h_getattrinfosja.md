---
layout: contents
language: ja
title: K2hash::getAttrInfos
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getattrinfos.html
lang_opp_word: To English
prev_url: k2h_enabletransactionja.html
prev_string: K2hash::enableTransaction
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getattrsja.html
next_string: K2hash::getAttrs
---

# K2hash::getAttrInfos
属性を取得する

## 説明
```
 public bool K2hash::getAttrInfos ([ mixed $output ] )
```
属性を取得します。属性とは、キーに対する設定（更新時刻保持の有無、暗号化の有無、履歴情報保持の有無など）です。 

## パラメータ
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。

## 例
- 例 1 - 属性を追加し、取得する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$fp = fopen("/tmp/k2hash_attr_information.log", 'w');
$k2hash->getAttrInfos($fp);
fclose($fp);
$k2hash->close();

$fp = fopen("/tmp/k2hash_attr_information.log", 'r');
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
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
