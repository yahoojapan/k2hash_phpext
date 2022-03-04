---
layout: contents
language: ja
title: k2hpx_keyq_remove
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_remove.html
lang_opp_word: To English
prev_url: k2hpx_keyq_readja.html
prev_string: k2hpx_keyq_read
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_load_archiveja.html
next_string: k2hpx_load_archive
---

# k2hpx_keyq_remove
K2hKeyQueueキューから要素（キーと値のセット）を削除する

## 説明

```
bool k2hpx_keyq_remove ( mixed $keyqhandle_res , int $count [, stringnull $pass ] )
```

[K2hKeyQueue](k2hkq_classja.html) キューから要素（キーと値のセット）を削除します。 

## パラメータ
- keyqhandle_res  
[K2hKeyQueue](k2hkq_classja.html) ハンドル。 [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) 関数の戻り値。
- count  
削除する要素の数
- pass  
暗号化されている値を復号化するためのパスワード（共有鍵）。

## 戻り値
成功時は、true。それ以外の場合は、false

## 参考
- [K2hKeyQueue::remove](k2hkq_removeja.html) - キューから要素（キーと値のセット）を削除する
