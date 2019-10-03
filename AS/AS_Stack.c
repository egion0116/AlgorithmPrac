#include "AS_Stack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
}

void AS_DestroyStack(ArrayStack* Stack)
{
    free(Stack->Nodes);
    free(Stack);
}

int AS_GetCapacity(ArrayStack* Stack)
{
    return Stack->Capacity;
}

int AS_GetSize(ArrayStack* Stack)
{
    return Stack->Top;
}

ElementType AS_Top(ArrayStack* Stack)
{
    int Pos = Stack->Top - 1;

    return Stack->Nodes[Pos].Data;
}

int AS_IsEmpty(ArrayStack* Stack)
{
    return (Stack->Top == 0);
}

void AS_Push(ArrayStack* Stack, ElementType p_Data)
{
    int Position = Stack->Top++;

    Stack->Nodes[Position].Data = p_Data;
}

ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = --Stack->Top;

    return Stack->Nodes[Position].Data;
}