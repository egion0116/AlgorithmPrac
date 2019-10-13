#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Common.h"

void RandomSet(int Arr[], int Length)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < Length; i++)
		Arr[i] = rand();
}

void Print(int Arr[], int Length)
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