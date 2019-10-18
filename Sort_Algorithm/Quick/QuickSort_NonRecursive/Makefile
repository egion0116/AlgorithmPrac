CC=gcc
CFLAGS=-g -Wall
OBJS=NR_Quick.o NR_Stack.o Test.o
TARGET=Test

all: ${TARGET}

clear:
	rm -f *.o
	rm -f ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o $@ $^

NR_Quick.o : NR_Quick.c NR_Quick.h NR_Stack.h stdfx.h
NR_Stack.o : NR_Stack.c NR_Stack.h stdfx.h
Test.o : Test.c stdfx.h NR_Quick.h