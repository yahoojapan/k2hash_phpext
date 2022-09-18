#!/bin/sh
#
# Utility tools for building configure/packages by AntPickax
#
# Copyright 2022 Yahoo Japan Corporation.
#
# AntPickax provides utility tools for supporting autotools
# builds.
#
# These tools retrieve the necessary information from the
# repository and appropriately set the setting values of
# configure, Makefile, spec,etc file and so on.
# These tools were recreated to reduce the number of fixes and
# reduce the workload of developers when there is a change in
# the project configuration.
# 
# For the full copyright and license information, please view
# the license file that was distributed with this source code.
#
# AUTHOR:   Takeshi Nakatani
# CREATE:   Fri, Feb 24 2022
# REVISION:
#

#----------------------------------------------------------
# Common variables
#----------------------------------------------------------
PRGNAME=$(basename "$0")
#SCRIPTDIR=$(dirname "$0")
#SCRIPTDIR=$(cd "${SCRIPTDIR}" || exit 1; pwd)
#SRCTOP=$(cd "${SCRIPTDIR}"/../.. || exit 1; pwd)

#----------------------------------------------------------
# Utility: Usage
#----------------------------------------------------------
func_usage()
{
	echo ""
	echo "Usage:  $1 [PHP name] [OS image name] [--skip-packagecloud-tool] [--help(-h)]"
	echo "        PHP name                 PHP version(\"PHP74\", \"PHP80\", \"PHP81\", etc)"
	echo "        OS image name            OS image name(If omitted, determined from the OS information)"
	echo "        --skip-packagecloud-tool Skip ruby tools and pcakagecloud.io tools"
	echo "        --help(-h)               print help"
	echo ""
	echo "Note:  When this script runs on the Github Actions, set the following environment"
	echo "       variables to Runner."
	echo "           DIST_TAG=\"ubuntu/focal\""
	echo "           PKG_EXT=\"deb\""
	echo "           PACKAGE_TYPE_RPM=\"0\""
	echo "           PACKAGE_TYPE_DEB=\"1\""
	echo "           BUILD_PLATFORM_COMMAND=\"scl enable phpXX --\""
	echo "           RUBY_SCL_ENV_FILE=\"/opt/rh/rh-ruby27/enable\""
	echo ""
}

#----------------------------------------------------------
# Utilities for message
#----------------------------------------------------------
if [ -t 1 ] || [ "X${CI}" = "Xtrue" ]; then
	# shellcheck disable=SC2034
	CBLD=$(printf '\033[1m')
	CREV=$(printf '\033[7m')
	CRED=$(printf '\033[31m')
	#CYEL=$(printf '\033[33m')
	CGRN=$(printf '\033[32m')
	CDEF=$(printf '\033[0m')
else
	# shellcheck disable=SC2034
	CBLD=""
	CREV=""
	CRED=""
	#CYEL=""
	CGRN=""
	CDEF=""
fi
if [ "X${CI}" = "Xtrue" ]; then
	GHAGRP_START="::group::"
	GHAGRP_END="::endgroup::"
else
	GHAGRP_START=""
	GHAGRP_END=""
fi

prn_title()
{
	echo "${GHAGRP_START}${CBLD}$*${CDEF}"
}
prn_success()
{
	echo "${CBLD}${CGRN}${CREV}[SUCCESS]${CDEF} $*"
	echo ""
}
prn_fauilure()
{
	echo "${CBLD}${CRED}${CREV}[FAILURE]${CDEF} ${CRED}$*${CDEF}"
	echo ""
}
prn_groupend()
{
	if [ -n "${GHAGRP_END}" ]; then
		echo "${GHAGRP_END}"
	fi
}

