#include <iostream>

using namespace std;

typedef struct element{
    int row;
    int col;
    int data;
};
element dataA[100];
element dataB[100];
element sortB[100];
element result[100];

int main()
{
    int m1, n1;
    cin >> m1 >> n1;
    int matrixA[m1][n1];
    int countA = 0;
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            cin >> matrixA[i][j];
            if(matrixA[i][j] != 0)
            {
                dataA[countA].row = i;
                dataA[countA].col = j;
                dataA[countA++].data = matrixA[i][j];
            }
        }
    }
    dataA[countA].row = -1;

    int m2, n2;
    cin >> m2 >> n2;
    int matrixB[m2][n2];
    int countB = 0;
    for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cin >> matrixB[i][j];
            if(matrixB[i][j] != 0)
            {
                dataB[countB].row = i;
                dataB[countB].col = j;
                dataB[countB++].data = matrixB[i][j];
            }
        }
    }
    // radix sort
    int sortIndex = 0;
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<m2;j++)
        {
            for(int k=0;k<countB;k++)
            {
                if(dataB[k].row == j && dataB[k].col == i)
                {
                    sortB[sortIndex++] = dataB[k];
                    break;
                }
            }
        }
    }
    int countR = 0;
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            int sum = 0;
            int indexA = 0, indexB = 0;
            for(int k=0;k<countA;k++)
            {
                if(dataA[k].row == i)
                {
                    indexA = k;
                    break;
                }
            }
            for(int k=0;k<countB;k++)
            {
                if(sortB[k].col == j)
                {
                    indexB = k;
                    break;
                }
            }
            while(dataA[indexA].row == i && sortB[indexB].col == j)
            {
                if(dataA[indexA].col == sortB[indexB].row)
                {
                    sum += dataA[indexA].data * sortB[indexB].data;
                    indexA++;
                    indexB++;
                }
                else if(dataA[indexA].col > sortB[indexB].row)
                {
                    indexB++;
                }
                else if(dataA[indexA].col < sortB[indexB].row)
                {
                    indexA++;
                }
            }
            if(sum != 0)
            {
                result[countR].row = i; result[countR].col = j; result[countR].data = sum;
                countR++;
            }
        }
    }
    for(int i=0;i<countR;i++)
    {
        cout << result[i].row << " " << result[i].col << " " << result[i].data << endl;
    }
    return 0;
}
