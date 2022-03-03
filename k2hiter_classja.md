---
layout: contents
language: ja
title: K2hIterator Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_class.html
lang_opp_word: To English
prev_url: k2hkq_classja.html
prev_string: K2hKeyQueue Class
top_url: developerja.html
top_string: Developer
next_url: k2hpxja.html
next_string: k2hash Functions
---

# K2hIterator クラス
K2hIteratorは、[K2HASH](https://k2hash.antpick.ax/indexja.html)のキーの配列へのポインタを操作するクラスです。   

## Class 概要
```
K2hIterator implements Iterator {
    public stringfalsecurrent ( void )
    public stringfalsekey ( void )
    public next ( void ) : void
    public rewind ( void ) : void
    public valid ( void ) : bool
}
```

## メソッド一覧

- [K2hIterator::__construct](k2hiter_constructja.html) - 新しい K2hIterator オブジェクトを作成する
- [K2hIterator::current](k2hiter_currentja.html) - 配列内の現在の要素を取得する
- [K2hIterator::key](k2hiter_keyja.html) - 配列からキーを取得する
- [K2hIterator::next](k2hiter_nextja.html) - 配列のポインタを一つ進める
- [K2hIterator::rewind](k2hiter_rewindja.html) - 配列のポインタを先頭に戻す
- [K2hIterator::valid](k2hiter_validja.html) - ポインタの有効性を調べる
