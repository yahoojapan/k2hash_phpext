#
# K2HASH PHP Extension library
#
# Copyright 2022 Yahoo! JAPAN corporation.
#
# K2HASH is key-valuew store base libraries.
# K2HASH is made for the purpose of the construction of
# original KVS system and the offer of the library.
# The characteristic is this KVS library which Key can
# layer. And can support multi-processing and multi-thread,
# and is provided safely as available KVS.
#
# For the full copyright and license information, please view
# the LICENSE file that was distributed with this source code.
#
# AUTHOR:   Takeshi Nakatani
# CREATE:   Fri, Feb 24 2022
# REVISION:
#

#===============================================================
# Configuration for phpext_helper.sh
#===============================================================
# This file is loaded into the phpext_helper.sh script.
# The phpext_helper.sh script is a Github Actions helper script
# that builds and packages the target repository.
# This file is mainly created to define variables that differ
# depending on the OS/PHP and version.
# It also contains different information(such as packages to
# install) for each repository.
#
# In the initial state, you need to set the following variables:
#   DIST_TAG                      : "Distro/Version" for publishing packages
#   PKG_EXT                       : The extension of the package file
#   PKG_OUTPUT_DIR                : Set the directory path where the package
#                                   will be created relative to the top
#                                   directory of the source
#
#   INSTALLER_BIN                 : Package management command
#   INSTALL_QUIET_ARG             : Quiet option for installing packages
#   INSTALL_PKG_LIST              : A list of packages to be installed for
#                                   build and packaging
#
#   INSTALL_PHP_PRE_ADD_REPO      : Install packages(or repositories) before
#                                   adding PHP repository
#   INSTALL_PHP_REPO              : PHP Repository
#   INSTALL_PHP_REPO_GPG_URL      : PHP Repository GPG file url for debian
#   INSTALL_PHP_REPO_GPG_FILEPATH : PHP Repository GPG file path for debian
#   INSTALL_PHP_PKG_LIST          : PHP Packages
#   INSTALL_PHP_OPT               : Option for installing PHP packages
#   INSTALL_PHP_POST_CONFIG       : Configuration after installing PHP
#   INSTALL_PHP_POST_BIN          : Binary configuration after installing PHP
#   SWITCH_PHP_COMMAND            : Command for switching build environment
#                                   (ex. SCL)
#
#   IS_OS_UBUNTU                  : Set to 1 for Ubuntu, 0 otherwise
#   IS_OS_DEBIAN                  : Set to 1 for Debian, 0 otherwise
#   IS_OS_CENTOS                  : Set to 1 for CentOS, 0 otherwise
#   IS_OS_FEDORA                  : Set to 1 for Fedora, 0 otherwise
#   IS_OS_ROCKY                   : Set to 1 for Rocky, 0 otherwise
#   IS_OS_ALPINE                  : Set to 1 for Alpine, 0 otherwise
#
# Set these variables according to the CI_OSTYPE and CI_PHPTYPE
# variable.
# The value of the CI_OSTYPE and CI_PHPTYPE variable matches the
# name of the Container(docker image) used in Github Actions.
# Check the ".github/workflow/***.yml" file for the value.
#
#----------------------------------------------------------
# Default values
#----------------------------------------------------------
DIST_TAG=""
PKG_EXT=""
PKG_OUTPUT_DIR=""

INSTALLER_BIN=""
INSTALL_QUIET_ARG=""
INSTALL_PKG_LIST=""

INSTALL_PHP_PRE_ADD_REPO=""
INSTALL_PHP_REPO=""
INSTALL_PHP_PKG_LIST=""
INSTALL_PHP_OPT=""
INSTALL_PHP_POST_CONFIG=""
INSTALL_PHP_POST_BIN=""
SWITCH_PHP_COMMAND=""

#
# Only debian
#
INSTALL_PHP_REPO_GPG_URL=""
INSTALL_PHP_REPO_GPG_FILEPATH=""

PHPVER_NOPERIOD=""
PHPVER_WITHPERIOD=""

IS_OS_UBUNTU=0
IS_OS_DEBIAN=0
IS_OS_CENTOS=0
IS_OS_FEDORA=0
IS_OS_ROCKY=0
IS_OS_ALPINE=0

#----------------------------------------------------------
# Variables for each OS/PHP Type
#----------------------------------------------------------
#
# PHP Version
#
if [ -z "${CI_PHPTYPE}" ]; then
	#
	# Unknown PHP version : Nothing to do
	#
	:
elif [ "${CI_PHPTYPE}" = "PHP7.4" ] || [ "${CI_PHPTYPE}" = "PHP74" ] || [ "${CI_PHPTYPE}" = "PHP7" ] || [ "${CI_PHPTYPE}" = "7.4" ] || [ "${CI_PHPTYPE}" = "74" ] || [ "${CI_PHPTYPE}" = "7" ]; then
	PHPVER_NOPERIOD="74"
	PHPVER_WITHPERIOD="7.4"
