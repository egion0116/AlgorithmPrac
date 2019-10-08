#include "TC_Calculator.h"
#include "stdfx.h"

int main(void)
{
    char Infix[] = "1 + 3.334 / (4.28*(110-7729))";

    double Result = TreeCalculator(Infix);

    printf("Infix : %s\nResult : %lf", Infix, Result);

    return 0;
}