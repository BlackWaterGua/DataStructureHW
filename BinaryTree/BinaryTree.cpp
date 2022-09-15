#include <iostream>
#include <vector>

typedef struct list_node *list_pointer;
typedef struct list_node{
    int data = 0;
    list_pointer linkRight = NULL;
    list_pointer linkLeft = NULL;
};

int maxDeep(list_pointer ptr)
{
    if(!ptr)
    {
        return 0;
    }
    int left_depth = maxDeep(ptr->linkLeft);
    int right_depth = maxDeep(ptr->linkRight);
    if(left_depth >= right_depth)
    {
        return left_depth+1;
    }
    else
    {
        return right_depth+1;
    }
}

using namespace std;

int main()
{
    list_node tree[10000];
    vector<int> record;
    int temp = 0;
    int data[10000];
    int left[10000];
    int right[10000];
    int dataCount = 0, leftCount = 0, rightCount = 0;
    while(cin >> temp)
    {
        data[dataCount++] = temp;
        cin >> left[leftCount++] >> right[rightCount++];
    }

    int handle = dataCount;
    int total = dataCount;
    dataCount = 0;
    leftCount = 0;
    rightCount = 0;
    bool valid = true;
    while(handle != 0)
    {
        if(handle == total)
        {
            tree[data[dataCount]].data = data[dataCount];
            record.push_back(data[dataCount]);
            if(left[leftCount] != 0)
            {
                tree[left[leftCount]].data = left[leftCount];
                record.push_back(left[leftCount]);
                tree[data[dataCount]].linkLeft = &tree[left[leftCount]];
                leftCount++;
            }
            else
            {
                leftCount++;
            }
            if(right[rightCount] != 0)
            {
                tree[right[rightCount]].data = right[rightCount];
                record.push_back(right[rightCount]);
                tree[data[dataCount]].linkRight = &tree[right[rightCount]];
                rightCount++;
            }
            else
            {
                rightCount++;
            }
            dataCount++;
        }
        else
        {
            if(tree[data[dataCount]].data != 0)
            {
                if(left[leftCount] != 0)
                {
                    tree[left[leftCount]].data = left[leftCount];
                    record.push_back(left[leftCount]);
                    tree[data[dataCount]].linkLeft = &tree[left[leftCount]];
                    leftCount++;
                }
                else
                {
                    leftCount++;
                }
                if(right[rightCount] != 0)
                {
                    tree[right[rightCount]].data = right[rightCount];
                    record.push_back(right[rightCount]);
                    tree[data[dataCount]].linkRight = &tree[right[rightCount]];
                    rightCount++;
                }
                else
                {
                    rightCount++;
                }
                dataCount++;
            }
            else
            {
                cout << "Invalid tree" << endl;
                valid = false;
                break;
            }
        }
        handle--;
    }
    if(valid == true && handle != total)
    {
        int leafCount = 0;
        for(int i = 0;i<record.size();i++)
        {
            if(tree[record.at(i)].linkLeft == NULL && tree[record.at(i)].linkRight == NULL)
            {
                leafCount++;
            }
        }
        list_pointer a = &tree[record.at(0)];
        int deepValue = maxDeep(a);
        cout << deepValue << endl;
        cout << leafCount << endl;
    }
    if(handle == total)
    {
        cout << "Tree is empty" << endl;
    }
    return 0;
}
