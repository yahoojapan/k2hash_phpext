---
layout: contents
language: ja
title: K2hash::getTransactionThreadPool
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_gettransactionthreadpool.html
lang_opp_word: To English
prev_url: k2h_getsubkeysja.html
prev_string: K2hash::getSubkeys
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getvalueja.html
next_string: K2hash::getValue
---

# K2hash::getTransactionThreadPool
トランザクション処理用のスレッド数を取得する

## 説明

```
 public static int K2hash::getTransactionThreadPool ( void )
```

トランザクション処理用のスレッド数を取得します。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
トランザクション処理用スレッド数 

## 例
- 例 1 - トランザクション処理用スレッド数を取得する

```
<?php
var_dump(K2hash::gettransactionThreadPool());
?>
```

上の例の出力は以下となります。

```
int(0)
```


## 参考
- [K2hash::setTransactionThreadPool](k2h_settransactionthreadpoolja.html) - トランザクション処理用のスレッド数を設定する
