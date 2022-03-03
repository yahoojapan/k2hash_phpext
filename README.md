k2hash php extension
====================
[![PHP AntPickax CI](https://github.com/yahoojapan/k2hash_phpext/workflows/PHP%20AntPickax%20CI/badge.svg)](https://github.com/yahoojapan/k2hash_phpext/actions)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/yahoojapan/k2hash_phpext/master/LICENSE)
[![GitHub forks](https://img.shields.io/github/forks/yahoojapan/k2hash_phpext.svg)](https://github.com/yahoojapan/k2hash_phpext/network)
[![GitHub stars](https://img.shields.io/github/stars/yahoojapan/k2hash_phpext.svg)](https://github.com/yahoojapan/k2hash_phpext/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/yahoojapan/k2hash_phpext.svg)](https://github.com/yahoojapan/k2hash_phpext/issues)
[![debian packages](https://img.shields.io/badge/deb-packagecloud.io-844fec.svg)](https://packagecloud.io/antpickax/stable)
[![RPM packages](https://img.shields.io/badge/rpm-packagecloud.io-844fec.svg)](https://packagecloud.io/antpickax/stable)

- K2HASH PHP Extension library  
K2HASH is NoSQL Key Value Store(KVS) library by Yahoo! JAPAN.

### Overview
K2HASH is NoSQL(key value store) library and tools for this library by Yahoo! JAPAN.  
This PHP Extension library is for using K2HASH from PHP.  

By [K2HASH PHP Extension](https://php.k2hash.antpick.ax/) library, you can easily incorporate the functions and features of K2HASH into PHP based programs.  
For the features and functions of K2HASH, see the [k2hash documentation](https://k2hash.antpick.ax/).  

![k2HASH PHP Extension](https://php.k2hash.antpick.ax/images/top_k2hash_phpext.png)

### Usage
K2HASH PHP Extension library is provided as RPM and Debian package.  
Before installing this package, you need the K2HASH package(RPM or Debian).  
First of all, please install the k2hash developer package as described [here](https://k2hash.antpick.ax/usage.html).  
Next, install the K2HASH PHP Extension library using the package manager command.  

- Debian based Linux users can install it by following the steps below:  
```
$ sudo apt-get update -y

$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh | sudo bash

$ sudo apt-get install -y php8.1 libapache2-mod-php8.1
$ sudo update-alternatives --set php-config /usr/bin/php-config8.1
$ sudo update-alternatives --set php /usr/bin/php8.1
$ sudo apt-get install -y k2hash php-pecl-k2hash
```
- Fedora derived RPM based Linux(Fedora, CentOS, CentOS Stream, RHEL, etc.) users can install it by following the steps below:
```
$ sudo dnf update -y

$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh | sudo bash

$ sudo dnf install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
$ sudo dnf install https://rpms.remirepo.net/enterprise/remi-release-8.rpm
$ sudo dnf module reset php
$ sudo dnf module install php:remi-8.1
$ sudo dnf install -y php-pecl-k2hash
```

### Documents
- [Document top page](https://php.k2hash.antpick.ax/)
- [Github wiki page](https://github.com/yahoojapan/k2hash_phpext/wiki)
- [About K2HASH](https://k2hash.antpick.ax/)
- [About AntPickax](https://antpick.ax/)

### Packages
- [RPM packages(packagecloud.io)](https://packagecloud.io/antpickax/stable)
- [Debian packages(packagecloud.io)](https://packagecloud.io/antpickax/stable)

### License
This software is released under the MIT License, see the license file.

### AntPickax
K2HASH PHP Extension is one of [AntPickax](https://antpick.ax/) products.

Copyright(C) 2022 Yahoo! JAPAN corporation.
