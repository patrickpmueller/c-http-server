TESTS = check_buildtool check_threadpool
check_PROGRAMS = check_buildtool check_threadpool

check_threadpool_SOURCES = $(top_builddir)/src/threadpool/libthreadpool.h check_threadpool.c
check_threadpool_CFLAGS = @CHECK_CFLAGS@
check_threadpool_LDADD = $(top_builddir)/src/threadpool/libthreadpool.la @CHECK_LIBS@

check_buildtool_SOURCES = $(top_builddir)/src/should_build.h check_buildtool.c  
check_buildtool_CFLAGS = @CHECK_CFLAGS@
check_buildtool_LDADD = $(top_builddir)/src/libbuildtool.la @CHECK_LIBS@
