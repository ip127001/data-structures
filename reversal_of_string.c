#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[5] = "Hello";
    int size = sizeof(c) / sizeof(c[0]);
    int n = size / 2;
    int i, j = (size - 1);
    for (i = 0; i < n + 1; i++)
    {
        char temp;
        if (i < j)
        {
            temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            j--;
        }
    }
    printf("%s ", c);
}