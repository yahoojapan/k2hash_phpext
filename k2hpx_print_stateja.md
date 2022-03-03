---
layout: contents
language: ja
title: k2hpx_print_state
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_print_state.html
lang_opp_word: To English
prev_url: k2hpx_print_attr_versionja.html
prev_string: k2hpx_print_attr_version
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_print_versionja.html
next_string: k2hpx_print_version
---

# k2hpx_print_state
k2hashのデータの状態を表示する

## 説明
```
bool k2hpx_print_state ( mixed $handle_res [, mixed $output ] )
```
k2hashのデータの状態を表示します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。

## 参考
- [K2hash::printState](k2h_printstateja.html) - k2hashのデータの状態を表示する