elif [ "${CI_PHPTYPE}" = "PHP8.0" ] || [ "${CI_PHPTYPE}" = "PHP80" ] || [ "${CI_PHPTYPE}" = "8.0" ] || [ "${CI_PHPTYPE}" = "80" ]; then
	PHPVER_NOPERIOD="80"
	PHPVER_WITHPERIOD="8.1"
elif [ "${CI_PHPTYPE}" = "PHP8.1" ] || [ "${CI_PHPTYPE}" = "PHP81" ] || [ "${CI_PHPTYPE}" = "PHP8" ] || [ "${CI_PHPTYPE}" = "8.1" ] || [ "${CI_PHPTYPE}" = "81" ] || [ "${CI_PHPTYPE}" = "8" ]; then
	PHPVER_NOPERIOD="81"
	PHPVER_WITHPERIOD="8.1"
fi

#
# OS Type
#
if [ -z "${CI_OSTYPE}" ]; then
	#
	# Unknown OS : Nothing to do
	#
	:
elif [ "${CI_OSTYPE}" = "ubuntu:22.04" ] || [ "${CI_OSTYPE}" = "ubuntu:jammy" ]; then
	DIST_TAG="ubuntu/jammy"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="ppa:ondrej/php"
	INSTALL_PHP_PKG_LIST="dh-php php-all-dev php${PHPVER_WITHPERIOD} libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_UBUNTU=1

elif [ "${CI_OSTYPE}" = "ubuntu:20.04" ] || [ "${CI_OSTYPE}" = "ubuntu:focal" ]; then
	DIST_TAG="ubuntu/focal"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="ppa:ondrej/php"
	INSTALL_PHP_PKG_LIST="dh-php php-all-dev php${PHPVER_WITHPERIOD} libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_UBUNTU=1

elif [ "${CI_OSTYPE}" = "ubuntu:18.04" ] || [ "${CI_OSTYPE}" = "ubuntu:bionic" ]; then
	DIST_TAG="ubuntu/bionic"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="ppa:ondrej/php"
	INSTALL_PHP_PKG_LIST="dh-php php-all-dev php${PHPVER_WITHPERIOD} libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_UBUNTU=1

elif [ "${CI_OSTYPE}" = "debian:11" ] || [ "${CI_OSTYPE}" = "debian:bullseye" ]; then
	DIST_TAG="debian/bullseye"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="packages.sury.org/php"
	INSTALL_PHP_REPO_GPG_URL="https://packages.sury.org/php/apt.gpg"
	INSTALL_PHP_REPO_GPG_FILEPATH="/usr/share/keyrings/deb.sury.org-php.gpg"
	INSTALL_PHP_PKG_LIST="dh-php php-all-dev php${PHPVER_WITHPERIOD} libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_DEBIAN=1


elif [ "${CI_OSTYPE}" = "debian:10" ] || [ "${CI_OSTYPE}" = "debian:buster" ]; then
	DIST_TAG="debian/buster"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="packages.sury.org/php"
	INSTALL_PHP_REPO_GPG_URL="https://packages.sury.org/php/apt.gpg"
	INSTALL_PHP_REPO_GPG_FILEPATH="/usr/share/keyrings/deb.sury.org-php.gpg"
	INSTALL_PHP_PKG_LIST="dh-php php-all-dev php${PHPVER_WITHPERIOD} libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_DEBIAN=1

elif [ "${CI_OSTYPE}" = "rockylinux:9.0" ] || [ "${CI_OSTYPE}" = "rockylinux:9" ]; then
	DIST_TAG="el/9"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/enterprise/remi-release-9.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_ROCKY=1

elif [ "${CI_OSTYPE}" = "rockylinux:8.6" ] || [ "${CI_OSTYPE}" = "rockylinux:8" ]; then
	DIST_TAG="el/8"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"
	INSTALLER_BIN="dnf"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build rubygems procps python3 k2hash-devel"
	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/enterprise/remi-release-8.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"
	IS_OS_ROCKY=1

elif [ "${CI_OSTYPE}" = "centos:7" ] || [ "${CI_OSTYPE}" = "centos:centos7" ]; then
	DIST_TAG="el/7"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="yum"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build rubygems procps python k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO="centos-release-scl-rh centos-release-scl"
	INSTALL_PHP_REPO="https://rpms.remirepo.net/enterprise/remi-release-7.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT="--enablerepo=remi-php${PHPVER_NOPERIOD}"
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_CENTOS=1

elif [ "${CI_OSTYPE}" = "fedora:37" ]; then
	DIST_TAG="fedora/37"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/fedora/remi-release-37.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_FEDORA=1

