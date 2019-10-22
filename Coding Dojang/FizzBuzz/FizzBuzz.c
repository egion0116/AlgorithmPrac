#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    FizzBuzz 문제
        1. 1 ~ 100 까지 숫자중에서
        2. 3의 배수는 Fizz
        3. 5의 배수를 Buzz
        4. 3과 5의 공배수는 FizzBuzz를 출력한다.
*/

int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 ==0)
            printf("%d :\tFizzBuzz\n", i);
        else if (i % 3 == 0)
            printf("%d : \tFizz\n", i);
        else if (i % 5 == 0)
            printf("%d :\tBuzz\n", i);
    }

    return 0;
}