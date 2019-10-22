#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsPalindrome(const char* str)
{
    const int str_length = strlen(str);

    int result = 1;

    for (int i = 0; i < str_length / 2; i++)
        if (str[i] != str[str_length - i - 1])
        {
            result = 0;
            break;
        }

    return result;
}

int main(void)
{
    char arr[100] = "eococo";

    int result = IsPalindrome(arr);

    printf("%d\n", result);

    return 0;
}