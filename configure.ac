AC_INIT([minicli], [1.0], [https://github.com/d0p1s4m4/libminicli/issues])
AC_COPYRIGHT([Copyright (C) 2023 d0p1])

AC_CONFIG_SRCDIR([src/cli.c])
AC_CONFIG_MACRO_DIRS([m4])

AC_CONFIG_FILES([ po/Makefile.in
	Makefile
	include/Makefile
	src/Makefile
	test/Makefile
	libminicli.pc
])

AM_INIT_AUTOMAKE([foreign subdir-objects -Werror -Wall])

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.20])

AC_CONFIG_HEADERS([config.h])
AH_TOP([
#ifndef MINICLI_CONFIG_H
# define MINICLI_CONFIG_H 1
])

AH_BOTTOM([
#endif /* !MINICLI_CONFIG_H */
])

AC_LANG([C])
AC_PROG_CC
AC_PROG_CPP
AM_PROG_AR
AC_PROG_INSTALL
LT_INIT
AM_PROG_CC_C_O
PKG_PROG_PKG_CONFIG

AC_C_CONST

AC_CHECK_HEADER([libgen.h],
    [AC_DEFINE(HAVE_LIBGEN_H, 1, Define if libgen.h exist)])


AC_OUTPUT
