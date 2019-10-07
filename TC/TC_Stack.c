#include "stdfx.h"
#include "TC_Stack.h"

void CreateStack(LinkedListStack** Stack)
{
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

void DestroyStack(LinkedListStack* Stack)
{
    Node* Target = NULL;

    while (!IsEmpty(Stack))
    {
        Target = Pop(Stack);
        DestroyNode(Target);
    }

    free(Stack);
}

Node* CreateNode(const char* Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    int Length = strlen(Data);
    NewNode->Data = (char*)malloc(sizeof(char) * Length + 1);
    strcpy(NewNode->Data, Data);

    NewNode->NextNode = NULL;

    return NewNode;
}

void DestroyNode(Node* p_Node)
{
    free(p_Node->Data);

    free(p_Node);
}

void Push(LinkedListStack* Stack, Node* p_Node)
{
    if (Stack->List == NULL)
        Stack->List = Stack->Top = p_Node;
    else
    {
        Stack->Top->NextNode = p_Node;
        Stack->Top = p_Node;
    }
}

Node* Pop(LinkedListStack* Stack)
{
    Node* NewNode = Stack->Top;

    if (Stack->Top == Stack->List)
        Stack->Top = Stack->List = NULL;
    else
    {
		Node* Temp = Stack->List;
        while (Temp->NextNode != Stack->Top)
			Temp = Temp->NextNode;

        Stack->Top = Temp;
		Temp->NextNode = NULL;
    }

    return NewNode;
}

Node* GetTop(LinkedListStack* Stack)
{
    return Stack->Top;
}

int GetSize(LinkedListStack* Stack)
{
    Node* Trace = Stack->List;
    int Size = 0;

    while (Trace != NULL)
    {
        Size++;
        Trace = Trace->NextNode;
    }
    
    return Size;
}

int IsEmpty(LinkedListStack* Stack)
{
    if (Stack->List == NULL)
        return 1;
    
    return 0;
}