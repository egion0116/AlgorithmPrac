CC=gcc
CFLAGS=-g -Wall
OBJS=TC_Calculator.o TC_Basic.o TC_Stack.o
TARGET=TC_Calculator

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

TC_Calculator.o : TC_Calculator.c TC_Basic.h TC_Stack.h stdfx.h
TC_Basic.o : TC_Basic.c TC_Basic.h TC_Stack.h stdfx.h
TC_Stack.o : TC_Stack.c TC_Stack.h stdfx.h