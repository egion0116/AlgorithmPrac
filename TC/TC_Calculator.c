#include "stdfx.h"
#include "TC_Basic.h"
#include "TC_BinaryTree.h"

double TreeCalculator(char* InfixExp)
{
    
}

int main(void)
{
	char Infix[30] = { "(117.32 + 83 ) * 49" };
	char Postfix[30] = { 0 };

	Infix_To_Postfix(Infix, Postfix);

	printf("Infix : %s\nPostfix : %s\n", Infix, Postfix);

	int Pos = 0;
	char Token[10] = { 0 };
	int Type = 0;

	for (int i = 0; i < GetTokenNum(Postfix);)
    {
        i = Exp_Parser_Backward(Token, Postfix, i, &Type);
        printf("%s\n", Token);
    }

	return 0;
}