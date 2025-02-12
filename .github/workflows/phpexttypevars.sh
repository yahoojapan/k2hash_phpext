#
# K2HASH PHP Extension library
#
# Copyright 2022 Yahoo Japan Corporation.
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
#   INSTALL_PKG_LIST              : A list of packages to be installed for
#                                   build and packaging
#
#   INSTALLER_BIN                 : Package management command
#   UPDATE_CMD                    : Update sub command for package management
#                                   command
#   UPDATE_CMD_ARG                : Update sub command arguments for package
#                                   management command
#   INSTALL_CMD                   : Install sub command for package management
#                                   command
#   INSTALL_CMD_ARG               : Install sub command arguments for package
#                                   management command
#   INSTALL_AUTO_ARG              : No interaption arguments for package
#                                   management command
#   INSTALL_QUIET_ARG             : Quiet arguments for package management
#                                   command
#   PKG_OUTPUT_DIR                : Set the directory path where the package
#                                   will be created relative to the top
#                                   directory of the source
#   PKG_EXT                       : The extension of the package file
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
#   IS_OS_FEDORA                  : Set to 1 for Fedora, 0 otherwise
#   IS_OS_ROCKY                   : Set to 1 for Rocky, 0 otherwise
#   IS_OS_ALPINE                  : Set to 1 for Alpine, 0 otherwise
#
#   NOT_PROVIDED_PHPVER           : Set to 1 if PHP * OS is not supported
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
UPDATE_CMD=""
UPDATE_CMD_ARG=""
INSTALL_CMD=""
INSTALL_CMD_ARG=""
INSTALL_AUTO_ARG=""
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
IS_OS_FEDORA=0
IS_OS_ROCKY=0
IS_OS_ALPINE=0

#
# Special variables
#
NOT_PROVIDED_PHPVER=0

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

elif echo "${CI_PHPTYPE}" | grep -q -i -e "PHP8.0" -e "PHP80" -e "8.0" -e "80"; then
	PHPVER_NOPERIOD="80"
	PHPVER_WITHPERIOD="8.0"

elif echo "${CI_PHPTYPE}" | grep -q -i -e "PHP8.1" -e "PHP81" -e "8.1" -e "81"; then
	PHPVER_NOPERIOD="81"
	PHPVER_WITHPERIOD="8.1"

elif echo "${CI_PHPTYPE}" | grep -q -i -e "PHP8.2" -e "PHP82" -e "8.2" -e "82"; then
	PHPVER_NOPERIOD="82"
	PHPVER_WITHPERIOD="8.2"

elif echo "${CI_PHPTYPE}" | grep -q -i -e "PHP8.3" -e "PHP83" -e "8.3" -e "83"; then
	PHPVER_NOPERIOD="83"
	PHPVER_WITHPERIOD="8.3"

elif echo "${CI_PHPTYPE}" | grep -q -i -e "PHP8.4" -e "PHP84" -e "8.4" -e "84"; then
	PHPVER_NOPERIOD="84"
	PHPVER_WITHPERIOD="8.4"
fi

#
# OS Type
#
if [ -z "${CI_OSTYPE}" ]; then
	#
	# Unknown OS : Nothing to do
	#
	:

elif echo "${CI_OSTYPE}" | grep -q -i -e "ubuntu:24.04" -e "ubuntu:noble"; then
	DIST_TAG="ubuntu/noble"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="ppa:ondrej/php"
	INSTALL_PHP_PKG_LIST="dh-php php${PHPVER_WITHPERIOD} php${PHPVER_WITHPERIOD}-dev libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_UBUNTU=1

elif echo "${CI_OSTYPE}" | grep -q -i -e "ubuntu:22.04" -e "ubuntu:jammy"; then
	DIST_TAG="ubuntu/jammy"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="ppa:ondrej/php"
	INSTALL_PHP_PKG_LIST="dh-php php${PHPVER_WITHPERIOD} php${PHPVER_WITHPERIOD}-dev libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_UBUNTU=1

elif echo "${CI_OSTYPE}" | grep -q -i -e "debian:12" -e "debian:bookworm"; then
	DIST_TAG="debian/bookworm"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="packages.sury.org/php"
	INSTALL_PHP_REPO_GPG_URL="https://packages.sury.org/php/apt.gpg"
	INSTALL_PHP_REPO_GPG_FILEPATH="/usr/share/keyrings/deb.sury.org-php.gpg"
	INSTALL_PHP_PKG_LIST="dh-php php${PHPVER_WITHPERIOD} php${PHPVER_WITHPERIOD}-dev libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_DEBIAN=1

elif echo "${CI_OSTYPE}" | grep -q -i -e "debian:11" -e "debian:bullseye"; then
	DIST_TAG="debian/bullseye"
	PKG_EXT="deb"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apt-get"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-qq"
	INSTALL_PKG_LIST="git lintian debhelper pkg-config ruby-dev rubygems rubygems-integration procps shtool k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO="ca-certificates apt-transport-https software-properties-common"
	INSTALL_PHP_REPO="packages.sury.org/php"
	INSTALL_PHP_REPO_GPG_URL="https://packages.sury.org/php/apt.gpg"
	INSTALL_PHP_REPO_GPG_FILEPATH="/usr/share/keyrings/deb.sury.org-php.gpg"
	INSTALL_PHP_PKG_LIST="dh-php php${PHPVER_WITHPERIOD} php${PHPVER_WITHPERIOD}-dev libapache2-mod-php${PHPVER_WITHPERIOD}"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	INSTALL_PHP_POST_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	SWITCH_PHP_COMMAND=""

	IS_OS_DEBIAN=1

