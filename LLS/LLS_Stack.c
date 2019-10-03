#include "LLS_Stack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

    (*Stack)->Top = NULL;
    (*Stack)->List = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
    while(!LLS_IsEmpty(Stack))
    {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }

    free(Stack);
}

Node* LLS_CreateList(char* p_Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    size_t size = sizeof(char) * strlen(p_Data) + 1;
    NewNode->Data = (char*)malloc(size);
    strcpy(NewNode->Data, p_Data);

    NewNode->NextNode = NULL;

    return NewNode;
}

void LLS_DestroyNode(Node* p_Node)
{
    free(p_Node->Data);
    free(p_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* p_Node)
{
    if (Stack->List == NULL)
        Stack->List = p_Node;
    else
        Stack->Top->NextNode = p_Node;
    
    Stack->Top = p_Node;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
    Node* TopNode = Stack->Top;

    if (Stack->List == Stack->Top)
    {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else
    {
        Node* CurrentNode = Stack->List;

        while (CurrentNode != NULL && CurrentNode->NextNode != Stack->Top)
            CurrentNode = CurrentNode->NextNode;
        
        Stack->Top = CurrentNode;
        CurrentNode->NextNode = NULL;
    }

    return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
    Node* CurrentTop = Stack->Top;

    return CurrentTop;
}

int LLS_GetSize(LinkedListStack* Stack)
{
    int Size = 0;

    Node* CurrentNode = Stack->List;

    while (CurrentNode != NULL)
    {
        CurrentNode = CurrentNode->NextNode;
        Size++;
    }

    return Size;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
    return (Stack->List==NULL);
}