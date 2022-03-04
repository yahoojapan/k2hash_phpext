---
layout: contents
language: ja
title: k2hpx_put_archive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_put_archive.html
lang_opp_word: To English
prev_url: k2hpx_print_versionja.html
prev_string: k2hpx_print_version
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_q_countja.html
next_string: k2hpx_q_count
---

# k2hpx_put_archive
k2hashファイルをアーカイブファイルとして保存する

## 説明

```
bool k2hpx_put_archive ( mixed $handle_res , string $filepath [, bool $errskip ] )
```

k2hashファイルをアーカイブファイルとして保存します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 k2hpx_open 関数の戻り値を指定。
- filepath  
アーカイブファイルのパス
- errskip  
データロード中のエラーを無視する場合は、true。そうでなければ、false

## 戻り値
成功した場合に true を、失敗した場合に false を返します。

## 参考
- [K2hash::putArchive](k2h_putarchiveja.html) - k2hファイルをアーカイブファイルとして保存する
