---
layout: contents
language: ja
title: k2hpx_add_subkeys
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_add_subkeys.html
lang_opp_word: To English
prev_url: k2hpx_add_subkeyja.html
prev_string: k2hpx_add_subkey
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_bump_debug_levelja.html
next_string: k2hpx_bump_debug_level
---

# k2hpx_add_subkeys
複数のキーを紐づける

## 説明
``` 
k2hpx_add_subkeys ( mixed $handle_res , string $key , array $subkeys ) : bool
```
キーに複数のキーを紐付けます。紐づけるキーは、紐づけられるキーの「サブキー」と呼びます。 

## パラメータ
- handle_res  
k2hash (.k2h) ファイルハンドル。 k2hpx_open 関数の戻り値。
- key  
サブキーを追加されるキー
- subkeys  
サブキーの配列

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::addSubkeys](k2h_addsubkeysja.html) - 複数のキーを紐づける
