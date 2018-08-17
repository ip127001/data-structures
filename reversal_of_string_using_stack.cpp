#include <iostream>
#include <string.h>
#include <cstdio>
#include <stack>
using namespace std;

void Reverse(char *c, int n)
{
    stack<char> S;
    for (int i = 0; i < n; i++)
    {
        S.push(c[i]);
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = S.top();
        S.pop();
    }
}
int main()
{
    char c[51];
    printf("enter a string");
    cin >> c;
    Reverse(c, strlen(c));
    printf("output = %s", c);
}
