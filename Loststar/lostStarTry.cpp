#include <iostream>

using namespace std;

typedef struct list_node *list_pointer;
typedef struct list_node{
    int row;
    int col;
    list_pointer linkDown = NULL;
    list_pointer linkRight = NULL;
};

void addDown(list_pointer ptr, int row, int col)
{
    // cout << "test" << endl;
    list_pointer temp = new list_node;
    temp->row = row;
    temp->col = col;
    list_pointer tmp = ptr;
    while(tmp->linkDown)
    {
        tmp = tmp->linkDown;
    }
    tmp->linkDown = temp;
}

void addRight(list_pointer ptr, int row, int col)
{
    list_pointer temp = new list_node;
    temp->row = row;
    temp->col = col;
    list_pointer tmp = ptr;
    while(tmp->linkDown->row != row && tmp->linkDown)
    {
        tmp = tmp->linkDown;
    }
    tmp = tmp->linkDown;
    while(tmp->linkRight)
    {
        tmp = tmp->linkRight;
    }
    tmp->linkRight = temp;
}

void checkLost(int row, int column, int* starCount, char** map)
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
    int m = -1,n = -1;
    while(m != 0 && n!= 0)
    {
        cin >> m >> n;
        if(m==0&&n==0)
        {
            break;
        }
        char map[m+2][n+2];
        for(int i=0;i<m+2;i++)
        {
            map[i][0] = '.';
            map[i][n+1] = '.';
        }
        for(int i=0;i<n+2;i++)
        {
            map[0][i] = '.';
            map[m+1][i] = '.';
        }
        list_pointer ptr;
        list_node a;
        a.row = 0; a.col = 0;
        ptr = &a;
        int rowCur = 0;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                cin >> map[i][j];
                if(map[i][j] == '*')
                {
                    if(i!=rowCur)
                    {
                        addDown(ptr, i, j);
                        rowCur = i;
                        // cout << ptr->linkDown->row;
                    }
                    else
                        addRight(ptr, i, j);
                }
            }
        }
        char* mapF[m+2];
        for(int i=0;i<m+2;i++)
            mapF[i] = map[i];

        int starCount = 0;
        list_pointer tmp = ptr;
        list_pointer stack[1000];
        int top = -1;
        while(tmp != NULL)
        {
            tmp = tmp->linkDown;
            if(tmp==NULL)
                break;
            top++;
            stack[top] = tmp;
            checkLost(tmp->row, tmp->col, &starCount, mapF);
        }
        while(top > -1)
        {
            tmp = stack[top];
            top--;
            while(tmp->linkRight)
            {
                tmp = tmp->linkRight;
                checkLost(tmp->row, tmp->col, &starCount, mapF);
            }
        }
        cout << starCount << endl;
    }
    return 0;
}
