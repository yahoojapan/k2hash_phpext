dnl
dnl K2HASH PHP Extension library
dnl
dnl Copyright 2015 Yahoo! JAPAN corporation.
dnl
dnl K2HASH is key-valuew store base libraries.
dnl K2HASH is made for the purpose of the construction of
dnl original KVS system and the offer of the library.
dnl The characteristic is this KVS library which Key can
dnl layer. And can support multi-processing and multi-thread,
dnl and is provided safely as available KVS.
dnl
dnl For the full copyright and license information, please view
dnl the LICENSE file that was distributed with this source code.
dnl
dnl AUTHOR:   Hirotaka Wakabayashi
dnl CREATE:   Tue, Feb 22 2022
dnl REVISION:
dnl
dnl -------------------------------------------------------
dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.
dnl -------------------------------------------------------

#
# Set k2hash php extension name
#
AC_SUBST([K2HASH_NAME],   "k2hash")
AC_SUBST([K2H_PECL_NAME], "pecl-k2hash")

#
# Common variables
#
AC_SUBST([GIT_DOMAIN], "github.com")
AC_SUBST([GIT_ORG],    "yahoojapan")
AC_SUBST([GIT_REPO],   "k2hash_phpext")
AC_SUBST([DEV_EMAIL],  [$(echo ${DEBEMAIL:-antpickax@mail.yahoo.co.jp})])
AC_SUBST([DEV_NAME],   [$(echo ${DEBFULLNAME:-K2HASH_DEVELOPER})])

AC_SUBST([HOME_PAGE],  "https://php.k2hash.antpick.ax/")
AC_SUBST([PKGLICENSE], [$(grep License LICENSE | sed 's/ License//g')])
AC_SUBST([DEBLICENSER],[$(grep Copyright LICENSE | sed 's/ *(c)//g')])
AC_SUBST([DEBCOPYING], [$(sed -e 's/^$/./g' -e 's/^/ /g' LICENSE)])

#
# Enable for this extension
#
PHP_ARG_ENABLE([k2hash], [whether to enable k2hash support], [AS_HELP_STRING([--enable-k2hash], [Enable k2hash support])], [no])

#
# For PHP Extension
#
if test "$PHP_K2HASH" != "no"; then
	PHP_EVAL_INCLINE($LIBK2HASH_CFLAGS)
	PHP_EVAL_LIBLINE($LIBK2HASH_LIBS, K2HASH_SHARED_LIBADD)

	AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
	AC_MSG_CHECKING(for libk2hash)

	if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists libk2hash; then
		K2HASH_INCDIR=`$PKG_CONFIG libk2hash --variable=includedir`
		K2HASH_LIBDIR=`$PKG_CONFIG libk2hash --variable=libdir`
		K2HASH_VERSION=`$PKG_CONFIG libk2hash --modversion`

		AC_MSG_RESULT(from pkgconfig: version $K2HASH_VERSION found in $K2HASH_LIBDIR)
	fi

	if test -z "$K2HASH_LIBDIR"; then
		AC_MSG_RESULT([not found])
		AC_MSG_ERROR([Please install the libk2hash distribution])
	fi

	PHP_ADD_INCLUDE($K2HASH_INCDIR/k2hash)
	PHP_ADD_LIBRARY_WITH_PATH(k2hash, $K2HASH_LIBDIR, K2HASH_SHARED_LIBADD)
	PHP_SUBST(K2HASH_SHARED_LIBADD)

	AC_DEFINE(HAVE_K2HASH, 1, [ Have k2hash support ])

	#
	# Source codes
	#
	PHP_NEW_EXTENSION(k2hash, k2hash_func.c K2hash.c K2hQueue.c K2hKeyQueue.c K2hIterator.c k2hash_stream.c, $ext_shared)
fi

AC_CHECK_PROG(K2H_HAVE_PHP_BINARY, [php --version], [yes], [no])

#
# Make PHP version variables
#
if test "${K2H_HAVE_PHP_BINARY}" = "yes"; then
	AC_SUBST([K2H_PHP_VERSION],       [$(php -r 'echo "".PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')])
	AC_SUBST([K2H_PHP_RAW_VERSION],   [$(php -r 'echo "".PHP_MAJOR_VERSION."".PHP_MINOR_VERSION;')])
	AC_SUBST([K2H_PHP_MAJOR_VERSION], [$(php -r 'echo "".PHP_MAJOR_VERSION."";')])
	AC_SUBST([K2H_PHP_MINOR_VERSION], [$(php -r 'echo "".PHP_MINOR_VERSION."";')])
	AC_SUBST([K2H_EXT_PKGNAME],       [$(head -n 1 $(pwd)/ChangeLog | awk '{print $1}')])
	AC_SUBST([K2H_EXT_VERSION],       [$(head -n 1 $(pwd)/ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g')])
	AC_SUBST([K2H_EXT_RELEASE],       [$(head -n 1 $(pwd)/ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/^.*-//g')])
else
	AC_SUBST([K2H_PHP_VERSION],       "0.0")
	AC_SUBST([K2H_PHP_RAW_VERSION],   "00")
	AC_SUBST([K2H_PHP_MAJOR_VERSION], "0")
	AC_SUBST([K2H_PHP_MINOR_VERSION], "0")
	AC_SUBST([K2H_EXT_PKGNAME],       "php-pecl-k2hash")
	AC_SUBST([K2H_EXT_VERSION],       "0.0.0")
	AC_SUBST([K2H_EXT_RELEASE],       "0")
fi

#
# Make changelog strings for rpm
#
if test -f $(pwd)/buildutils/make_rpm_changelog.sh; then
	AC_SUBST([K2H_RPMCHANGELOG], [$($(pwd)/buildutils/make_rpm_changelog.sh $(pwd)/ChangeLog)])
fi

#
# Set input files
#
if test -d buildutils; then
	AC_CONFIG_FILES([
		$(pwd)/buildutils/php-pecl-k2hash.spec
		$(pwd)/buildutils/k2hash.ini
		$(pwd)/buildutils/rules
		$(pwd)/buildutils/control.in
		$(pwd)/buildutils/copyright
		$(pwd)/buildutils/watch
		$(pwd)/buildutils/upstream/metadata
	])
fi

dnl
dnl Local variables:
dnl tab-width: 4
dnl c-basic-offset: 4
dnl End:
dnl vim600: noexpandtab sw=4 ts=4 fdm=marker
dnl vim<600: noexpandtab sw=4 ts=4
dnl
