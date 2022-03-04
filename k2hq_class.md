---
layout: contents
language: en-us
title: K2hQueue Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hq_classja.html
lang_opp_word: To Japanese
prev_url: k2h_class.html
prev_string: K2hash Class
top_url: developer.html
top_string: Developer
next_url: k2hkq_class.html
next_string: K2hKeyQueue Class
---

# K2hQueue Class
K2hQueue represents a queue that holds values by using [K2HASH](https://k2hash.antpick.ax/).  
Elements in K2hQueue are ordered in FIFO of LIFO manner. 

## Class overview

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


## Method list

- [K2hQueue::__construct](k2hq_construct.html) - Creates a K2hQueue instance
- [K2hQueue::count](k2hq_count.html) - Counts elements in the K2hQueue object
- [K2hQueue::dump](k2hq_dump.html) - Prints the elements in the K2hQueue object
- [K2hQueue::isEmpty](k2hq_isEmpty.html) - Returns whether the K2hQueue is empty
- [K2hQueue::pop](k2hq_pop.html) - Removes and returns the removed element from the K2hQueue
- [K2hQueue::push](k2hq_push.html) - Adds a value to the K2hQueue
- [K2hQueue::read](k2hq_read.html) - Returns a key/value pair from the K2hQueue
- [K2hQueue::remove](k2hq_remove.html) - Removes a value from the K2hQueue
