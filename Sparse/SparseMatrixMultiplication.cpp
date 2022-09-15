#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct{
    int col;
    int row;
    int value;
}term;

void fast_transpose(term[], term[]);
void mult(term[], term[], term[]);
int compare(int, int);
void storesum(term[], int* , int , int ,int*);

int main()
{

    int m1, n1, m2, n2, countA = 0, countB = 0;
    cin >> m1 >> n1;
    int matrixA[m1][n1];
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            cin >> matrixA[i][j];
            if(matrixA[i][j]!=0)
            {
                countA++;
            }
        }
    }
    cin >> m2 >> n2;
    int matrixB[m2][n2];
    for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            cin >> matrixB[i][j];
            if(matrixB[i][j]!=0)
            {
                countB++;
            }
        }
    }

    term a[countA+1];
    term b[countB+1];
    a[0].col = n1;
    a[0].row = m1;
    a[0].value = countA;
    b[0].col = n2;
    b[0].row = m2;
    b[0].value = countB;
    int countTermA = 1;
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            if(matrixA[i][j]!=0)
            {
                a[countTermA].col = j;
                a[countTermA].row = i;
                a[countTermA].value = matrixA[i][j];
                countTermA++;
            }
        }
    }
    int countTermB = 1;
    for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(matrixB[i][j]!=0)
            {
                b[countTermB].col = j;
                b[countTermB].row = i;
                b[countTermB].value = matrixB[i][j];
                countTermB++;
            }
        }
    }

    term d[100];
    mult(a, b, d);
    return 0;
}

void fast_transpose(term b[], term transposeB[])
{
    int num_cols = b[0].col, num_terms = b[0].value;
    int row_terms[100], starting_pos[100], j, i;
    transposeB[0].row = num_cols;
    transposeB[0].col = b[0].row;
    transposeB[0].value = num_terms;
    if(num_terms > 0)
    {
        for(i=0;i<num_cols;i++)
        {
            row_terms[i] = 0;
        }
        for(i=1;i<=num_terms;i++)
        {
            row_terms[b[i].col]++;
        }
        starting_pos[0] = 1;
        for(i=1;i<num_cols;i++)
        {
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }
        for(i=1;i<=num_terms;i++)
        {
            j = starting_pos[b[i].col]++;
            transposeB[j].row = b[i].col;
            transposeB[j].col = b[i].row;
            transposeB[j].value = b[i].value;
        }
    }
}


void mult(term a[], term b[], term d[])
{
    int i, j, column, totalb = b[0].value, totald = 0;
    int rows_a = a[0].row, cols_a = a[0].col, totala = a[0].value;
    int cols_b = b[0].col;
    int row_begin = 1, row = a[1].row, sum = 0;
    term new_b[100];
    fast_transpose(b, new_b);
    /*set boundary condition*/
    a[totala+1].row = rows_a;
    new_b[totalb+1].row = cols_b;
    new_b[totalb+1].col = -1;
    for(i=1;i<=totala;)
    {
        column = new_b[1].row;
        for(j=1;j<=totalb+1;)
        {
            /*multiply  row of a by column of b*/
            if(a[i].row != row)
            {
                if(sum != 0)
                {
                    totald++;
                    cout << row << " " << column << " " << sum << endl;
                    sum = 0;
                }
                i = row_begin;
                for(;new_b[j].row == column;j++);
                column = new_b[j].row;
            }
            else if(new_b[j].row != column)
            {
                if(sum != 0)
                {
                    totald++;
                    cout << row << " " << column << " " << sum << endl;
                    sum = 0;
                }
                i = row_begin;
                column = new_b[j].row;
            }
            else switch(compare(a[i].col, new_b[j].col))
            {
                case -1: /*go to next term in a*/
                    i++;
                    break;
                case 0: /*add terms, go to next term in a and b*/
                    sum += (a[i++].value * new_b[j++].value);
                    break;
                case 1: /*advance to next term in b*/
                    j++;
            }
        } /*end of for j <= totalb+1 */
        for(;a[i].row == row;i++);
        row_begin = i;
        row = a[i].row;
    }/*end of for i<=totala */
}

int compare(int a, int b)
{
    if(a<b)
        return -1;
    else if(a==b)
        return 0;
    else if(a>b)
        return 1;
}

void storesum(term d[], int *totald , int row, int column,int *sum)
{
    if(*sum != 0)
    {
        if(*totald < 100)
        {
            d[*totald].row = row;
            d[*totald].col = column;
            d[*totald].value = *sum;
            *totald++;
            *sum = 0;
        }
    }
}
