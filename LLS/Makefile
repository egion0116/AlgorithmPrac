CC=gcc
CFLAGS=-g -Wall
OBJS=LLS_Stack.o LLS_Stack_Prac.o
TARGET=LLS_Stack_Prac

all: $(TARGET)

clear:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

LLS_Stack_Prac.o : LLS_Stack_Prac.c LLS_Stack.h
LLS_Stack.o : LLS_Stack.c LLS_Stack.h