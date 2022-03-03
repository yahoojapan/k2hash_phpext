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
# CREATE:   Tue, Feb 22 2022
# REVISION:
#

#----------------------------------------------------------
# Common variables
#----------------------------------------------------------
PRGNAME=$(basename "$0")
SCRIPTDIR=$(dirname "$0")
SCRIPTDIR=$(cd "${SCRIPTDIR}" || exit 1; pwd)
SRCTOP=$(cd "${SCRIPTDIR}"/.. || exit 1; pwd)
DEB_TOPDIR="${SRCTOP}/debian_build"
PKG_TOPDIR="${SRCTOP}/packages"

#----------------------------------------------------------
# Utility: Usage
#----------------------------------------------------------
func_usage()
{
	echo ""
	echo "Usage:  $1 [--yes(-y)] [--clean(-c)] [--help(-h)] [--copy-common-package(-ccp)]"
	echo "        --yes(-y)                     runs no interactive mode."
	echo "        --clean(-c)                   only clean work directory."
	echo "        --copy-common-package(-ccp)   copy common package to packages directory."
	echo "        --help(-h)                    print help"
	echo ""
	echo "Note:  Only if \"--copy-common-package(-ccp)\" is specified, the following"
	echo "       packages will be copied to the packages directory."
	echo "           php-pecl-k2hash_X.Y.Z-N_****.deb"
	echo "           php-pecl-k2hash-all-dev_X.Y.Z-N_all.deb"
	echo "       These packages are PHP version independent and common, so use this"
	echo "       option to avoid conflicts."
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
IS_CLEAN=0
IS_INTERACTIVE=1
IS_COPY_COMMON_PKGS=0
while [ $# -ne 0 ]; do
	if [ "X$1" = "X" ]; then
		break
	elif [ "X$1" = "X-h" ] || [ "X$1" = "X-H" ] || [ "X$1" = "X--help" ] || [ "X$1" = "X--HELP" ]; then
		func_usage "${PRGNAME}"
		exit 0
	elif [ "X$1" = "X-c" ] || [ "X$1" = "X-C" ] || [ "X$1" = "X--clean" ] || [ "X$1" = "X--CLEAN" ]; then
		IS_CLEAN=1
	elif [ "X$1" = "X-y" ] || [ "X$1" = "X-Y" ] || [ "X$1" = "X--yes" ] || [ "X$1" = "X--YES" ]; then
		IS_INTERACTIVE=0
	elif [ "X$1" = "X-ccp" ] || [ "X$1" = "X-CCP" ] || [ "X$1" = "X--copy-common-package" ] || [ "X$1" = "X--COPY-COMMON-PACKAGE" ]; then
		IS_COPY_COMMON_PKGS=1
	else
		prn_fauilure "Unknown option - $1."
		exit 1
	fi
	shift
done

#----------------------------------------------------------
# Welcome message and confirming for interactive mode
#----------------------------------------------------------
if [ "${IS_INTERACTIVE}" -eq 1 ] && [ "${IS_CLEAN}" -ne 1 ]; then
	echo "---------------------------------------------------------------"
	echo " Do you change these file and commit to github?"
	echo " - ChangeLog              modify / add changes like dch tool format"
	echo " - Git TAG                stamp git tag for release"
	echo "---------------------------------------------------------------"
	while true; do
		printf "Confirm: [y/n] "
		read -r CONFIRM

		if [ "X${CONFIRM}" = "XY" ] || [ "X${CONFIRM}" = "Xy" ]; then
			break;
		elif [ "X${CONFIRM}" = "XN" ] || [ "X${CONFIRM}" = "Xn" ]; then
			echo "Bye..."
			exit 1
		fi
	done
	echo ""
fi

#----------------------------------------------------------
# Remove directory for clenup
#----------------------------------------------------------
prn_title "Remove old work directory for packaging"
rm -rf "${DEB_TOPDIR}"
prn_success "Removed ${DEB_TOPDIR}"
prn_groupend

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
# Check untracked files
#----------------------------------------------------------
prn_title "Check untracked files"
if [ -n "$(git status --untracked-files=no --porcelain 2>&1)" ]; then
	prn_fauilure "Some files are untracked."
	exit 1
fi
prn_success "No untracked files"
prn_groupend

#----------------------------------------------------------
# Run phpize and configure
#----------------------------------------------------------
prn_title "Run phpize"
if ! phpize; then
	prn_fauilure "Failed to run phpize."
	exit 1
fi
prn_success "phpize done"
prn_groupend

prn_title "Run configure"
if ! ./configure; then
	prn_fauilure "Failed to run configure."
	exit 1
fi
prn_success "configure done"
prn_groupend

#----------------------------------------------------------
# Create package top directory
#----------------------------------------------------------
prn_title "Create work directory for packaging"
if ! mkdir "${DEB_TOPDIR}"; then
	prn_fauilure "Could not create ${DEB_TOPDIR} dicretory."
	exit 1
fi
prn_success "Created ${DEB_TOPDIR}"
prn_groupend

#----------------------------------------------------------
# Get package name and version/build number
#----------------------------------------------------------
prn_title "Get package information"

PACKAGE_NAME=$(head -n 1 ./ChangeLog | awk '{print $1}')
PACKAGE_VERSION=$(head -n 1 ./ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g')
PACKAGE_RELEASE=$(head -n 1 ./ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/^.*-//g')
PACKAGE_PHPVERSION=$(php -r 'echo "".PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')
PACKAGE_PHPVER_NAME=$(echo "${PACKAGE_NAME}" | sed -s "s/php/php${PACKAGE_PHPVERSION}/g")

echo "-----------------------------------------------------------"
echo " Package name     : ${PACKAGE_NAME} / ${PACKAGE_PHPVER_NAME}"
echo " Package version  : ${PACKAGE_VERSION}"
echo " Package release  : ${PACKAGE_RELEASE}"
echo " PHP version      : ${PACKAGE_PHPVERSION}"
echo "-----------------------------------------------------------"
prn_success "done"
prn_groupend

#----------------------------------------------------------
# Make source tar.gz from git by archive
#----------------------------------------------------------
prn_title "Create base tar ball of source files"
if ! git archive HEAD --prefix="${PACKAGE_NAME}-${PACKAGE_VERSION}"/ --output="${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}".tar.gz; then
	prn_fauilure "Could not make source tar ball(${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}.tar.gz) from github repository."
	exit 1
fi
prn_success "Created ${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}.tar.gz"
prn_groupend

#----------------------------------------------------------
# Expand tar ball
#----------------------------------------------------------
prn_title "Expand base tar ball in work directory"
if ! tar xvfz "${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}".tar.gz -C "${DEB_TOPDIR}"/; then
	prn_fauilure "Could not expand tar ball(${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}.tar.gz)."
	exit 1
fi
prn_success "Expanded to ${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"
prn_groupend

#----------------------------------------------------------
# Delete unnecessary files and directories
#----------------------------------------------------------
prn_title "Remove unnecessary files and directories"
rm -rf "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/.github
rm -rf "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/buildutils
rm -f  "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/.gitignore
prn_success "Removed .github, .gitignore, buildutils/"
prn_groupend

#----------------------------------------------------------
# Setup debian directory
#----------------------------------------------------------
prn_title "Setup debian directories"
if ! mkdir "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian; then
	prn_fauilure "Could not create ${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}/debian dicretory."
	exit 1
fi
if ! mkdir "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/source; then
	prn_fauilure "Could not create ${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}/debian/source dicretory."
	exit 1
fi
if ! mkdir "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/upstream; then
	prn_fauilure "Could not create ${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}/debian/upstream dicretory."
	exit 1
fi
prn_success "Created ${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}/debian"
prn_groupend

prn_title "Copy files under debian directory"
if [ "$(cp ChangeLog                        "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/changelog            >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/copyright             "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/copyright            >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/k2hash.ini            "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/k2hash.ini           >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/"${PACKAGE_NAME}".php "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}/debian/${PACKAGE_NAME}".php  >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/rules                 "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/rules                >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/watch                 "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/watch                >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/control.in            "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/control.in           >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/source/format         "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/source/format        >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/source/local-options  "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/source/local-options >/dev/null 2>&1; echo $?)" -ne 0 ] ||
   [ "$(cp buildutils/upstream/metadata     "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}"/debian/upstream/metadata    >/dev/null 2>&1; echo $?)" -ne 0 ]; then

	prn_fauilure "Failed to copy files to ${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}/debian dicretories."
	exit 1
fi
prn_success "Copied changelog, copyright, k2hash.ini, php-pecl-k2hash.php, rules, watch, control.in, source/format, source/local-options, upstream/metadata"
prn_groupend

# [NOTE]
# The "control" file is created from "control.in", but when we run "dpkg-buildpackage",
# we need this file first.
# Thus, before running "dpkg-buildpackage", we need to prepare the "control" file.
# (But after running dpkg-buildpackage, the control file will be updated again)
#
prn_title "Pre-run gen-control"
cd "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}" || exit 1
if ! /usr/share/dh-php/gen-control; then
	prn_fauilure "Failed to run gen-control for initializing control file."
	exit 1
fi
prn_success "Generated ${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}/debian/control"
prn_groupend

#----------------------------------------------------------
# Create "orig" tar ball
#----------------------------------------------------------
prn_title "Create tar ball of original source file"
cd "${DEB_TOPDIR}" || exit 1
if ! tar cvfz "${PACKAGE_NAME}_${PACKAGE_VERSION}.orig.tar.gz" "${PACKAGE_NAME}-${PACKAGE_VERSION}"; then
	prn_fauilure "Failed to craete original source tar ball(${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}.orig.tar.gz)."
	exit 1
fi
prn_success "Created ${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}.orig.tar.gz"
prn_groupend

#----------------------------------------------------------
# Build packages
#----------------------------------------------------------
prn_title "Run dpkg-buildpackage for creating packages"
cd "${DEB_TOPDIR}/${PACKAGE_NAME}-${PACKAGE_VERSION}" || exit 1
if ! dpkg-buildpackage -us -uc; then
	prn_fauilure "Failed to create packages."
	exit 1
fi
prn_success "Created package files"
prn_groupend

#----------------------------------------------------------
# Check packages
#----------------------------------------------------------
prn_title "Check created debian packages"
cd "${SRCTOP}" || exit 1
echo ""
ls -la "${DEB_TOPDIR}"/*.deb
echo ""

# shellcheck disable=SC2012
if [ "$(ls -1 "${DEB_TOPDIR}/${PACKAGE_PHPVER_NAME}_${PACKAGE_VERSION}-${PACKAGE_RELEASE}"_*.deb 2>/dev/null    | wc -l)" -ne 1 ]; then
	prn_fauilure "There are too or few created debian packages(*.deb)."
	exit 1
fi
# shellcheck disable=SC2012
if [ "$(ls -1 "${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}-${PACKAGE_RELEASE}"_*.deb 2>/dev/null           | wc -l)" -ne 1 ]; then
	prn_fauilure "There are too or few created debian packages(*.deb)."
	exit 1
fi
# shellcheck disable=SC2012
if [ "$(ls -1 "${DEB_TOPDIR}/${PACKAGE_NAME}-all-dev_${PACKAGE_VERSION}-${PACKAGE_RELEASE}"_all.deb 2>/dev/null | wc -l)" -ne 1 ]; then
	prn_fauilure "There are too or few created debian packages(*.deb)."
	exit 1
fi

# shellcheck disable=SC2012
DEBIAN_PACKAGE_PHP=$(ls -1 "${DEB_TOPDIR}/${PACKAGE_PHPVER_NAME}_${PACKAGE_VERSION}-${PACKAGE_RELEASE}"_*.deb)
# shellcheck disable=SC2012
DEBIAN_PACKAGE_NORM=$(ls -1 "${DEB_TOPDIR}/${PACKAGE_NAME}_${PACKAGE_VERSION}-${PACKAGE_RELEASE}"_*.deb)
# shellcheck disable=SC2012
DEBIAN_PACKAGE_ALL=$(ls -1 "${DEB_TOPDIR}/${PACKAGE_NAME}-all-dev_${PACKAGE_VERSION}-${PACKAGE_RELEASE}"_all.deb)

echo "-----------------------------------------------------------"
echo "Package: ${DEBIAN_PACKAGE_PHP}"
echo "-----------------------------------------------------------"
dpkg -c "${DEBIAN_PACKAGE_PHP}" | sed -e 's/^/  /g'
echo ""
dpkg -I "${DEBIAN_PACKAGE_PHP}" | sed -e 's/^/  /g'
echo ""

echo "-----------------------------------------------------------"
echo "Package: ${DEBIAN_PACKAGE_NORM}"
echo "-----------------------------------------------------------"
dpkg -c "${DEBIAN_PACKAGE_NORM}" | sed -e 's/^/  /g'
echo ""
dpkg -I "${DEBIAN_PACKAGE_NORM}" | sed -e 's/^/  /g'
echo ""

echo "-----------------------------------------------------------"
echo "Package: ${DEBIAN_PACKAGE_ALL}"
echo "-----------------------------------------------------------"
dpkg -c "${DEBIAN_PACKAGE_ALL}" | sed -e 's/^/  /g'
echo ""
dpkg -I "${DEBIAN_PACKAGE_ALL}" | sed -e 's/^/  /g'
echo ""

prn_success "Checked package files"
prn_groupend

#----------------------------------------------------------
# Copy packages
#----------------------------------------------------------
if [ ! -d "${PKG_TOPDIR}" ]; then
	prn_title "Create ${PKG_TOPDIR} directory"
	if ! mkdir -p "${PKG_TOPDIR}"; then
		prn_fauilure "Failed to create ${PKG_TOPDIR} directory"
		exit 1
	fi
	prn_success "Created ${PKG_TOPDIR} directory"
	prn_groupend
fi

prn_title "Copy created debian packages to packages directory"
if ! cp -p "${DEBIAN_PACKAGE_PHP}" "${PKG_TOPDIR}"; then
	prn_fauilure "Failed to copy ${DEBIAN_PACKAGE_PHP} packages to ${PKG_TOPDIR}"
	exit 1
fi
echo "Copied ${DEBIAN_PACKAGE_PHP} package."

if [ "${IS_COPY_COMMON_PKGS}" -eq 1 ]; then
	if ! cp -p "${DEBIAN_PACKAGE_NORM}" "${PKG_TOPDIR}"; then
		prn_fauilure "Failed to copy ${DEBIAN_PACKAGE_NORM} packages to ${PKG_TOPDIR}"
		exit 1
	fi
	echo "Copied ${DEBIAN_PACKAGE_NORM} package."
else
	echo "Skip copying ${DEBIAN_PACKAGE_NORM} package."
fi

if [ "${IS_COPY_COMMON_PKGS}" -eq 1 ]; then
	if ! cp -p "${DEBIAN_PACKAGE_ALL}" "${PKG_TOPDIR}"; then
		prn_fauilure "Failed to copy ${DEBIAN_PACKAGE_ALL} packages to ${PKG_TOPDIR}"
		exit 1
	fi
	echo "Copied ${DEBIAN_PACKAGE_ALL} package."
else
	echo "Skip copying ${DEBIAN_PACKAGE_ALL} package."
fi
prn_success "Copied debian packages to ${PKG_TOPDIR}"
prn_groupend

#----------------------------------------------------------
# finish
#----------------------------------------------------------
prn_title "Install Summary"
prn_success "All processing is succeed"
echo "You can find ${PACKAGE_NAME} ${PACKAGE_VERSION}-${PACKAGE_RELEASE} version debian package in ${PKG_TOPDIR} directory."
echo ""
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
