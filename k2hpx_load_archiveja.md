---
layout: contents
language: ja
title: k2hpx_load_archive
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_load_archive.html
lang_opp_word: To English
prev_url: k2hpx_keyq_removeja.html
prev_string: k2hpx_keyq_remove
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_load_debug_envja.html
next_string: k2hpx_load_debug_env
---

# k2hpx_load_archive
ファイルからデータをロードする

## 説明
```
bool k2hpx_load_archive ( mixed $handle_res , string $filepath [, bool $errskip ] )
```
トランザクションファイルまたはアーカイブファイルからデータをロードします。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- filepath  
トランザクションファイルまたはアーカイブファイルのパス
- errskip  
データロード中のエラーを無視する場合は、true。そうでなければ、false

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::loadArchive](k2h_loadarchiveja.html) - ファイルからデータをロードする
