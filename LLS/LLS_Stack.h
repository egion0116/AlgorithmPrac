#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
    char* Data;
    struct tagNode* NextNode;
}Node;

typedef struct tagLinkedListStack
{
    Node* List;
    Node* Top;
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateList(char* p_Data);
void LLS_DestroyNode(Node* p_Node);

void LLS_Push(LinkedListStack* Stack, Node* p_Node);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);