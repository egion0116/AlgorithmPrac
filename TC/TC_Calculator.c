#include "stdfx.h"
#include "TC_Calculator.h"

/*
	주의.. -> 트리 수식분석을 할때는 숫자를 읽을때 순서에 유의한다.
*/

double TreeCalculator(char* Infix)
{
	// 빈 트리 만들기
	TreeNode* Exp_Root = NULL;

	// 중위수식을 후위수식으로 바꾼다.
	char Postfix[100] = { 0 };
	Infix_To_Postfix(Infix, Postfix);

	// 수식트리 설정
	TreeSet(&Exp_Root, Postfix, 0);

	// 결과값을 저장
	double Result = Exp_Tree_Cal(Exp_Root);

	return Result;
}

double Exp_Tree_Cal(TreeNode* Root)
{
	int Type = IsOp(Root->Data[0]);
	double Result = 0.0;

	if (Type)
	{
		// 읽는순서에 유의한다.
		double Op1 = Exp_Tree_Cal(Root->Right);
		double Op2 = Exp_Tree_Cal(Root->Left);

		// 타입에 따라 계산
		Result = Type_Cal(Op1, Op2, Type);
	}
	else 
		Result = atof(Root->Data);	// 실수형으로 바꾼 값을 반환

	return Result;
}