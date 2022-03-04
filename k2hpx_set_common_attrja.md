---
layout: contents
language: ja
title: k2hpx_set_common_attr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_common_attr.html
lang_opp_word: To English
prev_url: k2hpx_renameja.html
prev_string: k2hpx_rename
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_set_debug_fileja.html
next_string: k2hpx_set_debug_file
---

# k2hpx_set_common_attr
キーの基本属性を設定する

## 説明

```
bool k2hpx_set_common_attr ( mixed $handle_res [, int $is_mtime [, int $is_history [, int $is_encrypt [, stringnull $passfile [, int $is_expire [, int $expire ]]]]]] )
```

キーの基本属性を設定します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- is_mtime  
キーの更新時刻を保存する場合は、true。設定変更しない場合は、NULL。
- is_history  
キーの履歴を保存する場合は、true。設定変更しない場合は、NULL。
- is_encrypt  
値を暗号化する場合は、true。そうでない場合は、false設定変更しない場合は、NULL。
- passfile  
値を暗号化するパスワード（共有鍵）が保存されているファイルのパス。
- is_expire  
キーの有効期限を指定する場合は、true。設定変更しない場合は、NULL。
- expire  
キーの有効期限（秒）。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::setCommonAttribute](k2h_setcommonattributeja.html) - キーの基本属性を設定する
