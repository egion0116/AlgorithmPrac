#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itos(const int p_Num, char Target[]);
int NumToChar(int p_Num, char* Target);
void Rev_String(char* Target);
void CheckNumbers(char* Target, int Result[]);

char LookUp[10] = { '0' ,'1', '2', '3', '4', '5', '6', '7', '8', '9' };

/*
	int를 문자열로 만들기
		1. 매개변수로 숫자를 받는다.
		2. (p_Num / 10^n) % 10 의 공식으로 만든다.
		3. 남은 숫자를 LookUp과 비교하여 어떤것 인지 확인한다.
*/
void itos(const int p_Num, char Target[])
{
	char Temp_Char = 0;
	int Temp = -1;

	for (int Dec = 1, i = 0; Dec < p_Num; Dec *= 10, i++)
	{
		Temp = (p_Num / Dec) % 10;
		NumToChar(Temp, &Temp_Char);
		Target[i] = Temp_Char;
	}

	Rev_String(Target);
}

// 1의 자리 숫자를 단일문자로 치환합니다.
int NumToChar(int p_Num, char* Target)
{
	for (int i = 0; i < sizeof(LookUp) / sizeof(char); i++)
	{
		if (p_Num == i)
		{
			*Target = LookUp[i];
			return 1;   // 변환 성공
		}
	}

	// 변환 실패
	return 0;
}

// 문자열 뒤집기
void Rev_String(char* Target)
{
	int Length = strlen(Target);
	int Pos_To_Change = Length - 1;

	for (int i = 0; i < Length / 2; i++)
	{
		char Temp = Target[Pos_To_Change - i];
		Target[Pos_To_Change - i] = Target[i];
		Target[i] = Temp;
	}
}

// 배열내에 0~9까지 숫자가 각각 몇개 있는지 확인한다.
void CheckNumbers(char* Target, int Result[])
{
	int Length = strlen(Target);

	for (int i = 0; i < Length; i++)
	{
		for (int j = 0; j < sizeof(LookUp) / sizeof(char); j++)
		{
			if (Target[i] == LookUp[j])
			{
				Result[j]++;
				break;
			}
		}
	}
}

int main(void)
{
	int Input = 1219402;
	char Output[32] = { 0 };

	int Operand1 = 0, Operand2 = 0, Operand3 = 0;
	scanf("%d %d %d", &Operand1, &Operand2, &Operand3);

	int Result_Num = Operand1 * Operand2 * Operand3;
	char Result_String[32] = { 0 };
	itos(Result_Num, Result_String);

	int Result_NumStat[10] = { 0 };
	CheckNumbers(Result_String, Result_NumStat);
	for (int i = 0; i < sizeof(Result_NumStat) / sizeof(int); i++)
		printf("%d\n", Result_NumStat[i]);

	return 0;
}