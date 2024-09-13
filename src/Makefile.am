SUBDIRS = file_manager threadpool netlayer .

bin_PROGRAMS = http_server 
http_server_SOURCES = main.c
http_server_LADD = threadpool/libthreadpool.la libfile_manager.la libnetlayer.la

lib_LTLIBRARIES = libbuildtool.la
libbuildtool_la_SOURCES = should_build.c
