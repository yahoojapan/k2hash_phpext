#!/bin/sh
#
# Utility tools for building PHP packages by AntPickax
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
# CREATE:   Fri, Feb 18 2022
# REVISION: 1.1
#

#==============================================================
# Autobuild for PHP rpm package
#==============================================================
#
# Instead of pipefail(for shells not support "set -o pipefail")
#
#PIPEFAILURE_FILE="/tmp/.pipefailure.$(od -An -tu4 -N4 /dev/random | tr -d ' \n')"

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
SRCTOP=$(cd "${SCRIPTDIR}"/.. || exit 1; pwd)

RPM_TOPDIR="${SRCTOP}/rpmbuild"
PKG_TOPDIR="${SRCTOP}/packages"

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

#----------------------------------------------------------
# Utility: Usage
#----------------------------------------------------------
func_usage()
{
	echo ""
	echo "Usage:  $1 [--help(-h)] [--clean(-c)] [--buildnum(-b) <build number>] [--yes(-y)]"
	echo "        --help(-h)                     print help"
	echo "        --clean(-c)                    only clean work directory."
	echo "        --buildnum(-b) <build number>  specify build number for packaging(default 1)"
	echo "        --yes(-y)                      runs no interactive mode."
	echo ""
}

#----------------------------------------------------------
# Utilities for message
#----------------------------------------------------------
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

#----------------------------------------------------------
# Parse options
#----------------------------------------------------------
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
if [ "${BUILD_NUMBER}" -eq 0 ]; then
	BUILD_NUMBER=1
fi

#----------------------------------------------------------
# Welcome message and confirming for interactive mode
#----------------------------------------------------------
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

#----------------------------------------------------------
# Remove directory for clenup
#----------------------------------------------------------
PRNTITLE "Remove old work directory for packaging"

rm -rf "${RPM_TOPDIR}"
PRNSUCCESS "Removed ${RPM_TOPDIR}"

#
# Clean mode -> finish
#
if [ "${IS_CLEAN}" -eq 1 ]; then
	exit 0
fi

#----------------------------------------------------------
# Start building
#----------------------------------------------------------
cd "${SRCTOP}" || exit 1

#----------------------------------------------------------
# Check ~/.rpmmacros file
#----------------------------------------------------------
PRNTITLE "Check ~/.rpmmacros file"

if [ -f "${HOME}/.rpmmacros" ]; then
	PRNERR "Found \"${HOME}/.rpmmacros\" file."
	echo "  Checking with \"check-rpaths\" may result in an error due to the existence"
	echo "  of the \"${HOME}/.rpmmacros\" file."
	echo "  If you get that error, delete the \"${HOME}/.rpmmacros\" file"
	echo "  and try again."
	echo ""
	exit 1
fi
PRNSUCCESS "${HOME}/.rpmmacros file does not exist."

#----------------------------------------------------------
# Check untracked files
#----------------------------------------------------------
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

#----------------------------------------------------------
# Run phpize and configure
#----------------------------------------------------------
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

#----------------------------------------------------------
# Create package top directories
#----------------------------------------------------------
PRNTITLE "Create work directories for packaging"

_SUB_RPM_DIRS="BUILD BUILDROOT RPM SOURCES SPECS SRPMS"
for _SUB_RPM_DIR in ${_SUB_RPM_DIRS}; do
	if ! mkdir -p "${RPM_TOPDIR}/${_SUB_RPM_DIR}"; then
		PRNERR "Could not create ${RPM_TOPDIR}/${_SUB_RPM_DIR} directory."
		exit 1
	fi
done

PRNSUCCESS "Created ${RPM_TOPDIR}"

#----------------------------------------------------------
# Get package name and version/build number
#----------------------------------------------------------
PRNTITLE "Get package information"

