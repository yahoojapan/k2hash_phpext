---
layout: contents
language: ja
title: K2hash::getStream
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_getstream.html
lang_opp_word: To English
prev_url: k2h_getqueueja.html
prev_string: K2hash::getQueue
top_url: k2h_classja.html
top_string: K2hash Class
next_url: k2h_getsubkeysja.html
next_string: K2hash::getSubkeys
---

# K2hash::getStream
k2hashファイルストリームを取得する

## 説明

```
 public mixed K2hash::getStream ( string $key , string $mode )
```

指定されたキーを先頭にしたk2hashファイルストリームを取得します。 

## パラメータ
- key  
ファイルストリームの開始となるキー。キーの指定がない場合は、k2hashファイルの先頭を指します。
- mode  
ファイル操作方法を指定します。詳しくは、[fopen](http://docs.php.net/manual/en/function.fopen.php) を参照してください。

## 戻り値
k2hashファイルストリーム 

## 例
- 例 1 - キーへのストリームを操作する

```
<?php
K2hash::create("/tmp/test_k2hash.k2h");
$k2hash = new K2hash();
$k2hash->openRW("/tmp/test_k2hash.k2h");
$k2hash->setValue("test1", "value1");
$stream = $k2hash->getStream("test1", "r+");
var_dump(fread($stream, 6));
while (!feof($stream)) {
      if (($buf = fgets($stream, 4096)) !== false) {
           echo $buf;
      }
}
fclose($stream);
$k2hash->close();
?>
```

上の例の出力は以下となります。

```
string(6) "value1"
```

