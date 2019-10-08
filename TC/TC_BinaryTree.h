#pragma once

typedef char* ElementType;

typedef struct tagTreeNode
{
    ElementType Data;

    struct tagTreeNode* Left;
    struct tagTreeNode* Right;
}TreeNode;

TreeNode* CreateTreeNode(char* p_Data);
void DestroyTree(TreeNode* BinaryTree);
