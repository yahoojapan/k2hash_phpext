---
layout: contents
language: ja
title: K2hash::transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_transaction.html
lang_opp_word: To English
prev_url: k2h_setvalueja.html
prev_string: K2hash::setValue
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_unsettransactionthreadpoolja.html
next_string: K2hash::unsetTransactionThreadPool
---

# K2hash::transaction
トランザクションを有効また無効にする

## 説明
```
 public bool K2hash::transaction ( bool $enable [, string $transfile [, string $prefix [, string $param [, int $expire ]]]] )
```
トランザクションを有効または無効にします。 

## パラメータ
- enable  
トランザクションを開始する場合は、true。そうでなければ、false
- transfile  
トランザクションログ出力先ファイルのパス
- prefix  
トランザクションログデータ（エントリ）のキー名の先頭につける識別子となる文字列
- param  
トランザクションログ処理ハンドラーに渡されるパラメータ
- expire  
トランザクションログデータの有効期限（単位：秒）

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - トランザクションを開始する
```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
var_dump($k2hash->transaction(true, "/tmp/test_k2h_trans", "trans_prefix_", "myparam"));
$k2hash->close();
?>
```
上の例の出力は以下となります。
```
bool(true)
```

## 参考
- [K2hash::disableTransaction](k2h_disabletransactionja.html) - トランザクションを停止する
- [K2hash::enableTransaction](k2h_enabletransactionja.html) - トランザクションを開始する
