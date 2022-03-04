---
layout: contents
language: ja
title: K2hash::loadArchive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_loadarchive.html
lang_opp_word: To English
prev_url: k2h_getvalueja.html
prev_string: K2hash::getValue
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_openja.html
next_string: K2hash::open
---

# K2hash::loadArchive
ファイルからデータをロードする

## 説明

```
 public bool K2hash::loadArchive ( string $filepath [, bool $errskip ] )
```

トランザクションファイルまたはアーカイブファイルからデータをロードします。 

## パラメータ
- filepath  
トランザクションファイルまたはアーカイブファイルのパス
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
- [K2hash::enableTransaction](k2h_enabletransactionja.html) - トランザクションを開始する
- [K2hash::putArchive](k2h_putarchiveja.html) - k2hファイルをアーカイブファイルとして保存する
- [K2hash::transaction](k2h_transactionja.html) - トランザクションを有効また無効にする
