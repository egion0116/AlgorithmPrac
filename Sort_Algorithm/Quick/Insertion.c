#include "Insertion.h"
#include "stdfx.h"

void Insertion_Sort(int Arr[], int Length)
{
    for (int i = 1; i < Length; i++)
    {
        // 최적화 방법 1 : 해당 값이 이전 정렬된 값의 최대값보다 크면 정렬을 하지 않는다.
        if (Arr[i - 1] <= Arr[i])
            continue;
        
        for (int j = 0; j < i; j++)
        {
            if (Arr[j] >= Arr[i])
            {
                int Temp = Arr[i];
                memcpy(&Arr[j + 1], &Arr[j], sizeof(int) * (i - j));
                Arr[j] = Temp;
                break;
            }
        }
    }
}

void Insertion_Interval(int Arr[], int Left, int Right)
{
    for (int i = Left + 1; i <= Right; i++)
    {
        if (Arr[i - 1] <= Arr[i])
            continue;
        for (int j = Left; j < Right; j++)
        {
            if (Arr[j] >= Arr[i])
            {
                int Temp = Arr[i];
                memcpy(&Arr[j + 1], &Arr[j], sizeof(int) * (i - j));
                Arr[j] = Temp;
                break;
            }
        }
    }
}