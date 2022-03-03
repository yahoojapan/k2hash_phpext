---
layout: contents
language: ja
title: K2hKeyQueue::dump
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_dump.html
lang_opp_word: To English
prev_url: k2hkq_countja.html
prev_string: K2hKeyQueue::count
top_url: k2hkq_classja.html
top_string: K2hKeyQueue Class
next_url: k2hkq_isemptyja.html
next_string: K2hKeyQueue::isEmpty
---

# K2hKeyQueue::dump
キューにある要素を表示する

## 説明
```
 public bool K2hKeyQueue::dump ([ mixed $output ] )
```
キューにある要素（キーと値のセット）を表示します。 

## パラメータ
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力へのファイルストリーム。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - キューを表示する
```
<?php
$handle = k2hpx_open_mem();

$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
$k2hkeyqueue->push("test_queue_key", "test_queue_value");
$fp = fopen("/tmp/k2hkeyqueue_dump.log", 'w');
$k2hkeyqueue->dump($fp);
fclose($fp);
$fp = fopen("/tmp/k2hkeyqueue_dump.log", 'r');
if ($fp) {
        while (!feof($fp)) {
                if (($buf = fgets($fp, 4096)) !== false) {
                        echo $buf;
                }
        }
        fclose($fp);
}
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
bool(true)
MARKER(test_queue_MARKER)= {
        START KEY               = test_queue_00000000000071EC_0000000061D9D54D_0000000031DD32D2
        END KEY                 = test_queue_00000000000071EC_0000000061D9D54D_0000000031DD32D2
}
[0]                    = test_queue_00000000000071EC_0000000061D9D54D_0000000031DD32D2
```
