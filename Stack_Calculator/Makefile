CC=gcc
CFLAGS=-g -Wall
OBJS=SC_Test.o SC_Calculator.o SC_Basic.o LLS_Stack.o
TARGET=SC_Test

all: ${TARGET}

clean:
	rm -f *.o
	rm -f ${TARGET}

${TARGET} : ${OBJS}
	${CC} -o $@ $^

SC_Test.o : stdfx.h SC_Calculator.c SC_Calculator.h SC_Basic.c SC_Basic.h
SC_Calculator.o : stdfx.h SC_Calculator.c SC_Calculator.h SC_Basic.c SC_Basic.h LLS_Stack.c LLS_Stack.h
SC_Basic.o : stdfx.h SC_Basic.c SC_Basic.h LLS_Stack.c LLS_Stack.h
LLS_Stack.o : stdfx.h LLS_Stack.c LLS_Stack.h

