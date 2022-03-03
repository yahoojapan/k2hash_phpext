---
layout: contents
language: ja
title: K2hash::putArchive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_putarchive.html
lang_opp_word: To English
prev_url: k2h_printversionja.html
prev_string: K2hash::printVersion
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_removeja.html
next_string: K2hash::remove
---

# K2hash::putArchive
k2hashファイルをアーカイブファイルとして保存する

## 説明
```
 public bool K2hash::putArchive ( string $filepath [, bool $errskip ] )
```
k2hashファイルをアーカイブファイルとして保存します。 

## パラメータ
- filepath  
アーカイブファイルのパス
- errskip  
データロード中のエラーを無視する場合は、true。そうでなければ、false

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - アーカイブファイルの作成とロード
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("key1", "value1");
var_dump($k2hash->putArchive("/tmp/test_k2h_archive", true));
$k2hash->close();

$k2hash2 = new K2hash();
$k2hash2->openMem();
$k2hash2->loadArchive("/tmp/test_k2h_archive", true);
var_dump($k2hash2->getValue("key1"));
$k2hash2->close();
?>
```
上の例の出力は以下となります。
```
bool(true)
string(6) "value1"
```

## 参考
- [K2hash::loadArchive](k2h_loadarchiveja.html) - ファイルからデータをロードする
