CC=gcc
CFLAGS=-g -Wall
OBJS=Test.o Sort.o Common.o
TARGET=Test

all:${TARGET}

clear:
	rm -f *.o
	rm -f ${TARGET}

${TARGET} : ${OBJS}
	${CC} -o $@ $^

Test.o : Test.c Sort.h Common.h
Sort.o : Sort.c Sort.h
Common.o : Common.c Common.h