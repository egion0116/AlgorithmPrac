#pragma once

typedef int ElementType;

typedef struct tagStack
{
    int Top;
    int Capacity;

    ElementType* Nodes;
}Stack;

void DEAS_CreateStack(Stack** p_Stack);
void DEAS_DestroyStack(Stack** p_Stack);
void DEAS_Push(Stack* p_Stack, ElementType p_Data);
ElementType DEAS_Pop(Stack* p_Stack);