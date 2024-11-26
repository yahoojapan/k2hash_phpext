#!/bin/sh
#
# Utility tools for building configure/packages by AntPickax
#
# Copyright 2018 Yahoo Japan Corporation.
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
# CREATE:   Fri, Jan 13 2023
# REVISION: 1.1
#

#==============================================================
# Autobuild for apk package
#==============================================================
#
# Instead of pipefail(for shells not support "set -o pipefail")
#
PIPEFAILURE_FILE="/tmp/.pipefailure.$(od -An -tu4 -N4 /dev/random | tr -d ' \n')"

#
# For shellcheck
#
if command -v locale >/dev/null 2>&1; then
	if locale -a | grep -q -i '^[[:space:]]*C.utf8[[:space:]]*$'; then
		LANG=$(locale -a | grep -i '^[[:space:]]*C.utf8[[:space:]]*$' | sed -e 's/^[[:space:]]*//g' -e 's/[[:space:]]*$//g' | tr -d '\n')
		LC_ALL="${LANG}"
		export LANG
		export LC_ALL
	elif locale -a | grep -q -i '^[[:space:]]*en_US.utf8[[:space:]]*$'; then
		LANG=$(locale -a | grep -i '^[[:space:]]*en_US.utf8[[:space:]]*$' | sed -e 's/^[[:space:]]*//g' -e 's/[[:space:]]*$//g' | tr -d '\n')
		LC_ALL="${LANG}"
		export LANG
		export LC_ALL
	fi
fi

#----------------------------------------------------------
# Common variables
#----------------------------------------------------------
PRGNAME=$(basename "$0")
SCRIPTDIR=$(dirname "$0")
SCRIPTDIR=$(cd "${SCRIPTDIR}" || exit 1; pwd)
SRCTOP=$(cd "${SCRIPTDIR}/.." || exit 1; pwd)

SRCTOP_DIRNAME=$(basename "${SRCTOP}")
APK_TOPDIR="${SRCTOP}/apk_build"
PKG_TOPDIR="${SRCTOP}/packages"

PRGNAME_NOEXT=$(echo "${PRGNAME}" | sed -e 's/[\.].*$//g' | tr -d '\n')
EXTRA_COPY_FILES_CONF="${SCRIPTDIR}/${PRGNAME_NOEXT}_copy.conf"

APKBUILD_TEMPLATE_FILE="${SRCTOP}/buildutils/APKBUILD.templ"
APKBUILD_FILE="${APK_TOPDIR}/APKBUILD"
APKBUILD_CONFIG_DIR="${HOME}/.abuild"
APK_KEYS_DIR="/etc/apk/keys"

#
# Message variables
#
IN_GHAGROUP_AREA=0

#
# Variables
#
BUILD_NUMBER=0
IS_CLEAN=0
NO_INTERACTIVE=0

#==============================================================
# Utilities
#==============================================================
# 
# Usage
#
func_usage()
{
	echo ""
	echo "Usage:  $1 [--help(-h)] [--clean(-c)] [--buildnum(-b) <build number>] [--yes(-y)]"
	echo "        --help(-h)                     print help"
	echo "        --clean(-c)                    only clean work directory."
	echo "        --buildnum(-b) <build number>  specify build number for packaging(default 1)"
	echo "        --yes(-y)                      runs no interactive mode."
	echo ""
	echo "Note:   about <build number>"
	echo "        Specify a number starting from 1, just like other OS builds."
	echo "        However, ALPINE packages are 0-based, so the specified \"<build number> - 1\""
	echo "        is the actual number of the package."
	echo ""
}

#--------------------------------------------------------------
# Utilities for message
#--------------------------------------------------------------
if [ -t 1 ] || { [ -n "${CI}" ] && [ "${CI}" = "true" ]; }; then
	CBLD=$(printf '\033[1m')
	CREV=$(printf '\033[7m')
	CRED=$(printf '\033[31m')
	CYEL=$(printf '\033[33m')
	CGRN=$(printf '\033[32m')
	CDEF=$(printf '\033[0m')
