#include "stdfx.h"
#include "NR_Quick.h"

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

void SetArrRandom(int Arr[], int Length)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < Length; i++)
        Arr[i] = rand();
}

int Comparison(const void* _elem1, const void* _elem2)
{
    const int* elem1 = (int*)_elem1;
    const int* elem2 = (int*)_elem2;

    if (*elem1 >= *elem2)
        return 1;

    return -1;
}


int main(void)
{
    int Length = 10000000;
    int* Arr = (int*)calloc(sizeof(int), Length);

    SetArrRandom(Arr, Length);

    clock_t Spent = clock();
    NR_QuickSort(Arr, Length);
    Spent = clock() - Spent;

    printf("Non-Recursive QuickSort : %lf\n", (double)Spent / CLOCKS_PER_SEC);

    SetArrRandom(Arr, Length);

    Spent = clock();
    qsort((void*)Arr, Length, sizeof(int), Comparison);
    Spent = clock() - Spent;

    printf("QuickSort_std : %lf\n", (double)Spent / CLOCKS_PER_SEC);

    return 0;
}