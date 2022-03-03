---
layout: contents
language: ja
title: k2hpx_transaction
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_transaction.html
lang_opp_word: To English
prev_url: k2hpx_set_valueja.html
prev_string: k2hpx_set_value
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_unload_hash_libraryja.html
next_string: k2hpx_unload_hash_library
---

# k2hpx_transaction
トランザクションを有効また無効にする

## 説明
```
bool k2hpx_transaction ( mixed $handle_res , bool $enable [, stringnull $transfile [, stringnull $prefix [, stringnull $param [, int $expire ]]]] )
```
トランザクションを有効また無効にする。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- enable  
トランザクションを有効する場合は、true。そうでなければ、false
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
- [K2hash::transaction](k2h_transactionja.html) - トランザクションを有効また無効にする
s