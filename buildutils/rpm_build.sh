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
# CREATE:   Fri, Feb 18 2022
# REVISION:
#

#----------------------------------------------------------
# Common variables
#----------------------------------------------------------
PRGNAME=$(basename "$0")
SCRIPTDIR=$(dirname "$0")
SCRIPTDIR=$(cd "${SCRIPTDIR}" || exit 1; pwd)
SRCTOP=$(cd "${SCRIPTDIR}"/.. || exit 1; pwd)
RPM_TOPDIR="${SRCTOP}/rpmbuild"
PKG_TOPDIR="${SRCTOP}/packages"

#----------------------------------------------------------
# Utility: Usage
#----------------------------------------------------------
func_usage()
{
	echo ""
	echo "Usage:  $1 [--yes(-y)] [--clean(-c)] [--help(-h)]"
	echo "        --yes(-y)     runs no interactive mode."
	echo "        --clean(-c)   only clean work directory."
	echo "        --help(-h)    print help"
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
	else
		prn_fauilure "Unknown option $1."
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
rm -rf "${RPM_TOPDIR}"
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
# Check ~/.rpmmacros file
#----------------------------------------------------------
prn_title "Check ~/.rpmmacros file"
if [ -f "${HOME}/.rpmmacros" ]; then
	prn_fauilure "Found \"${HOME}/.rpmmacros\" file."
	echo "  Checking with \"check-rpaths\" may result in an error due to the existence"
	echo "  of the \"${HOME}/.rpmmacros\" file."
	echo "  If you get that error, delete the \"${HOME}/.rpmmacros\" file"
	echo "  and try again."
	echo ""
	exit 1
fi
prn_success "${HOME}/.rpmmacros file does not exist."
prn_groupend

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
# Create package top directories
#----------------------------------------------------------
prn_title "Create work directories for packaging"
if ! mkdir -p "${RPM_TOPDIR}"/BUILD     ||
   ! mkdir -p "${RPM_TOPDIR}"/BUILDROOT ||
   ! mkdir -p "${RPM_TOPDIR}"/RPM       ||
   ! mkdir -p "${RPM_TOPDIR}"/SOURCES   ||
   ! mkdir -p "${RPM_TOPDIR}"/SPECS     ||
   ! mkdir -p "${RPM_TOPDIR}"/SRPMS; then
	prn_fauilure "Could not create ${RPM_TOPDIR}/* directories."
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

echo "-----------------------------------------------------------"
echo " Package name     : ${PACKAGE_NAME}"
echo " Package version  : ${PACKAGE_VERSION}"
echo " Package release  : ${PACKAGE_RELEASE}"
echo "-----------------------------------------------------------"
prn_success "done"
prn_groupend

#----------------------------------------------------------
# Make source tar.gz from git by archive
#----------------------------------------------------------
prn_title "Create base tar ball of source files"
if ! git archive HEAD --prefix="${PACKAGE_NAME}-${PACKAGE_VERSION}"/ --output="${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}".tar.gz; then
	prn_fauilure "Could not make source tar ball(${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}.tar.gz) from github repository."
	exit 1
fi
prn_success "Created ${RPM_TOPDIR}/SOURCES/${PACKAGE_NAME}-${PACKAGE_VERSION}.tar.gz"
prn_groupend

#----------------------------------------------------------
# Copy spec file
#----------------------------------------------------------
prn_title "Copy spec file to ${SRCTOP}"
if ! cp "${SRCTOP}"/buildutils/*.spec "${SRCTOP}"/; then
	prn_fauilure "Could not find and feiled to copy spec files."
	exit 1
fi
prn_success "Copied spec file to ${SRCTOP}"
prn_groupend

#----------------------------------------------------------
# Run rpmbuild
#----------------------------------------------------------
prn_title "Run rpmbuild"
if ! rpmbuild -vv -ba --define "_topdir ${RPM_TOPDIR}" --define "_prefix /usr" --define "_mandir /usr/share/man" --define "_defaultdocdir /usr/share/doc" --define "package_revision ${PACKAGE_RELEASE}" ./*.spec; then
	prn_fauilure "Failed to build rpm packages by rpmbuild."
	exit 1
fi
prn_success "rpmbuild done"
prn_groupend

#----------------------------------------------------------
# Check packages
#----------------------------------------------------------
prn_title "Check created RPM packages"
echo ""
ls -la "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm
echo ""

# shellcheck disable=SC2012
_rpm_package_count="$(ls -1 "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm 2>/dev/null | wc -l)"
if [ "${_rpm_package_count}" -ne 3 ] && [ "${_rpm_package_count}" -ne 4 ]; then
	prn_fauilure "There are too or few created RPM packages(*.rpm)."
	exit 1
fi

for _rpm_file in "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm; do
	if test ! -e "${_rpm_file}"; then
		continue
	fi
	echo "-----------------------------------------------------------"
	echo "Package: ${_rpm_file}"
	echo "-----------------------------------------------------------"
	rpm -qpl "${_rpm_file}" | sed -e 's/^/  /g'
	echo ""
	rpm -qpi "${_rpm_file}" | sed -e 's/^/  /g'
	echo ""
done

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

prn_title "Copy created RPM packages to packages directory"
if ! cp -p "${RPM_TOPDIR}"/RPMS/*/*.rpm "${RPM_TOPDIR}"/SRPMS/*.rpm "${PKG_TOPDIR}"; then
	prn_fauilure "Failed to copy packages to ${PKG_TOPDIR}"
	exit 1
fi
prn_success "Copied RPM packages to ${PKG_TOPDIR}"
prn_groupend

#----------------------------------------------------------
# finish
#----------------------------------------------------------
prn_title "Install Summary"
prn_success "All processing is succeed"
echo "You can find ${PACKAGE_NAME} ${PACKAGE_VERSION}-${PACKAGE_RELEASE} version rpm package in ${PKG_TOPDIR} directory."
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
