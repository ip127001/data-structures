#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 50

int top = -1;

void push(char *c, int data) //overflow condition + pushing the data
{
    if (top == MAX_SIZE - 1)
    {
        printf("overflow condition is true");
        return;
    }
    top++;
    c[top] = data;
}

void pop()
{
    if (top == -1)
    {
        printf("underflow condition is true");
        return;
    }
    top--;
}

int Top(char *c)
{
    return c[top];
}

bool isEmpty(char *c)
{
    if (top == -1)
        return true;
    else
        return false;
}

void printStack(char *c)
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}

int main()
{
    char str[MAX_SIZE];

    push(str, 10);
    push(str, 20);
    push(str, 30);
    push(str, 40);

    pop();
    printf("%d ", Top(str));
    printf("\n");
    printStack(str);

    return 0;
}