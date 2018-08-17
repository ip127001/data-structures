#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatch(char first, char second)
{
    if (first == '(' && second == ')')
        return true;
    else if (first == '[' && second == ']')
        return true;
    else if (first == '{' && second == '}')
        return true;
    else
        return false;
}

bool isBalanced(string ex)
{
    stack<char> S;

    for (int i = 0; i < ex.length(); i++)
    {
        if (ex[i] == '(' || ex[i] == '[' || ex[i] == '{')
            S.push(ex[i]);
        else if (ex[i] == ')' || ex[i] == ']' || ex[i] == '}')
        {
            if (S.empty() || !isMatch(S.top(), ex[i]))
                return false;
            else
                S.pop();
        }
        else
            continue;
    }
    return S.empty() ? true : false;
}

int main()
{
    string exp;
    cout << "enter the expression: ";
    cin >> exp;
    for (int i = 0; i < exp.length(); i++)
        cout << exp[i];

    if (isBalanced(exp))
        cout << "balanced exression \n";
    else
        cout << "not balanced expression \n";

    return 0;
}