CC=gcc
CFLAGS=-g -Wall
OBJS=TC_Test.o TC_Calculator.o TC_Basic.o TC_Stack.o TC_BinaryTree.o
TARGET=TC_Test

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

TC_Test.o : TC_Test.c TC_Calculator.h stdfx.h
TC_Calculator.o : TC_Calculator.c TC_Calculator.h stdfx.h
TC_Basic.o : TC_Basic.c TC_Basic.h TC_Stack.h TC_BinaryTree.h stdfx.h
TC_Stack.o : TC_Stack.c TC_Stack.h stdfx.h
TC_BinaryTree.o : TC_BinaryTree.c TC_BinaryTree.h stdfx.h