else
	CBLD=""
	CREV=""
	CRED=""
	CYEL=""
	CGRN=""
	CDEF=""
fi
if [ -n "${CI}" ] && [ "${CI}" = "true" ] && [ -z "${RUN_AS_SUBPROCESS}" ]; then
	GHAGRP_START="::group::"
	GHAGRP_END="::endgroup::"
else
	GHAGRP_START=""
	GHAGRP_END=""
fi

PRNGROUPEND()
{
	if [ -n "${IN_GHAGROUP_AREA}" ] && [ "${IN_GHAGROUP_AREA}" -eq 1 ]; then
		if [ -n "${GHAGRP_END}" ]; then
			echo "${GHAGRP_END}"
		fi
	fi
	IN_GHAGROUP_AREA=0
}
PRNTITLE()
{
	PRNGROUPEND
	echo "${GHAGRP_START}${CBLD}${CGRN}${CREV}[TITLE]${CDEF} ${CGRN}$*${CDEF}"
	IN_GHAGROUP_AREA=1
}
PRNINFO()
{
	echo "${CBLD}${CREV}[INFO]${CDEF} $*"
}
PRNWARN()
{
	echo "${CBLD}${CYEL}${CREV}[WARNING]${CDEF} ${CYEL}$*${CDEF}"
}
PRNERR()
{
	echo "${CBLD}${CRED}${CREV}[ERROR]${CDEF} ${CRED}$*${CDEF}"
	PRNGROUPEND
}
PRNSUCCESS()
{
	echo "${CBLD}${CGRN}${CREV}[SUCCEED]${CDEF} ${CGRN}$*${CDEF}"
	PRNGROUPEND
}
PRNFAILURE()
{
	echo "${CBLD}${CRED}${CREV}[FAILURE]${CDEF} ${CRED}$*${CDEF}"
	PRNGROUPEND
}

