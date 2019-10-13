#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    두가지 파티션 방법에 따라 속도가 달라지는것을 알 수 있다.
*/

void Swap(int* Left, int* Right);
int Another_Partition(int Arr[], int Left, int Right);
int Partition(int Arr[], int Left, int Right);
void QuickSort(int Arr[], int Left, int Right, int(*partition)(int*, int, int));

void RandomSet(int Arr[], int Length);
void Print(int Arr[], int Length);

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

void RandomSet(int Arr[], int Length)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < Length; i++)
		Arr[i] = rand();
}

void Print(int Arr[], int Length)
{
	for (int i = 0, Number = 1; i < Length; i++)
	{
		if (i % 10 == 0)
			printf("%d :\t", Number++);
		printf("%d\t", Arr[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
}

int main(void)
{
	int Arr[1000000] = { 0 };
	int Length = sizeof(Arr) / sizeof(int);

	RandomSet(Arr, Length);

	clock_t Spent = clock();
	QuickSort(Arr, 0, Length - 1, Partition);
	Spent = clock() - Spent;

	printf("QuickSort_1 : %lf\n", (double)Spent / CLOCKS_PER_SEC);

	RandomSet(Arr, Length);

	Spent = clock();
	QuickSort(Arr, 0, Length - 1, Another_Partition);
	Spent = clock() - Spent;

	printf("QuickSort_2 : %lf\n", (double)Spent / CLOCKS_PER_SEC);

	return 0;
}
