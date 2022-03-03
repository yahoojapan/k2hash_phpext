---
layout: contents
language: ja
title: K2hQueue Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_class.html
lang_opp_word: To English
prev_url: k2h_classja.html
prev_string: K2hash Class
top_url: developerja.html
top_string: Developer
next_url: k2hkq_classja.html
next_string: K2hKeyQueue Class
---

# K2hQueue クラス
K2hQueueクラスは、[K2HASH](https://k2hash.antpick.ax/indexja.html)を利用したキューです。  
キューには、値を格納します。  
データの取り出し方法は、先入先出し（FIFO）、後入れ先出し（LIFO）を指定できます。

## Class 概要
```
K2hQueue {
    public intfalsecount ( void )
    public dump ([ mixed $output ] ) : bool
    public isEmpty ( void ) : bool
    public stringfalsepop ([ string $pass ] )
    public push ( string $datavalue [, string $pass [, int $expire ]] ) : bool
    public stringfalseread ([ int $pos [, string $pass ]] )
    public remove ( int $count [, string $pass ] ) : bool
}
```

## メソッド一覧

- [K2hQueue::__construct](k2hq_constructja.html) - 新しいK2hQueueオブジェクトを作成する
- [K2hQueue::count](k2hq_countja.html) - キューにある要素の数を取得する
- [K2hQueue::dump](k2hq_dumpja.html) - キューにある要素を表示する
- [K2hQueue::isEmpty](k2hq_isEmptyja.html) - キューが空かどうかを判定する
- [K2hQueue::pop](k2hq_popja.html) - キューから要素を取得する
- [K2hQueue::push](k2hq_pushja.html) - キューに要素を追加する
- [K2hQueue::read](k2hq_readja.html) - キューの要素を表示する
- [K2hQueue::remove](k2hq_removeja.html) - キューから要素を削除する
