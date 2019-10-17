#include "stdfx.h"
#include "SingleLinkedList.h"

Node* SLL_CreateNode(ElementType Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = Data;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SLL_DestroyNode(Node* Head)
{
    free(Head);
}

void SLL_AppendNode(Node** Head, Node* Target)
{
    if ((*Head) == NULL) (*Head) = Target;

    Node* Current = *Head;
    while(Current->NextNode != NULL)
        Current = Current->NextNode;
    
    Current->NextNode = Target;
}


// 리스트의 형태만 바꿀뿐.. 해당 노드의 해제는 호출자에게 달렸다.
void SLL_RemoveNode(Node** Head, Node* Target)
{
    // 삭제하려는 대상이 헤드일경우

    if (*Head == Target) 
    {
        *Head = Target->NextNode;
        Target->NextNode = NULL;
        return;
    }

    // 노드간 삭제, 노드끝 삭제의 경우 같은 동작으로 구현 가능!
    
    Node* Current = *Head;
    // 찾는 대상이 없을때를 고려한다.. 
    while(Current != NULL && Current->NextNode != Target)
        Current = Current->NextNode;

    // 찾는 대상이 있으면 리스트에서 제외
    if (Current != NULL)
    {
        Current->NextNode = Target->NextNode;
        Target->NextNode = NULL;
    }
}

Node* SLL_GetNodeAt(Node* Head, int Position)
{
    Node* Current = Head;

    while (Current->NextNode != NULL && (--Position) >= 0)
        Current = Current->NextNode;
    
    return Current;
}

void SLL_InsertNode(Node* Origin, Node* Target)
{
    Target->NextNode = Origin->NextNode;
    Origin->NextNode = Target;
}

void SLL_PrintAllNodes(const Node* Head)
{
    const Node* Current = Head;
    int Num = SLL_GetNodesNum(Head);

    for (int i = 0; i < Num; i++)
    {
        printf("List[%d] : %d\t", i, Current->Data);
        Current = Current->NextNode;
    }
    
    putchar('\n');
}

int SLL_GetNodesNum(const Node* Head)
{
    const Node* Current = Head;
    int Num = 1;

    while(Current->NextNode != NULL)
    {
        Current = Current->NextNode;
        Num++;
    }
    
    return Num;
}

void SLL_DestroyList(Node* Head)
{
    int Node_Number = SLL_GetNodesNum(Head);

    for(int i = 0; i < Node_Number; i++)
    {
        Node* Temp = SLL_GetNodeAt(Head, 0);

        SLL_RemoveNode(&Head, Temp);
        SLL_DestroyNode(Temp);
    }
}