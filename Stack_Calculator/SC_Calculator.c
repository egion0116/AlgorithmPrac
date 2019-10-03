#include "stdfx.h"
#include "SC_Basic.h"
#include "LLS_Stack.h"
#include "SC_Calculator.h"

/*
	후위 표현식 계산기

	(루프) 문자열이 끝날때 까지 읽는다. 
	-> 토큰을 읽어내는 방식으로 길이 초과시 탈출!
		1. 스택에 하나씩 담는다.
		2. 연산자가 발견되면 (스페이스바는 무시한다.)
			2-1. 스택에서 2개를 Pop한 뒤
			2-2. 해당 자료형을 double형으로 atof 표준함수를 이용해 바꾸고
			2-3. 해당하는 연산자로 계산을 한 뒤
			2-4. 연산 결과를 다시 스택으로 넣는다.
*/
double SC_Calculator(char* PostFixExp)
{
	// 계산 결과를 담을 스택을 저장한다.
	LinkedListStack* Cal_Stack;
	LLS_CreateStack(&Cal_Stack);

	// 토큰을 담아낼 배열과 받아낸 토큰의 종류
	char Token[32] = { 0 };
	int Type = 0;

	// 결과를 저장할 부동소수점 타입 변수 선언 및 초기화
	double result = 0.0;

	// 후위 표현식의 길이와 토큰 위치 변수
	int Length = strlen(PostFixExp);
	int Pos = 0;

	// 문자열이 끝날때 까지 읽기 
	while (Pos < Length)
	{
		// 토큰 받아오기 -> 이때 스페이스바는 토큰 읽어올때부터 무시하도록 설계했음
		Pos = SC_GetToken(PostFixExp, Pos, Token, &Type);

		// 받아온 토큰의 종류가 피연산자라면
		if (Type == OPERAND)
			// 토큰을 스택에 넣는다.
			LLS_Push(Cal_Stack, LLS_CreateNode(Token));
		else
		{
			/*
				이외에 가능성은 사칙연산자밖에 없다.
				왜냐하면 스페이스바는 토큰을 받아오면서 무시되고
				괄호는 후위 표현식을 만들면서 정리되기 때문이다.
			*/
			
			// 피연산자 2개를 스택에서 빼온다.
			Node* Operand_2 = LLS_Pop(Cal_Stack);
			Node* Operand_1 = LLS_Pop(Cal_Stack);

			// atof 표준함수로 문자열을 doulble 타입으로 변환한다.
			double f_Operand_2 = atof(Operand_2->Data);
			double f_Operand_1 = atof(Operand_1->Data);

			// 의존성이 없어진 메모리는 쓰고난 뒤 지운다.
			free(Operand_2);
			free(Operand_1);

			double Temp_Res = 0.0;
			char Temp_Str[32] = { 0 };

			// 연산자 케이스에 따라 계산한다.
			switch (Type)
			{
			case PLUS:
				Temp_Res = f_Operand_1 + f_Operand_2;
				break;
			case MINUS:
				Temp_Res = f_Operand_1 - f_Operand_2;
				break;
			case MULTIPLY:
				Temp_Res = f_Operand_1 * f_Operand_2;
				break;
			case DIVIDE:
				Temp_Res = f_Operand_1 / f_Operand_2;
				break;
			}
			
			// gcvt 함수로 소수점수를 문자열로 변환
			_gcvt(Temp_Res, 10, Temp_Str);

			// 결과를 스택에 저장
			LLS_Push(Cal_Stack, LLS_CreateNode(Temp_Str));
		}
	}

	// 마지막 남은 결과를 저장한다.
	result = atof(Cal_Stack->Top->Data);
	// 계산결과를 담은 스택을 해제한다. -> 내부 모든게 해제
	LLS_DestroyStack(Cal_Stack);

	// 결과를 반환한다.
	return result;
}