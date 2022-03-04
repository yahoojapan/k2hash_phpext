---
layout: contents
language: ja
title: K2hash::create
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_create.html
lang_opp_word: To English
prev_url: k2h_closeja.html
prev_string: K2hash::close
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_disabletransactionja.html
next_string: K2hash::disableTransaction
---

# K2hash::create
k2hashファイルを作成する

## 説明

```
 public static bool K2hash::create ( string $filepath [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] )
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

## 例
- 例 1 - k2hashファイルを作る

```
<?php
var_dump(K2hash::create("/tmp/test_k2hash.k2h"));
?>
```

上の例の出力は以下となります。

```
bool(true)
```

