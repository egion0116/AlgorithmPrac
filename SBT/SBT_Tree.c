#include "SBT_Tree.h"

SBTNode* SBT_CreateNode(const ElementType r_Data)
{
    SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));

    NewNode->Data = r_Data;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
    free(Node);
}

void SBT_DestroyTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    SBT_DestroyTree(Node->Left);
    SBT_DestroyTree(Node->Right);

    SBT_DestroyNode(Node);
}

void SBT_PreOrderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    putchar(' ');
    putchar(Node->Data);

    SBT_PreOrderPrintTree(Node->Left);
    SBT_PreOrderPrintTree(Node->Right);
}

void SBT_InOrderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    SBT_InOrderPrintTree(Node->Left);
    putchar(' ');
    putchar(Node->Data);
    SBT_InOrderPrintTree(Node->Right);
}

void SBT_PostOrderPrintTree(SBTNode* Node)
{
    if (Node == NULL)
        return;

    SBT_PostOrderPrintTree(Node->Left);
    SBT_PostOrderPrintTree(Node->Right);
    putchar(' ');
    putchar(Node->Data);
}