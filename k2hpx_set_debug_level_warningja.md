---
layout: contents
language: ja
title: k2hpx_set_debug_level_warning
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_debug_level_warning.html
lang_opp_word: To English
prev_url: k2hpx_set_debug_level_silentja.html
prev_string: k2hpx_set_debug_level_silent
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_set_transaction_thread_poolja.html
next_string: k2hpx_set_transaction_thread_pool
---

# k2hpx_set_debug_level_warning
ライブラリのログレベルをwarningにする

## 説明
```
void k2hpx_set_debug_level_warning ( void )
```
ライブラリのログレベルをwarningにします。

## パラメータ
この関数にはパラメータはありません。

## 戻り値
値を返しません。 

## 例
- 例 1 - ライブラリのログレベルをwarningにする
```
<?php
var_dump(k2hpx_set_debug_file("/tmp/k2h.log"));
k2hpx_set_debug_level_warning();
?>
```
上の例の出力は以下となります。
```
NULL
```

## 参考
- [k2hpx_bump_debug_level](k2hpx_bump_debug_levelja.html) - ログレベルを変更する
- [k2hpx_set_debug_file](k2hpx_set_debug_fileja.html) - ログ出力先ファイル名を指定する
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_errorja.html) - ライブラリのログレベルをerrorにする
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_messageja.html) - ライブラリのログレベルをmessage(info相当）にする
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silentja.html) - ライブラリのログを出力しない
- [k2hpx_unset_debug_file](k2hpx_unset_debug_fileja.html) - ログ出力先を標準エラーに指定する
