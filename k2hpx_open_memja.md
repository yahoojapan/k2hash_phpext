---
layout: contents
language: ja
title: k2hpx_open_mem
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_open_mem.html
lang_opp_word: To English
prev_url: k2hpx_load_transaction_libraryja.html
prev_string: k2hpx_load_transaction_library
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_open_roja.html
next_string: k2hpx_open_ro
---

# k2hpx_open_mem
揮発性（メモリ）としてk2hashをオープンします。

## 説明

```
mixed k2hpx_open_mem ([ int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
```

揮発性（メモリ）としてk2hashをオープンします。

## パラメータ
- maskbitcnt  
初期MASKビットカウント数。この値は、キーに対するハッシュ値をマスクするするときに使われます。
- cmaskbitcnt  
CMASKビットカウント数。この値は、キーが衝突した際に、データの位置を決めるときに使われます。
- maxelementcnt  
ハッシュ値の衝突時の重複された要素数の上限
- pagesize  
データ保管時のブロックサイズ。データ（一つのキー、値、サブキーリスト）を格納するデータの最小単位です。

## 戻り値
成功時はk2hashデータハンドル、それ以外は0。 

## 参考
- [K2hash::openMem](k2h_openmemja.html) - 揮発性（メモリ）としてk2hashをオープンする
