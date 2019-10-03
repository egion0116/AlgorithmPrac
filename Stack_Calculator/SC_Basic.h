#pragma once

typedef enum
{
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-',
	MULTIPLY = '*', DIVIDE = '/',
	SPACE = ' ', OPERAND
} SYMBOL;

void SC_GetPostFixExp(char* InFixExp, char* PostFixExp);
int SC_GetToken(char* Exp, const int pos, char* parse_result, int* Type);
int IsNum(char p_Char);
int IsPrior(char* Left, char* Right);