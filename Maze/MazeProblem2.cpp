#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

vector<vector<int>> inputMapString(vector<vector<int>>, int, int);

int main()
{
  int i, row, col, next_row, next_col, dir, exit_row, exit_col;
  bool found = false;

  int m = 0, n = 0; //cin mxn matrix
  cin >> m >> n;
  vector<vector<int>> map;
  map = inputMapString(map, m, n);
  vector<vector<int>> mark;

  if(true)
  {
    vector<int> temp;
    for(int i=0;i<n+2;i++)
    {
      temp.push_back(1);
    }
    mark.push_back(temp);
  }
  for(int i=0;i<m;i++)
  {
    vector<int> temp;
    temp.push_back(1);
    for(int j=0;j<n;j++)
    {
      temp.push_back(0);
    }
    temp.push_back(1);
    mark.push_back(temp);
  }
  if(true)
  {
    vector<int> temp;
    for(int i=0;i<n+2;i++)
    {
      temp.push_back(1);
    }
    mark.push_back(temp);
  }

  mark.at(1).at(1) = 1;

  exit_row = m;
  exit_col = n;

  // for(int i=0;i<m+2;i++)
  // {
  //   for(int j=0;j<n+2;j++)
  //   {
  //     cout << map.at(i).at(j);
  //     if(j==n+1)
  //       cout << endl;
  //   }
  // }
  // for(int i=0;i<m+2;i++)
  // {
  //   for(int j=0;j<n+2;j++)
  //   {
  //     cout << mark.at(i).at(j);
  //     if(j==n+1)
  //       cout << endl;
  //   }
  // }

  vector<int> pathRow;
  vector<int> pathCol;
  vector<int> pathDir;

  pathRow.push_back(1);
  pathCol.push_back(1);
  pathDir.push_back(0);
  pathRow.push_back(1);
  pathCol.push_back(1);
  pathDir.push_back(0);

  vector<int> movRow;
  vector<int> movCol;

  //directions
  movRow.push_back(-1); //up 0
  movCol.push_back(0);

  movRow.push_back(-1); //up right 1
  movCol.push_back(1);

  movRow.push_back(0); //right 2
  movCol.push_back(1);

  movRow.push_back(1); //right down 3
  movCol.push_back(1);

  movRow.push_back(1); //down 4
  movCol.push_back(0);

  movRow.push_back(1); //left down 5
  movCol.push_back(-1);

  movRow.push_back(0); //left 6
  movCol.push_back(-1);

  movRow.push_back(-1); //left up 7
  movCol.push_back(-1);

  while(pathRow.size()>0 && found == false)
  {
    // cout << row << " " << col << endl;
    pathRow.pop_back();
    pathCol.pop_back();
    pathDir.pop_back();
    row = pathRow.at(pathRow.size()-1);
    col = pathCol.at(pathCol.size()-1);
    dir = pathDir.at(pathDir.size()-1);
    while(dir<8 && found == false)
    {
      // cout << row << " " << col << endl;
      next_row = row + movRow.at(dir);
      next_col = col + movCol.at(dir);
      if(next_row == exit_row && next_col == exit_col)
      {
        found = true;
        pathRow.push_back(row);
        pathCol.push_back(col);
        pathRow.push_back(exit_row);
        pathCol.push_back(exit_col);
      }
      else if(map.at(next_row).at(next_col)==0 && mark.at(next_row).at(next_col)==0)
      {
        mark.at(next_row).at(next_col) = 1;
        pathRow.push_back(row);
        pathCol.push_back(col);
        pathDir.push_back(++dir);
        row = next_row;
        col = next_col;
        dir = 0;
      }
      else ++dir;
    }
  }

  for(int i=0;i<pathRow.size()-1;i++)
  {
    if(pathRow.at(i)==pathRow.at(i+1) && pathCol.at(i)==pathCol.at(i+1))
    {
      pathRow.erase(pathRow.begin()+i);
      pathCol.erase(pathCol.begin()+i);
    }
  }

  for(int i=0;i<pathRow.size();i++)
  {
      cout << pathRow.at(i) << " " << pathCol.at(i) << endl;
  }

  return 0;
}

vector<vector<int>> inputMapString(vector<vector<int>> map, int m, int n)
{
  vector<int> temp;
  for(int i=0;i<n+2;i++)
  {
    temp.push_back(1);  //first line have n piece 1
  }
  map.push_back(temp);
  temp.clear();

  for(int i=0;i<m;i++)
  {
    temp.push_back(1);  //we put an 1 infront of the line
    for(int j=0;j<n;j++)
    {
      int mapTemp;
      cin >> mapTemp;
      temp.push_back(mapTemp);  //the map that we put in
    }
    temp.push_back(1);  //put an 1 behind the line
    map.push_back(temp);
    temp.clear();
  }

  for(int i=0;i<n+2;i++)
  {
    temp.push_back(1);  //the last line is full of 1
  }
  map.push_back(temp);
  temp.clear();
  return map;
}
