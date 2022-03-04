---
layout: contents
language: ja
title: k2hpx_print_attr_version
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_print_attr_version.html
lang_opp_word: To English
prev_url: k2hpx_print_attr_informationja.html
prev_string: k2hpx_print_attr_information
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_print_stateja.html
next_string: k2hpx_print_state
---

# k2hpx_print_attr_version
属性のライブラリバージョン情報を表示する

## 説明

```
bool k2hpx_print_attr_version ( mixed $handle_res [, mixed $output ] )
```

属性のライブラリバージョン情報を表示します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
