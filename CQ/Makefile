CC=gcc
CFLAGS=-g -Wall
OBJS=CQ_Queue.o CQ_Test.o
TARGET=CQ_Test

all: ${TARGET}

clean:
	rm -f *.o
	rm -f ${TARGET}

${TARGET} : ${OBJS}
	${CC} -o $@ $^

CQ_Test.o : CQ_Test.c stdfx.h
CQ_Queue.o : CQ_Queue.c CQ_Queue.h stdfx.h
