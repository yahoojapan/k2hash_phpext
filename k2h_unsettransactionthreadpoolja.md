---
layout: contents
language: ja
title: K2hash::unsetTransactionThreadPool
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_unsettransactionthreadpool.html
lang_opp_word: To English
prev_url: k2h_transactionja.html
prev_string: K2hash::transaction
top_url: k2h_classja.html
top_string: K2hash Class
next_url: 
next_string: 
---

# K2hash::unsetTransactionThreadPool
トランザクション処理用のスレッドを利用しない

## 説明

```
 public static bool K2hash::unsetTransactionThreadPool ( void )
```

トランザクション処理用のスレッドを利用しません。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - トランザクション処理用のスレッド数を設定する

```
<?php
var_dump(K2hash::settransactionThreadPool(1));
var_dump(K2hash::gettransactionThreadPool());
var_dump(K2hash::unsettransactionThreadPool());
?>
```

上の例の出力は以下となります。

```
bool(true)
int(1)
bool(true)
```


## 参考
- [K2hash::getTransactionThreadPool](k2h_gettransactionthreadpoolja.html) - トランザクション処理用のスレッド数を取得する
- [K2hash::setTransactionThreadPool](k2h_settransactionthreadpoolja.html) - トランザクション処理用のスレッド数を設定する
