---
layout: contents
language: ja
title: K2hash::close
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_close.html
lang_opp_word: To English
prev_url: k2h_cleancommonattributeja.html
prev_string: K2hash::cleanCommonAttribute
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_createja.html
next_string: K2hash::create
---

# K2hash::close
k2hashファイルを閉じる

## 説明

```
 public bool K2hash::close ([ int $waitms ] )
```

オープンされているk2hファイルを閉じて、変更内容を保存します。

## パラメータ
- waitms  
k2hファイルを閉じるまでの待ち時間（単位は1/1000秒）

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - k2hashファイルを閉じる

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->close());
?>
```

上の例の出力は以下となります。

```
bool(true)
```


## 参考
- [K2hash::open](k2h_openja.html) - k2hファイルを開く
- [K2hash::openMem](k2h_openmemja.html) - k2hash用メモリセグメントにアクセスする
- [K2hash::openRO](k2h_openroja.html) - k2hファイルを 読み込む
- [K2hash::openRW](k2h_openrwja.html) - k2hファイルを編集する
- [K2hash::openTempfile](k2h_opentempfileja.html) - 一時ファイルとしてk2hファイルを編集する
