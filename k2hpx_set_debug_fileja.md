---
layout: contents
language: ja
title: k2hpx_set_debug_file
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_set_debug_file.html
lang_opp_word: To English
prev_url: k2hpx_set_common_attrja.html
prev_string: k2hpx_set_common_attr
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_set_debug_level_errorja.html
next_string: k2hpx_set_debug_level_error
---

# k2hpx_set_debug_file
ログ出力先ファイル名を指定する

## 説明

```
bool k2hpx_set_debug_file ( string $filepath )
```

ログ出力先ファイル名を指定します。 

## パラメータ
- filepath  
ログ出力先ファイルのパス

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ログファイル名を指定する

```
<?php
var_dump(k2hpx_set_debug_file("/tmp/k2h.log"));
?>
```

上の例の出力は以下となります。

```
NULL
```


## 参考
- [k2hpx_bump_debug_level](k2hpx_bump_debug_levelja.html) - ログレベルを変更する
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_errorja.html) - ライブラリのログレベルをerrorにする
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_messageja.html) - ライブラリのログレベルをmessage(info相当）にする
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silentja.html) - ライブラリのログを出力しない
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warningja.html) - ライブラリのログレベルをwarningにする
- [k2hpx_unset_debug_file](k2hpx_unset_debug_fileja.html) - ログ出力先を標準エラーに指定する
