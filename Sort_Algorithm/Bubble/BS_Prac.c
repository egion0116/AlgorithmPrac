#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort_Asc(int Arr[], int Arr_Size)
{
    // 최적화 기법 1 -> 첫번째 순회때 한번도 버블
    int Count = 0;

    for (int i = 0; i < Arr_Size; i++)
    {
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

void PrintArr(int Arr[], int Arr_Size)
{
    for (int i = 0, LineNum = 1; i < Arr_Size; i++)
    {
        if (i % 10 == 0)
            printf("%d :\t", LineNum++);
        printf("%d\t", Arr[i]);
        if (i % 10 == 9)
            putchar('\n');
    }
}

int main(void)
{
    int arr[100000] = { 0 };
    int arr_Size = sizeof(arr) / sizeof(int);

    srand(time(NULL));
    for (int i = 0; i < arr_Size; i++)
        arr[i] = rand();

    clock_t t = clock();
    BubbleSort_Asc(arr, arr_Size);
    t = clock() - t;
    // PrintArr(arr, arr_Size);
    printf("Spend Time : %lf\n", (double)t / CLOCKS_PER_SEC);

    return 0;
}

