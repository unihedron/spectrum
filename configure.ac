#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([spectrum], [0.20], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([numbers.c])
AC_PATH_PROG([GS], [gs], [/usr/bin/gs])
AC_PATH_PROG([LATEX], [latex])
AC_CACHE_CHECK([for LaTeX], [ac_cv_path_LATEX],
                            [ac_path_LATEX_found=false])
$ac_path_LATEX_found || {
AC_MSG_ERROR([[LaTeX is required.
If you have it installed under another name, configure with 'LATEX=...'.
For example, run '$0 LATEX=some-other-latex'.]])
}

AC_PATH_PROG([DVIPS], [dvips])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([pow])

AC_CONFIG_FILES([Makefile
                 pictures/Makefile])
AC_OUTPUT
