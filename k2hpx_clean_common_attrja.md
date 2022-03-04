---
layout: contents
language: ja
title: k2hpx_clean_common_attr
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_clean_common_attr.html
lang_opp_word: To English
prev_url: k2hpx_bump_debug_levelja.html
prev_string: k2hpx_bump_debug_level
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_closeja.html
next_string: k2hpx_close
---

# k2hpx_clean_common_attr
キーの基本属性を初期化する

## 説明

```
bool k2hpx_clean_common_attr ( mixed $handle_res )
```

キーの基本属性を初期化します。

基本属性は次のとおりです。
- mtime  
設定値がtrueの時に、k2hashは、値の変更時刻を記録します。
- encrypt  
設定値がtrueの時に、k2hashは、値を暗号化します。
- history  
設定値がtrueの時、k2hashは、値の変更履歴を保存します。
- expire  
設定値がtrueの時、k2hashは、値に有効期限を設定します。

## パラメータ
- handle_res  
k2hash (.k2h) ファイルハンドル。 k2hpx_open 関数の戻り値。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
