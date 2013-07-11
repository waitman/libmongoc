CC?=            clang
AR?=            ar
INSTALL?=       install
PREFIX?=        /usr/local
CFLAGS?=        -O2

all: libmongoc

libmongoc:
	$(CC) -c -fPIC -I./mongoc -I$(PREFIX)/include -DMONGOC_COMPILATION -DBSON_BYTE_ORDER=1234 $(CFLAGS) -g -Wall -Werror ./mongoc/mongoc-array.c ./mongoc/mongoc-buffer.c ./mongoc/mongoc-client-pool.c ./mongoc/mongoc-client.c ./mongoc/mongoc-cluster.c ./mongoc/mongoc-collection.c ./mongoc/mongoc-cursor.c ./mongoc/mongoc-database.c ./mongoc/mongoc-list.c ./mongoc/mongoc-log.c ./mongoc/mongoc-queue.c ./mongoc/mongoc-read-prefs.c ./mongoc/mongoc-rpc.c ./mongoc/mongoc-stream.c ./mongoc/mongoc-uri.c ./mongoc/mongoc-write-concern.c
	$(AR) rvs libmongoc.a mongoc-array.o mongoc-buffer.o mongoc-client-pool.o mongoc-client.o mongoc-cluster.o mongoc-collection.o mongoc-cursor.o mongoc-database.o mongoc-list.o mongoc-log.o mongoc-queue.o mongoc-read-prefs.o mongoc-rpc.o mongoc-stream.o mongoc-uri.o mongoc-write-concern.o
	$(CC) -shared -fPIC -o libmongoc.so libmongoc.a mongoc-array.o mongoc-buffer.o mongoc-client-pool.o mongoc-client.o mongoc-cluster.o mongoc-collection.o mongoc-cursor.o mongoc-database.o mongoc-list.o mongoc-log.o mongoc-queue.o mongoc-read-prefs.o mongoc-rpc.o mongoc-stream.o mongoc-uri.o mongoc-write-concern.o

install:
	mkdir $(PREFIX)/include/mongoc
	$(INSTALL) -m 644 ./mongoc/mongoc-version.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-array-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-buffer-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-client-pool.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-client-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-client.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-cluster-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-collection-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-collection.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-cursor-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-cursor.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-database-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-database.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-error.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-flags.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-host-list.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-list-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-log.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-opcode.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-queue-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-read-prefs-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-read-prefs.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-rpc-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-stream.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-uri.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-write-concern-private.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-write-concern.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/op-header.def $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 ./mongoc/mongoc-stdint.h $(PREFIX)/include/mongoc/
	$(INSTALL) -m 644 libmongoc.a $(PREFIX)/lib/
	$(INSTALL) -m 644 libmongoc.so $(PREFIX)/lib/

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.so

deinstall:
	rm -Rf $(PREFIX)/include/mongoc
	rm -f $(PREFIX)/lib/libmongoc.a
	rm -f $(PREFIX)/lib/libmongoc.so

