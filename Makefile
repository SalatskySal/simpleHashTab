STATIC=libhtab.a
DYNAMIC=libhtab.so

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
CPPFLAGS = -std=c++11 -pedantic -Wall
DYNAMIC_FLAGS=-shared -Wl,-soname,
LDFLAGS = -L. -lhtab

LIBS = htab_create.h htab.h
MODULES = htab_init.c htab_lookup_add.c htab_begin.c htab_end.c htab_hash_function.c htab_iterator_next.c htab_size.c htab_clear.c htab_free.c htab_iterator_get_key.c htab_iterator_get_value.c htab_iterator_set_value.c htab_bucket_count.c htab_move.c htab.c
SOURCE_HASH = wordcount.c io.c io.h

OBJ = $(MODULES:.c=.o) 

all: $(STATIC) $(DYNAMIC) remove compile

$(STATIC): $(OBJ) 
	ar rcs $@ $^

$(DYNAMIC): $(OBJ) $(LIBS)
	$(CC) $(DYNAMIC_FLAGS)$@ -o $@ $^

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@ 

remove:
	rm -f $(OBJ) 

clean: 
	rm -f *.a *.so wordcount wordcount-dynamic tail1 tail2

compile: 
	$(CC) $(CFLAGS) $(SOURCE_HASH) -static $(LDFLAGS) -o wordcount
	$(CC) $(CFLAGS) $(SOURCE_HASH) $(LDFLAGS) -o $< wordcount-dynamic
	$(CC) $(CFLAGS) tail.c -o tail1
	g++ $(CPPFLAGS) tail.cc -o tail2	