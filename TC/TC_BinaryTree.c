#include "stdfx.h"
#include "TC_BinaryTree.h"

TreeNode* CreateTreeNode(char* p_Data)
{
    TreeNode* NewTreeNode = (TreeNode*)malloc(sizeof(TreeNode));

    int Length = strlen(p_Data);
    NewTreeNode->Data = (char*)malloc(sizeof(char) * Length + 1);
    strcpy(NewTreeNode->Data, p_Data);

    NewTreeNode->Left = NULL;
    NewTreeNode->Right = NULL;

    return NewTreeNode;
}

void DestroyTree(TreeNode* BinaryTree)
{
    if (BinaryTree == NULL)
        return;

    DestroyTree(BinaryTree->Left);
    DestroyTree(BinaryTree->Right);

    free(BinaryTree->Data);
    free(BinaryTree);
}