#----------------------------------------------------------
# Parse options
#----------------------------------------------------------
OS_NAMEVER=
PHP_NAMEVER=
SKIP_PACKAGECLOUD_TOOL=0
while [ $# -ne 0 ]; do
	if [ "X$1" = "X" ]; then
		break
	elif [ "X$1" = "X-h" ] || [ "X$1" = "X-H" ] || [ "X$1" = "X--help" ] || [ "X$1" = "X--HELP" ]; then
		func_usage "${PRGNAME}"
		exit 0
	elif [ "X$1" = "X--skip-packagecloud-tool" ] || [ "X$1" = "X--SKIP-PACKAGECLOUD-TOOL" ]; then
		if [ "${SKIP_PACKAGECLOUD_TOOL}" -ne 0 ]; then
			prn_fauilure "Already set \"--skip-packagecloud-tool\" option."
			exit 1
		fi
		SKIP_PACKAGECLOUD_TOOL=1
	else
		if [ -z "${PHP_NAMEVER}" ]; then
			PHP_NAMEVER="$1"
		elif [ -z "${OS_NAME}" ]; then
			OS_NAMEVER="$1"
		else
			prn_fauilure "Already set OS image name(${OS_NAME}) and PHP name(${PHP_NAMEVER}), but you spacified more option($1)"
			exit 1
		fi
	fi
	shift
done

#----------------------------------------------------------
# Set variables for PHP packages
#----------------------------------------------------------
if [ -z "${PHP_NAMEVER}" ]; then
	prn_fauilure "The PHP version is unknown(not specified it by option)."
	exit 1
fi
if [ "${PHP_NAMEVER}" = "PHP74" ]; then
	PHPVER_NOPERIOD="74"
	PHPVER_WITHPERIOD="7.4"
elif [ "${PHP_NAMEVER}" = "PHP80" ]; then
	PHPVER_NOPERIOD="80"
	PHPVER_WITHPERIOD="8.0"
elif [ "${PHP_NAMEVER}" = "PHP81" ]; then
	PHPVER_NOPERIOD="81"
	PHPVER_WITHPERIOD="8.1"
else
	prn_fauilure "Unknown PHP version(${PHP_NAMEVER})."
	exit 1
fi

#----------------------------------------------------------
# Check OS name / type
#----------------------------------------------------------
# OS_NAMEVER	ex. "cesntos:centos7" "centos:stream8" "ubuntu:18.04" "ubuntu:20.04" ...
# OS_TYPE		ex. "cesntos"         "cesntos"        "ubuntu"       "ubuntu"
# OS_VER		ex. "7"               "8"              "18.04"        "20.04"
#
# shellcheck disable=SC1009
if [ -z "${OS_NAME}" ]; then
	if [ ! -f /etc/os-release ]; then
		prn_fauilure "The OS name is unknown."
		exit 1
	fi
	# shellcheck disable=SC1091
	. /etc/os-release

	OS_NAMEVER="${ID}:${VERSION_ID}"
	OS_TYPE="${ID}"
	OS_VER="${VERSION_ID}"
else
	OS_NAMEVER=$(echo "${OS_NAMEVER}" | awk -F"/" '{print $NF}')
	OS_TYPE=$(echo "${OS_NAMEVER}" | awk -F":" '{print $1}')
	OS_VER=$(echo "${OS_NAMEVER}" | awk -F":" '{print $NF}' | sed -e 's/centos//g' -e 's/stream//g')
fi

#----------------------------------------------------------
# Set variables for basic/php packages
#----------------------------------------------------------
if [ "${OS_TYPE}" = "centos" ]; then
	#
	# Package manager
	#
	if [ "${OS_VER}" -eq 8 ]; then
		PKGMAN_BIN="dnf"
		PKG_UPDATE_OPT="update -y -qq"
	else
		PKGMAN_BIN="yum"
		PKG_UPDATE_OPT="update -y"
	fi

	#
	# Repository / Pakacges
	#
	# [NOTE]
	# CentOS7 has a too low version of ShellCheck, and CentOS8 does not offer it.
	# We can run ShellCheck with ubuntu, so we don't install it for CentOS.
	#
	if [ "${OS_VER}" -eq 8 ]; then
		OSVER_PKGS_INSTALL_PRE_PACKAGECLOUD="ruby-devel rubygems"
		OSVER_PKGS_INSTALL_BASIC="python3"
		OSVER_OPT_BASIC_PKGS_INSTALL="--enablerepo=powertools"
		OSVER_OPT_PHP_PKGS_INSTALL=""
		OSVER_ADD_BASIC_REPO_NAMES="epel-release-${OS_VER}"
		OSVER_RUBY_SCL_ENV_FILE=""
	else
		OSVER_PKGS_INSTALL_PRE_PACKAGECLOUD="rh-ruby27 rh-ruby27-ruby-devel rh-ruby27-rubygem-rake"
		OSVER_PKGS_INSTALL_BASIC="python centos-release-scl"
		OSVER_OPT_BASIC_PKGS_INSTALL=""
		OSVER_OPT_PHP_PKGS_INSTALL="--enablerepo=remi-php${PHPVER_NOPERIOD}"
		OSVER_ADD_BASIC_REPO_NAMES="epel-release-${OS_VER} centos-release-scl-rh centos-release-scl"
		OSVER_RUBY_SCL_ENV_FILE="/opt/rh/rh-ruby27/enable"
	fi

	PKGS_INSTALL_PRE_ADDREPO="curl"
	PKGS_INSTALL_PRE_PACKAGECLOUD="${OSVER_PKGS_INSTALL_PRE_PACKAGECLOUD}"
	PKGS_INSTALL_CHECKERS="cppcheck"
	PKGS_INSTALL_BASIC="git k2hash-devel rpm-build rpm-devel rpmlint make diffutils patch rpmdevtools scl-utils-build yum-utils ${OSVER_PKGS_INSTALL_BASIC}"
	PKGS_INSTALL_BASIC_ALL="${PKGS_INSTALL_BASIC} ${PKGS_INSTALL_CHECKERS} ${PKGS_INSTALL_PRE_PACKAGECLOUD}"
	PKGS_INSTALL_PHP="php${PHPVER_NOPERIOD}-php-devel php${PHPVER_NOPERIOD}-scldevel php${PHPVER_NOPERIOD}-build"
	PKGS_INSTALL_PKGCLOUD="package_cloud"

	OPT_BASIC_PKGS_INSTALL="${OSVER_OPT_BASIC_PKGS_INSTALL}"
	OPT_PHP_PKGS_INSTALL="${OSVER_OPT_PHP_PKGS_INSTALL}"

	ADD_BASIC_REPO_CMD="${PKGMAN_BIN} install -y ${OSVER_ADD_BASIC_REPO_NAMES}"
	ADD_PHP_REPO_CMD="${PKGMAN_BIN} install -y https://rpms.remirepo.net/enterprise/remi-release-${OS_VER}.rpm"
	CHECK_PHP_REPO_CMD="yum list installed | grep remi-release >/dev/null 2>&1"

	UPDATE_ALT_PHP_CONFIG=""
	UPDATE_ALT_PHP_BIN=""
	RUBY_SCL_ENV_FILE="${OSVER_RUBY_SCL_ENV_FILE}"

	ADD_PACKAGECLOUD_URL="https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh"

	# [NOTE]
	# When this script runs on the Github Actions, set the following environment
	# variables to Runner.
	#     DIST_TAG="el8"
	#     PKG_EXT="rpm"
	#     PACKAGE_TYPE_RPM=1"
	#     PACKAGE_TYPE_DEB=0"
	#     BUILD_PLATFORM_COMMAND="scl enable phpXX --"
	# This environment variable is used to run the build in the SCL environment.
	#
    if [ -n "${GITHUB_ENV}" ]; then
		#
		# Package parameters to Environment
		#
		if [ "${OS_VER}" -eq 8 ]; then
			DIST_TAG="el/8"
			PKG_EXT="rpm"
		else
			DIST_TAG="el/7"
			PKG_EXT="rpm"
		fi
		{
			echo "DIST_TAG=${DIST_TAG}"
			echo "PKG_EXT=${PKG_EXT}"
			echo "PACKAGE_TYPE_RPM=1"
			echo "PACKAGE_TYPE_DEB=0"
			echo "BUILD_PLATFORM_COMMAND=scl enable php${PHPVER_NOPERIOD} --"
			echo "RUBY_SCL_ENV_FILE=${RUBY_SCL_ENV_FILE}"
		} >> "${GITHUB_ENV}"
	fi

elif [ "${OS_TYPE}" = "ubuntu" ]; then
	#
	# Installation special environment variables
	#
	export DEBIAN_FRONTEND="noninteractive"

	#
	# Package manager
	#
	PKGMAN_BIN="apt-get"
	PKG_UPDATE_OPT="update -y -qq"

	#
	# Repository / Pakacges
	#
	PKGS_INSTALL_PRE_ADDREPO="ca-certificates apt-transport-https software-properties-common curl"
	PKGS_INSTALL_PRE_PACKAGECLOUD="ruby-dev rubygems rubygems-integration"
	PKGS_INSTALL_CHECKERS="cppcheck shellcheck"
	PKGS_INSTALL_BASIC="git k2hash-dev lintian debhelper pkg-config shtool"
	PKGS_INSTALL_BASIC_ALL="${PKGS_INSTALL_BASIC} ${PKGS_INSTALL_CHECKERS} ${PKGS_INSTALL_PRE_PACKAGECLOUD}"
	PKGS_INSTALL_PHP="dh-php php-all-dev php${PHPVER_WITHPERIOD} libapache2-mod-php${PHPVER_WITHPERIOD}"
	PKGS_INSTALL_PKGCLOUD="rake package_cloud"

	OPT_BASIC_PKGS_INSTALL=""
	OPT_PHP_PKGS_INSTALL=""

	ADD_BASIC_REPO_CMD=""
	ADD_PHP_REPO_CMD="add-apt-repository -y ppa:ondrej/php"
	CHECK_PHP_REPO_CMD=""

	UPDATE_ALT_PHP_CONFIG="update-alternatives --set php-config /usr/bin/php-config${PHPVER_WITHPERIOD}"
	UPDATE_ALT_PHP_BIN="update-alternatives --set php /usr/bin/php${PHPVER_WITHPERIOD}"
	RUBY_SCL_ENV_FILE=""

	ADD_PACKAGECLOUD_URL="https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh"

	# [NOTE]
	# When this script runs on the Github Actions, set the following environment
	# variables to Runner.
	#     DIST_TAG="ubuntu/focal"
	#     PKG_EXT="deb"
	#     PACKAGE_TYPE_RPM=0"
	#     PACKAGE_TYPE_DEB=1"
	# This environment variable is used to run the build in the SCL environment.
	#
    if [ -n "${GITHUB_ENV}" ]; then
		#
		# Package parameters to Environment
		#
		if [ "${OS_VER}" = "20.04" ]; then
			DIST_TAG="ubuntu/focal"
			PKG_EXT="deb"
		else
			DIST_TAG="ubuntu/bionic"
			PKG_EXT="deb"
		fi
		{
			echo "DIST_TAG=${DIST_TAG}"
			echo "PKG_EXT=${PKG_EXT}"
			echo "PACKAGE_TYPE_RPM=0"
			echo "PACKAGE_TYPE_DEB=1"
		} >> "${GITHUB_ENV}"
	fi
else
	prn_fauilure "Unknown OS type(${OS_TYPE})."
	exit 1
fi

#----------------------------------------------------------
# Print information
#----------------------------------------------------------
prn_title "Start to install packages"
echo "-----------------------------------------------------------"
echo "Information"
echo "-----------------------------------------------------------"
echo "[OS]"
echo "  name                      ${OS_NAMEVER}"
echo "  type                      ${OS_TYPE}"
echo "  version                   ${OS_VER}"
echo "  distribution tag          ${DIST_TAG}"
echo "  package extension         .${PKG_EXT}"
echo "  package manager           ${PKGMAN_BIN}"
echo ""
echo "[PHP]"
echo "  name                      ${PHP_NAMEVER}"
echo "  version                   ${PHPVER_WITHPERIOD}"
echo ""
echo "[Repository]"
echo "  Basic                     $(echo "${ADD_BASIC_REPO_CMD}" | awk '{print $NF}')"
echo "  PHP                       $(echo "${ADD_PHP_REPO_CMD}" | awk '{print $NF}')"
echo "  packagecloud.io           ${ADD_PACKAGECLOUD_URL}"
echo ""
echo "[Packages]"
echo "  Pre-Basic packages        ${PKGS_INSTALL_PRE_ADDREPO}"
echo "  Basic packages            ${PKGS_INSTALL_BASIC}"
echo "  PHP packages              ${PKGS_INSTALL_PHP}"
echo "  Checker packages          ${PKGS_INSTALL_CHECKERS}"
echo "  Pre-packagecloud.io tools ${PKGS_INSTALL_PRE_PACKAGECLOUD}"
echo ""
echo "[Install Options]"
echo "  Basic                     ${OPT_BASIC_PKGS_INSTALL}"
echo "  PHP                       ${OPT_PHP_PKGS_INSTALL}"
echo "  Package update option     \"${PKG_UPDATE_OPT}\""
echo ""
echo "[Other]"
echo "  Update-alt PHP config     \"${UPDATE_ALT_PHP_CONFIG}\""
echo "  Update-alt PHP bin        \"${UPDATE_ALT_PHP_BIN}\""
echo "  Ruby SCL env file         \"${RUBY_SCL_ENV_FILE}\""
echo "-----------------------------------------------------------"
prn_groupend

#----------------------------------------------------------
# Update package cache
#----------------------------------------------------------
prn_title "Update package cache"
if ! /bin/sh -c "${PKGMAN_BIN} ${PKG_UPDATE_OPT}"; then
	prn_fauilure "Could not update package cache."
	exit 1
fi
prn_success "Updated package cache"
prn_groupend

#----------------------------------------------------------
# Install packages before adding repositories
#----------------------------------------------------------
prn_title "Install packages before adding repositories"
if [ -n "${PKGS_INSTALL_PRE_ADDREPO}" ]; then
	if ! /bin/sh -c "${PKGMAN_BIN} install -y ${PKGS_INSTALL_PRE_ADDREPO}"; then
		prn_fauilure "Could not install packages before adding repositories."
		exit 1
	fi
	prn_success "Installed packages before adding repositories"
else
	prn_success "Nothing to install packages"
fi
prn_groupend

#----------------------------------------------------------
# Add repositories
#----------------------------------------------------------
prn_title "Add repositories"
if [ -n "${ADD_BASIC_REPO_CMD}" ]; then
	if ! /bin/sh -c "${ADD_BASIC_REPO_CMD}"; then
		prn_fauilure "Could not add repositories."
		exit 1
	fi
	prn_success "Added repositories"
else
	prn_success "Nothing to add repositories"
fi
prn_groupend

prn_title "Add paclagecloud repository"
if [ -n "${ADD_PACKAGECLOUD_URL}" ]; then
	if ! curl -s "${ADD_PACKAGECLOUD_URL}" | bash; then
		prn_fauilure "Could not add paclagecloud repository."
		exit 1
	fi
	prn_success "Added paclagecloud repository"
else
	prn_success "Nothing to add paclagecloud repository"
fi
prn_groupend

#----------------------------------------------------------
# Install basic packages
#----------------------------------------------------------
prn_title "Install basic packages"
if [ -n "${PKGS_INSTALL_BASIC_ALL}" ]; then
	if ! /bin/sh -c "${PKGMAN_BIN} ${OPT_BASIC_PKGS_INSTALL} install -y ${PKGS_INSTALL_BASIC_ALL}"; then
		prn_fauilure "Could not install basic packages."
		exit 1
	fi
	prn_success "Installed basic packages"
else
	prn_success "Nothing to install basic packages"
fi
prn_groupend

#----------------------------------------------------------
# Add PHP repositories
#----------------------------------------------------------
prn_title "Add PHP repository"
if [ -n "${ADD_PHP_REPO_CMD}" ]; then
	FOUND_PHP_REPO=0
	if [ -n "${CHECK_PHP_REPO_CMD}" ]; then
		if /bin/sh -c "${CHECK_PHP_REPO_CMD}"; then
			FOUND_PHP_REPO=1
		fi
	fi
	if [ "${FOUND_PHP_REPO}" -eq 0 ]; then
		if ! /bin/sh -c "${ADD_PHP_REPO_CMD}"; then
			prn_fauilure "Could not add PHP repository."
			exit 1
		fi
		prn_success "Added PHP repository."
	else
		prn_success "Already set PHP repository."
	fi
else
	prn_success "Nothing to add PHP repository."
fi
prn_groupend

#----------------------------------------------------------
# Install PHP packages
#----------------------------------------------------------
prn_title "Install PHP packages"
if [ -n "${PKGS_INSTALL_PHP}" ]; then
	if ! /bin/sh -c "${PKGMAN_BIN} ${OPT_PHP_PKGS_INSTALL} install -y ${PKGS_INSTALL_PHP}"; then
		prn_fauilure "Could not install PHP packages."
		exit 1
	fi
	prn_success "Installed PHP packages"
else
	prn_success "Nothing to install PHP packages."
fi
prn_groupend

if [ -n "${UPDATE_ALT_PHP_CONFIG}" ]; then
	prn_title "Update alternetives php config"
	if ! /bin/sh -c "${UPDATE_ALT_PHP_CONFIG}"; then
		prn_fauilure "Could not update alternetives php config."
		exit 1
	fi
	prn_success "Updated alternetives php config."
	prn_groupend
fi

if [ -n "${UPDATE_ALT_PHP_BIN}" ]; then
	prn_title "Update alternetives php bin"
	if ! /bin/sh -c "${UPDATE_ALT_PHP_BIN}"; then
		prn_fauilure "Could not update alternetives php bin."
		exit 1
	fi
	prn_success "Updated alternetives php config."
	prn_groupend
fi

#----------------------------------------------------------
# Install packagecloud.io tools
#----------------------------------------------------------
prn_title "Install packagecloud.io tools"
if [ "${SKIP_PACKAGECLOUD_TOOL}" -eq 0 ]; then
	if [ -n "${PKGS_INSTALL_PKGCLOUD}" ]; then
		if [ -n "${RUBY_SCL_ENV_FILE}" ]; then
			echo "\"RUBY_SCL_ENV_FILE\" environment is found, do set it before run gem install."
			#shellcheck disable=SC1090
			. "${RUBY_SCL_ENV_FILE}"
		fi

		if ! /bin/sh -c "gem install ${PKGS_INSTALL_PKGCLOUD}"; then
			prn_fauilure "Could not install packagecloud.io tools."
			exit 1
		fi
		prn_success "Installed packagecloud.io tools."
	else
		prn_success "Nothing to install packagecloud.io tools."
	fi
else
	prn_success "Skip install packagecloud.io tools."
fi
prn_groupend

#----------------------------------------------------------
# Finish
#----------------------------------------------------------
prn_title "Install Summary"
prn_success "All setup for build environment"
prn_groupend

exit 0

#
# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noexpandtab sw=4 ts=4 fdm=marker
# vim<600: noexpandtab sw=4 ts=4
#
