---
layout: contents
language: ja
title: K2hash::printVersion
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_printversion.html
lang_opp_word: To English
prev_url: k2h_printstateja.html
prev_string: K2hash::printState
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_putarchiveja.html
next_string: K2hash::putArchive
---

# K2hash::printVersion
ライブラリのバージョンなどを表示する

## 説明

```
 public static bool K2hash::printVersion ([ mixed $output ] )
```

k2hashライブラリのバージョンおよびクレジットを表示します。 

## パラメータ
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - k2hash バージョンを表示する

```
<?php
$k2hash = new K2hash();
$fp = fopen("/tmp/k2hash_print_version.log", 'w');
$k2hash->printVersion($fp);
fclose($fp);

$fp = fopen("/tmp/k2hash_print_version.log", 'r');
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
K2HASH library Version 1.0.83 (commit: 143975d) with NSS

Copyright(C) 2013 Yahoo Japan Corporation.

K2HASH is key-valuew store base libraries. K2HASH is made for
the purpose of the construction of original KVS system and the
offer of the library. The characteristic is this KVS library
which Key can layer. And can support multi-processing and
multi-thread, and is provided safely as available KVS.


FULLOCK Version 1.0.44 (commit: 20ce073)

Copyright(C) 2015 Yahoo Japan Corporation.

FULLOCK is fast locking library on user level by Yahoo! JAPAN.
FULLOCK is following specifications.
```

