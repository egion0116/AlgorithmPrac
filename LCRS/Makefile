CC=gcc
CFLAGS=-g -Wall
OBJS=LCRS_Tree_Prac.o LCRS_Tree.o
TARGET=LCRS_Tree_Prac

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

LCRS_Tree.o : LCRS_Tree.c LCRS_Tree.h
LCRS_Tree_Prac.o : LCRS_Tree_Prac.c LCRS_Tree.h