elif echo "${CI_OSTYPE}" | grep -q -i "rockylinux:9"; then
	DIST_TAG="el/9"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build ruby-devel rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/enterprise/remi-release-9.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_ROCKY=1

elif echo "${CI_OSTYPE}" | grep -q -i "rockylinux:8"; then
	DIST_TAG="el/8"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build ruby-devel rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/enterprise/remi-release-8.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"
	IS_OS_ROCKY=1

elif echo "${CI_OSTYPE}" | grep -q -i "fedora:41"; then
	DIST_TAG="fedora/41"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build ruby-devel rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/fedora/remi-release-41.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_FEDORA=1

elif echo "${CI_OSTYPE}" | grep -q -i "fedora:40"; then
	DIST_TAG="fedora/40"
	PKG_EXT="rpm"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="dnf"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG=""
	INSTALL_CMD="install"
	INSTALL_CMD_ARG=""
	INSTALL_AUTO_ARG="-y"
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="git make diffutils pkgconfig patch yum-utils rpmdevtools redhat-rpm-config rpm-build rpm-devel rpmlint scl-utils-build ruby-devel rubygems procps python3 k2hash-devel"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO="https://rpms.remirepo.net/fedora/remi-release-40.rpm"
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND="scl enable php${PHPVER_NOPERIOD} --"

	IS_OS_FEDORA=1

elif echo "${CI_OSTYPE}" | grep -q -i "alpine:3.21"; then
	DIST_TAG="alpine/v3.21"
	PKG_EXT="apk"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apk"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG="--no-progress"
	INSTALL_CMD="add"
	INSTALL_CMD_ARG="--no-progress --no-cache"
	INSTALL_AUTO_ARG=""
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="bash sudo alpine-sdk util-linux-misc musl-locales ruby-dev procps k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO=""
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD} php${PHPVER_NOPERIOD}-dev"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND=""

	IS_OS_ALPINE=1

	# [FIXME]
	# We want to use PHP8.4 for ALPINE3.21, but phpize is not included in php84-dev.
	# Therefore, at the moment (February 2025), we will use PHP8.3.
	#
	if [ "${PHPVER_NOPERIOD}" != "83" ]; then
		NOT_PROVIDED_PHPVER=1
	fi

elif echo "${CI_OSTYPE}" | grep -q -i "alpine:3.20"; then
	DIST_TAG="alpine/v3.20"
	PKG_EXT="apk"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apk"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG="--no-progress"
	INSTALL_CMD="add"
	INSTALL_CMD_ARG="--no-progress --no-cache"
	INSTALL_AUTO_ARG=""
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="bash sudo alpine-sdk util-linux-misc musl-locales ruby-dev procps k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO=""
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD} php${PHPVER_NOPERIOD}-dev"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND=""

	IS_OS_ALPINE=1

	if [ "${PHPVER_NOPERIOD}" != "83" ]; then
		NOT_PROVIDED_PHPVER=1
	fi

elif echo "${CI_OSTYPE}" | grep -q -i "alpine:3.19"; then
	DIST_TAG="alpine/v3.19"
	PKG_EXT="apk"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apk"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG="--no-progress"
	INSTALL_CMD="add"
	INSTALL_CMD_ARG="--no-progress --no-cache"
	INSTALL_AUTO_ARG=""
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="bash sudo alpine-sdk util-linux-misc musl-locales ruby-dev procps k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO=""
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD} php${PHPVER_NOPERIOD}-dev"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND=""

	IS_OS_ALPINE=1

	if [ "${PHPVER_NOPERIOD}" != "82" ]; then
		NOT_PROVIDED_PHPVER=1
	fi

elif echo "${CI_OSTYPE}" | grep -q -i "alpine:3.18"; then
	DIST_TAG="alpine/v3.18"
	PKG_EXT="apk"
	PKG_OUTPUT_DIR="packages"

	INSTALLER_BIN="apk"
	UPDATE_CMD="update"
	UPDATE_CMD_ARG="--no-progress"
	INSTALL_CMD="add"
	INSTALL_CMD_ARG="--no-progress --no-cache"
	INSTALL_AUTO_ARG=""
	INSTALL_QUIET_ARG="-q"
	INSTALL_PKG_LIST="bash sudo alpine-sdk util-linux-misc musl-locales ruby-dev procps k2hash-dev"

	INSTALL_PHP_PRE_ADD_REPO=""
	INSTALL_PHP_REPO=""
	INSTALL_PHP_PKG_LIST="php${PHPVER_NOPERIOD} php${PHPVER_NOPERIOD}-dev"
	INSTALL_PHP_OPT=""
	INSTALL_PHP_POST_CONFIG=""
	INSTALL_PHP_POST_BIN=""
	SWITCH_PHP_COMMAND=""

	IS_OS_ALPINE=1

	if [ "${PHPVER_NOPERIOD}" != "81" ]; then
		NOT_PROVIDED_PHPVER=1
	fi
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
#	CREATE_PACKAGE_TOOL_ALPINE		"buildutils/php_alpine_build.sh"
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
	apk_build
	packages
	tests/*.diff
	tests/*.exp
	tests/*.log
	tests/*.out
	tests/*.php
	tests/*.sh
	php-pecl-k2hash.spec"

if [ "${PHPVER_NOPERIOD}" = "82" ]; then
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
