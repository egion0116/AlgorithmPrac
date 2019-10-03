#include "stdfx.h"

// 집합 원소 노드 -> 일반적인 트리와 다르게 부모를 가르키는 포인터를 가진다.
typedef struct tagNode
{
    struct tagSetTree* Parent;
    void* Data;
}Node;

Node* DST_CreateNode(void* p_Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = p_Data;
    NewNode->Parent = NULL;

    return NewNode;
}