PACKAGE_NAME=$(head -n 1 ./ChangeLog | awk '{print $1}' | tr -d '\n')
PACKAGE_VERSION=$(head -n 1 ./ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g' | tr -d '\n')

echo "-----------------------------------------------------------"
echo " Package name     : ${PACKAGE_NAME}"
echo " Package version  : ${PACKAGE_VERSION}"
echo " Build number     : ${BUILD_NUMBER}"
echo "-----------------------------------------------------------"
PRNSUCCESS "Got package information"

#----------------------------------------------------------
# Make source tar.gz
#----------------------------------------------------------
PRNTITLE "Create base tar ball of source files"

if [ -d "${SRCTOP}/.git" ] && [ "$(git status -s 2>&1 | wc -l)" -eq 0 ]; then
	#
	# No untracked files, make source package(tar.gz) by git archive
	#
	if ! git archive HEAD --prefix="${PACKAGE_NAME}-${PACKAGE_VERSION}"/ --output="${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}".tar.gz; then
		PRNERR "Could not make source tar ball(${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}.tar.gz) from github repository."
		exit 1
	fi
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

	if ! mv /tmp/"${_SOURCECODE_DIRNAME}" /tmp/"${PACKAGE_NAME}-${PACKAGE_VERSION}"; then
		PRNERR "Failed to rename from /tmp/${_SOURCECODE_DIRNAME} directory to /tmp/${PACKAGE_NAME}-${PACKAGE_VERSION}."
		exit 1
	fi
	if ! (cd /tmp || exit 1; tar cvfz "${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}".tar.gz "${PACKAGE_NAME}-${PACKAGE_VERSION}"); then
		PRNERR "Failed to create ${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}.tar.gz."
		exit 1
	fi
	rm -rf /tmp/"${PACKAGE_NAME}-${PACKAGE_VERSION}"
fi

PRNSUCCESS "Created ${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}.tar.gz"

#----------------------------------------------------------
# Copy spec file
#----------------------------------------------------------
PRNTITLE "Copy spec file to ${SRCTOP}"

if ! cp "${SRCTOP}"/buildutils/*.spec "${SRCTOP}"/; then
	PRNERR "Could not find and feiled to copy spec files."
	exit 1
fi
PRNSUCCESS "Copied spec file to ${SRCTOP}"

#----------------------------------------------------------
# Run rpmbuild
#----------------------------------------------------------
PRNTITLE "Run rpmbuild"

if ! rpmbuild -vv -ba --define "_topdir ${RPM_TOPDIR}" --define "_prefix /usr" --define "_mandir /usr/share/man" --define "_defaultdocdir /usr/share/doc" --define "package_revision ${BUILD_NUMBER}" ./*.spec; then
	PRNERR "Failed to build rpm packages by rpmbuild."
	exit 1
fi
PRNSUCCESS "rpmbuild done"

#----------------------------------------------------------
# Check packages
#----------------------------------------------------------
PRNTITLE "Check created RPM packages"

echo ""
# shellcheck disable=SC2012
ls -la "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm | sed -e 's/^/    /g'
echo ""

# shellcheck disable=SC2012
_rpm_package_count="$(ls -1 "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm 2>/dev/null | wc -l)"
if [ "${_rpm_package_count}" -ne 3 ] && [ "${_rpm_package_count}" -ne 4 ]; then
	PRNERR "There are too or few created RPM packages(*.rpm)."
	exit 1
fi

for _rpm_file in "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm; do
	if test ! -e "${_rpm_file}"; then
		continue
	fi
	echo "-----------------------------------------------------------"
	echo "Package: ${_rpm_file}"
	echo "-----------------------------------------------------------"
	rpm -qpl "${_rpm_file}" | sed -e 's/^/    /g'
	echo ""
	rpm -qpi "${_rpm_file}" | sed -e 's/^/    /g'
	echo ""
done

PRNSUCCESS "Checked package files"

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

PRNTITLE "Copy created RPM packages to packages directory"

if ! cp -p "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm "${PKG_TOPDIR}"; then
	PRNERR "Failed to copy packages to ${PKG_TOPDIR}"
	exit 1
fi
PRNSUCCESS "Copied RPM packages to ${PKG_TOPDIR}"

#----------------------------------------------------------
# finish
#----------------------------------------------------------
PRNTITLE "Install Summary"

PRNSUCCESS "All processing is succeed"
echo "[SUCCEED] You can find ${PACKAGE_NAME} ${PACKAGE_VERSION}-${BUILD_NUMBER} version rpm package in ${PKG_TOPDIR} directory."
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
