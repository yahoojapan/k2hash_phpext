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
# CREATE:   Fri, Apr 13 2018
# REVISION:
#

#
# Common variables
#
PRGNAME=$(basename "$0")
SCRIPTDIR=$(dirname "$0")
SRCTOP=$(cd "${SCRIPTDIR}"/.. || exit 1; pwd)

#
# Convert ChangeLog to use it in spec file for rpm
#
func_usage()
{
	echo ""
	echo "Usage:  $1 <ChangeLog file> [-h]"
	echo "	<ChangeLog file>    specify ChnageLog file path. if not specify, use ChangeLog file in top directory as default."
	echo "	-h(help)            print help."
	echo ""
}

#
# Check options
#
CHANGELOG_FILE="${SRCTOP}/ChangeLog"
ISSETCHANGELOG=0
while [ $# -ne 0 ]; do
	if [ "X$1" = "X" ]; then
		break;

	elif [ "X$1" = "X-h" ] || [ "X$1" = "X-help" ]; then
		func_usage "${PRGNAME}"
		exit 0

	else
		if [ "${ISSETCHANGELOG}" -ne 0 ]; then
			echo "ERROR: already ${CHANGELOG_FILE} file is specified." 1>&2
			echo "No changelog by ${CHANGELOG_FILE} with error."
			exit 1
		fi
		if [ ! -f "$1" ]; then
			echo "ERROR: $1 file is not existed." 1>&2
			echo "No changelog by ${CHANGELOG_FILE} with error."
			exit 1
		fi
		CHANGELOG_FILE=$1
		ISSETCHANGELOG=1
	fi
	shift
done

#
# convert ChangeLog to spec file format for rpm
#
INONEVER=0
DETAILS=""
ALLLINES=""
# shellcheck disable=SC2162
while read oneline; do
	# shellcheck disable=SC2116
	oneline=$(echo "${oneline}")
	if [ -z "${oneline}" ]; then
		continue
	fi

	if [ ${INONEVER} -eq 0 ]; then
		PKG_VERSION=$(echo "${oneline}" | grep '^.*[(].*\..*[)].*[;].*$' | grep -o '[(].*[)]' | sed 's/[(|)]//g')
		# shellcheck disable=SC2116
		PKG_VERSION=$(echo "${PKG_VERSION}")
		if [ -n "${PKG_VERSION}" ]; then
			INONEVER=1
			DETAILS=""
		fi
	else
		TEST_CONTENTS=$(echo "${oneline}" | grep '^[-][-].*[ ][ ].*$')
		PKG_RF2822=$(echo "${TEST_CONTENTS}" | grep -o '[ ][ ].*')
		# shellcheck disable=SC2116
		PKG_RF2822=$(echo "${PKG_RF2822}")
		PKG_COMITTER=$(echo "${TEST_CONTENTS}" | grep -o '.*[ ][ ]' | sed 's/^[-][-][ ]//')
		if [ -n "${PKG_RF2822}" ] && [ -n "${PKG_COMITTER}" ]; then
			INONEVER=0
			PKG_DATE=$(echo "${PKG_RF2822}" | sed 's/,/ /g' | awk '{print $1" "$3" "$2" "$4}')
			PKG_LINE="* ${PKG_DATE} ${PKG_COMITTER} ${PKG_VERSION}${DETAILS}"
			if [ "X${ALLLINES}" != "X" ]; then
				ALLLINES="${ALLLINES}\\n\\n${PKG_LINE}"
			else
				ALLLINES="${PKG_LINE}"
			fi
		else
			ONEDETAIL=$(echo "$oneline" | grep '^[\*][ ].*' | sed 's/^[\*]//g')
			# shellcheck disable=SC2116
			ONEDETAIL=$(echo "${ONEDETAIL}")
			if [ "X${ONEDETAIL}" != "X" ]; then
				DETAILS="${DETAILS}\\n- ${ONEDETAIL}"
			fi
		fi
	fi
done < "${CHANGELOG_FILE}"

#
# print changelog
#
# shellcheck disable=SC2039,SC3037
echo -e "${ALLLINES}"

exit 0

#
# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noexpandtab sw=4 ts=4 fdm=marker
# vim<600: noexpandtab sw=4 ts=4
#
