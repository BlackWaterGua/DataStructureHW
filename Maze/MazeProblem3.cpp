#include <iostream>
#include <cstring>
#include <vector>
#include <string>

typedef struct element{
    short int row;
    short int col;
    short int dir;
};
element stack[100];

typedef struct offsets{
    short int vert;
    short int horiz;
};

using namespace std;

int main()
{
    offsets move[8];
    move[0].vert = -1;move[0].horiz = 0;
    move[1].vert = -1;move[1].horiz = 1;
    move[2].vert = 0;move[2].horiz = 1;
    move[3].vert = 1;move[3].horiz = 1;
    move[4].vert = 1;move[4].horiz = 0;
    move[5].vert = 1;move[5].horiz = -1;
    move[6].vert = 0;move[6].horiz = -1;
    move[7].vert = -1;move[7].horiz = -1;
    int m, n;
    cin >> m >> n;
    int map[100][100];
    int mark[100][100];
    for(int i=0;i<=n+1;i++)
    {
        map[0][i] = 1;
        map[m+1][i] = 1;
        mark[0][i] = 1;
        mark[m+1][i] = 1;
    }
    for(int i=0;i<=m+1;i++)
    {
        map[i][0] = 1;
        map[i][n+1] = 1;
        mark[i][0] = 1;
        mark[i][n+1] = 1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> map[i][j];
        }
    }

    mark[1][1] = 1;
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
    int End_row = m, End_col = n, top = 0;
    int i, row, column, next_row, next_col, found = 0, dir;
    element position;
    while(top>-1 && found!=1)
    {
        position.row = stack[top].row; position.col = stack[top].col; position.dir = stack[top].dir;
        top--;
        row = position.row; column = position.col; dir = position.dir;
        while(dir<8 && found!=1)
        {
            next_row = row + move[dir].vert;
            next_col = column + move[dir].horiz;
            if(next_row==End_row&&next_col==End_col)
            {
                found = 1;
                break;
            }
            else if(map[next_row][next_col]!=1 && mark[next_row][next_col]!=1)
            {
                mark[next_row][next_col]=1;
                // rowR.push_back(next_row); colR.push_back(next_col);
                position.row = row; position.col = column; position.dir = ++dir;
                top++;
                stack[top].row = position.row; stack[top].col = position.col; stack[top].dir = position.dir;
                row = next_row; column = next_col; dir = 0;
            }
            else
            {
                dir++;
            }
        }

    }
    for(int i=0;i<=top;i++)
    {
        cout << stack[i].row << " " << stack[i].col << endl;
    }
    cout << row << " " << column << endl;
    cout << End_row << " " << End_col << endl;

    return 0;
}
