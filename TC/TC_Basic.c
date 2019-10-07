#include "stdfx.h"
#include "TC_Stack.h"
#include "TC_BinaryTree.h"
#include "TC_Basic.h"

// 숫자 테이블
char LookUp[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

// 연산자 타입의 열거형
typedef enum {
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-',
	MULTIPLY = '*', DIVIDE = '/',
	SPACE = ' ', OPERAND
}TYPES;

/*
	트리를 이용한 계산기 필수요소 -> 중위를 후위로 만드는 함수 필요

	1. 중위 수식을 읽어내는 파서를 만든다. -> 의존성을 더하기 위해 반환을 인덱스로 한다.
	2. 파서 내부에서, 읽어낸 문자가 어떤 유형인지 알려주는 역할을 한다.

	후위표현식을 트리에 저장하기 위해서는 후위수식을 뒤에서부터 읽어야 한다.
	해결책 1. 후위수식을 읽어내는 파서를 따로 만든다. -> 원래 파서와 스택을 이용하면 쉽게 만들 수 있다.
	해결책 2. 원래 파서를 재활용하면서 후위수식을 뒤집어서 인자로 보내준다. -> 문자열을 뒤집는 함수만 만들면 된다.
		-> 해결책 2의 맹점 : 단순히 뒤집으면 내부에 2자리수 이상 숫자들도 전부 뒤집어 진다...
*/

double TreeSet(TreeNode* Root, char* PostfixExp, int Pos)
{
    // Token을 다 읽었으면 끝낸다.
    if (Pos == GetTokenNum(PostfixExp))
        return 0.0;

    // 토큰 변수
    int Type = 0;
    char Token[10] = { 0 };
    
    // 후위표현식을 뒤에서부터 읽는다.
    Pos = Exp_Parser_Backward(Token, PostfixExp, Pos, &Type);
    strcpy(Root->Data, Token);

    if (Type == OPERAND)

    // 결과값 변수
    double Result = 0.0;


    return Result;
}

// 토큰이 몇개인지 세어본다.
int GetTokenNum(char* Exp)
{
	// 파싱 대상 표현식의 길이
	int Length = strlen(Exp);

	// 임시로 담을 토큰
	char Temp_Token[10] = { 0 };

	// 토큰 갯수
	int Token_Number = 0;

	// 토큰별로 스택에 차곡차곡 담는다.
	for (int i = 0; i < Length;)
	{
		int Type = 0;
		i = Exp_Parser(Temp_Token, Exp, i, &Type);

		Token_Number++;
	}

	// 토큰의 갯수 반환
	return Token_Number;
}

/*
	스택 + 순방향 파서를 조합한 역방향 파서

	반환인자 : 몇번째 문자 덩어리를 반환했는지

	인수1 : 토큰 그릇
	인수2 : 파싱하고자하는 표현식
	인수3 : 토큰의 순서
	인수4 : 토큰의 형식
*/
int Exp_Parser_Backward(char* Token, char* Exp, int Pos, int* Type)
{
	// 토큰들을 담을 빈 스택 생성
	LinkedListStack* Stack;
	CreateStack(&Stack);

	// 파싱 대상 표현식의 길이
	int Length = strlen(Exp);

	// 임시로 담을 토큰
	char Temp_Token[10] = { 0 };

	// 토큰별로 스택에 차곡차곡 담는다.
	for (int i = 0; i < Length;)
	{
		i = Exp_Parser(Temp_Token, Exp, i, Type);

		Push(Stack, CreateNode(Temp_Token));
	}

	// 나눠진 문자열을 담을 2차원 배열을 선언한다.
	int Token_List_Length = GetSize(Stack);
	char** Token_List = (char**)calloc(sizeof(char*), Token_List_Length);

	for (int i = 0; i < Token_List_Length; i++)
	{
		Node* TempNode = Pop(Stack);

		int str_Length = strlen(TempNode->Data);
		Token_List[i] = (char*)malloc(sizeof(char) * str_Length + 1);
		strcpy(Token_List[i], TempNode->Data);

		DestroyNode(TempNode);
	}

	strcpy(Token, Token_List[Pos++]);

	// 토큰 리스트 파괴
	for (int i = 0; i < Token_List_Length; i++)
		free(Token_List[i]);
	free(Token_List);

	return Pos;
}

void Infix_To_Postfix(char* InfixExp, char* Postfix_Exp)
{
	/*
		(루프) 중위수식을 널문자가 올때 까지 읽는다.

		** 중위식을 후위식으로 만드는 알고리즘(다익스트라의 철도길 공식) **
		1. 피연산자가 오면 무조건 후위수식 결과로 떼놓는다.
		2. 연산자가 오면
			2-1. 우선순위가 높으면 -> 스택에 넣고
						   낮으면 -> 원래 있던 연산자를 Pop 하고 스택에 넣는다. (예외적으로 왼쪽 소괄호는 항상 스택에 넣는다.)
			2-2 오른쪽 소괄호를 만나면 -> 왼쪽 소괄호를 만날때 까지 스택을 비우고 왼쪽 소괄호는 삭제한다.

		3. 스택에 남아있는 모든 연산자를 Pop 한다.

	*/

	// 읽을 문자열 인덱스값
	int Pos = 0;
	// 토큰을 저장할 문자열
	char Token[10] = { 0 };
	// 문자 타입을 저장할 변수
	int Type = 0;
	// 연산자들을 저장할 스택
	LinkedListStack* Stack = NULL;
	// 빈 스택 생성
	CreateStack(&Stack);

	while (InfixExp[Pos] != '\0')
	{
		Pos = Exp_Parser(Token, InfixExp, Pos, &Type);  // 파서로 하나씩 떼온다.
		if (Type == OPERAND)    // 피연산자 이면 후위수식에 무조건 출력한다.
		{
			strcat(Postfix_Exp, Token);
			strcat(Postfix_Exp, " ");
		}
		else    // 연산자이면
		{
			if (IsEmpty(Stack)) // 스택이 비어있을 때는
				Push(Stack, CreateNode(Token)); // 연산자를 스택에 무조건 넣는다.
			else
			{
				if (Type == RIGHT_PARENTHESIS)  // 연산자가 오른쪽 괄호일 경우
				{
					// 왼쪽 괄호를 만날때 까지 Pop 해서 출력한다.
					Node* Temp = Pop(Stack);
					while (Temp->Data[0] != LEFT_PARENTHESIS)
					{
						strcat(Postfix_Exp, Temp->Data);
						strcat(Postfix_Exp, " ");
						DestroyNode(Temp);
						Temp = Pop(Stack);
					}
					DestroyNode(Temp);
				}
				else if (Type == LEFT_PARENTHESIS)  // 왼쪽 괄호면 무조건 푸시
					Push(Stack, CreateNode(Token));
				else if (IsPrior(Token[0], GetTop(Stack)->Data[0]))  // 토큰과 원래 있던 연산자와 우선순위 높으면
					Push(Stack, CreateNode(Token));
				else    // 우선순위가 낮으면
				{
					// 스택에서 꺼내서 출력후
					Node* Temp = Pop(Stack);
					strcat(Postfix_Exp, Temp->Data);
					strcat(Postfix_Exp, " ");
					DestroyNode(Temp);

					// 연산자를 스택에 Push한다.
					Push(Stack, CreateNode(Token));
				}
			}
		}
	}

	// 스택이 완전히 빌때 까지 Pop
	while (!IsEmpty(Stack))
	{
		Node* Temp = Pop(Stack);
		strcat(Postfix_Exp, Temp->Data);
		DestroyNode(Temp);
	}
}

/*
	문자열을 파싱한다.
	인자1 : 파싱한 결과를 저장할 문자열
	인자2 : 파싱할 문자열
	인자3 : 파싱을 시작할 인덱스
	인자4 : 파싱한 문자열의 종류
*/
int Exp_Parser(char* Token, char* Exp, int Pos, int* Type)
{
	/*
		(루프) 문자열이 받은 위치로부터 널이 아니면
			1. 해당 문자가 숫자인지 확인한다.
				-> 그 다음 문자가 숫자인지 확인하고,
					숫자가 아니면 바로 루프를 나가면서 Type은 OPERAND로 지정

			2. 그게 아니면
				2-1. 타입 분류 후
				2-2. 해당 문자를 토큰에 넣은뒤 널 문자를 추가로 넣어주고 루프를 나간다.
	*/
	for (int i = 0; Exp[Pos] != '\0'; i++)
	{
		if (IsNum(Exp[Pos]))    // 숫자가 맞으면
		{
			Token[i] = Exp[Pos++];    // 해당 문자를 삽입하고
			if (!IsNum(Exp[Pos]))   // 이 다음 문자가 숫자가 아니면 (문자열은 널이 있으므로 최대 배열길이를 넘지 않는다.)
			{
				Token[i + 1] = '\0';    // 토큰 끝에 널문자 삽입 후
				*Type = OPERAND;    // 타입을 피연산자로 바꾸고
				break;  // 루프를 나간다.
			}
		}
		else
		{
			switch (Exp[Pos])
			{
			case LEFT_PARENTHESIS:
				*Type = LEFT_PARENTHESIS;
				break;
			case RIGHT_PARENTHESIS:
				*Type = RIGHT_PARENTHESIS;
				break;
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
			case SPACE:     // 스패이스는 무시한다.
				Pos++;
				i = -1;
				continue;
			}

			Token[i] = Exp[Pos++];  // 해당 문자를 토큰에 삽입 후
			Token[i + 1] = '\0';    // 널 문자를 넣어준 뒤
			break;                  // 루프 종료
		}
	}

	return Pos; // 다음에 읽을 인덱스를 반환
}

// 해당 문자가 숫자인지 아닌지 판별하는 함수
int IsNum(char c_Target)
{
	for (int i = 0; i < sizeof(LookUp) / sizeof(char); i++)
		if (c_Target == LookUp[i])
			return 1;

	return 0;
}

/*
	연산자 우선순위 판별 함수
		인자 1이 우선순위가 2보다 높거나 같으면 : 참값
*/
int IsPrior(char Target, char Compare)
{
	if (Target == PLUS || Target == MINUS)
		if (Compare == MULTIPLY || Compare == DIVIDE)
			return 0;

	return 1;
}