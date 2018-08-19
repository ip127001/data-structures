#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluateExp(int first, int second, char op)
{
    int sum = first + second;
    printf("sum is %d= ", sum);
    return sum;

    // else if (op == '-')
    // {
    //     int sub = (first - second);
    //     return sub;
    // }
    // else if (op == '*')
    // {
    //     int mul = (first * second);
    //     return mul;
    // }
    // else if (op == '/')
    // {
    //     int div = (first / second);
    //     return div;
    // }
    // else
    //     return first;
}

int evaluatePostfix(string exp)
{
    stack<char> S;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            printf("%c\n", exp[i]);
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            int c = a / b;
            S.push(c);
        }
        else
        {
            printf("%c\n", exp[i]);
            S.push(exp[i]);
        }
    }

    return S.top();
}

int main()
{
    string exp;
    cout << "enter the expression in postfix form: ";
    cin >> exp;
    for (int i = 0; i < exp.length(); i++)
    {
        printf("%c ", exp[i]);
    }
    cout << "\n";
    int x = evaluatePostfix(exp);
    cout << "evaluation is: ";
    cout << x;

    return 0;
}