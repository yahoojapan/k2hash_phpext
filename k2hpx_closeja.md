---
layout: contents
language: ja
title: k2hpx_close
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_close.html
lang_opp_word: To English
prev_url: k2hpx_clean_common_attrja.html
prev_string: k2hpx_clean_common_attr
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_createja.html
next_string: k2hpx_create
---

# k2hpx_close
k2hashファイルを閉じる

## 説明

```
bool k2hpx_close ( mixed $handle_res [, int $waitms ] )
```

オープンされているk2hashファイルを閉じて、変更内容を保存します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 k2hpx_open 関数の戻り値。
- waitms  
k2hashファイルを閉じるまでの待ち時間（単位は1/1000秒）

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::close](k2h_closeja.html) - k2hファイルを閉じる
