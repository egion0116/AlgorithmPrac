CC=gcc
CFLAGS=-g -Wall
OBJS=AS_Stack.o AS_Stack_Prac.o
TARGET=AS_Stack_Prac

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

AS_Stack_Prac.o : AS_Stack_Prac.c AS_Stack.h
AS_Stack.o : AS_Stack.c AS_Stack.h