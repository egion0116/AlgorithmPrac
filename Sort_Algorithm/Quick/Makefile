CC=gcc
CFLAGS=-g -Wall
OBJS=Test.o Insertion.o QuickSort.o
TARGET=Test

all: ${TARGET}

clear:
	rm -f *.o
	rm -f ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o $@ $^

Test.o: Test.c Insertion.h QuickSort.h stdfx.h
Insertion.o: Insertion.c Insertion.h stdfx.h
QuickSort.o: QuickSort.c QuickSort.h Insertion.h stdfx.h
