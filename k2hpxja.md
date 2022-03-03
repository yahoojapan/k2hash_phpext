---
layout: contents
language: ja
title: k2hash Functions
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2hpx.html
lang_opp_word: To English
prev_url: k2hiter_classja.html
prev_string: K2hIterator Class
top_url: developerja.html
top_string: Developer
next_url: 
next_string: 
---

# k2hash 関数群
K2HASH PHP Extenstionは、[K2HASH](https://k2hash.antpick.ax/indexja.html) を操作する以下の関数群を提供します。  

## 関数一覧

- [k2hpx_add_attr_crypt_pass](k2hpx_add_attr_crypt_passja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
- [k2hpx_add_attr_plugin_library](k2hpx_add_attr_plugin_libraryja.html) - ユーザ定義の動的ライブラリを追加する
- [k2hpx_add_attr](k2hpx_add_attrja.html) - キーに属性を追加する
- [k2hpx_add_subkey](k2hpx_add_subkeyja.html) - キーを紐づける
- [k2hpx_add_subkeys](k2hpx_add_subkeysja.html) - 複数のキーを紐づける
- [k2hpx_bump_debug_level](k2hpx_bump_debug_levelja.html) - ログレベルを変更する
- [k2hpx_clean_common_attr](k2hpx_clean_common_attrja.html) - キーの基本属性を初期化する
- [k2hpx_close](k2hpx_closeja.html) - k2hファイルを閉じる
- [k2hpx_create](k2hpx_createja.html) - k2hファイルを作成する
- [k2hpx_da_free](k2hpx_da_freeja.html) - データアクセスハンドルを解放する
- [k2hpx_da_get_handle_read](k2hpx_da_get_handle_readja.html) - ダイレクトアクセスハンドル(データ読み出し専用)を取得する
- [k2hpx_da_get_handle_rw](k2hpx_da_get_handle_rwja.html) - ダイレクトアクセスハンドル(データ編集用)を取得する
- [k2hpx_da_get_handle_write](k2hpx_da_get_handle_writeja.html) - ダイレクトアクセスハンドル(データ書き込み専用)を取得する
- [k2hpx_da_get_handle](k2hpx_da_get_handleja.html) - ファイル操作方法を指定して、ダイレクトアクセスハンドルを取得する
- [k2hpx_da_get_length](k2hpx_da_get_lengthja.html) - データ長を取得する
- [k2hpx_da_get_offset](k2hpx_da_get_offsetja.html) - データを読み書き開始する位置を取得する
- [k2hpx_da_get_read_offset](k2hpx_da_get_read_offsetja.html) - データを読みとり開始する位置を取得する
- [k2hpx_da_get_value_to_file](k2hpx_da_get_value_to_fileja.html) - 読み取った値をファイルに書き出す
- [k2hpx_da_get_value](k2hpx_da_get_valueja.html) - データを読み取る
- [k2hpx_da_get_write_offset](k2hpx_da_get_write_offsetja.html) - データの書き込み開始する位置を取得する
- [k2hpx_da_set_offset](k2hpx_da_set_offsetja.html) - データを読み込むまたは書き込む位置を指定する
- [k2hpx_da_set_read_offset](k2hpx_da_set_read_offsetja.html) - データを読み込む位置を指定する
- [k2hpx_da_set_value_from_file](k2hpx_da_set_value_from_fileja.html) - ファイルから書き込むデータを読み込み、直接データを書きこむ位置を指定し、書き込む
- [k2hpx_da_set_value](k2hpx_da_set_valueja.html) - データを書きこむ位置を指定し、書き込む
- [k2hpx_da_set_write_offset](k2hpx_da_set_write_offsetja.html) - データを書き込む位置を指定する
- [k2hpx_disable_transaction](k2hpx_disable_transactionja.html) - トランザクションを停止する
- [k2hpx_dump_elementtable](k2hpx_dump_elementtableja.html) - k2hashのハッシュテーブル内部の要素などを表示する
- [k2hpx_dump_full_keytable](k2hpx_dump_full_keytableja.html) - k2hashのハッシュテーブルなどを表示する
- [k2hpx_dump_full](k2hpx_dump_fullja.html) - k2hashのハッシュテーブル内部のデータなどを表示する
- [k2hpx_dump_head](k2hpx_dump_headja.html) - k2hashのヘッダを表示する
- [k2hpx_dump_keytable](k2hpx_dump_keytableja.html) - k2hashのハッシュテーブルを表示する
- [k2hpx_enable_transaction](k2hpx_enable_transactionja.html) - トランザクションを開始する
- [k2hpx_find_first](k2hpx_find_firstja.html) - キー探索用ハンドルを取得する
- [k2hpx_find_free](k2hpx_find_freeja.html) - キー探索用ハンドルを解放する
- [k2hpx_find_get_key](k2hpx_find_get_keyja.html) - キーを探索する
- [k2hpx_find_get_subkeys](k2hpx_find_get_subkeysja.html) - キーに紐づけられたキーを探索する
- [k2hpx_find_get_value](k2hpx_find_get_valueja.html) - キーを探索して値を取得する
- [k2hpx_find_next](k2hpx_find_nextja.html) - キー探索用ハンドルを次のキーに移動する
- [k2hpx_get_attr_value](k2hpx_get_attr_valueja.html) - キーに設定されている属性値を取得する
- [k2hpx_get_attrs](k2hpx_get_attrsja.html) - キーに設定されている属性を取得する
- [k2hpx_get_subkeys](k2hpx_get_subkeysja.html) - キーに紐づけられたキー（サブキー）の一覧を取得する
- [k2hpx_get_transaction_thread_pool](k2hpx_get_transaction_thread_poolja.html) - トランザクション処理用のスレッド数を取得する
- [k2hpx_get_value](k2hpx_get_valueja.html) - キーの値を取得する
- [k2hpx_keyq_count](k2hpx_keyq_countja.html) - K2hKeyQueueキューにある要素の数を取得する
- [k2hpx_keyq_dump](k2hpx_keyq_dumpja.html) - K2hKeyQueueキューにある要素を表示する
- [k2hpx_keyq_empty](k2hpx_keyq_emptyja.html) - K2hKeyQueueキューが空かどうかを判定する
- [k2hpx_keyq_free](k2hpx_keyq_freeja.html) - K2hKeyQueueキューハンドルを解放する
- [k2hpx_keyq_handle](k2hpx_keyq_handleja.html) - K2hKeyQueueハンドルを取得する
- [k2hpx_keyq_pop](k2hpx_keyq_popja.html) - K2hKeyQueueキューから要素（キーと値のセット）を取得する
- [k2hpx_keyq_push](k2hpx_keyq_pushja.html) - K2hKeyQueueキューに要素（キーと値のセット）を追加する
- [k2hpx_keyq_read](k2hpx_keyq_readja.html) - K2hKeyQueueキューの要素（キーと値のセット）を表示する
- [k2hpx_keyq_remove](k2hpx_keyq_removeja.html) - K2hKeyQueueキューから要素（キーと値のセット）を削除する
- [k2hpx_load_archive](k2hpx_load_archiveja.html) - ファイルからデータをロードする
- [k2hpx_load_debug_env](k2hpx_load_debug_envja.html) - 環境変数を読み込む
- [k2hpx_load_hash_library](k2hpx_load_hash_libraryja.html) - ハッシュ関数を有効にする
- [k2hpx_load_transaction_library](k2hpx_load_transaction_libraryja.html) - トランザクション用ライブラリを読み込む
- [k2hpx_open_mem](k2hpx_open_memja.html) - k2hash用メモリセグメントにアクセスする
- [k2hpx_open_ro](k2hpx_open_roja.html) - k2hファイルを 読み込む
- [k2hpx_open_rw](k2hpx_open_rwja.html) - k2hファイルを編集する
- [k2hpx_open_tempfile](k2hpx_open_tempfileja.html) - 一時ファイルとしてk2hファイルを編集する
- [k2hpx_open](k2hpx_openja.html) - k2hファイルを開く
- [k2hpx_print_attr_information](k2hpx_print_attr_informationja.html) - 属性情報を表示する
- [k2hpx_print_attr_version](k2hpx_print_attr_versionja.html) - 属性のライブラリバージョン情報を表示する
- [k2hpx_print_state](k2hpx_print_stateja.html) - k2hashのデータの状態を表示する
- [k2hpx_print_version](k2hpx_print_versionja.html) - ライブラリのバージョンなどを表示する
- [k2hpx_put_archive](k2hpx_put_archiveja.html) - k2hファイルをアーカイブファイルとして保存する
- [k2hpx_q_count](k2hpx_q_countja.html) - K2hQueueキューにある要素の数を取得する
- [k2hpx_q_dump](k2hpx_q_dumpja.html) - K2hQueueキューにある要素を表示する
- [k2hpx_q_empty](k2hpx_q_emptyja.html) - K2hQueueキューが空かどうかを判定する
- [k2hpx_q_free](k2hpx_q_freeja.html) - K2hQueueキューハンドルを解放する
- [k2hpx_q_handle](k2hpx_q_handleja.html) - K2hQueueハンドルを取得する
- [k2hpx_q_pop](k2hpx_q_popja.html) - K2hQueueキューから要素を取得する
- [k2hpx_q_push](k2hpx_q_pushja.html) - K2hQueueキューに要素を追加する
- [k2hpx_q_read](k2hpx_q_readja.html) - K2hQueueキューの要素（値）を表示する
- [k2hpx_q_remove](k2hpx_q_removeja.html) - K2hQueueキューから要素を削除する
- [k2hpx_remove_all](k2hpx_remove_allja.html) - キーと、キーに紐づけられているキー（サブキー）を削除する
- [k2hpx_remove](k2hpx_removeja.html) - キーを削除する
- [k2hpx_rename](k2hpx_renameja.html) - キー名を変更する
- [k2hpx_set_common_attr](k2hpx_set_common_attrja.html) - キーの基本属性を設定する
- [k2hpx_set_debug_file](k2hpx_set_debug_fileja.html) - ログ出力先ファイル名を指定する
- [k2hpx_set_debug_level_error](k2hpx_set_debug_level_errorja.html) - ライブラリのログレベルをerrorにする
- [k2hpx_set_debug_level_message](k2hpx_set_debug_level_messageja.html) - ライブラリのログレベルをmessage(info相当）にする
- [k2hpx_set_debug_level_silent](k2hpx_set_debug_level_silentja.html) - ライブラリのログを出力しない
- [k2hpx_set_debug_level_warning](k2hpx_set_debug_level_warningja.html) - ライブラリのログレベルをwarningにする
- [k2hpx_set_transaction_thread_pool](k2hpx_set_transaction_thread_poolja.html) - トランザクション処理用のスレッド数を設定する
- [k2hpx_set_value](k2hpx_set_valueja.html) - キーに値を設定する
- [k2hpx_transaction](k2hpx_transactionja.html) - トランザクションを有効また無効にする
- [k2hpx_unload_hash_library](k2hpx_unload_hash_libraryja.html) - ハッシュ関数ライブラリを取り外す
- [k2hpx_unload_transaction_library](k2hpx_unload_transaction_libraryja.html) - トランザクション用ライブラリを無効にする
- [k2hpx_unset_debug_file](k2hpx_unset_debug_fileja.html) - ログ出力先を標準エラーに指定する
- [k2hpx_unset_transaction_thread_pool](k2hpx_unset_transaction_thread_poolja.html) - トランザクション処理用のスレッドを利用しない
