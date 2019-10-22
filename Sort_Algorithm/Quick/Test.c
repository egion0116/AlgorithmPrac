#include "stdfx.h"
#include "Insertion.h"
#include "QuickSort.h"

void SetArrRandom(int Arr[], int Length)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < Length; i++)
        Arr[i] = rand();
}

void PrintAll(int Arr[], int Length)
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
	int Length = 10000000;
	int* Arr = (int*)calloc(sizeof(int), Length);

	SetArrRandom(Arr, Length);

	clock_t Spent = clock();
	QuickSort(Arr, 0, Length - 1, Partition);
	Spent = clock() - Spent;

	printf("QuickSort_FestPartition : %lf\n", (double)Spent / CLOCKS_PER_SEC);

	// SetArrRandom(Arr, Length);

	// Spent = clock();
	// QuickSort(Arr, 0, Length - 1, Another_Partition);
	// Spent = clock() - Spent;

	// printf("QuickSort_SlowPartiton : %lf\n", (double)Spent / CLOCKS_PER_SEC);

    SetArrRandom(Arr, Length);

	Spent = clock();
    qsort((void*)Arr, Length, sizeof(int), Comparison);
	Spent = clock() - Spent;

	printf("QuickSort_std : %lf\n", (double)Spent / CLOCKS_PER_SEC);

	// 콜스텍 오버플로우가 난다.
    // SetArrRandom(Arr, Length);

    // Spent = clock();
    // QuickSort_Optimized(Arr, 0, Length - 1, Partition);
	// Spent = clock() - Spent;

	// printf("QuickSort_Optimized : %lf\n", (double)Spent / CLOCKS_PER_SEC);

	return 0;
}