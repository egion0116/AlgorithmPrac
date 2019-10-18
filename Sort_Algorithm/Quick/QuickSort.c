#include "stdfx.h"
#include "QuickSort.h"
#include "Insertion.h"

/*
    두가지 파티션 방법에 따라 속도가 달라지는것을 알 수 있다.
*/

/*
	퀵 소트의 최적화 방법 3가지
		1. 퀵소트의 효율이 삽입정렬과 일치되는 컷오프 자료양은 10개정도이다.
			따라서, 10개이하의 자료에 대해서는 파티션이 아닌 인서션을 사용하는 편이 낫다.
		2. 파티션을 하기위해 피봇을 잡을때 3값을 잡아(Randomly 하게 잡는게 가장 좋다) 
			그 값들의 중간값을 피봇으로 잡는게 최악의 수를 방지할 수 있는 방법이다.
		3. 중복키를 잡기위해 3 point way를 사용한다. 
			-> 파티션시에 ld와 rd변수를 추가적으로 이용해 중복되는 값을 한곳에 몰아넣는다.
			-> 이후 ld 왼쪽으로 rd 오른쪽으로 추가 재귀를 하면 중복키를 막을 수 있다.
*/

// 퀵소트보다 삽입정렬이 더 빠른 정보의 갯수
#define QuickSort_CutOff 10

void Swap(int* Left, int* Right)
{
	int Temp = *Left;
	*Left = *Right;
	*Right = Temp;
}

int Another_Partition(int Arr[], int Left, int Right)
{
	int Pivot = Left;

	int i = Left + 1;
	int j = Right;

	while (1)
	{
		if (i <= j && Arr[i] <= Arr[Pivot]) i++;
		if (i <= j && Arr[j] > Arr[Pivot]) j--;

		if (i < j)
			Swap(&Arr[i], &Arr[j]);
		else
			break;
	}
	Swap(&Arr[j], &Arr[Pivot]);

	return j;
}

int Partition(int Arr[], int Left, int Right)
{
	int Pivot = Right;
	int i = Left;

	for (int j = Left; j < Right; j++)
	{
		if (Arr[j] < Arr[Pivot])
		{
			Swap(&Arr[i], &Arr[j]);
			i++;
		}
	}
	Swap(&Arr[i], &Arr[Pivot]);

	return i;
}

void QuickSort(int Arr[], int Left, int Right, int(*partition)(int*, int, int))
{
	if (Left > Right)
		return;

	int Pivot = partition(Arr, Left, Right);

	QuickSort(Arr, Left, Pivot - 1, partition);
	QuickSort(Arr, Pivot + 1, Right, partition);
}

void QuickSort_Optimized(int Arr[], int Left, int Right, int(*partition)(int*, int, int))
{
	// 최적화 방법 1 : 10보다 작은 정보양에 대해서는 삽입정렬을 사용하는게 더 빠를수 있다.
	if (Right - Left + 1 <= QuickSort_CutOff)
	{
		Insertion_Interval(Arr, Left, Right);
		return;
	}
	
	int Pivot = partition(Arr, Left, Right);

	QuickSort_Optimized(Arr, Left, Pivot - 1, partition);
	QuickSort_Optimized(Arr, Pivot + 1, Right, partition);
}

int Comparison(const void* _elem1, const void* _elem2)
{
    const int* elem1 = (int*)_elem1;
    const int* elem2 = (int*)_elem2;

    if (*elem1 >= *elem2)
        return 1;

    return -1;
}
