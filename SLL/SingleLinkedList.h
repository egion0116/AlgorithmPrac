#pragma once

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;

    struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(ElementType Data);
void SLL_DestroyNode(Node* Head);
void SLL_AppendNode(Node** Head, Node* Target);
void SLL_RemoveNode(Node** Head, Node* Target);
Node* SLL_GetNodeAt(Node* Head, int Position);
Node* SLL_GetNodeAt(Node* Head, int Position);
void SLL_InsertNode(Node* Origin, Node* Target);
void SLL_PrintAllNodes(const Node* Head);
int SLL_GetNodesNum(const Node* Head);
void SLL_DestroyList(Node* Head);