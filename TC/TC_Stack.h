#pragma once

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

void CreateStack(LinkedListStack** Stack);
void DestroyStack(LinkedListStack* Stack);

Node* CreateNode(const char* Data);
void DestroyNode(Node* p_Node);

void Push(LinkedListStack* Stack, Node* p_Node);
Node* Pop(LinkedListStack* Stack);

Node* GetTop(LinkedListStack* Stack);
int GetSize(LinkedListStack* Stack);
int IsEmpty(LinkedListStack* Stack);