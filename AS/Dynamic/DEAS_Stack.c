#include "stdfx.h"
#include "DEAS_Stack.h"

void DEAS_CreateStack(Stack** p_Stack)
{
    (*p_Stack) = (Stack*)malloc(sizeof(Stack));

    (*p_Stack)->Capacity = 100;
    (*p_Stack)->Top = 0;
    (*p_Stack)->Nodes = (ElementType*)calloc(sizeof(ElementType), (*p_Stack)->Capacity);
}

void DEAS_Push(Stack* p_Stack, ElementType p_Data)
{
    /*
        범위를 초과하면
            1. Capacity를 30% 늘린다.
            2. 늘린 Capacity만큼 메모리를 realloc으로 재할당한다.
            3. realloc 메모리 누수를 막기위해 안전장치 프로그래밍을 한다.
    */
    if (p_Stack->Capacity <= p_Stack->Top)
    {
        p_Stack->Capacity += (int)((double)p_Stack->Capacity * 0.3);
        int* Temp = p_Stack->Nodes;
        p_Stack->Nodes = (ElementType*)realloc(p_Stack->Nodes, sizeof(ElementType) * p_Stack->Capacity);
        if (p_Stack->Nodes == NULL)
        {
            free(Temp);
            perror("memory realloc error");
            exit(1);
        }
    }

    p_Stack->Nodes[p_Stack->Top++] = p_Data;
}

ElementType DEAS_Pop(Stack* p_Stack, ElementType p_Data)
{
    /*
        용량이 100 이상이면서 용량의 70퍼센트 이하의 사용률을 나타내면
            1. 용량을 20퍼센트 줄인다.
            2. 줄여진 용량대로 realloc을 한다.
    */
    if (p_Stack->Capacity >= 100 && p_Stack->Top < (int)((double)p_Stack->Capacity * 0.70))
    {
        p_Stack->Capacity -= (int)((double)p_Stack->Capacity * 0.2);
        int* Temp = p_Stack->Nodes;
        p_Stack->Nodes = (ElementType*)realloc(p_Stack->Nodes, sizeof(ElementType) * p_Stack->Capacity);
        if (p_Stack->Nodes == NULL)
        {
            free(Temp);
            perror("memory realloc error");
            exit(1);
        }
    }

    int Current = --p_Stack->Top;

    return p_Stack->Nodes[Current];
}