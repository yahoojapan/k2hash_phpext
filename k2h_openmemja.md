---
layout: contents
language: ja
title: K2hash::openMem
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_openmem.html
lang_opp_word: To English
prev_url: k2h_openja.html
prev_string: K2hash::open
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_openroja.html
next_string: K2hash::openRO
---

# K2hash::openMem
揮発性（メモリ）としてk2hashをオープンします。

## 説明
```
 public bool K2hash::openMem ([ int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
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
成功した場合に true を、失敗した場合に false を返します。

## 参考
- [K2hash::open](k2h_openja.html) - k2hファイルを開く
- [K2hash::openRO](k2h_openroja.html) - k2hファイルを 読み込む
- [K2hash::openRW](k2h_openrwja.html) - k2hファイルを編集する
- [K2hash::openTempfile](k2h_opentempfileja.html) - 一時ファイルとしてk2hファイルを編集する
