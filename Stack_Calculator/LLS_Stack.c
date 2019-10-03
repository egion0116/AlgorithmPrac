#include "stdfx.h"
#include "LLS_Stack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Target = LLS_Pop(Stack);
		free(Target);
	}

	free(Stack);
}

Node* LLS_CreateNode(char* p_Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	size_t Size = sizeof(char) * strlen(p_Data) + 1;
	NewNode->Data = (char*)malloc(Size);
	NewNode->NextNode = NULL;

	strcpy(NewNode->Data, p_Data);

	return NewNode;
}

void LLS_DestroyNode(Node* p_Node)
{
	free(p_Node->Data);
	free(p_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* p_Node)
{
	if (LLS_IsEmpty(Stack))
		Stack->List = p_Node;
	else
		Stack->Top->NextNode = p_Node;

	Stack->Top = p_Node;
}

// 주의!! 파괴는 호출자에서 해야한다!
Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* Res = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Node* Temp = Stack->List;

		while (Temp->NextNode != Stack->Top)
			Temp = Temp->NextNode;

		Stack->Top = Temp;
		Stack->Top->NextNode = NULL;
	}

	return Res;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	Node* Res = Stack->Top;

	return Res;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int Size = 0;

	Node* Temp = Stack->List;
	while (Temp != NULL)
	{
		Temp = Temp->NextNode;
		Size++;
	}

	return Size;
}