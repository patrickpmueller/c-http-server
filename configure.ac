#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.72])
AC_INIT([http-webserver],[0.1],[patrickpmueller@yahoo.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_HEADERS([config.h])

# Libtool
AM_PROG_AR
AM_PATH_CHECK
AC_PROG_RANLIB
LT_INIT

# Checks for programs.
AC_PROG_CC

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/file_manager/Makefile
	src/threadpool/Makefile
	src/netlayer/Makefile
	tests/Makefile])
AC_OUTPUT
