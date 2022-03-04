---
layout: contents
language: ja
title: K2hash::setValue
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_setvalue.html
lang_opp_word: To English
prev_url: k2h_settransactionthreadpoolja.html
prev_string: K2hash::setTransactionThreadPool
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_transactionja.html
next_string: K2hash::transaction
---

# K2hash::setValue
キーに値を設定する

## 説明

```
 public bool K2hash::setValue ( string $key , string $value [, string $subkey [, string $pass [, int $expire ]]] )
```

キーに値を設定します。

## パラメータ
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

## 例
- 例 1 - キーに値を設定する

```
<?php
$k2hash = new K2hash();
$k2hash->openMem();
$k2hash->setValue("key1", "value1");
var_dump($k2hash->getValue("key1"));
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
string(6) "value1"
```


## 参考
- [K2hash::getValue](k2h_getvalueja.html) - 値を取得する
