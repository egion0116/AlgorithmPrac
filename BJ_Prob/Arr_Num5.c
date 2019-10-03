#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int Input[10] = { 0 };
    int Same_Arr[42] = { 0 };

    // 숫자 10개를 입력받음과 동시에 42로 나눈 나머지를 대입한다.
    for (int i = 0; i < sizeof(Input) / sizeof(int); i++)
    {
        scanf("%d", &Input[i]);
        Same_Arr[Input[i] % 42]++;
    }

    int Count = 0;
    for (int i = 0; i < sizeof(Same_Arr) / sizeof(int); i++)
        if (Same_Arr[i] != 0)
            Count++;
    
    printf("%d\n", Count);

   return 0;
}