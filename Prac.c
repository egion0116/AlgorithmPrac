#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int Length = 100;
    int* Arr = (int*)calloc(sizeof(int), Length);

    SetArrRandom(Arr, Length);

    PrintAll(Arr, Length);

    Length = 120;

    int* For_Error = Arr;
    Arr = (int*)realloc(Arr, sizeof(int) * Length);
    if (Arr == 0)
    {
        free(For_Error);
        perror("memory allocate error");
        exit(1);
    }

    PrintAll(Arr, Length);

    printf("Origin : %p and Realloc : %p\n", For_Error, Arr);

    return 0;
}