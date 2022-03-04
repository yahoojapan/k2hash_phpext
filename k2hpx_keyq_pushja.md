---
layout: contents
language: ja
title: k2hpx_keyq_push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_keyq_push.html
lang_opp_word: To English
prev_url: k2hpx_keyq_popja.html
prev_string: k2hpx_keyq_pop
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_keyq_readja.html
next_string: k2hpx_keyq_read
---

# k2hpx_keyq_push
K2hKeyQueueキューに要素（キーと値のセット）を追加する

## 説明

```
bool k2hpx_keyq_push ( mixed $keyqhandle_res , string $key , string $value [, stringnull $pass [, int $expire ]] )
```

[K2hKeyQueue](k2hkq_classja.html) キューに要素（キーと値のセット）を追加します。

## パラメータ
- keyqhandle_res  
[K2hKeyQueue](k2hkq_classja.html) ハンドル。 [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) 関数の戻り値。
- key  
キー
- value  
値
- pass  
パスワード（値を暗号化するための鍵）
- expire  
有効期限（単位：秒）

## 戻り値
成功時は、true。それ以外の場合は、false

## 参考
- [K2hKeyQueue::push](k2hkq_pushja.html) - キューに要素（キーと値のセット）を追加する
