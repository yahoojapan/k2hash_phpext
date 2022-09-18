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
SRCTOP=$(cd "${SCRIPTDIR}"/../.. || exit 1; pwd)
PKG_TOPDIR="${SRCTOP}/packages"

#----------------------------------------------------------
# Utility: Usage
#----------------------------------------------------------
func_usage()
{
	echo ""
	echo "Usage:  $1 [options...] [--help(-h)]"
	echo " --distribution-tag(-disttag)                         distoribution tag name of uploading to packagecloud.io"
	echo " --package-extension(-pkgext)                         package extension"
	echo " --packagecloudio-token(-pctoken)        <token>      packagecloud.io token for uploading(specify when uploading)"
	echo " --packagecloudio-owner(-pcowner)        <owner>      owner name of uploading destination to packagecloud.io, this is part of the repository path(default is antpickax)"
	echo " --packagecloudio-publish-repo(-pcprepo) <repository> repository name of uploading destination to packagecloud.io, this is part of the repository path(default is current)"
	echo " --force-publish(-f)                                  force the release package to be uploaded. normally the package is uploaded only when it is tagged(determined from GITHUB_REF/GITHUB_EVENT_NAME)."
	echo " --help(-h)                                           print help"
	echo ""
	echo "  Note:"
	echo "    This program uses the GITHUB_REF / GITHUB_EVENT_NAME / RUBY_SCL_ENV_FILE environment variable internally."
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

prn_title()
{
	echo "${CBLD}$*${CDEF}"
}
prn_success()
{
	echo "${CBLD}${CGRN}${CREV}[SUCCESS]${CDEF} $*"
	echo ""
}
prn_message()
{
	echo "${CBLD}${CREV}[MESSAGE]${CDEF} $*"
	echo ""
}
prn_fauilure()
{
	echo "${CBLD}${CRED}${CREV}[FAILURE]${CDEF} ${CRED}$*${CDEF}"
	echo ""
}

#----------------------------------------------------------
# Parse options
#----------------------------------------------------------
DIST_TAG=
PKG_EXT=
PC_TOKEN=
PC_OWNER=
PC_PREPO=
FORCE_PUSH=0
while [ $# -ne 0 ]; do
	if [ "X$1" = "X" ]; then
		break

	elif [ "X$1" = "X-h" ] || [ "X$1" = "X-H" ] || [ "X$1" = "X--help" ] || [ "X$1" = "X--HELP" ]; then
		func_usage "${PRGNAME}"
		exit 0

	elif [ "X$1" = "X--distribution-tag" ] || [ "X$1" = "X--DISTRIBUTION-TAG" ] || [ "X$1" = "X-disttag" ] || [ "X$1" = "X-DISTTAG" ]; then
		if [ -n "${DIST_TAG}" ]; then
			prn_fauilure "Already specified \"--distribution-tag(-disttag)\" option(${DIST_TAG})."
			exit 1
		fi
		shift
		if [ $# -eq 0 ]; then
			prn_fauilure "\"--distribution-tag(-disttag)\" option is specified without parameter."
			exit 1
		fi
		DIST_TAG="$1"

	elif [ "X$1" = "X--package-extension" ] || [ "X$1" = "X--PACKAGE-EXTENSION" ] || [ "X$1" = "X-pkgext" ] || [ "X$1" = "X-PKGEXT" ]; then
		if [ -n "${PKG_EXT}" ]; then
			prn_fauilure "Already specified \"--package-extension(-pkgext)\" option(${PKG_EXT})."
			exit 1
		fi
		shift
		if [ $# -eq 0 ]; then
			prn_fauilure "\"--package-extension(-pkgext)\" option is specified without parameter."
			exit 1
		fi
		PKG_EXT="$1"

	elif [ "X$1" = "X--packagecloudio-token" ] || [ "X$1" = "X--PACKAGECLOUDIO-TOKEN" ] || [ "X$1" = "X-pctoken" ] || [ "X$1" = "X-PCTOKEN" ]; then
		if [ -n "${PC_TOKEN}" ]; then
			prn_fauilure "Already specified \"--packagecloudio-token(-pctoken)\" option(${PC_TOKEN})."
			exit 1
		fi
		shift
		if [ $# -eq 0 ]; then
			prn_fauilure "\"--packagecloudio-token(-pctoken)\" option is specified without parameter."
			exit 1
		fi
		PC_TOKEN="$1"

	elif [ "X$1" = "X--packagecloudio-owner" ] || [ "X$1" = "X--PACKAGECLOUDIO-OWNER" ] || [ "X$1" = "X-pcowner" ] || [ "X$1" = "X-PCOWNER" ]; then
		if [ -n "${PC_OWNER}" ]; then
			prn_fauilure "Already specified \"--packagecloudio-owner(-pcowner)\" option(${PC_OWNER})."
			exit 1
		fi
		shift
		if [ $# -eq 0 ]; then
			prn_fauilure "\"--packagecloudio-owner(-pcowner)\" option is specified without parameter."
			exit 1
		fi
		PC_OWNER="$1"

	elif [ "X$1" = "X--packagecloudio-publish-repo" ] || [ "X$1" = "X--PACKAGECLOUDIO-PUBLISH-REPO" ] || [ "X$1" = "X-pcprepo" ] || [ "X$1" = "X-PCPREPO" ]; then
		if [ -n "${PC_PREPO}" ]; then
			prn_fauilure "Already specified \"--packagecloudio-publish-repo(-pcprepo)\" option(${PC_PREPO})."
			exit 1
		fi
		shift
		if [ $# -eq 0 ]; then
			prn_fauilure "\"--packagecloudio-publish-repo(-pcprepo)\" option is specified without parameter."
			exit 1
		fi
		PC_PREPO="$1"

	elif [ "X$1" = "X--force-publish" ] || [ "X$1" = "X--FORCE-PUBLISH" ] || [ "X$1" = "X-f" ] || [ "X$1" = "X-F" ]; then
		if [ "${FORCE_PUSH}" -eq 1 ]; then
			prn_fauilure "Already specified \"--force-publish(-f)\" option."
			exit 1
		fi
		FORCE_PUSH=1

	else
		prn_fauilure "Unknown option - $1."
		exit 1
	fi
	shift
done

if [ -z "${DIST_TAG}" ]; then
	prn_fauilure "\"--distribution-tag(-disttag)\" option is not specified."
	exit 1
fi
if [ -z "${PKG_EXT}" ]; then
	prn_fauilure "\"--package-extension(-pkgext)\" option is not specified."
	exit 1
fi
if [ -z "${PC_TOKEN}" ]; then
	prn_message "\"--packagecloudio-token(-pctoken)\" option is not specified, so do not publish a package."
fi
if [ -z "${PC_OWNER}" ]; then
	PC_OWNER="antpickax"
fi
if [ -z "${PC_PREPO}" ]; then
	PC_PREPO="current"
fi

#---------------------------------------------------------------------
# Check allow publishing
#---------------------------------------------------------------------
prn_title "Check if the package will be published"

#
# Check GITHUB Environment
#
if [ "X${GITHUB_EVENT_NAME}" = "Xschedule" ]; then
	IN_SCHEDULE_PROCESS=1
else
	IN_SCHEDULE_PROCESS=0
fi

PUBLISH_TAG_NAME=
if [ -n "${GITHUB_REF}" ]; then
	if echo "${GITHUB_REF}" | grep -q 'refs/tags/'; then
		PUBLISH_TAG_NAME=$(echo "${GITHUB_REF}" | sed 's#refs/tags/##g')
	fi
fi

IS_PUBLISH=0
if [ "${FORCE_PUSH}" -eq 0 ]; then
	if [ "${IN_SCHEDULE_PROCESS}" -eq 0 ]; then
		if [ -n "${PUBLISH_TAG_NAME}" ]; then
			IS_PUBLISH=1
		else
			echo "The tag name to publish could not be found in the GITHUB_REF environment variable."
		fi
	else
		echo "Called from a scheduled scheduled build."
	fi
else
	#
	# FORCE PUBLISH
	#
	if [ "${IN_SCHEDULE_PROCESS}" -eq 0 ]; then
		if [ -n "${PUBLISH_TAG_NAME}" ]; then
			echo "Specified \"--force-publish(-f)\" option."
			IS_PUBLISH=1
		else
			prn_fauilure "Specified \"--force-publish(-f)\" option, but the tag name to publish could not be found in the GITHUB_REF environment variable."
			exit 1
		fi
	else
		prn_fauilure "Specified \"--force-publish(-f)\" option, but called from a scheduled scheduled build."
		exit 1
	fi
fi

if [ "${IS_PUBLISH}" -eq 0 ]; then
	prn_success "The package will not be published, the conditions for publishing the package are not in place."
	exit 0
fi
prn_success "Do publish the package"

#---------------------------------------------------------------------
# Information
#---------------------------------------------------------------------
prn_title "Start to publish packages"
echo "-----------------------------------------------------------"
echo "Information"
echo "-----------------------------------------------------------"
echo "packagecloud.io repository owner  ${PC_OWNER}"
echo "packagecloud.io repository name   ${PC_PREPO}"
echo "packagecloud.io token             ********"
echo "Distoribution Tag name            ${DIST_TAG}"
echo "Publish repository path           ${PC_PUBLISH_PATH}"
echo "Publish package extension         ${PKG_EXT}"
echo "-----------------------------------------------------------"

#---------------------------------------------------------------------
# Publish
#---------------------------------------------------------------------
prn_title "Start publishing"

PC_PUBLISH_PATH="${PC_OWNER}/${PC_PREPO}/${DIST_TAG}"

if [ -n "${RUBY_SCL_ENV_FILE}" ]; then
	echo "\"RUBY_SCL_ENV_FILE\" environment is found, do set it before run package_cloud command."
	#shellcheck disable=SC1090
	. "${RUBY_SCL_ENV_FILE}"
fi

if ! PACKAGECLOUD_TOKEN="${PC_TOKEN}" package_cloud push "${PC_PUBLISH_PATH}" "${PKG_TOPDIR}"/*."${PKG_EXT}"; then
	prn_fauilure "Failed to publish *.${PKG_EXT} packages"
	exit 1
fi
prn_success "Published all pacakages(*.${PKG_EXT})"

#----------------------------------------------------------
# finish
#----------------------------------------------------------
exit 0

#
# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noexpandtab sw=4 ts=4 fdm=marker
# vim<600: noexpandtab sw=4 ts=4
#
