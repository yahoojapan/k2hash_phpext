---
layout: contents
language: ja
title: k2hpx_print_attr_information
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx_print_attr_information.html
lang_opp_word: To English
prev_url: k2hpx_openja.html
prev_string: k2hpx_open
top_url: k2hpxja.html
top_string: k2hash Functions
next_url: k2hpx_print_attr_versionja.html
next_string: k2hpx_print_attr_version
---

# k2hpx_print_attr_information
属性情報を表示する

## 説明

```
bool k2hpx_print_attr_information ( mixed $handle_res [, mixed $output ] )
```

属性情報を表示します。 

## パラメータ
- handle_res  
k2hash (`.k2h`) ファイルハンドル。 [k2hpx_open](k2hpx_openja.html) 関数の戻り値を指定。
- output  
出力先のファイルストリーム。デフォルトは、標準エラー出力。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - 属性情報を表示する

```
<?php
$handle = k2hpx_open_mem();
$fp = fopen("/tmp/k2hpx_print_attr_information.log", 'w');
k2hpx_print_attr_information($handle, $fp);
fclose($fp);
k2hpx_close($handle);
?>
```

上の例の出力は以下となります。

```
K2HASH attribute libraries:  K2H ATTR BUILTIN
```

