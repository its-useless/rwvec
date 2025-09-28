CFLAGS = -Iinclude -Wall -Werror -Wpedantic -std=c90 -g -fsanitize=address
CC = cc

all: main
clean:
	rm -rf main *.o *.a *.so

include/rwvec.h:
	touch $@

include/rwvec_vecs.h: include/rwvec.h
	touch $@

main: src/main.c include/rwvec_vecs.h
	$(CC) $(CFLAGS) -o $@ $^