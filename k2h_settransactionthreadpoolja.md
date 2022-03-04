---
layout: contents
language: ja
title: K2hash::setTransactionThreadPool
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_settransactionthreadpool.html
lang_opp_word: To English
prev_url: k2h_setcommonattributeja.html
prev_string: K2hash::setCommonAttribute
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_setvalueja.html
next_string: K2hash::setValue
---

# K2hash::setTransactionThreadPool
トランザクション処理用のスレッド数を設定する

## 説明

```
 public static bool K2hash::setTransactionThreadPool ( int $count )
```

トランザクション処理用のスレッド数を設定します。 

## パラメータ
- count  
トランザクション処理用のスレッド数

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - トランザクション処理用のスレッド数を設定する

```
<?php
var_dump(K2hash::settransactionThreadPool(1));
var_dump(K2hash::gettransactionThreadPool());
?>
```

上の例の出力は以下となります。

```
bool(true)
int(1)
```


## 参考
- [K2hash::getTransactionThreadPool](k2h_gettransactionthreadpoolja.html) - トランザクション処理用のスレッド数を取得する
