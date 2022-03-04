---
layout: contents
language: ja
title: K2hKeyQueue Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_class.html
lang_opp_word: To English
prev_url: k2hq_classja.html
prev_string: K2hQueue Class
top_url: developerja.html
top_string: Developer
next_url: k2hiter_classja.html
next_string: K2hIterator Class
---

# K2hKeyQueue クラス
K2hKeyQueueクラスは、[K2HASH](https://k2hash.antpick.ax/indexja.html)を利用したキューです。  
キューには、値を格納します。  
データの取り出し方法は、先入先出し（FIFO）、後入れ先出し（LIFO）を指定できます。  

## Class 概要

```
K2hKeyQueue {
    public count ( void ) : int
    public dump ([ mixed $output ] ) : bool
    public isEmpty ( void ) : bool
    public arrayfalsepop ([ string $pass ] )
    public push ( string $key , string $value [, string $pass [, int $expire ]] ) : bool
    public arrayfalseread ([ int $pos [, string $pass ]] )
    public remove ( int $count [, string $pass ] ) : bool
}
```


## メソッド一覧

- [K2hKeyQueue::__construct](k2hkq_constructja.html) - 新しいK2hKeyQueueオブジェクトを作成する
- [K2hKeyQueue::count](k2hkq_countja.html) - キューにある要素の数を取得する
- [K2hKeyQueue::dump](k2hkq_dumpja.html) - キューにある要素を表示する
- [K2hKeyQueue::isEmpty](k2hkq_isemptyja.html) - キューが空かどうかを判定する
- [K2hKeyQueue::pop](k2hkq_popja.html) - キューから要素（キーと値のセット）を取得する
- [K2hKeyQueue::push](k2hkq_pushja.html) - キューに要素（キーと値のセット）を追加する
- [K2hKeyQueue::read](k2hkq_readja.html) - キューの要素（キーと値のセット）を表示する
- [K2hKeyQueue::remove](k2hkq_removeja.html) - キューから要素（キーと値のセット）を削除する

