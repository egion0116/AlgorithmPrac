#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode* Left;
    struct tagSBTNode* Right;

    ElementType Data;
}SBTNode;

SBTNode* SBT_CreateNode(const ElementType r_Data);
void SBT_DestroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Node);

void SBT_PreOrderPrintTree(SBTNode* Node);
void SBT_InOrderPrintTree(SBTNode* Node);
void SBT_PostOrderPrintTree(SBTNode* Node);