#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

vector<vector<int>> inputMapString(vector<vector<int>>, int, int);
string moveRecordInput(vector<vector<int>>, string*, vector<string>, int*, bool*);

int main()
{
  int m = 0, n = 0; //cin mxn matrix
  cin >> m >> n;

  vector<vector<int>> map;
  map = inputMapString(map, m, n);
  string goal = to_string(m) + " " +to_string(n);

  //for now we will make the moving program, which will move in ↑↓←→↖↗↙↘
  vector<string> moveRecord;  //using for record the path of map
  moveRecord.push_back("1 1");  //we push a "1 1" first as it original position
  string nowPosition = "1 1";  //the position now is also the original point
  string *nowPositionLink = &nowPosition; //make a pointer of nowPosition
  int recordNum = -1;
  int *recordNumLink = &recordNum;
  bool deadroad = false;
  bool *deadroadLink = &deadroad;

  while(nowPosition != goal)
  {
    // cout << deadroad << endl;
    if(deadroad == true)
    {
      string posTemp = *nowPositionLink;
      int positionRow = stoi(posTemp.substr(0, 1));
      int positionColumn = stoi(posTemp.substr(2, 1));
      map.at(positionRow).at(positionColumn) = 1;
      nowPosition = "1 1";
      recordNum = -1;
      moveRecord.clear();
      moveRecord.push_back("1 1");
      deadroad = false;
    }

    moveRecord.push_back(moveRecordInput(map, nowPositionLink, moveRecord, recordNumLink, deadroadLink));  //push the now point to the record

    // posTemp = moveRecord.at(recordNum);
    // positionRow = stoi(posTemp.substr(0, 1));
    // positionColumn = stoi(posTemp.substr(2, 1));
    // map.at(positionRow).at(positionColumn) = 0;
  }
  for(int i=0;i<moveRecord.size();i++)
  {
    cout << moveRecord.at(i) << endl;
  }

  // for(int i=0;i<m+2;i++)
  // {
  //   for(int j=0;j<n+2;j++)
  //   {
  //     cout << map.at(i).at(j);
  //     if(j==n+1)
  //       cout << endl;
  //   }
  // }

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

string moveRecordInput(vector<vector<int>> map, string* nowPositionLink, vector<string> moveRecord, int* recordNumLink, bool* deadroadLink)
{
  string posTemp = *nowPositionLink;
  int positionRow = stoi(posTemp.substr(0, 1));
  int positionColumn = stoi(posTemp.substr(2, 1));
  if(map.at(positionRow-1).at(positionColumn-1) == 0 && (*recordNumLink == -1 || to_string(positionRow-1)+" "+to_string(positionColumn-1) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow-1) + " " + to_string(positionColumn-1);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else if(map.at(positionRow-1).at(positionColumn) == 0 && (*recordNumLink == -1 || to_string(positionRow-1)+" "+to_string(positionColumn) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow-1) + " " + to_string(positionColumn);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else if(map.at(positionRow-1).at(positionColumn+1) == 0 && (*recordNumLink == -1 || to_string(positionRow-1)+" "+to_string(positionColumn+1) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow-1) + " " + to_string(positionColumn+1);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else if(map.at(positionRow).at(positionColumn+1) == 0 && (*recordNumLink == -1 || to_string(positionRow)+" "+to_string(positionColumn+1) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow) + " " + to_string(positionColumn+1);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else if(map.at(positionRow+1).at(positionColumn+1) == 0 && (*recordNumLink == -1 || to_string(positionRow+1)+" "+to_string(positionColumn+1) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow+1) + " " + to_string(positionColumn+1);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else if(map.at(positionRow+1).at(positionColumn) == 0 && (*recordNumLink == -1 || to_string(positionRow+1)+" "+to_string(positionColumn) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow+1) + " " + to_string(positionColumn);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else if(map.at(positionRow+1).at(positionColumn-1) == 0 && (*recordNumLink == -1 || to_string(positionRow+1)+" "+to_string(positionColumn-1) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow+1) + " " + to_string(positionColumn-1);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else if(map.at(positionRow).at(positionColumn-1) == 0 && (*recordNumLink == -1 || to_string(positionRow)+" "+to_string(positionColumn-1) != moveRecord.at(*recordNumLink)))
  {
    string temp = to_string(positionRow) + " " + to_string(positionColumn-1);
    *nowPositionLink = temp;
    *recordNumLink = *recordNumLink + 1;
    return temp;
  }
  else
  {
    // cout << "test" << endl;
    *deadroadLink = true;
  }
}

// 5 5
// 0 0 0 0 0
// 0 1 1 1 1
// 0 1 1 1 1
// 0 1 1 1 1
// 0 0 0 0 0
