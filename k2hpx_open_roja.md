---
layout: contents
language: ja
title: k2hpx_open_ro
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_open_ro.html
lang_opp_word: To English
prev_url: k2hpx_open_memja.html
prev_string: k2hpx_open_mem
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_open_rwja.html
next_string: k2hpx_open_rw
---

# k2hpx_open_ro
k2hashファイルを読み出し用にオープンする

## 説明

```
mixed k2hpx_open_ro ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] )
```

読み取り専用でk2hashファイルを開きます。

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
- [K2hash::openRO](k2h_openroja.html) - k2hファイルを 読み込む
