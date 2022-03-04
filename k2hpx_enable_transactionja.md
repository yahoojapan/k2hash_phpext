---
layout: contents
language: ja
title: k2hpx_enable_transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_enable_transaction.html
lang_opp_word: To English
prev_url: k2hpx_dump_keytableja.html
prev_string: k2hpx_dump_keytable
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_find_firstja.html
next_string: k2hpx_find_first
---

# k2hpx_enable_transaction
トランザクションを開始する

## 説明

```
bool k2hpx_enable_transaction ( mixed $handle_res [, stringnull $transfile [, stringnull $prefix [, stringnull $param [, int $expire ]]]] )
```

トランザクションを開始します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
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

## 参考
- [K2hash::enableTransaction](k2h_enabletransactionja.html) - トランザクションを開始する
