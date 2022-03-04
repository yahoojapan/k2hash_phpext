---
layout: contents
language: ja
title: k2hpx_find_get_key
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_find_get_key.html
lang_opp_word: To English
prev_url: k2hpx_find_freeja.html
prev_string: k2hpx_find_free
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_find_get_subkeysja.html
next_string: k2hpx_find_get_subkeys
---

# k2hpx_find_get_key
キーを探索する

## 説明

```
string k2hpx_find_get_key ( mixed $findhandle_res )
```

キーを探索します。 

## パラメータ
- findhandle_res  
k2hash キー探索用ハンドル（ [k2hpx_find_first](k2hpx_find_firstja.html) 関数の戻り値）。

## 戻り値
探索結果のキー 

## 例
- 例 1 - キー探索用ファイルハンドルを取得する

```
<?php
$handle = k2hpx_open_mem();
k2hpx_set_value($handle, "test1", "value1");
$findhandle = k2hpx_find_first($handle);
var_dump($findhandle);
var_dump(k2hpx_find_get_key($findhandle));
k2hpx_find_free($findhandle);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
resource(5) of type (k2hfindhandle)
string(5) "test1"
```


## 参考
- [k2hpx_find_first](k2hpx_find_firstja.html) - キー探索用ハンドルを取得する
- [k2hpx_find_free](k2hpx_find_freeja.html) - キー探索用ハンドルを解放する
- [k2hpx_find_get_subkeys](k2hpx_find_get_subkeysja.html) - キーに紐づけられたキーを探索する
- [k2hpx_find_get_value](k2hpx_find_get_valueja.html) - キーを探索して値を取得する
- [k2hpx_find_next](k2hpx_find_nextja.html) - キー探索用ハンドルを次のキーに移動する
