---
layout: contents
language: ja
title: K2hash::open
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_open.html
lang_opp_word: To English
prev_url: k2h_loadarchiveja.html
prev_string: K2hash::loadArchive
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_openmemja.html
next_string: K2hash::openMem
---

# K2hash::open
k2hashファイルを開く

## 説明

```
 public bool K2hash::open ( string $filepath , bool $readonly [, bool $removefile [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]]] )
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
- [K2hash::close](k2h_closeja.html) - k2hファイルを閉じる
- [K2hash::openMem](k2h_openmemja.html) - 揮発性（メモリ）としてk2hashをオープンする
- [K2hash::openRO](k2h_openroja.html) - k2hファイルを 読み込む
- [K2hash::openRW](k2h_openrwja.html) - k2hファイルを編集する
- [K2hash::openTempfile](k2h_opentempfileja.html) - 一時ファイルとしてk2hファイルを編集する
