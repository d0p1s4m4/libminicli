AC_INIT([minicli], [1.0], [https://github.com/d0p1s4m4/libminicli/issues])
AC_COPYRIGHT([Copyright (C) 2023 d0p1])

AC_CONFIG_SRCDIR(src/cli.c)

AC_CONFIG_FILES([
	Makefile
	include/Makefile
	src/Makefile
	test/Makefile
])

AM_INIT_AUTOMAKE([foreign subdir-objects -Werror -Wall])

AC_LANG([C])
AC_PROG_CC
AC_PROG_CPP
AM_PROG_AR
AC_PROG_RANLIB
AC_PROG_INSTALL
AM_PROG_CC_C_O

AC_C_CONST

AC_OUTPUT
