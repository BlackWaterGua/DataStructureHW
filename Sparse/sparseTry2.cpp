#include <iostream>;

using namespace std;

typedef struct element{
    int row;
    int col;
    int data;
};
element dataA[1000];
element dataB[1000];
element sortB[1000];
element result[1000];

int main()
{
    int m1, n1, countA = 0;
    cin >> m1 >> n1;
    int matrixA[m1][n1];
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            cin >> matrixA[i][j];
            if(matrixA[i][j] != 0)
            {
                dataA[countA].row = i; dataA[countA].col = j; dataA[countA++].data = matrixA[i][j];
            }
        }
    }
    int m2, n2, countB = 0;
    cin >> m2 >> n2;
    int matrixB[m2][n2];
    for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cin >> matrixB[i][j];
            if(matrixB[i][j] != 0)
            {
                dataB[countB].row = i; dataB[countB].col = j; dataB[countB++].data = matrixB[i][j];
            }
        }
    }

    int sortCount = 0;
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<m2;j++)
        {
            for(int k=0;k<countB;k++)
            {
                if(dataB[k].row == j && dataB[k].col == i)
                {
                    sortB[sortCount++] = dataB[k];
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
                result[countR].row = i; result[countR].col = j; result[countR++].data = sum;
            }
        }
    }

    for(int k=0;k<countR;k++)
    {
         cout << result[k].row << " " << result[k].col << " " << result[k].data << endl;
    }

    return 0;
}
