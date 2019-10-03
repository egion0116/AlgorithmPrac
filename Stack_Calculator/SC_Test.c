#include "stdfx.h"
#include "SC_Basic.h"
#include "SC_Calculator.h"

int main(void)
{
	char InFixExp[100];
	char PostFixExp[100];

	memset(InFixExp, 0, sizeof(InFixExp));
	memset(PostFixExp, 0, sizeof(PostFixExp));

	printf("Enter InFix Expression : ");
	scanf("%s", InFixExp);

	SC_GetPostFixExp(InFixExp, PostFixExp);

	printf("Infix : %s\n", InFixExp);
	printf("Postfix : %s\n", PostFixExp);

	double Result = SC_Calculator(PostFixExp);

	printf("Calculation Result : %.10lf\n", Result);

	return 0;
}