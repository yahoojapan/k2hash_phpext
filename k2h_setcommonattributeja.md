---
layout: contents
language: ja
title: K2hash::setCommonAttribute
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_setcommonattribute.html
lang_opp_word: To English
prev_url: k2h_renameja.html
prev_string: K2hash::rename
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_settransactionthreadpoolja.html
next_string: K2hash::setTransactionThreadPool
---

# K2hash::setCommonAttribute
キーの基本属性を設定する

## 説明
```
 public bool K2hash::setCommonAttribute ([ int $is_mtime [, int $is_history [, int $is_encrypt [, string $passfile [, int $is_expire [, int $expire ]]]]]] )
```
キーの基本属性を設定します。 

## パラメータ
- is_mtime  
キーの更新時刻を保存する場合は、true。設定変更しない場合は、NULL。
- is_history  
キーの履歴を保存する場合は、true。設定変更しない場合は、NULL。
- is_encrypt  
値を暗号化する場合は、true。設定変更しない場合は、NULL。
- passfile  
値を暗号化するパスワード（共有鍵）が保存されているファイルのパス。
- is_expire  
キーの有効期限を指定する場合は、true。設定変更しない場合は、NULL。
- expire  
キーの有効期限（秒）。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - 基本属性を設定する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->setCommonAttribute(K2H_ATTR_ENABLE, K2H_ATTR_ENABLE, K2H_ATTR_DEFAULT, '', K2H_ATTR_ENABLE, 300));
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
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
