---
layout: contents
language: ja
title: Usage
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: usage.html
lang_opp_word: To English
prev_url: featureja.html
prev_string: Feature
top_url: indexja.html
top_string: TOP
next_url: developerja.html
next_string: Developer
---

# 使い方
K2HASH PHP Extensionをビルドした後で、動作確認をしてみます。

## 1. インストール
K2HASH PHP Extensionは、[K2HASH](https://k2hash.antpick.ax/indexja.html)を必要とします。  
[K2HASH](https://k2hash.antpick.ax/indexja.html) のインストールは、K2HASHの[使い方](https://k2hash.antpick.ax/usageja.html) を参照して、事前にインストールしてください。  

K2HASH PHP Extension のパッケージは、[AntPickax packagecloud.io](https://packagecloud.io/app/antpickax/stable/search?q=pecl-k2hash) にあります。  

まず、[AntPickax packagecloud.io](https://packagecloud.io/antpickax/stable) のリポジトリを登録してください。  
リポジトリは、[こちら](https://packagecloud.io/antpickax/stable/install) の手順に従って簡単に登録できます。  
リポジトリの登録が終わったら、K2HASH PHP Extension をインストールしてください。


DebianベースのLinuxユーザは、下の手順でインストールできます。
```
$ sudo apt-get update -y

$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh | sudo bash

$ sudo apt-get install -y php8.1 libapache2-mod-php8.1
$ sudo update-alternatives --set php-config /usr/bin/php-config8.1
$ sudo update-alternatives --set php /usr/bin/php8.1
$ sudo apt-get install -y k2hash php-pecl-k2hash
```

Fedora派生のRPMベースのLinux(Fedora, CentOS, CentOS Stream, RHELなど)ユーザは、下の手順でインストールできます。

```
$ sudo dnf update -y

$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh | sudo bash

$ sudo dnf install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
$ sudo dnf install https://rpms.remirepo.net/enterprise/remi-release-8.rpm
$ sudo dnf module reset php
$ sudo dnf module install php:remi-8.1
$ sudo dnf install -y php-pecl-k2hash
```

## 2. 実行テスト
以下のようなファイルを作成し、ファイル作成、キーと値の書き込み、読み出しができるか確認してみてください。  
```
<?php
    $handle = k2hpx_open_mem();
    if(!k2hpx_set_value($handle, "test", "value")){
        k2hpx_close($handle);
        echo "NG";
        exit;
    }
    if(false === ($value = k2hpx_get_value($handle, "test")) || $value != "value"){
        k2hpx_close($handle);
        echo "NG";
        exit;
    }
    echo "OK";
?>
```

## 3. ロード・実行
[PHP](https://www.php.net/) の説明に従って、K2HASH PHP Extensionをロードして使ってください。  
パッケージでK2HASH PHP Extensionをインストールした場合、`k2hash.ini` が含まれており、すぐに利用できます。  

## 4. 例
以下にいくつかの K2HASH PHP Extension を使った PHPソースコードの例を示します。  
一つ目の例では、値を持ったキーを保存し、それを取得しています。 二つ目の例では、子供のキーを持ったキーを保存し、それを取得しています。  

### 例 1 - K2hashサンプルコード
```
<?php
    // k2hpx_set_debug_level_message();

    // set value & get value
    $handle = k2hpx_open_mem();
    k2hpx_set_value($handle, "test", "value");

    $value = k2hpx_get_value($handle, "test");
    var_dump($value);

    k2hpx_close($handle);

?>
```
上の例の出力は、 たとえば以下のようになります。
```
string(5) "value"
```

### 例 2 - K2hashサンプルコード
```
<?php
    // set subkeys & get subkeys
    $handle = k2hpx_open_mem();

    $putsubkeys = array("subkey1", "subkey2", "subkey3");
    k2hpx_add_subkeys($handle, "test", $putsubkeys);

    $getsubkeys = k2hpx_get_subkeys($handle, "test");
    var_dump($getsubkeys);

    k2hpx_close($handle);
?>
```
上の例の出力は、 たとえば以下のようになります。
```
array(3) {
  [0]=>
  string(7) "subkey1"
  [1]=>
  string(7) "subkey2"
  [2]=>
  string(7) "subkey3"
}
```
