---
layout: contents
language: en-us
title: K2hIterator Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hiter_classja.html
lang_opp_word: To Japanese
prev_url: k2hkq_class.html
prev_string: K2hKeyQueue Class
top_url: developer.html
top_string: Developer
next_url: k2hpx.html
next_string: k2hash Functions
---

# K2hIterator Class
K2hIterator represents a pointer of an array of [K2HASH](https://k2hash.antpick.ax/) keys.  

## Class overview
```
K2hIterator implements Iterator {
    public stringfalsecurrent ( void )
    public stringfalsekey ( void )
    public next ( void ) : void
    public rewind ( void ) : void
    public valid ( void ) : bool
}
```

## Method list

- [K2hIterator::__construct](k2hiter_construct.html) - Creates a K2hIterator instance
- [K2hIterator::current](k2hiter_current.html) - Gets value of the current K2hIterator item
- [K2hIterator::key](k2hiter_key.html) - Gets key of the current K2hIterator item
- [K2hIterator::next](k2hiter_next.html) - Advances the internal array pointer of k2hash keys
- [K2hIterator::rewind](k2hiter_rewind.html) - Rewinds the internal array pointer of k2hash keys
- [K2hIterator::valid](k2hiter_valid.html) - Returns whether the current K2hIterator item is valid
