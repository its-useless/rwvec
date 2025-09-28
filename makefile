CFLAGS = -Iinclude -Wall -Werror -Wpedantic -std=c90 -g -fsanitize=address
CC = cc

all: main
clean:
	rm -rf main *.o *.a *.so

include/rwvec.h:
	touch $@

include/rwvec_vecs.h: include/rwvec.h
	touch $@

src/rwvec.c: include/rwvec_vecs.h
	touch $@

rwvec.o: src/rwvec.c
	$(CC) $(CFLAGS)	-c -o $@ $^

main: src/main.c rwvec.o
	$(CC) $(CFLAGS) -o $@ $^