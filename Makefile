CFLAGS=-Wall -Wextra -Werror -Wpedantic
CC=clang $(CFLAGS)

sorting     :    sorting.o bubble.o shell.o quick.o binary.o
	$(CC) -o sorting sorting.o bubble.o shell.o quick.o binary.o -lm
sorting.o   :    sorting.c
	$(CC) -c sorting.c
bubble.o   :     bubble.c bubble.h
	$(CC) -c bubble.c
shell.o   :      shell.c shell.h
	$(CC) -c shell.c
quick.o   :      quick.c quick.h
	$(CC) -c quick.c
binary.o   :     binary.c binary.h
	$(CC) -c binary.c
valgrind:
	valgrind ./sorting -A
clean   :
	rm -f sorting sorting.o bubble.o shell.o quick.o binary.o
infer   :
	make clean; infer-capture -- make; infer-analyze -- make