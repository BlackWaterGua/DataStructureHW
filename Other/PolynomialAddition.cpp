#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

void PolynomialAddition (string, string);


int main()
{
  string Polynomial1, Polynomial2;
  cin >> Polynomial1;
  cin >> Polynomial2;
  PolynomialAddition(Polynomial1, Polynomial2);
  return 0;
}

void PolynomialAddition (string Summand,string Addand) {
  Summand += "+";
  Addand += "+";
  int flag1 = 0;
  int flag2 = 0;
  vector<string> PolynomialItem1;
  vector<string> PolynomialItem2;
  bool Ps1 = 0, Ps2 = 0;
  if(Summand.at(0)=='x')
  {
    Summand = "1" + Summand;
  }
  if(Summand.at(0)=='-'&& Summand.at(1)=='x')
  {
    string temp = Summand.substr(1,Summand.length()-1);
    Summand = "-1" + temp;
  }
  if(Addand.at(0)=='x')
  {
    Addand = "1" + Addand;
  }
  if(Addand.at(0)=='-'&& Addand.at(1)=='x')
  {
    string temp = Addand.substr(1,Addand.length()-1);
    Addand = "-1" + temp;
  }
  for(int i=1;i<Summand.length();i++)
  {
    string temp;
    if(Summand.at(i)== '+' || Summand.at(i)== '-')
    {
      temp = Summand.substr(flag1, i-flag1); //substr(起點, 長度)
      if(Ps1==1)
      {
        temp = "-" + temp;
      }
      PolynomialItem1.push_back(temp);
      flag1 = i+1;
      if(Summand.at(i)== '+')
      {
        Ps1 = 0;
      }
      if(Summand.at(i)== '-')
      {
        Ps1 = 1;
      }
    }
  }
  for(int i=1;i<Addand.length();i++)
  {
    string temp;
    if(Addand.at(i)== '+' || Addand.at(i)== '-')
    {
      temp = Addand.substr(flag2, i-flag2);
      if(Ps2==1)
      {
        temp = "-" + temp;
      }
      PolynomialItem2.push_back(temp);
      flag2 = i+1;
      if(Addand.at(i)== '+')
      {
        Ps2 = 0;
      }
      if(Addand.at(i)== '-')
      {
        Ps2 = 1;
      }
    }
  }
  // for(int i=0;i<PolynomialItem1.size();i++)
  // {
  //   cout << PolynomialItem1[i] << endl;
  // }
  vector<float> P1Coefficient;
  vector<float> P2Coefficient;
  vector<int> P1Index;
  vector<int> P2Index;
  for(int i=0;i<PolynomialItem1.size();i++)
  {
    for(int j=0;j<PolynomialItem1[i].length();j++)
    {
      if(PolynomialItem1[i].at(j)=='x'&& j!=0)
      {
        if(PolynomialItem1[i].at(j+1)=='^')
        {
          if(PolynomialItem1[i].at(j-1)=='-')
          {
            P1Coefficient.push_back(-1);
            string temp = PolynomialItem1[i].substr(j+2,PolynomialItem1[i].length()-j-2);
            P1Index.push_back(stoi(temp));
            break;
          }
          // cout << (PolynomialItem1.at(i)) << endl;
          P1Coefficient.push_back(stof(PolynomialItem1[i]));
          // cout << (PolynomialItem1.at(i)) << endl;
          string temp = PolynomialItem1[i].substr(j+2,PolynomialItem1[i].length()-j-2);
          P1Index.push_back(stoi(temp));
          break;
        }
        else
        {
          // cout << (PolynomialItem1.at(i));
          P1Coefficient.push_back(stof(PolynomialItem1[i]));
          // cout << (PolynomialItem1.at(i));
          P1Index.push_back(1);
          break;
        }
      }
      else if(PolynomialItem1[i].at(j)=='x'&& j==0)
      {
        P1Coefficient.push_back(1);
        if(PolynomialItem1[i].at(j+1)=='^')
        {
          string temp = PolynomialItem1[i].substr(j+2,PolynomialItem1[i].length()-j-2);
          P1Index.push_back(stoi(temp));
          break;
        }
        else
        {
          P1Index.push_back(1);
          break;
        }
      }
      else if(j==PolynomialItem1[i].length()-1)
      {
        // cout << (PolynomialItem1.at(i));
        P1Coefficient.push_back(stof(PolynomialItem1[i]));
        // cout << (PolynomialItem1.at(i));
        P1Index.push_back(0);
      }
    }
  }

  for(int i=0;i<PolynomialItem2.size();i++)
  {
    for(int j=0;j<PolynomialItem2[i].length();j++)
    {
      if(PolynomialItem2[i].at(j)=='x'&& j!=0)
      {
        if(PolynomialItem2[i].at(j+1)=='^')
        {
          // cout << (PolynomialItem2.at(i)) << endl;132132132132
          if(PolynomialItem2[i].at(j-1)=='-')
          {
            // cout << "kkkkkk" << endl;
            P2Coefficient.push_back(-1);
            // cout << P1Coefficient[0] << endl;
            string temp = PolynomialItem2[i].substr(j+2,PolynomialItem2[i].length()-j-2);
            P2Index.push_back(stoi(temp));
            break;
          }
          P2Coefficient.push_back(stof(PolynomialItem2.at(i)));
          // cout << (PolynomialItem2.at(i)) << endl;
          string temp = PolynomialItem2[i].substr(j+2,PolynomialItem2[i].length()-j-2);
          P2Index.push_back(stoi(temp));
          break;
        }
        else
        {
          // cout << (PolynomialItem2.at(i)) << endl;
          P2Coefficient.push_back(stof(PolynomialItem2[i]));
          // cout << (PolynomialItem2.at(i)) << endl;
          P2Index.push_back(1);
          break;
        }
      }
      else if(PolynomialItem2[i].at(j)=='x'&& j==0)
      {
        P2Coefficient.push_back(1);
        if(PolynomialItem2[i].at(j+1)=='^')
        {
          string temp = PolynomialItem2[i].substr(j+2,PolynomialItem2[i].length()-j-2);
          P2Index.push_back(stoi(temp));
          break;
        }
        else
        {
          P2Index.push_back(1);
          break;
        }
      }
      else if(j==PolynomialItem2[i].length()-1)
      {
        // cout << (PolynomialItem2.at(i)) << endl;
        P2Coefficient.push_back(stof(PolynomialItem2[i]));
        // cout << (PolynomialItem2.at(i)) << endl;
        P2Index.push_back(0);
      }
    }
  }

  // for(int i=0;i<PolynomialItem2.size();i++)
  // {
  //   cout << PolynomialItem2[i] << endl;
  // }
  // for(int i=0;i<P2Coefficient.size();i++)
  // {
  //   cout << P2Coefficient[i] << endl;
  // }

  vector<float> AnswerCoefficient;
  vector<int> AnswerIndex;
  while(P1Index.size()!=0 && P2Index.size()!=0)
  {
    if(P1Index[0]>P2Index[0])
    {
      AnswerIndex.push_back(P1Index[0]);
      AnswerCoefficient.push_back(P1Coefficient[0]);
      P1Index.erase(P1Index.begin());
      P1Coefficient.erase(P1Coefficient.begin());
    }
    if(P1Index[0]<P2Index[0])
    {
      AnswerIndex.push_back(P2Index[0]);
      AnswerCoefficient.push_back(P2Coefficient[0]);
      P2Index.erase(P2Index.begin());
      P2Coefficient.erase(P2Coefficient.begin());
    }
    if(P1Index[0]==P2Index[0])
    {
      // cout << P1Coefficient[0] << ' ' << P2Coefficient[0] << endl;
      AnswerIndex.push_back(P1Index[0]);
      AnswerCoefficient.push_back(P1Coefficient[0] + P2Coefficient[0]);
      P1Index.erase(P1Index.begin());
      P1Coefficient.erase(P1Coefficient.begin());
      P2Index.erase(P2Index.begin());
      P2Coefficient.erase(P2Coefficient.begin());
    }
  }
  if(P1Index.size()!=0)
  {
    for(int i=0;i<P1Index.size();i++)
    {
      AnswerIndex.push_back(P1Index[i]);
      AnswerCoefficient.push_back(P1Coefficient[i]);
    }
  }
  if(P2Index.size()!=0)
  {
    for(int i=0;i<P2Index.size();i++)
    {
      AnswerIndex.push_back(P2Index[i]);
      AnswerCoefficient.push_back(P2Coefficient[i]);
    }
  }
  for(int i=0;i<AnswerIndex.size();i++)
  {
    if(i==0)
    {
      cout << AnswerCoefficient[i] << "x^" << AnswerIndex[i];
    }
    else if(AnswerIndex[i]>1 && i!=0)
    {
      if(AnswerCoefficient[i]>0)
      {
        if(AnswerCoefficient[i]==1)
        {
          cout << "+" << "x^" << AnswerIndex[i];
        }
        else
        {
          cout << "+" << AnswerCoefficient[i] << "x^" << AnswerIndex[i];
        }
      }
      else if(AnswerCoefficient[i]<0)
      {
        if(AnswerCoefficient[i]==-1)
        {
          cout << "-" << "x^" << AnswerIndex[i];
        }
        else
        {
          cout << AnswerCoefficient[i] << "x^" << AnswerIndex[i];
        }
      }
    }
    else if(AnswerIndex[i]==1 && i!=0)
    {
      if(AnswerCoefficient[i]>0)
      {
        if(AnswerCoefficient[i]==1)
        {
          cout << "+" << "x^1";
        }
        else
        {
          cout << "+" << AnswerCoefficient[i] << "x^1";
        }
      }
      else if(AnswerCoefficient[i]<0)
      {
        if(AnswerCoefficient[i]==-1)
        {
          cout << "-" << "x^1";
        }
        else
        {
          cout << AnswerCoefficient[i] << "x^1";
        }
      }
    }
    else
    {
      if(AnswerCoefficient[i]>0)
      {
        cout << "+" << AnswerCoefficient[i];
      }
      else if(AnswerCoefficient[i]<0)
      {
        cout << AnswerCoefficient[i];
      }
    }
  }
}
