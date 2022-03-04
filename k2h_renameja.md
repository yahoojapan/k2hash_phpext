---
layout: contents
language: ja
title: K2hash::rename
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_rename.html
lang_opp_word: To English
prev_url: k2h_removeallja.html
prev_string: K2hash::removeAll
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_setcommonattributeja.html
next_string: K2hash::setCommonAttribute
---

# K2hash::rename
キー名を変更する

## 説明

```
 public bool K2hash::rename ( string $key , string $newkey )
```

キー名を変更します。 

## パラメータ
- key  
現在のキー名
- newkey  
変更後のキー名

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - キー名を変更する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("test1", "value");
var_dump($k2hash->rename("test1", "test2"));
var_dump($k2hash->getValue("test2"));
?>
```

上の例の出力は以下となります。

```
bool(true)
string(5) "value"
```


## 参考
- [K2hash::getValue](k2h_getvalueja.html) - 値を取得する
- [K2hash::setValue](k2h_setvalueja.html) - キーに値を設定する
