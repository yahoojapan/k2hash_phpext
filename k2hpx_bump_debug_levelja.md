---
layout: contents
language: ja
title: k2hpx_bump_debug_level
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_bump_debug_level.html
lang_opp_word: To English
prev_url: k2hpx_add_subkeysja.html
prev_string: k2hpx_add_subkeys
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_clean_common_attrja.html
next_string: k2hpx_clean_common_attr
---

# k2hpx_bump_debug_level
ログレベルを変更する

## 説明

```
void k2hpx_bump_debug_level ( void )
```

ログレベルを変更します。ログレベルは、関数が呼ばれるごとに変わります。順番は、error -> warning -> message(info) -> dump(debug) -> silent(出力しない) の順番です。silentの状態で呼ばれると、errorになります。PHPのログレベルにあたる、emergency, alert, noticeは未定義です。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
値を返しません。 

## 例
- 例 1 - ログレベルを変更する

```
<?php
var_dump(k2hpx_bump_debug_level());
?>
```

上の例の出力は以下となります。

```
NULL
```


## 参考
- [k2hpx_set_common_attr](k2hpx_set_common_attrja.html) - キーの基本属性を設定する
- [k2hpx_set_debug_file](k2hpx_set_debug_fileja.html) - ログ出力先ファイル名を指定する
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_errorja.html) - ライブラリのログレベルをerrorにする
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_messageja.html) - ライブラリのログレベルをmessage(info相当）にする
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silentja.html) - ライブラリのログを出力しない
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warningja.html) - ライブラリのログレベルをwarningにする
- [k2hpx_unset_debug_file](k2hpx_unset_debug_fileja.html) - ログ出力先を標準エラーに指定する
