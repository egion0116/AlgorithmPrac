#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
    ElementType Data;

    struct tagLCRSNode* LeftChild;
    struct tagLCRSNode* RightSibling;
}LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_AddChild(LCRSNode* Parent, LCRSNode* Child);
void LCRS_PrintAll(LCRSNode* Root, int Depth);

