#pragma once

#include "TC_BinaryTree.h"

int TreeSet(TreeNode** Root, char* PostfixExp, int Pos);
int GetTokenNum(char* Exp);
int Exp_Parser_Backward(char* Token, char* Exp, int Pos, int* Type);
void Infix_To_Postfix(char* InfixExp, char* Postfix_Exp);
int Exp_Parser(char* Token, char* Exp, int Pos, int* Type);
int IsNum(char c_Target);
int IsOp(char c_Target);
int IsPrior(char Target, char Compare);
double Type_Cal(double Op1, double Op2, int Type);