#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Insertion_Sort_Asc(int* Arr, int Arr_Size);

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

void PrintArr(int Arr[], int Arr_Size)
{
    for (int i = 0, LineNum = 1; i < Arr_Size; i++)
    {
        if (i % 10 == 0)
            printf("%d : \t", LineNum++);
        printf("%d\t", Arr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }
}

int main(void)
{
    int Arr_Size = 10000;
    int* Arr = (int*)calloc(sizeof(int), Arr_Size);

    srand(time(NULL));
    // 배열 초기화
    for (int i = 0; i < Arr_Size; i++)
        Arr[i] = rand();

    clock_t Spent_Clock = clock();
    Insertion_Sort_Asc(Arr, Arr_Size);
    Spent_Clock = clock() - Spent_Clock;

    // PrintArr(Arr, Arr_Size);

    printf("Spent Time : %lf\n", (double)Spent_Clock / CLOCKS_PER_SEC);

    return 0;
}