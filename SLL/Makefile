CC=gcc
CFLAGS=-g -Wall
OBJS=SingleLinkedList.o Test.o
TARGET=Test

all: ${TARGET}

clear:
	rm -f *.o
	rm -f ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o $@ $^

SingleLinkedList.o : SingleLinkedList.c SingleLinkedList.h stdfx.h
Test.o : Test.c SingleLinkedList.h stdfx.h