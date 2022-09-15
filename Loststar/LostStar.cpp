#include <iostream>

using namespace std;

typedef struct list_node *list_pointer;
typedef struct list_node{
    int row;
    int column;
    list_pointer linkRight;
    list_pointer linkDown;
};

void linkDet(int row, int column, int *starCount, char** map)
{
    if(map[row-1][column-1] != '*' &&
       map[row-1][column] != '*' &&
       map[row-1][column+1] != '*' &&
       map[row][column-1] != '*' &&
       map[row][column+1] != '*' &&
       map[row+1][column-1] != '*' &&
       map[row+1][column] != '*' &&
       map[row+1][column+1] != '*')
    {
        *starCount = *starCount + 1;
    }
    return;
}

int main()
{
    int m = -1, n = -1;
    int starNum[10000];
    int starNumIndex = 0;
    while(m != 0 && n != 0)
    {
        list_node record[10000];     //for record the next * position
        int recordCount = 0;         //for record index
        // input the matrix
        cin >> m >> n;
        //when input (0,0), break;
        if(m == 0 && n == 0)
        {
            break;
        }
        char map[m+2][n+2];
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                cin >> map[i][j];
            }
        }
        for(int i=0;i<n+2;i++)
        {
            map[0][i] = '.';
            map[m+1][i] = '.';
        }
        for(int i=0;i<m+2;i++)
        {
            map[i][0] = '.';
            map[i][n+1] = '.';
        }
        //creat a tree, the scanning is begin in most left side,
        //if there is * in right, link it,
        //if the node is head, link the next head of row.
        list_pointer temp;
        for(int i = 0; i < m+2; i++)
        {
            for(int j = 0; j < n+2; j++)
            {
                if(map[i][j]=='*')
                {
                    record[recordCount].row = i;
                    record[recordCount].column = j;
                    record[recordCount].linkRight = NULL;
                    record[recordCount].linkDown = NULL;
                    recordCount++;
                    if(recordCount == 1)
                    {
                        temp = &record[0];
                    }
                    else if(record[recordCount-2].row == record[recordCount-1].row)
                    {
                        record[recordCount-2].linkRight = &record[recordCount-1];
                    }
                    else if(record[recordCount-2].row != record[recordCount-1].row)
                    {
                        temp->linkDown = &record[recordCount-1];
                        temp = temp->linkDown;
                    }
                }
            }
        }
        // list_pointer a;
        // a = &record[0];
        // a = a->linkDown;
        // a = a->linkDown;
        // a = a->linkRight;
        // cout << a->row << " " << a->column << endl;
        //making deep first searching function
        int starCount = 0;
        int totalNum = recordCount;
        list_pointer w = &record[0];
        list_pointer h[1000];
        int hIndex = 0;
        char* mapF[m+2];
        for(int i=0;i<m+2;i++)
        {
            mapF[i] = map[i];
        }

        // dfs(visitCounter, visited[], record[], &starCount, m, map[m][n]);
        while(totalNum != 0)
        {
            // cout << w->row << " " << w->column << endl;
            linkDet(w->row, w->column, &starCount, mapF);
            // cout << "X";
            if(w->linkDown)
            {
                h[hIndex] = w;
                // cout << h[hIndex]->row << " " << h[hIndex]->column << endl;
                hIndex++;
                w = w->linkDown;
                totalNum--;
            }
            else if(w->linkRight)
            {
                w = w->linkRight;
                totalNum--;
            }
            else if(!w->linkRight)
            {
                if(hIndex==0)
                    break;
                w = h[hIndex-1];
                hIndex--;
                while(!w->linkRight && hIndex != 0)
                {
                    w = h[hIndex-1];
                    hIndex--;
                }
                w->linkDown = NULL;
                if(w->linkRight)
                    w = w->linkRight;
                totalNum--;
            }
        }
        // cout << starCount << endl;
        starNum[starNumIndex] = starCount;
        starNumIndex++;
    }
    for(int i=0;i<starNumIndex;i++)
    {
        cout << starNum[i] << endl;
    }
    return 0;
}
