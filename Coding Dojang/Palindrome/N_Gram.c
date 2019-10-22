#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Str_N_Gram(const char* str, char* token, const int N, int* Index)
{
    size_t i = 0;
    int IsNext = 1;

    while (i < N)
    {
        if (str[*Index] != '\0')
            token[i++] = str[(*Index)++];
        else
        {
            IsNext = 0;
            break;
        }
    }
    
    token[i] = '\0';
    return IsNext;
}

int main(void)
{
    char str[100] = "Hello World!";
    char token[20] = { 0 };
    int Index = 0;

    while (Str_N_Gram(str, token, 2, &Index))
        printf("%s\n", token);

    return 0;
}

