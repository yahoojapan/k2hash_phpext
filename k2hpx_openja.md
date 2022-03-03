---
layout: contents
language: ja
title: k2hpx_open
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_open.html
lang_opp_word: To English
prev_url: k2hpx_open_tempfileja.html
prev_string: k2hpx_open_tempfile
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_print_attr_informationja.html
next_string: k2hpx_print_attr_information
---

# k2hpx_open
k2hashファイルを開く

## 説明
```
mixed k2hpx_open ( string $filepath , bool $readonly [, bool $removefile [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]]] )
```
k2hashファイルを開きます。 

## パラメータ
- filepath  
k2hashファイルのパス
- readonly  
読み込み専用でファイルを開く場合は、true。
- removefile  
ファイルを開いているプロセスがいない場合、ファイルを削除する場合は、true。
- fullmap  
ファイルの全データをメモリにマッピングする場合は、true（mmapを使う）。
- maskbitcnt  
初期MASKビットカウント数
- cmaskbitcnt  
CMASKビットカウント数
- maxelementcnt  
ハッシュ値の衝突時の重複された要素数の上限
- pagesize  
データ保管時のブロックサイズ

## 戻り値
成功時はk2hashファイルハンドル、それ以外は0。 

## 参考
- [K2hash::open](k2h_openja.html) - k2hファイルを開く
