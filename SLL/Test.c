#include "stdfx.h"
#include "SingleLinkedList.h"

int main(void)
{
    Node* Head = SLL_CreateNode(10);

    SLL_AppendNode(&Head, SLL_CreateNode(20));
    SLL_AppendNode(&Head, SLL_CreateNode(30));
    SLL_AppendNode(&Head, SLL_CreateNode(40));
    SLL_AppendNode(&Head, SLL_CreateNode(50));
    SLL_AppendNode(&Head, SLL_CreateNode(60));
    SLL_AppendNode(&Head, SLL_CreateNode(70));

    SLL_PrintAllNodes(Head);

    puts("Inserting 3000 After List[2]");
    SLL_InsertNode(SLL_GetNodeAt(Head, 2), SLL_CreateNode(3000));
    
    SLL_PrintAllNodes(Head);

    SLL_DestroyList(Head);

    return 0;
}