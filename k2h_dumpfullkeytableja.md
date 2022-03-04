---
layout: contents
language: ja
title: K2hash::dumpFullKeytable
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_dumpfullkeytable.html
lang_opp_word: To English
prev_url: k2h_dumpfullja.html
prev_string: K2hash::dumpFull
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_dumpheadja.html
next_string: K2hash::dumpHead
---

# K2hash::dumpFullKeytable
k2hashのハッシュテーブルなどを表示する

## 説明

```
 public bool K2hash::dumpFullKeytable ([ mixed $output ] )
```

k2hashのハッシュテーブルなどを表示します。k2hashのヘッダ、ハッシュテーブル、サブハッシュテーブルなども含まれます。

## パラメータ
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ハッシュテーブルなどを出力する

```
<?php
K2hash::create("/tmp/test_k2hash.k2h");
$k2hash = new K2hash();
$k2hash->openRO("/tmp/test_k2hash.k2h");
$fp = fopen("/tmp/k2hash_dump_full_keytable.log", 'w');
$k2hash->dumpFullKeytable($fp);
fclose($fp);
$k2hash->close();

$fp = fopen("/tmp/k2hash_dump_full_keytable.log", 'r');
if ($fp) {
        while (!feof($fp)) {
                if (($buf = fgets($fp, 4096)) !== false) {
                        echo $buf;
                }
        }
        fclose($fp);
}
?>
```

上の例の出力は以下となります。

```
...
    Key Index Pointer[29] = Not Allocated
    Key Index Pointer[30] = Not Allocated
    Key Index Pointer[31] = Not Allocated
  }
```


## 参考
- [K2hash::dumpElementtable](k2h_dumpelementtableja.html) - k2hashのハッシュテーブル内部の要素などを表示する
- [K2hash::dumpFull](k2h_dumpfullja.html) - k2hashのハッシュテーブル内部のデータなどを表示する
- [K2hash::dumpHead](k2h_dumpheadja.html) - k2hashのヘッダを表示する
- [K2hash::dumpKeytable](k2h_dumpkeytableja.html) - k2hashのハッシュテーブルを表示する
