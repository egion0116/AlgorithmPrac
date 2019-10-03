#include "stdfx.h"
#include "SC_Basic.h"
#include "LLS_Stack.h"

const char NUMBER[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

void SC_GetPostFixExp(char* InFixExp, char* PostFixExp)
{
	/*
	(루프) 표현식을 토큰중심으로 끝까지 읽는다. -> 문자 길이 탈출조건 (파서로 읽은 길이가 원 문장 길이보다 길면 탈출)
		1. 피연산자이면 -> PostFixExp에 strcat으로 복사
		2. 연산자이면 ->
			2-1. 연산자 우선순위를 따져 높으면 넣고 낮으면 strcat으로 복사
			2-2. 왼쪽괄호는 예외적으로 무조건 스택에 넣는다.
			2-3. 오른쪽괄호는 지끔까지 스택에 있는 연산자를 왼쪽괄호를 만날때까지 출력하고 왼쪽은 그냥 제거한다.

	(루프) 스택에 남은 연산자들을 순서대로 Pop 연산을 하여 출력한다. -> 스택에 아무것도 없을때 까지
	*/

	LinkedListStack* OperatorStack;
	LLS_CreateStack(&OperatorStack);

	int Length = strlen(InFixExp);   // 원문의 길이
	int Num = 0;                     // 읽을 인덱스값

	char parsed_result[32] = { 0 };    // 파싱한 결과를 저장
	int Type = 0;                    // 타입을 저장

	 // 읽을 인덱스가 원문 길이를 초과하면 탈출한다.
	while (Num < Length)
	{
		// 토큰을 읽어서 저장한다.
		Num = SC_GetToken(InFixExp, Num, parsed_result, &Type);
		if (Type == OPERAND)    // 피연산자이면 그대로 표현식으로 출력
		{
			strcat(PostFixExp, parsed_result);
			strcat(PostFixExp, " ");
		}
		else                    // 연산자이면
		{
			// 왼쪽 괄호이면 무조건 스택에 삽입
			if (Type == LEFT_PARENTHESIS)
				LLS_Push(OperatorStack, LLS_CreateNode(parsed_result));
			// 오른쪽 괄호이면 -> 1. 왼쪽괄호 만날때 까지 출력후 2. 왼쪽괄호 파괴
			else if (Type == RIGHT_PARENTHESIS)
			{
				// 1. 왼쪽괄호를 만날때 까지 스택 Pop해서 출력후 파괴
				while (strcmp(OperatorStack->Top->Data, "(") != 0)
				{
					Node* Temp = LLS_Pop(OperatorStack);
					strcat(PostFixExp, Temp->Data);
					strcat(PostFixExp, " ");
					free(Temp);
				}

				// 2. 왼쪽 괄호 그냥 파괴
				free(LLS_Pop(OperatorStack));
			}
			// 그 이외의 연산일 경우
			else
			{
				// 스택이 비어있으면 비교가 불가능 하므로..
				if (LLS_IsEmpty(OperatorStack))
					LLS_Push(OperatorStack, LLS_CreateNode(parsed_result));
				// 스택 최상위 연산자보다 우선순위가 높으면 스택에 넣고
				else if (IsPrior(parsed_result, LLS_Top(OperatorStack)->Data))
					LLS_Push(OperatorStack, LLS_CreateNode(parsed_result));
				else    // 아니면 원래 있던 연산자를 출력후 스택에 넣는다.
				{
					// 원래 있던 연산자 출력
					Node* Temp = LLS_Pop(OperatorStack);
					strcat(PostFixExp, Temp->Data);
					strcat(PostFixExp, " ");
					free(Temp);

					// 읽은 연산자 스택에 삽입
					LLS_Push(OperatorStack, LLS_CreateNode(parsed_result));
				}
			}
		}
	}

	// 스택이 빌 때 까지 Pop하고 출력
	while (!LLS_IsEmpty(OperatorStack))
	{
		Node* Temp = LLS_Pop(OperatorStack);
		strcat(PostFixExp, Temp->Data);
		free(Temp);
	}

	// 스택 파괴
	LLS_DestroyStack(OperatorStack);
}

/*
	토큰 파서의 기능
		1. 연산자를 기준으로 파싱을 한다. -> 파라미터 1의 기능
		2. 파싱결과를 알려준다. -> 파라미터 3의 기능
		2. 연산자인지 피연산자인지 구분을 할 수 있다. -> 파라미터 4의 기능
		3. static의 사용을 피하기 위해 자신이 어디까지 읽었는지 인덱스를 반환한다. -> 즉, 호출하는 쪽에서 기억해야한다.(의존성 생김)
			-> 파라미터 2번의 기능

*/
int SC_GetToken(char* Exp, const int pos, char* parse_result, int* Type)
{
	/*
		(루프) 문자열 끝까지 읽는다.
			1. 하나씩 읽어(루프) 숫자이면 parse_result에 하나씩 저장하고, Type을 OPERAND로 정한다.
				1-1. 연산자를 만나면 널문자를 입력후 루프를 나간다.
			2. 연산자이면 parse_result에 저장후 널문자 입력후 Type을 조건에 따라 정한뒤 루프를 나간다.

		Exp의 어디까지 읽었는지 인덱스의 다음으로 반환한다.
		-> 왜냐하면, 이미 읽은 인덱스는 다음에 사용하려면 +1 계산을 해야하는 번거로움이 생긴다.
	*/

	// 문자열을 읽을 시작점을 정한다.
	int Position = pos;

	// 널 문자를 읽을때 까지 읽어낸다.
	for (int i = 0; Exp[Position] != '\0'; i++)
	{
		// 숫자이면
		if (IsNum(Exp[Position]))
		{
			// 결과에 저장후 타입을 피연산자로 지정한다.
			parse_result[i] = Exp[Position];
			*Type = OPERAND;

			// 다음 배열의 요소가 숫자가 아니면
			if (!IsNum(Exp[++Position]))
			{
				// 널 문자를 삽입하고 종료한다.
				parse_result[i + 1] = '\0';
				break;
			}
		}
		else    // 연산자이면
		{
			// 연산자의 종류 지정
			switch (Exp[Position])
			{
			case PLUS:
				*Type = PLUS;
				break;
			case MINUS:
				*Type = MINUS;
				break;
			case MULTIPLY:
				*Type = MULTIPLY;
				break;
			case DIVIDE:
				*Type = DIVIDE;
				break;
			case LEFT_PARENTHESIS:
				*Type = LEFT_PARENTHESIS;
				break;
			case RIGHT_PARENTHESIS:
				*Type = RIGHT_PARENTHESIS;
				break;
			case SPACE: // 공백은 읽을때 무시한다.
				*Type = SPACE;
				Position++;
				i = -1;	// i가 루프를 돌면서 증가할 것 이므로...
				continue; // 루프를 계속 진행시킨다.
			}

			// 결과값을 저장
			parse_result[i] = Exp[Position++];
			parse_result[i + 1] = '\0';
			break;
		}
	}

	return Position;
}

// 매개변수로 받은 문자가 숫자가 맞으면 참, 아니면 거짓을 반환한다.
int IsNum(char p_Char)
{
	// LookUp 배열의 크기를 컴파일타임에 계산한다.
	int Lookup_NUMBER_Size = sizeof(char) * sizeof(NUMBER);

	// 하나씩 비교해가면서 숫자인지 확인하고 맞으면 참값 반환
	for (int i = 0; i < Lookup_NUMBER_Size; i++)
		if (p_Char == NUMBER[i])
			return 1;

	return 0;
}

/*
	IsPrior의 기능
		- 왼쪽이 우선순위가 높으면 참, 아니면 거짓을 반환한다. (같으면 참을 반환한다.)
		- 플러스와 마이너스만이 곱셈이나 나눗셈과 비교했을때 우선순위가 낮으므로,
		  그 이외에는 모두 참이다.
*/
int IsPrior(char* Left, char* Right)
{
	if (Left[0] == PLUS || Left[0] == MINUS)
		if (Right[0] == MULTIPLY || Right[0] == DIVIDE)
			return 0;

	return 1;
}