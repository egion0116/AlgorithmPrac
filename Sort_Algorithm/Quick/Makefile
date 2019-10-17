CC=gcc
CFLAGS=-g -Wall
OBJS=Test.o Insertion.o
TARGET=Test

all: ${TARGET}

clear:
	rm -f *.o
	rm -f ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o $@ $^

Test.o: Test.c Insertion.h stdfx.h
Insertion.o: Insertion.c Insertion.h stdfx.h