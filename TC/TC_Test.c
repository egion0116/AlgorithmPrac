#include <time.h>
#include "TC_Calculator.h"
#include "stdfx.h"

int main(void)
{
    char Infix[] = "1 + 3.334 / (4.28*(110-7729))";

    clock_t t = clock();
    double Result = TreeCalculator(Infix);
    t = t - clock();

    printf("Infix : %s\nResult : %lf\n", Infix, Result);
    printf("Spent Time : %lf\n", (double)t / CLOCKS_PER_SEC);

    return 0;
}