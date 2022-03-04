---
layout: contents
language: ja
title: K2hash::printState
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_printstate.html
lang_opp_word: To English
prev_url: k2h_opentempfileja.html
prev_string: K2hash::openTempfile
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_printversionja.html
next_string: K2hash::printVersion
---

# K2hash::printState
k2hashのデータの状態を表示する

## 説明

```
 public bool K2hash::printState ([ mixed $output ] )
```

k2hashのデータの状態を表示します。 

## パラメータ
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。

## 例
- 例 1 - k2hash データの状態を出力する

```
<?php
K2hash::create("/tmp/test_k2hash.k2h");
$k2hash = new K2hash();
$k2hash->openRO("/tmp/test_k2hash.k2h");
$fp = fopen("/tmp/k2hash_print_state.log", 'w');
$k2hash->printState($fp);
fclose($fp);
$k2hash->close();

$fp = fopen("/tmp/k2hash_print_state.log", 'r');
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

Total Key count         = 16384
System usage            = 2695168 byte
Total real data size    = 133431296 byte
real data ratio         = 98 %
}
```

