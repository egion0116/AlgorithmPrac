#pragma once

typedef char* ElementType;

typedef struct tagTreeNode
{
    ElementType Data;

    struct tagNode* Left;
    struct tagNode* Right;
}TreeNode;

TreeNode* CreateTreeNode(char* p_Data);
void DestroyTree(TreeNode* BinaryTree);
