CC=gcc
CFLAGS=-g -Wall
OBJS=LLS_Stack.o LLS_Stack_Test.o
TARGET=LLS_Stack_Test

all: ${TARGET}

clean:
	rm -f *.o
	rm -f ${TARGET}

${TARGET} : ${OBJS}
	${CC} -o $@ $^

LLS_Stack_Test.o : LLS_Stack_Test.c LLS_Stack.h stdfx.h
LLS_Stack_Test.o : LLS_Stack.c LLS_Stack.h stdfx.h