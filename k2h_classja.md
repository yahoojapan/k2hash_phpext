---
layout: contents
language: ja
title: K2hash Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_class.html
lang_opp_word: To English
prev_url: constantsja.html
prev_string: Constants
top_url: developerja.html
top_string: Developer
next_url: k2hq_classja.html
next_string: K2hQueue Class
---

# K2hash クラス
K2hashクラスは、[K2HASH](https://k2hash.antpick.ax/indexja.html)を操作するメソッドを提供します。  
使い方は、各メソッドの説明ページを参照してください。

## Class 概要
```
K2hash {
    public addAttr ( string $key , string $attrkey , string $attrval ) : bool
    public addAttrCryptPass ( string $encpass [, bool $is_default_encrypt ] ) : bool
    public addAttrPluginLib ( string $libfile ) : bool
    public addSubkey ( string $key , string $subkey ) : bool
    public addSubkeys ( string $key , array $subkeys ) : bool
    public cleanCommonAttribute ( void ) : bool
    public close ([ int $waitms ] ) : bool
    public static create ( string $filepath [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] ) : bool
    public disableTransaction ( void ) : bool
    public dumpElementtable ([ mixed $output ] ) : bool
    public dumpFull ([ mixed $output ] ) : bool
    public dumpFullKeytable ([ mixed $output ] ) : bool
    public dumpHead ([ mixed $output ] ) : bool
    public dumpKeytable ([ mixed $output ] ) : bool
    public enableTransaction ([ string $transfile [, string $prefix [, string $param [, int $expire ]]]] ) : bool
    public getAttrInfos ([ mixed $output ] ) : bool
    public arrayfalsegetAttrs ( string $key )
    public stringfalsegetAttrValue ( string $key , string $attrkey )
    public getAttrVersionInfos ([ mixed $output ] ) : bool
    public getIterator ( string $key ) : mixed
    public getKeyQueue ([ bool $is_filo [, string $prefix ]] ) : mixed
    public getQueue ([ bool $is_filo [, string $prefix ]] ) : mixed
    public getStream ( string $key , string $mode ) : mixed
    public arrayfalsegetSubkeys ( string $key [, bool $attrcheck ] )
    public static getTransactionThreadPool ( void ) : int
    public stringfalsegetValue ( string $key [, string $subkey [, bool $attrcheck [, string $pass ]]] )
    public loadArchive ( string $filepath [, bool $errskip ] ) : bool
    public open ( string $filepath , bool $readonly [, bool $removefile [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]]] ) : bool
    public openMem ([ int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] ) : bool
    public openRO ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] ) : bool
    public openRW ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] ) : bool
    public openTempfile ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] ) : bool
    public printState ([ mixed $output ] ) : bool
    public static printVersion ([ mixed $output ] ) : bool
    public putArchive ( string $filepath [, bool $errskip ] ) : bool
    public remove ( string $key [, string $subkey ] ) : bool
    public removeAll ( string $key ) : bool
    public rename ( string $key , string $newkey ) : bool
    public setCommonAttribute ([ int $is_mtime [, int $is_history [, int $is_encrypt [, string $passfile [, int $is_expire [, int $expire ]]]]]] ) : bool
    public static setTransactionThreadPool ( int $count ) : bool
    public setValue ( string $key , string $value [, string $subkey [, string $pass [, int $expire ]]] ) : bool
    public transaction ( bool $enable [, string $transfile [, string $prefix [, string $param [, int $expire ]]]] ) : bool
    public static unsetTransactionThreadPool ( void ) : bool
}
```

## メソッド一覧
- [K2hash::addAttr](k2h_addattrja.html) - キーに属性を追加する
- [K2hash::addAttrCryptPass](k2h_addattrcryptpassja.html) - 値を暗号化するパスワード（暗号鍵）を追加する
- [K2hash::addAttrPluginLib](k2h_addattrpluginlibja.html) - ユーザ定義の動的ライブラリを追加する
- [K2hash::addSubkey](k2h_addsubkeyja.html) - キーを紐づける
- [K2hash::addSubkeys](k2h_addsubkeysja.html) - 複数のキーを紐づける
- [K2hash::cleanCommonAttribute](k2h_cleancommonattributeja.html) - キーの基本属性を初期化する
- [K2hash::close](k2h_closeja.html) - k2hファイルを閉じる
- [K2hash::create](k2h_createja.html) - k2hファイルを作成する
- [K2hash::disableTransaction](k2h_disabletransactionja.html) - トランザクションを停止する
- [K2hash::dumpElementtable](k2h_dumpelementtableja.html) - k2hashのハッシュテーブル内部の要素などを表示する
- [K2hash::dumpFull](k2h_dumpfullja.html) - k2hashのハッシュテーブル内部のデータなどを表示する
- [K2hash::dumpFullKeytable](k2h_dumpfullkeytableja.html) - k2hashのハッシュテーブルなどを表示する
- [K2hash::dumpHead](k2h_dumpheadja.html) - k2hashのヘッダを表示する
- [K2hash::dumpKeytable](k2h_dumpkeytableja.html) - k2hashのハッシュテーブルを表示する
- [K2hash::enableTransaction](k2h_enabletransactionja.html) - トランザクションを開始する
- [K2hash::getAttrInfos](k2h_getattrinfosja.html) - 属性を取得する
- [K2hash::getAttrs](k2h_getattrsja.html) - キーに設定されている属性を取得する
- [K2hash::getAttrValue](k2h_getattrvalueja.html) - キーに設定されている属性値を取得する
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfosja.html) - 属性のライブラリバージョン情報を表示する
- [K2hash::getIterator](k2h_getiteratorja.html) - K2hIteratorオブジェクトを取得する
- [K2hash::getKeyQueue](k2h_getkeyqueueja.html) - K2hKeyQueueオブジェクトを取得する
- [K2hash::getQueue](k2h_getqueueja.html) - K2hQueueオブジェクトを取得する
- [K2hash::getStream](k2h_getstreamja.html) - k2hashファイルストリームを取得する
- [K2hash::getSubkeys](k2h_getsubkeysja.html) - キーに紐づけられたキー（サブキー）の一覧を取得する
- [K2hash::getTransactionThreadPool](k2h_gettransactionthreadpoolja.html) - トランザクション処理用のスレッド数を取得する
- [K2hash::getValue](k2h_getvalueja.html) - 値を取得する
- [K2hash::loadArchive](k2h_loadarchiveja.html) - ファイルからデータをロードする
- [K2hash::open](k2h_openja.html) - k2hファイルを開く
- [K2hash::openMem](k2h_openmemja.html) - k2hash用メモリセグメントにアクセスする
- [K2hash::openRO](k2h_openroja.html) - k2hファイルを 読み込む
- [K2hash::openRW](k2h_openrwja.html) - k2hファイルを編集する
- [K2hash::openTempfile](k2h_opentempfileja.html) - 一時ファイルとしてk2hファイルを編集する
- [K2hash::printState](k2h_printstateja.html) - k2hashのデータの状態を表示する
- [K2hash::printVersion](k2h_printversionja.html) - ライブラリのバージョンなどを表示する
- [K2hash::putArchive](k2h_putarchiveja.html) - k2hファイルをアーカイブファイルとして保存する
- [K2hash::remove](k2h_removeja.html) - キーを削除する
- [K2hash::removeAll](k2h_removeallja.html) - キーと、キーに紐づけられているキー（サブキー）を削除する
- [K2hash::rename](k2h_renameja.html) - キー名を変更する
- [K2hash::setCommonAttribute](k2h_setcommonattributeja.html) - キーの基本属性を設定する
- [K2hash::setTransactionThreadPool](k2h_settransactionthreadpoolja.html) - トランザクション処理用のスレッド数を設定する
- [K2hash::setValue](k2h_setvalueja.html) - キーに値を設定する
- [K2hash::transaction](k2h_transactionja.html) - トランザクションを有効また無効にする
- [K2hash::unsetTransactionThreadPool](k2h_unsettransactionthreadpoolja.html) - トランザクション処理用のスレッドを利用しない
