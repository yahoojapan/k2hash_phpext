---
layout: contents
language: en-us
title: K2hKeyQueue Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hkq_classja.html
lang_opp_word: To Japanese
prev_url: k2hq_class.html
prev_string: K2hQueue Class
top_url: developer.html
top_string: Developer
next_url: k2hiter_class.html
next_string: K2hIterator Class
---

# K2hKeyQueue Class
K2hKeyQueue represents a queue that holds key/value pairs by using [K2HASH](https://k2hash.antpick.ax/).  
Elements in K2hKeyQueue are ordered in FIFO of LIFO manner.  

## Class overview

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


## Method list

- [K2hKeyQueue::__construct](k2hkq_construct.html) - Creates a K2hKeyQueue instance
- [K2hKeyQueue::count](k2hkq_count.html) - Counts elements in the K2hKeyQueue object
- [K2hKeyQueue::dump](k2hkq_dump.html) - Prints the elements in the K2hKeyQueue object
- [K2hKeyQueue::isEmpty](k2hkq_isempty.html) - Returns whether the K2hKeyQueue is empty
- [K2hKeyQueue::pop](k2hkq_pop.html) - Removes and returns the removed element from the K2hKeyQueue
- [K2hKeyQueue::push](k2hkq_push.html) - Adds a key/value pair to the K2hKeyQueue
- [K2hKeyQueue::read](k2hkq_read.html) - Returns a key/value pair from the K2hKeyQueue
- [K2hKeyQueue::remove](k2hkq_remove.html) - Removes a key/value pair from the K2hKeyQueue
