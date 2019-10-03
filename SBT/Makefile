CC=gcc
CFLAGS=-g -Wall
OBJS=SBT_Tree_Prac.o SBT_Tree.o
TARGET=SBT_Tree_Prac

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

SBT_Tree_Prac.o : SBT_Tree_Prac.c SBT_Tree.h
SBT_Tree.o : SBT_Tree.c SBT_Tree.h