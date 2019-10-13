#include <string.h>
#include "Sort.h"

void Swap(int* Left, int* Right)
{
	int Temp = *Left;
	*Left = *Right;
	*Right = Temp;
}

// 버블정렬

void BubbleSort_Asc(int Arr[], int Arr_Size)
{

    for (int i = 0; i < Arr_Size - 1; i++)
    {
        // 최적화 기법 1 -> 첫번째 순회때 한번도 이동이 안생기면 모두 정렬된것으로 판단후 나간다.
        int Count = 0;

        // 최적화 기법 2 -> 이미 정렬이 된 수는 다시 정렬하지 않는다.
        for (int j = 0; j < Arr_Size - i - 1; j++)
        {
            if (Arr[j] > Arr[j+1])
            {
                int Temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = Temp;
                Count++;
            }
        }
        // 정렬이 되어있을 경우 : 한번도 교환이 일어나지 않을경우 -> 루프를 나간다.
        if (Count == 0)
            break;
    }
}

// 삽입정렬

void Insertion_Sort_Asc(int* Arr, int Arr_Size)
{
    // 삽입할 대상
    int val = 0;

    // 탐색 범위를 1~배열끝까지..
    for (int i = 1; i < Arr_Size; i++)
    {
        // 최적화 테크닉 1. 이미 정렬이 되어있으면 정렬하지 않는다.
        if (Arr[i - 1] <= Arr[i])
            continue;

        val = Arr[i];
        for (int j = 0; j < i; j++)
        {
            if (Arr[j] > val)
            {
                memmove(&Arr[j+1], &Arr[j], sizeof(int) * (i - j));
                Arr[j] = val;
                break;
            }
        }
    }
}

// 퀵소트

int Partition(int Arr[], int Left, int Right)
{
	int Pivot = Right;
	int i = Left;

	/*
		알고리즘 고찰..
			두개의 탐색자를 이용해 하나는 박아두고 나머지 하나만 움직여
			피봇보다 작은 친구는 전부 왼쪽 탐색자로 보낸뒤 왼쪽 탐색자를 1 증가시킨다.
	*/
	for (int j = Left; j < Right; j++)
	{
		if (Arr[j] <= Arr[Pivot])
		{
			Swap(&Arr[i], &Arr[j]);
			i++;
		}
	}

	// i의 위치와 피봇을 교환한다.
	Swap(&Arr[i], &Arr[Pivot]);

	// 피봇의 위치정보를 반환한다.
	return i;
}

// 퀵소트
void QuickSort(int Arr[], int Left, int Right)
{
	// 재귀 탈출조건
	if (Left > Right)
		return;

	int Pivot = Partition(Arr, Left, Right);

	// 왼쪽 재귀
	QuickSort(Arr, Left, Pivot - 1);
	// 오른쪽 재귀
	QuickSort(Arr, Pivot + 1, Right);
}
