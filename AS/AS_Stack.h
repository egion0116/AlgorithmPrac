#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagNode
{
    ElementType Data;
}Node;

typedef struct tagArrayStack
{
    int Capacity;
    int Top;
    Node* Nodes;
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);

int AS_GetCapacity(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);

void AS_Push(ArrayStack* Stack, ElementType p_Data);
ElementType AS_Pop(ArrayStack* Stack);