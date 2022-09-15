#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//1+3*5/4
int main()
{
  string formula;
  cin >> formula;
  vector<string> stack;
  int top = -1;
  for(int i=0;i<formula.length();i++)
  {
    string token = formula.substr(i,1);
    if(token == "*" || token == "/")
    {
      if(stack.size()==0)
      {
        stack.push_back(token);
        top++;
      }
      else if(stack.at(top)=="*"||stack.at(top)=="/")
      {
        cout << stack.at(top);
        stack.pop_back();
        stack.push_back(token);
      }
      else
      {
        stack.push_back(token);
        top++;
      }
    }
    else if(token == "+" || token == "-")
    {
      if(stack.size()==0)
      {
        stack.push_back(token);
        top++;
      }
      else if(stack.at(top)=="*"||stack.at(top)=="/"||stack.at(top)=="+"||stack.at(top)=="-")
      {
        while(top!=-1 && (stack.at(top)=="*"||stack.at(top)=="/"||stack.at(top)=="+"||stack.at(top)=="-"))
        {
          cout << stack.at(top);
          stack.pop_back();
          top--;
        }
        stack.push_back(token);
        top++;
      }
      else
      {
        stack.push_back(token);
        top++;
      }
    }
    else if(token == "(")
    {
      stack.push_back(token);
      top++;
    }
    else if(token == ")")
    {
      while(stack.at(top)!="(")
      {
        cout << stack.at(top);
        stack.pop_back();
        top--;
      }
      stack.pop_back();
      top--;
    }
    else
    {
      cout << token;
    }
  }
  int size = stack.size();
  if(stack.size()!=0)
  {
    for(int i=0;i<size;i++)
    {
      cout << stack.at(top);
      stack.pop_back();
      top--;
    }
  }
  cout << endl;
  return 0;
}
