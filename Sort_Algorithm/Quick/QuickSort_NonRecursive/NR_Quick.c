#include "stdfx.h"
#include "NR_Stack.h"
#include "NR_Quick.h"

// 재귀 퀵정렬을 비재귀 형태로 구현

void Swap(int* Operand1, int* Operand2)
{
    int Temp = *Operand2;
    *Operand2 = *Operand1;
    *Operand1 = Temp;
}

int NR_Partition(int Arr[], int Left, int Right)
{
    int Pivot = Arr[Right];
    int i = Left;

    for (int j = Left; j < Right; j++)
    {
        if (Arr[j] < Pivot)
        {
            Swap(&Arr[i], &Arr[j]);
            i++;
        }
    }
    Swap(&Arr[i], &Arr[Right]);

    return i;
}

/*
    재귀시 변화하는 변수를 전부 스택화 시키는게 아이디어...
*/

void NR_QuickSort(int Arr[], int Length)
{
    // 스택 초기화 및 생성
    Stack* Req_Stack = NULL;
    CreateStack(&Req_Stack);

    // 초기값 넣기
    Push(Req_Stack, 0, Length - 1);

    while (!IsEmptyStack(Req_Stack))
    {
        Node Req_Node = *Pop(Req_Stack);

        // 스택이 더이상 쌓이지 않을 조건
        if (Req_Node.Left < Req_Node.Right)
        {
            int Pivot = NR_Partition(Arr, Req_Node.Left, Req_Node.Right);

            Push(Req_Stack, Req_Node.Left, Pivot - 1);
            Push(Req_Stack, Pivot + 1, Req_Node.Right);
        }
    }

    DestroyStack(&Req_Stack);
}