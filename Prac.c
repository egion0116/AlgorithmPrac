#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
    LEFT_PARENTHESIS = '(',    RIGHT_PARENTHESIS = ')',
    PLUS             = '+',    MINUS             = '-',
    MULTIPLY         = '*',    DIVIDE            = '/',
    SPACE            = ' ',    OPERAND
} SYMBOL;

const char NUMBER[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int SC_GetToken(char* Exp, const int pos, char* parse_result, int* Type);
int IsNum(char p_Char);

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
                parse_result[i+1] = '\0';
                break;
            }
        }
        else    // 연산자이면
        {
            // 연산자의 종류 지정
            switch(Exp[Position])
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
                    i = -1; // 루프 초기화.
                    Position++;
                    continue; // 루프를 계속 진행시킨다.
            }

            // 결과값을 저장
            parse_result[i] = Exp[Position++];
            parse_result[i+1] = '\0';
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

int main(void)
{
    char InExp[32] = "3 + 2 * 23 + 12";
    char result[32] = "";
    int Type;
    int Num = 0;

    while (Num < strlen(InExp))
    {
        Num = SC_GetToken(InExp, Num, result, &Type);
        printf("Result : %s, Type = %c, NextNum = %d\n", result, Type, Num);
    }


    return 0;
}