---
layout: contents
language: en-us
title: Usage
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: usageja.html
lang_opp_word: To Japanese
prev_url: feature.html
prev_string: Feature
top_url: index.html
top_string: TOP
next_url: developer.html
next_string: Developer
---

# Usage
Try to check its operation after building K2HASH PHP Extension library.

## 1. Install
The K2HASH PHP Extension requires [K2HASH](https://k2hash.antpick.ax/index.html).
To install [K2HASH](https://k2hash.antpick.ax/index.html), refer to [Usage](https://k2hash.antpick.ax/usage.html) of K2HASH and install it in advance.

The K2HASH PHP Extension packages can be found at [AntPickax packagecloud.io](https://packagecloud.io/app/antpickax/stable/search?q=pecl-k2hash).  

First, you register the repository of [AntPickax packagecloud.io](https://packagecloud.io/antpickax/stable).  
You can easily register the repository by following the steps at [here](https://packagecloud.io/antpickax/stable/install).  
After registering the repository, install the K2HASH PHP Extension.  

Debian based Linux users can install it by following the steps below:
```
$ sudo apt-get update -y

$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh | sudo bash

$ sudo apt-get install -y php8.1 libapache2-mod-php8.1
$ sudo update-alternatives --set php-config /usr/bin/php-config8.1
$ sudo update-alternatives --set php /usr/bin/php8.1
$ sudo apt-get install -y k2hash php-pecl-k2hash
```

Fedora derived RPM based Linux(Fedora, CentOS, CentOS Stream, RHEL, etc.) users can install it by following the steps below:
```
$ sudo dnf update -y

$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh | sudo bash

$ sudo dnf install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
$ sudo dnf install https://rpms.remirepo.net/enterprise/remi-release-8.rpm
$ sudo dnf module reset php
$ sudo dnf module install php:remi-8.1
$ sudo dnf install -y php-pecl-k2hash
```

## 2. Test Execution
Please create the following file and check whether file creation, key and value writing and reading are possible.
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

## 3. Importing and Executing
Load and use the K2HASH PHP Extension as described in [PHP](https://www.php.net/).  
If you installed the package, `k2hash.ini` is included in the package and you can use it immediately.  

## 4. Examples
Below is an example of PHP source code using some K2HASH PHP Extensions.  
The first example shows how to set a key with a value and get it. The second one shows set a key with a subkey with a value and get it. 

### Example 1 - Adds a key/value pair
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
The above example will output something similar to:
```
string(5) "value"
```

### Example 2 - Adds a key with a subkey
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
The above example will output something similar to:
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
