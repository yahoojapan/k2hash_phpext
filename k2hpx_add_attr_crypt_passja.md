---
layout: contents
language: ja
title: k2hpx_add_attr_crypt_pass
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_attr_crypt_pass.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_add_attr_plugin_libraryja.html
next_string: k2hpx_add_attr_plugin_library
---

# k2hpx_add_attr_crypt_pass
値を暗号化するパスワード（暗号鍵）を追加する

## 説明
```
 bool k2hpx_add_attr_crypt_pass ( mixed $handle_res , string $encpass [, bool $is_default_encrypt ] )
```
値を暗号化するパスワードを追加します。パスワードは、AES256共通鍵として使われます。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 k2hpx_open 関数の戻り値。
- encpass  
値を暗号化するためのパスワード文字列
- is_default_encrypt  
値を常時暗号化する場合は、true。それ以外はfalse（デフォルトはfalse）。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::addAttrCryptPass](k2h_addattrcryptpassja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
