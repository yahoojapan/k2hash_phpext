---
layout: contents
language: ja
title: K2hKeyQueue::push
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_push.html
lang_opp_word: To English
prev_url: k2hkq_popja.html
prev_string: K2hKeyQueue::pop
top_url: k2hkq_classja.html
top_string: K2hKeyQueue Class
next_url: k2hkq_readja.html
next_string: K2hKeyQueue::read
---

# K2hKeyQueue::push
キューに要素（キーと値のセット）を追加する

## 説明
```
 public bool K2hKeyQueue::push ( string $key , string $value [, string $pass [, int $expire ]] )
```
キューに要素（キーと値のセット）を追加します。 

## パラメータ
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

## 例
- 例 1 - キューから要素を取得する
```
<?php
$handle = k2hpx_open_mem();
$k2hkeyqueue = new K2hKeyQueue($handle, true, "test_queue_");
var_dump($k2hkeyqueue->push("test_queue_key", "test_queue_value"));
var_dump($k2hkeyqueue->pop());
unset($k2hkeyqueue);
k2hpx_close($handle);
?>
```
上の例の出力は以下となります。
```
bool(true)
array(2) {
  [0]=>
  string(14) "test_queue_key"
  [1]=>
  string(16) "test_queue_value"
}
```

## 参考
- [K2hKeyQueue::pop](k2hkq_popja.html) - キューから要素（キーと値のセット）を取得する
- [K2hKeyQueue::read](k2hkq_readja.html) - キューの要素（キーと値のセット）を表示する
- [K2hKeyQueue::remove](k2hkq_removeja.html) - キューから要素（キーと値のセット）を削除する