elif [ "${CI_OSTYPE}" = "fedora:36" ]; then
	DIST_TAG="fedora/36"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/fedora/remi-release-36.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_FEDORA=1

elif [ "${CI_OSTYPE}" = "fedora:35" ]; then
	DIST_TAG="fedora/35"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/fedora/remi-release-35.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_FEDORA=1
fi

#---------------------------------------------------------------
# Enable/Disable processing
#---------------------------------------------------------------
# [NOTE]
# Specify the phase of processing to use.
# The phases that can be specified are the following values, and
# the default is set for PHP Extension processing.
# Setting this value to 1 enables the corresponding processing,
# setting it to 0 disables it.
#
#	<variable name>		<default value>
#	RUN_PRE_CONFIG			1
#	RUN_CONFIG				1
#	RUN_PRE_CLEANUP			1
#	RUN_CLEANUP				1
#	RUN_POST_CLEANUP		0
#	RUN_CPPCHECK			1
#	RUN_SHELLCHECK			1
#	RUN_CHECK_OTHER			0
#	RUN_PRE_BUILD			0
#	RUN_BUILD				1
#	RUN_POST_BUILD			0
#	RUN_PRE_TEST			0
#	RUN_TEST				1
#	RUN_POST_TEST			0
#	RUN_PRE_PACKAGE			0
#	RUN_PACKAGE				1
#	RUN_POST_PACKAGE		0
#	RUN_PUBLISH_PACKAGE		1

#---------------------------------------------------------------
# Variables for each process
#---------------------------------------------------------------
# [NOTE]
# Specify the following variables that can be specified in each phase.
# Each value has a default value for PHP Extension processing.
#
#	PRE_CLEANUP_FILES_DIRS			""
#
#	CPPCHECK_TARGET					"."
#	CPPCHECK_BASE_OPT				"--quiet --error-exitcode=1 --inline-suppr -j 4 --std=c++03 --xml"
#	CPPCHECK_ENABLE_VALUES			"warning style information missingInclude"
#	CPPCHECK_IGNORE_VALUES			"unmatchedSuppression"
#	CPPCHECK_BUILD_DIR				"/tmp/cppcheck"
#
#	SHELLCHECK_TARGET_DIRS			"."
#	SHELLCHECK_BASE_OPT				"--shell=sh"
#	SHELLCHECK_EXCEPT_PATHS			"/\.libs/ /autom4te.cache/ /build/ /debian_build/ /rpmbuild/ /include/ /modules/ /packages/ /run-tests.php"
#	SHELLCHECK_IGN					"SC1117 SC1090 SC1091"
#	SHELLCHECK_INCLUDE_IGN			"SC2034 SC2148"
#
#	BUILD_MAKE_EXT_OPT_RPM			""
#	BUILD_MAKE_EXT_OPT_DEBIAN		""
#	BUILD_MAKE_EXT_OPT_ALPINE		""
#	BUILD_MAKE_EXT_OPT_OTHER		""
#
#	MAKE_TEST_OPT_RPM				"test"
#	MAKE_TEST_OPT_DEBIAN			"test"
#	MAKE_TEST_OPT_ALPINE			"test"
#	MAKE_TEST_OPT_OTHER				"test"
#
#	CREATE_PACKAGE_TOOL_RPM			"buildutils/php_rpm_build.sh"
#	CREATE_PACKAGE_TOOL_DEBIAN		"buildutils/php_debian_build.sh"
#	CREATE_PACKAGE_TOOL_ALPINE		"buildutils/php_apline_build.sh"
#	CREATE_PACKAGE_TOOL_OTHER		""
#
#	CREATE_PACKAGE_TOOL_OPT_AUTO	"-y"
#	CREATE_PACKAGE_TOOL_OPT_RPM		""
#	CREATE_PACKAGE_TOOL_OPT_DEBIAN	""
#	CREATE_PACKAGE_TOOL_OPT_ALPINE	""
#	CREATE_PACKAGE_TOOL_OPT_OTHER	""
#

PRE_CLEANUP_FILES_DIRS="
	config.h.in~
	configure~
	core.*
	rpmbuild
	debian_build
	packages
	tests/*.diff
	tests/*.exp
	tests/*.log
	tests/*.out
	tests/*.php
	tests/*.sh
	php-pecl-k2hash.spec"

if [ "${PHPVER_NOPERIOD}" = "81" ]; then
	if [ "${IS_OS_UBUNTU}" -eq 1 ] || [ "${IS_OS_DEBIAN}" -eq 1 ]; then
		CREATE_PACKAGE_TOOL_OPT_DEBIAN="-ccp"
	fi
fi

#
# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noexpandtab sw=4 ts=4 fdm=marker
# vim<600: noexpandtab sw=4 ts=4
#
