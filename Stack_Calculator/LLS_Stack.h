#pragma once
#include "stdfx.h"

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagLinkedListStack
{
	Node* Top;
	Node* List;
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(char* p_Data);
void LLS_DestroyNode(Node* p_Node);

void LLS_Push(LinkedListStack* Stack, Node* p_Node);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);