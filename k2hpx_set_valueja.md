---
layout: contents
language: ja
title: k2hpx_set_value
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_value.html
lang_opp_word: To English
prev_url: k2hpx_set_transaction_thread_poolja.html
prev_string: k2hpx_set_transaction_thread_pool
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_transactionja.html
next_string: k2hpx_transaction
---

# k2hpx_set_value
キーに値を設定する

## 説明

```
bool k2hpx_set_value ( mixed $handle_res , string $key , string $value [, stringnull $subkey [, stringnull $pass [, int $expire ]]] )
```

キーに値を設定します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- key  
キー
- value  
値
- subkey  
キーに紐付けるキー（サブキー）
- pass  
値を暗号化するパスワード（共有鍵）
- expire  
有効期限（単位：秒）

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 参考
- [K2hash::setValue](k2h_setvalueja.html) - キーに値を設定する
