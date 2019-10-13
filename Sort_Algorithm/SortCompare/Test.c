#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Common.h"
#include "Sort.h"

int main(void)
{
    int Arr[100000] = { 0 };
    int Length = sizeof(Arr) / sizeof(int);

    // 초기화
    RandomSet(Arr, Length);

    // Bubble Sort
    clock_t Spent = clock();
    BubbleSort_Asc(Arr, Length);
    Spent = clock() - Spent;

    printf("Bubble Sort : %lf\n", (double)Spent / CLOCKS_PER_SEC);

    // 초기화
    RandomSet(Arr, Length);

    // Insertion Sort
    Spent = clock();
    Insertion_Sort_Asc(Arr, Length);
    Spent = clock() - Spent;
    
    printf("Insertion Sort : %lf\n", (double)Spent / CLOCKS_PER_SEC);

    // 초기화
    RandomSet(Arr, Length);

    // Quick Sort
    Spent = clock();
    QuickSort(Arr, 0, Length - 1);
    Spent = clock() - Spent;

    printf("Quick Sort : %lf\n", (double)Spent / CLOCKS_PER_SEC);

    return 0;
}