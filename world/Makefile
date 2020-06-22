hey:
	gcc main.c -o result
stat_lib: main
	gcc -c main.c main1.c main2.c
	ar rc liblib.a main1.o main2.o
	ranlib liblib.a

main:
	gcc main.c -L. -llib -o result

CFLAGS = -o result
C = gcc

all: hello
hello:
	$(C) main.c $(CFLAGS)
