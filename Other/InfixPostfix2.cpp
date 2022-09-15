#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    string a;
    cin >> a;

    stack<char> s;
    for (int i = 0; i < a.length(); i++)
    {
        char token = a.at(i);
        if(s.empty()&& (token=='*' || token=='/' || token == '+' || token == '-'))
        {
            s.push(token);
        }
        else if(token == '*' || token == '/')
        {
            while (!s.empty() && (s.top()=='*' || s.top()=='/'))
            {
                cout << s.top();
                s.pop();
            }
            s.push(token);
        }
        else if(token == '+' || token == '-')
        {
            while(!s.empty() && (s.top()=='*' || s.top()=='/' || s.top() == '+' || s.top() == '-'))
            {
                cout << s.top();
                s.pop();
            }
            s.push(token);
        }
        else if(token == '(')
        {
            s.push(token);
        }
        else if(token == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();
        }
        else
        {
            cout << token;
        }
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}
