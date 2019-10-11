#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Print_SelfNum(int Maximum);
int Operator_D(int Number);
void Extract_Max_Min_Num(int Number, int* Max, int* Min);
int* Extract_Numbers(int Number, int* Length);
void Arr_Inverse(int Arr[], int Length);
void Arr_PrintAll(int Arr[], int Lenght);

/*
    셀프넘버 찾기..
    -> 주어진 구간은 1 ~ Maximum까지 이다.

    1. 1 ~ Maximum까지 매핑하는 LookUp을 만든다.
    2. 1부터 D연산을 해서 나오는 모든 값을 LookUp 인덱스에 넣고 해당 값을 1씩 증가시킨다. (인덱스 유계를 만족시키기 위해 Maximum보다 작거나 같은값만 진행)
    3. 배열상 0값을 가지는 인덱스가 최종적인 셀프넘버이다.

    왜냐하면.. 무한번 가능하다고 해도 어차피 D연산 자체가 자기자신보다 무조건 커질수 밖에 없는 연산이기 때문에 비선형적인 탐색이 필요없다.
*/
void Print_SelfNum(int Maximum)
{
    // 1. 1 ~ Maximum까지 매핑하는 Lookup
    int* Numbers = (int*)calloc(sizeof(int), Maximum + 1);
    int Operated_Result = 0;

    for (int i = 1; i <= Maximum; i++)
    {
        Operated_Result = Operator_D(i);

        if(Operated_Result <= Maximum)
            Numbers[Operated_Result]++;
    }

    for (int i = 1; i <= Maximum; i++)
    {
        if (Numbers[i] == 0)
            printf("%d\n", i);
    }
}

int Operator_D(int Number)
{
    int Result = Number;

    while (Number)
    {
        Result += Number % 10;
        Number /= 10;
    }

    return Result;
}

void Extract_Max_Min_Num(int Number, int* Max, int* Min)
{
    *Min = Number % 10;
    while (Number)
    {
        *Max = Number % 10;
        Number /= 10;
    }
}

int* Extract_Numbers(int Number, int* Length)
{
	*Length = 20;
	int* Numbers = (int*)calloc(sizeof(int), 20);

	for (int i = 0; Number != 0; i++)
	{
		Numbers[i] = Number % 10;
		Number /= 10;
	}

	return Numbers;
}

void Arr_Inverse(int Arr[], int Length)
{
	int Temp = 0;
	int Loop_Length = Length / 2;

	for (int i = 0; i < Loop_Length; i++)
	{
		Temp = Arr[i];
		Arr[i] = Arr[Length - i - 1];
		Arr[Length - i - 1] = Temp;
	}
}

void Arr_PrintAll(int Arr[], int Length)
{
	for (int i = 0, Line = 1; i < Length; i++)
	{
		if (i % 10 == 0)
			printf("%d :\t", Line++);
		printf("%d\t", Arr[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
}

int main(void)
{
	Print_SelfNum(10000);

	return 0;
}