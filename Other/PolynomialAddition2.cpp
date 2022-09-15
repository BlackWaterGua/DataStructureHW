#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

typedef struct Polynomial{
    float coef;
    int expon;
};
Polynomial term[100];
int avail = 0;

void inputTerm(string a, int *finisha)
{
    for(int i=0;i<a.length();i++)
    {
        string temp;
        int j=0;
        for(j=i;a.at(j)!='x';j++)
        {
            temp += a.at(j);
        }
        // cout << j << endl;
        i = j;
        float coe=0;
        if(temp.length()==0 || temp == "+")
        {
            coe = 1;
        }
        else if(temp == "-")
        {
            coe = -1;
        }
        else
        {
            coe = stof(temp);
        }
        // cout << temp << endl;
        i+=2;

        string temp2;
        int exp=0;
        for(int j=i;j<a.length() && a.at(j)!='+' && a.at(j)!='-';j++)
        {
            temp2+=a.at(j);
        }
        // cout << temp2 << endl;
        exp = stoi(temp2);
        // cout << exp << endl;

        term[avail].coef = coe;
        term[avail++].expon = exp;
        *finisha++;
    }
}

int main()
{
    int starta = 0, finisha = 0;
    string a;
    cin >> a;
    inputTerm(a, &finisha);
    for(int i=0;i<avail;i++)
    {
        cout << term[i].coef << " " << term[i].expon << " " << endl;
    }

    return 0;
}
