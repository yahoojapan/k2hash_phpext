---
layout: contents
language: ja
title: K2hQueue::dump
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_dump.html
lang_opp_word: To English
prev_url: k2hq_countja.html
prev_string: K2hQueue::count
top_url: k2hq_classja.html
top_string: K2hQueue Class
next_url: k2hq_isemptyja.html
next_string: K2hQueue::isEmpty
---

# K2hQueue::dump
キューにある要素を表示する

## 説明

```
 public bool K2hQueue::dump ([ mixed $output ] )
```

キューにある要素を表示します。 

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

$k2hqueue = new K2hQueue($handle, true, "test_queue_");
$k2hqueue->push("test_queue_key", "test_queue_value");
$fp = fopen("/tmp/k2hqueue_dump.log", 'w');
var_dump($k2hqueue->dump($fp));
fclose($fp);
$fp = fopen("/tmp/k2hqueue_dump.log", 'r');
if ($fp) {
        while (!feof($fp)) {
                if (($buf = fgets($fp, 4096)) !== false) {
                        echo $buf;
                }
        }
        fclose($fp);
}
unset($k2hqueue);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
bool(true)
MARKER(test_queue_MARKER)= {
	START KEY               = test_queue_000000000000758C_0000000061D9E5C9_0000000006108B76
	END KEY                 = test_queue_000000000000758C_0000000061D9E5C9_0000000006108B76
}
[0]                    = test_queue_000000000000758C_0000000061D9E5C9_0000000006108B76
```

