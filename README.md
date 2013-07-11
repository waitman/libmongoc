# libmongoc

This is a prototype for a new MongoDB C library.

************************************************************
Modified by Waitman Gobble <waitman@waitman.net> 7/11/2013

*) removed autotools build, replaced with BSD style Makefile
*) added '#include <netinet/in.h>' to mongoc/mongoc-client.c
*) changed 2x references ETIME to ETIMEDOUT in mongoc/mongoc-stream.c
*) changed '#include <bson.h>' to '#include <bson/bson.h>' in all c files

This version of the mongoc library requires devel/libbson FreeBSD port 
installed. (see https://github.com/waitman/libbson)

For the unmodified original code see
https://github.com/chergert/libmongoc


