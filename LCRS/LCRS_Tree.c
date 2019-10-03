#include "LCRS_Tree.h"

// Create Empty!! Node
LCRSNode* LCRS_CreateNode(ElementType NewData)
{
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));

    NewNode->Data = NewData;
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;

    return NewNode;
}

// Destroy Empty!! Node
void LCRS_DestroyNode(LCRSNode* Node)
{
    free(Node);
}

// Add Child
void LCRS_AddChild(LCRSNode* Parent, LCRSNode* Child)
{
    // if There is no child, Add new child
    if (Parent->LeftChild == NULL)
    {
        Parent->LeftChild = Child;
        return;
    }

    LCRSNode* Node_Temp = Parent->LeftChild;
    while(Node_Temp->RightSibling != NULL)
        Node_Temp = Node_Temp->RightSibling;
    
    Node_Temp->RightSibling = Child;
}

void LCRS_PrintAll(LCRSNode* Root, int Depth)
{
    for (int i = 0; i < Depth; i++)
        printf(" ");

    printf("%d\n", Root->Data);

    if (Root->LeftChild != NULL)
        LCRS_PrintAll(Root, Depth + 1);
    
    if (Root->RightSibling != NULL)
        LCRS_PrintAll(Root, Depth);
}