---
layout: contents
language: ja
title: k2hpx_create
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_create.html
lang_opp_word: To English
prev_url: k2hpx_closeja.html
prev_string: k2hpx_close
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_da_freeja.html
next_string: k2hpx_da_free
---

# k2hpx_create
k2hashファイルを作成する

## 説明

```
bool k2hpx_create ( string $filepath [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
```

k2hashファイルを作成します。 

## パラメータ
- filepath  
k2hファイルのパス名
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
- [K2hash::create](k2h_createja.html) - k2hファイルを作成する
