#include "stdfx.h"
#include "Insertion.h"

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
    int Arr[1000] = { 0 };
    int Length = sizeof(Arr) / sizeof(int);

    SetArrRandom(Arr, Length);

    Insertion_Sort(Arr, Length);

    PrintAll(Arr, Length);
}