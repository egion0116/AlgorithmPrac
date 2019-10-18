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

int main(void)
{
    int Length = 18000;
    int* Arr = (int*)calloc(sizeof(int), Length);

    SetArrRandom(Arr, Length);

    clock_t Spent = clock();
    NR_QuickSort(Arr, Length);
    Spent = clock() - Spent;
    
    printf("Non-Recursive QuickSort : %lf\n", (double)Spent / CLOCKS_PER_SEC);

    return 0;
}