#==============================================================
# Parse options
#==============================================================
while [ $# -ne 0 ]; do
	if [ -z "$1" ]; then
		break

	elif [ "$1" = "-h" ] || [ "$1" = "-H" ] || [ "$1" = "--help" ] || [ "$1" = "--HELP" ]; then
		func_usage "${PRGNAME}"
		exit 0

	elif [ "$1" = "-c" ] || [ "$1" = "-C" ] || [ "$1" = "--clean" ] || [ "$1" = "--CLEAN" ]; then
		if [ "${IS_CLEAN}" -ne 0 ]; then
			PRNERR "Already --clean(-c) option is specified."
			exit 1
		fi
		IS_CLEAN=1

	elif [ "$1" = "-b" ] || [ "$1" = "-B" ] || [ "$1" = "--buildnum" ] || [ "$1" = "--BUILDNUM" ]; then
		if [ "${BUILD_NUMBER}" -ne 0 ]; then
			PRNERR "Already --buildnum(-b) option is specified(${BUILD_NUMBER})."
			exit 1
		fi
		shift
		if [ -z "$1" ]; then
			PRNERR "--buildnum(-b) option need parameter."
			exit 1
		fi
		if echo "$1" | grep -q "[^0-9]"; then
			PRNERR "--buildnum(-b) option parameter must be number(and not equal zero)."
			exit 1
		fi
		if [ "$1" -eq 0 ]; then
			PRNERR "--buildnum(-b) option parameter must be number(and not equal zero)."
			exit 1
		fi
		BUILD_NUMBER="$1"

	elif [ "$1" = "-y" ] || [ "$1" = "-Y" ] || [ "$1" = "--yes" ] || [ "$1" = "--YES" ]; then
		if [ "${NO_INTERACTIVE}" -ne 0 ]; then
			PRNERR "Already --yes(-y) option is specified."
			exit 1
		fi
		NO_INTERACTIVE=1

	else
		PRNERR "Unknown option $1."
		exit 1
	fi
	shift
done

#
# Check parameters
#
# [NOTE]
# APK package revision starts "0", it is default value.
#
if [ -z "${BUILD_NUMBER}" ]; then
	BUILD_NUMBER=0
elif [ "${BUILD_NUMBER}" -gt 0 ]; then
	BUILD_NUMBER=$((BUILD_NUMBER - 1))
fi

#--------------------------------------------------------------
# Welcome message and confirming for interactive mode
#--------------------------------------------------------------
if [ "${NO_INTERACTIVE}" -eq 0 ] && [ "${IS_CLEAN}" -ne 1 ]; then
	echo "---------------------------------------------------------------"
	echo " Do you change these file and commit to github?"
	echo " - ChangeLog     modify / add changes like dch tool format"
	echo " - Git TAG       stamp git tag for release"
	echo "---------------------------------------------------------------"
	IS_CONFIRMED=0
	while [ "${IS_CONFIRMED}" -eq 0 ]; do
		printf '[INPUT] Confirm (y/n) : '
		read -r CONFIRM

		if [ "${CONFIRM}" = "y" ] || [ "${CONFIRM}" = "Y" ] || [ "${CONFIRM}" = "yes" ] || [ "${CONFIRM}" = "YES" ]; then
			IS_CONFIRMED=1
		elif [ "${CONFIRM}" = "n" ] || [ "${CONFIRM}" = "N" ] || [ "${CONFIRM}" = "no" ] || [ "${CONFIRM}" = "NO" ]; then
			PRNINFO "Interrupt this processing, bye..."
			exit 0
		fi
	done
	echo ""
fi

#==============================================================
# Remove directory for clenup
#==============================================================
PRNTITLE "Remove old work directory for packaging"

if [ -d "${APK_TOPDIR}" ] || [ -f "${APK_TOPDIR}" ]; then
	rm -rf "${APK_TOPDIR}"
fi
PRNSUCCESS "Removed ${APK_TOPDIR}"

#
# Clean mode -> finish
#
if [ "${IS_CLEAN}" -eq 1 ]; then
	exit 0
fi

#==============================================================
# Get package information
#==============================================================
PRNTITLE "Get package information"

#--------------------------------------------------------------
# Check Environments and variables
#--------------------------------------------------------------
# [NOTE]
# This script sets variables in the APKBUILD file from environment
# and variables.
# Use the following environment variables and variables.
#
#	DEBEMAIL			: Used for creating RSA keys
#	DEBFULLNAME			: Used for creating RSA keys
#	GITHUB_REF_TYPE		: This environment variable is set by GithubActions.
#						  For release tagging, this value is set to "tag".
#						  Unset and otherwise("branch") indicate that the call was
#						  not made by the release process.
#	ABUILD_OPT			: abuild common option for running as root user.
#
PRNINFO "Check Environments and variables"

if [ -z "${DEBEMAIL}" ]; then
	PRNWARN "DEBEMAIL environment is not set, so set default \"${USER}@$(hostname)\""
	DEBEMAIL="${USER}@$(hostname)"
fi

if [ -z "${DEBFULLNAME}" ]; then
	PRNWARN "DEBFULLNAME environment is not set, so set default \"${USER}\"."
	DEBFULLNAME="${USER}"
fi

if [ -z "${GITHUB_REF_TYPE}" ] || [ "${GITHUB_REF_TYPE}" != "tag" ]; then
	SOURCE_ARCHIVE_URL=""
	SOURCE_ARCHIVE_SEPARATOR=""
else
	SOURCE_ARCHIVE_URL="https://\$_git_domain/\$_organization_name/\$_repository_name/archive/refs/tags/v\$pkgver.tar.gz"
	SOURCE_ARCHIVE_SEPARATOR="::"
fi

#--------------------------------------------------------------
# Check running as root user and Set APKBUILD option
#--------------------------------------------------------------
PRNINFO "Check running as root user and Set APKBUILD option"

#
# Check running as root user
#
RUN_USER_ID=$(id -u)

if [ -n "${RUN_USER_ID}" ] && [ "${RUN_USER_ID}" -eq 0 ]; then
	SUDO_CMD=""
else
	SUDO_CMD="sudo"
fi

# [NOTE]
# The abuild tool drains errors when run as root.
# To avoid this, the "-F" option is required.
# If you need verbose message, you can add "-v" option here.
#
if [ -n "${RUN_USER_ID}" ] && [ "${RUN_USER_ID}" -eq 0 ]; then
	ABUILD_OPT="-F"
else
	ABUILD_OPT=""
fi

#--------------------------------------------------------------
# Check package name and version
#--------------------------------------------------------------
PRNINFO "Check package name and version"

PACKAGE_NAME=$(head -n 1 "${SRCTOP}"/ChangeLog | awk '{print $1}' | tr -d '\n')
PACKAGE_VERSION=$(head -n 1 "${SRCTOP}"/ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g' | tr -d '\n')

PACKAGE_PHPMAJORVERSION=$(php -r 'echo PHP_MAJOR_VERSION;')
PACKAGE_PHPMINORVERSION=$(php -r 'echo PHP_MINOR_VERSION;')

if [ "${PACKAGE_PHPMAJORVERSION}" = "8" ] && [ "${PACKAGE_PHPMINORVERSION}" = "0" ]; then
	#
	# 8.0 -> 8
	#
	PACKAGE_PHPVERSION="${PACKAGE_PHPMAJORVERSION}"
else
	#
	# 8.1/8.2/... -> 81/82/...
	#
	PACKAGE_PHPVERSION="${PACKAGE_PHPMAJORVERSION}${PACKAGE_PHPMINORVERSION}"
fi
PACKAGE_PHPVER_NAME=$(echo "${PACKAGE_NAME}" | sed -e "s/php/php${PACKAGE_PHPVERSION}/g")
PACKAGE_DESC="k2hash extension for PHP${PACKAGE_PHPMAJORVERSION}.${PACKAGE_PHPMINORVERSION}"

if [ -z "${PACKAGE_NAME}" ] || [ -z "${PACKAGE_PHPVER_NAME}" ] || [ -z "${PACKAGE_VERSION}" ]; then
	PRNERR "Failed to get Package name and version."
	exit 1
fi

#--------------------------------------------------------------
# Print information
#--------------------------------------------------------------
#
# Information
#
PRNINFO "Information for building APK packages"
echo ""
echo "    PACKAGE NAME        = ${PACKAGE_NAME} / ${PACKAGE_PHPVER_NAME}"
echo "    PACKAGE DESCRIPTION = ${PACKAGE_DESC}"
echo "    PACKAGE VERSION     = ${PACKAGE_VERSION}"
echo "    BUILD NUMBER        = ${BUILD_NUMBER}"
echo "    PHP VERSION         = ${PACKAGE_PHPVERSION}"
echo ""
echo "    APK_TOPDIR          = ${APK_TOPDIR}"
echo "    NO_INTERACTIVE      = ${NO_INTERACTIVE}"
echo ""
echo "    GITHUB_REF_TYPE     = ${GITHUB_REF_TYPE}"
echo "    SOURCE_ARCHIVE_URL  = ${SOURCE_ARCHIVE_URL}"
echo "    BUILD_NUMBER        = ${BUILD_NUMBER}"
echo "    ABUILD_OPT          = ${ABUILD_OPT}"
echo ""

PRNSUCCESS "Got package information"

#==============================================================
# Main processing
#==============================================================
cd "${SRCTOP}" || exit 1

#--------------------------------------------------------------
# Check untracked files
#--------------------------------------------------------------
PRNTITLE "Check untracked files"

# [NOTE]
# When using actions/checkout@v1, suppress the following errors.
# "Error: fatal: unsafe repository ('...' is owned by someone else)"
#
git config --global --add safe.directory "${GITHUB_WORKSPACE}"

if [ -n "$(git status --untracked-files=no --porcelain 2>&1)" ]; then
	PRNWARN "Some files are in untracked state. Packages are created for testing, but must not be published."
	PRNFAILURE "Check untracked files, but continue..."
else
	PRNSUCCESS "No untracked files"
fi

#--------------------------------------------------------------
# Run phpize and configure
#--------------------------------------------------------------
PRNTITLE "Run phpize"

if ! phpize; then
	PRNERR "Failed to run phpize."
	exit 1
fi
PRNSUCCESS "phpize done"

PRNTITLE "Run configure"

if ! ./configure; then
	PRNERR "Failed to run configure."
	exit 1
fi
PRNSUCCESS "configure done"

#--------------------------------------------------------------
# Create package top directories
#--------------------------------------------------------------
PRNTITLE "Create work directories for packaging"

if ! mkdir "${APK_TOPDIR}"; then
	PRNERR "Could not create ${APK_TOPDIR} dicretory."
	exit 1
fi

PRNSUCCESS "Created ${APK_TOPDIR}"

#---------------------------------------------------------------
# Create RSA key for signing
#---------------------------------------------------------------
PRNTITLE "Create RSA key for signing"

#
# Determining the RSA key location directory
#
# [NOTE]
# This directory path depends on the apk-tools version.
# It is different for 2.14.4 and later and previous versions.
#
APKTOOLS_ALL_VER=$(apk list apk-tools | awk '{print $1}' | tail -1)
APKTOOLS_MAJOR_VER=$(echo "${APKTOOLS_ALL_VER}" | sed -e 's#^[[:space:]]*apk-tools-##g' -e 's#-# #g' -e 's#\.# #g' | awk '{print $1}')
APKTOOLS_MINOR_VER=$(echo "${APKTOOLS_ALL_VER}" | sed -e 's#^[[:space:]]*apk-tools-##g' -e 's#-# #g' -e 's#\.# #g' | awk '{print $2}')
APKTOOLS_PATCH_VER=$(echo "${APKTOOLS_ALL_VER}" | sed -e 's#^[[:space:]]*apk-tools-##g' -e 's#-# #g' -e 's#\.# #g' | awk '{print $3}')
if [ -z "${APKTOOLS_MAJOR_VER}" ] || [ -z "${APKTOOLS_MINOR_VER}" ] || [ -z "${APKTOOLS_PATCH_VER}" ]; then
	echo "[ERROR] Could not get aok-tools package version." 1>&2
	exit 1
fi
APKTOOLS_MIX_VER=$((APKTOOLS_MAJOR_VER * 1000 * 1000 + APKTOOLS_MINOR_VER * 1000 + APKTOOLS_PATCH_VER))
if [ "${APKTOOLS_MIX_VER}" -lt 2014004 ]; then
	RSA_KEYS_DIR="${APK_TOPDIR}"
else
	RSA_KEYS_DIR="${APK_KEYS_DIR}"
fi

#
# Check "${HOME}/.abuild" directory
#
if [ -d "${APKBUILD_CONFIG_DIR}" ] || [ -f "${APKBUILD_CONFIG_DIR}" ]; then
	rm -rf "${APKBUILD_CONFIG_DIR}"
fi

#
# Create temporary RSA key
#
# [NOTE]
# The keys that are created are the following files:
#	${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-<unixtime(hex)>.rsa
#	${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-<unixtime(hex)>.rsa.pub
#
if ({ PACKAGER="${DEBFULLNAME} <${DEBEMAIL}>" abuild-keygen -a -n 2>&1 || echo > "${PIPEFAILURE_FILE}"; } | sed -e 's#^#    #') && rm "${PIPEFAILURE_FILE}" >/dev/null 2>&1; then
	PRNERR "Failed to create temporary RSA key for building APK packages."
	exit 1
fi

#
# Check and Copy RSA keys
#
if ! find "${APKBUILD_CONFIG_DIR}" -name "${DEBEMAIL}"-\*\.rsa | grep -q "${DEBEMAIL}"; then
	PRNERR "Not found ${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-<unixtime(hex)>.rsa files."
	exit 1
fi
if ! find "${APKBUILD_CONFIG_DIR}" -name "${DEBEMAIL}"-\*\.rsa\.pub | grep -q "${DEBEMAIL}"; then
	PRNERR "Not found ${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-<unixtime(hex)>.rsa.pub files."
	exit 1
fi
if ! /bin/sh -c "${SUDO_CMD} cp -p ${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-*.rsa ${RSA_KEYS_DIR} >/dev/null 2>&1"; then
	PRNERR "Failed to copy RSA private key(${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-<unixtime(hex)>.rsa) to ${RSA_KEYS_DIR} directory."
	exit 1
fi
if ! /bin/sh -c "${SUDO_CMD} cp -p ${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-*.rsa.pub ${RSA_KEYS_DIR} >/dev/null 2>&1"; then
	PRNERR "Failed to copy RSA public key(${APKBUILD_CONFIG_DIR}/${DEBEMAIL}-<unixtime(hex)>.rsa.pub) to ${RSA_KEYS_DIR} directory."
	exit 1
fi

#
# Remove abuild configuration directory(with abuild.conf)
#
# [NOTE]
# When building the package, the RSA key is specified by an environment
# variable, so the presence of this configuration file is misleading.
#
rm -rf "${APKBUILD_CONFIG_DIR}"

#
# Set file name/key contents to variables
#
APK_PACKAGE_PRIV_KEYNAME="$(find "${RSA_KEYS_DIR}" -name "${DEBEMAIL}"-\*\.rsa 2>/dev/null | head -1 | sed -e "s#${RSA_KEYS_DIR}/##g" | tr -d '\n')"
APK_PACKAGE_PUB_KEYNAME="$(find "${RSA_KEYS_DIR}" -name "${DEBEMAIL}"-\*\.rsa\.pub 2>/dev/null | head -1 | sed -e "s#${RSA_KEYS_DIR}/##g" | tr -d '\n')"

#
# Information
#
echo ""
echo "    RSA private key : ${RSA_KEYS_DIR}/${APK_PACKAGE_PRIV_KEYNAME}"
echo "    RSA public key  : ${RSA_KEYS_DIR}/${APK_PACKAGE_PUB_KEYNAME}"
echo ""

PRNSUCCESS "Created RSA keys"

#--------------------------------------------------------------
# Make source tar.gz
#--------------------------------------------------------------
PRNTITLE "Create base tar ball of source files or URL"

if [ -n "${GITHUB_REF_TYPE}" ] && [ "${GITHUB_REF_TYPE}" = "tag" ]; then
	#
	# Source archive is URL (not local archive file)
	#
	# ex. https://github.com/yahoojapan/xxx_phpext/archive/refs/tags/v1.0.0.tar.gz
	#     extracted top directory name -> xxx_phpext-1.0.0
	#
	PRNSUCCESS "Created source code URL ${SOURCE_ARCHIVE_URL}"

elif [ -d "${SRCTOP}/.git" ] && [ "$(git status -s 2>&1 | wc -l)" -eq 0 ]; then
	#
	# No untracked files, make source package(tar.gz) by git archive
	#
	if ! git archive HEAD --prefix="${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}"/ --output="${APK_TOPDIR}/${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}".tar.gz; then
		PRNERR "Could not make source tar ball(${APK_TOPDIR}/${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}.tar.gz) from github repository."
		exit 1
	fi
	PRNSUCCESS "Created ${APK_TOPDIR}/${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}.tar.gz"

else
	#
	# Found untracked files or Not have .git directory, source code package(tar.gz) like "make dist" and copy it
	#
	# [NOTICE]
	# PHP Extension is built using "phpize(config.m4)".
	# The "Makefile" created by "phpize" does not have "make dist",
	# so the source code expanded by "Github Actions" is created in
	# advance as "<DIRNAME>_allsource.tar.gz" with "phpext_helper.sh".
	# Extract this "<DIRNAME>_allsource.tar.gz" and create a file
	# similar to "make dist" here.
	#
	_SOURCECODE_DIRNAME=$(basename "${SRCTOP}")
	_ALL_SOURCE_TARGZ_FILENAME="${_SOURCECODE_DIRNAME}_allsource.tar.gz"

	if [ ! -f "${SRCTOP}/${_ALL_SOURCE_TARGZ_FILENAME}" ]; then
		PRNERR "Not found all source code tar.gz file(${SRCTOP}/${_ALL_SOURCE_TARGZ_FILENAME})."
		exit 1
	fi
	if ! tar xvfz "${SRCTOP}/${_ALL_SOURCE_TARGZ_FILENAME}" -C /tmp/ >/dev/null 2>&1; then
		PRNERR "Failed to expand all source code tar.gz file(${SRCTOP}/${_ALL_SOURCE_TARGZ_FILENAME}) to /tmp."
		exit 1
	fi
	if [ ! -d /tmp/"${_SOURCECODE_DIRNAME}" ]; then
		PRNERR "Not found expanded all source code directory(/tmp/${_SOURCECODE_DIRNAME}) from file(${SRCTOP}/${_ALL_SOURCE_TARGZ_FILENAME})."
		exit 1
	fi
	rm -rf /tmp/"${_SOURCECODE_DIRNAME}"/.git

	if ! mv /tmp/"${_SOURCECODE_DIRNAME}" /tmp/"${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}"; then
		PRNERR "Failed to rename from /tmp/${_SOURCECODE_DIRNAME} directory to /tmp/${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}."
		exit 1
	fi
	if ! (cd /tmp || exit 1; tar cvfz "${APK_TOPDIR}/${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}".tar.gz "${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}"); then
		PRNERR "Failed to create ${APK_TOPDIR}/${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}.tar.gz."
		exit 1
	fi
	rm -rf /tmp/"${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}"

	PRNSUCCESS "Created ${APK_TOPDIR}/${PACKAGE_PHPVER_NAME}-${PACKAGE_VERSION}.tar.gz"
fi

#---------------------------------------------------------------
# Copy extra files
#---------------------------------------------------------------
# [NOTE]
# If you have files to copy under "<package build to pdirectory>/apk_build"
# directory(includes in your package), you can prepare
# "buildutils/alpine_build_copy.conf" file and lists target files
# int it.
# The file names in this configuration file list with relative paths
# from the source top directory.
#	ex)	src/myfile
#		lib/mylib
#
if [ -f "${EXTRA_COPY_FILES_CONF}" ]; then
	PRNTITLE "Copy extra files"

	EXTRA_COPY_FILES=$(sed -e 's/#.*$//g' -e 's/^[[:space:]]*//g' -e 's/[[:space:]]*$//g' -e '/^$/d' "${EXTRA_COPY_FILES_CONF}")
	for _extra_file in ${EXTRA_COPY_FILES}; do
		if [ ! -f "${SRCTOP}/${_extra_file}" ]; then
			PRNERR "Not found ${SRCTOP}/${_extra_file} file for extra copy."
			exit 1
		fi
		if ! cp -p "${SRCTOP}/${_extra_file}" "${APK_TOPDIR}"; then
			PRNERR "Failed to copy ${SRCTOP}/${_extra_file} file to ${APK_TOPDIR}."
			exit 1
		fi
	done

	PRNSUCCESS "Copied extra files"
fi

#---------------------------------------------------------------
# Create APKBUILD file
#---------------------------------------------------------------
PRNTITLE "Create APKBUILD file"

#
# Create APKBUILD file from template
#
PRNINFO "Create APKBUILD file from template"

if ! sed -e "s#%%PACKAGE_PHPVER_NAME%%#${PACKAGE_PHPVER_NAME}#g"							\
		-e "s#%%PACKAGE_VERSION%%#${PACKAGE_VERSION}#g"										\
		-e "s#%%BUILD_NUMBER%%#${BUILD_NUMBER}#g"											\
		-e "s#%%PACKAGE_DESC%%#${PACKAGE_DESC}#g"											\
		-e "s#%%PACKAGE_PHPVERSION%%#${PACKAGE_PHPVERSION}#g"								\
		-e "s#%%SOURCE_ARCHIVE_URL%%#${SOURCE_ARCHIVE_SEPARATOR}${SOURCE_ARCHIVE_URL}#g"	\
		"${APKBUILD_TEMPLATE_FILE}" > "${APKBUILD_FILE}"									; then

	PRNERR "Failed to create APKBUILD file in ${APK_TOPDIR} directory."
	exit 1
fi

#
# Add checksum to APKBUILD file
#
PRNINFO "Add checksum to APKBUILD file"

cd "${APK_TOPDIR}" || exit 1

if ! /bin/sh -c "abuild ${ABUILD_OPT} checksum"; then
	PRNERR "Failed to add checksum to APKBUILD file(${APKBUILD_FILE})."
	exit 1
fi

#
# Get Arch name for a part of package directory path
#
PRNINFO "Get Arch name"

ARCH_NAME=$(grep '^arch=' "${APKBUILD_FILE}" | sed -e 's#^arch=##g' -e 's#"##g' | tail -1 | tr -d '\n')

#
# Print APKBUILD file
#
PRNSUCCESS "Created APKBUILD file(${APKBUILD_FILE})"
echo ""
sed -e 's#^#    #g' "${APKBUILD_FILE}"
echo ""

#---------------------------------------------------------------
# Create packages
#---------------------------------------------------------------
PRNTITLE "Build APK packages."

#
# build APK packages
#
if ({ /bin/sh -c "PACKAGER_PRIVKEY=${RSA_KEYS_DIR}/${APK_PACKAGE_PRIV_KEYNAME} abuild ${ABUILD_OPT} -r -P $(pwd)" || echo > "${PIPEFAILURE_FILE}"; } | sed -e 's#^#    #') && rm "${PIPEFAILURE_FILE}" >/dev/null 2>&1; then
	PRNERR "Failed to create APK packages."
	exit 1
fi
PRNSUCCESS "Built APK packages"

#
# Show APK packages
#
for _one_pkg in "${APK_TOPDIR}"/"${SRCTOP_DIRNAME}"/"${ARCH_NAME}"/*.apk; do
	echo ""
	echo "[INFO] Dump APK package : ${_one_pkg}"

	if ({ tar tvfz "${_one_pkg}" 2>/dev/null || echo > "${PIPEFAILURE_FILE}"; } | sed -e 's#^#    #') && rm "${PIPEFAILURE_FILE}" >/dev/null 2>&1; then
		PRNERR "Failed to extract ${_one_pkg} APK package."
		exit 1
	fi
done

#----------------------------------------------------------
# Copy packages
#----------------------------------------------------------
if [ ! -d "${PKG_TOPDIR}" ]; then
	PRNTITLE "Create ${PKG_TOPDIR} directory"
	if ! mkdir -p "${PKG_TOPDIR}"; then
		PRNERR "Failed to create ${PKG_TOPDIR} directory"
		exit 1
	fi
	PRNSUCCESS "Created ${PKG_TOPDIR} directory"
fi

#
# Copy APK packages
#
PRNTITLE "Copy created APK packages to packages directory"

if ! cp -p "${APK_TOPDIR}"/"${SRCTOP_DIRNAME}"/"${ARCH_NAME}"/*.apk "${PKG_TOPDIR}"; then
	PRNERR "Failed to copy ${APK_TOPDIR}/${SRCTOP_DIRNAME}/${ARCH_NAME}/*.apk package to ${PKG_TOPDIR} directory."
	exit 1
fi
ls -la "${PKG_TOPDIR}"

PRNSUCCESS "Copied created APK packages to packages directory"

#---------------------------------------------------------------
# Finish
#---------------------------------------------------------------
echo ""
PRNSUCCESS "You can find APK package in ${PKG_TOPDIR} directory"
echo ""

exit 0

#
# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noexpandtab sw=4 ts=4 fdm=marker
# vim<600: noexpandtab sw=4 ts=4
#
