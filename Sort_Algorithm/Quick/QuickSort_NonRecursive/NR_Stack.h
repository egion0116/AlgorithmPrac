#pragma once

typedef int ElementType;

typedef struct tagNode
{
    ElementType Left;
    ElementType Right;
}Node;

typedef struct tagStack
{
    int Capacity;
    int Top;

    Node* Nodes;
}Stack;

void SetNode(Node* p_Node, int Left, int Right);
void CreateStack(Stack** p_Stack);
void DestroyStack(Stack** p_Stack);
void Push(Stack* p_Stack, int Left, int Right);
Node* Pop(Stack* p_Stack);
Node* GetTop(Stack* p_Stack);
int IsEmptyStack(Stack* p_Stack);
int GetSize(Stack* p_Stack);