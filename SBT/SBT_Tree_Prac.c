#include "SBT_Tree.h"

int main(void)
{
    SBTNode* A = SBT_CreateNode('A');
    SBTNode* B = SBT_CreateNode('B');
    SBTNode* C = SBT_CreateNode('C');
    SBTNode* D = SBT_CreateNode('D');
    SBTNode* E = SBT_CreateNode('E');
    SBTNode* F = SBT_CreateNode('F');
    SBTNode* G = SBT_CreateNode('G');

    A->Left = B;
    B->Left = C;
    B->Right = D;

    A->Right = E;
    E->Left = F;
    E->Right = G;

    printf("Preorder...\n");
    SBT_PreOrderPrintTree(A);
    printf("\n\n");

    printf("InOrder...\n");
    SBT_InOrderPrintTree(A);
    printf("\n\n");

    printf("PostOrder...\n");
    SBT_PostOrderPrintTree(A);
    printf("\n");

    SBT_DestroyTree(A);

    return 0;
}