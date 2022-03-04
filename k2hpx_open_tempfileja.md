---
layout: contents
language: ja
title: k2hpx_open_tempfile
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_open_tempfile.html
lang_opp_word: To English
prev_url: k2hpx_open_rwja.html
prev_string: k2hpx_open_rw
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_openja.html
next_string: k2hpx_open
---

# k2hpx_open_tempfile
一時ファイルとしてk2hashファイルをオープンする

## 説明

```
mixed k2hpx_open_tempfile ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] )
```

一時ファイルとして、k2hashファイルを開きます。 

## パラメータ
- filepath  
k2hashファイルのパス
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
成功時はk2hashファイルハンドル、それ以外は0。 

## 参考
- [K2hash::openTempfile](k2h_opentempfileja.html) - 一時ファイルとしてk2hファイルを編集する
