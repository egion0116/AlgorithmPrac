#pragma once

int GetTokenNum(char* Exp);
int Exp_Parser_Backward(char* Token, char* Exp, int Pos, int* Type);
void Infix_To_Postfix(char* InfixExp, char* Postfix_Exp);
int Exp_Parser(char* Token, char* Exp, int Pos, int* Type);
int IsNum(char c_Target);
int IsPrior(char Target, char Compare);