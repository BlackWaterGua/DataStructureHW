#include <iostream>
#include <string>

using namespace std;

typedef struct list_node *list_pointer;
typedef struct list_node{
    int weight = 999;     //for edge
    int index = -1;      //for node
    list_pointer link = NULL;         //for node
};

void addnode(list_pointer ptr, int link_index, int weightTemp)
{
    list_pointer temp = new list_node;
    // list_pointer temp = (list_pointer)malloc(sizeof(list_node));
    temp->index = link_index;
    temp->link = NULL;
    temp->weight = weightTemp;
    list_pointer tmp = ptr;
    while(tmp->link!=NULL)
    {
        tmp = tmp->link;
    }
    tmp->link = temp;
}

int main()
{
    int trial = 0;
    cin >> trial;
    for(int i=0;i<trial;i++)
    {
        // input
        int nodeN=0, edgeN=0;
        cin >> nodeN >> edgeN;
        list_node nodelist[nodeN];
        for(int j=0;j<edgeN;j++)
        {
            int nodeA, nodeB, weightTemp;
            cin >> nodeA >> nodeB >> weightTemp;
            addnode(&nodelist[nodeA], nodeB, weightTemp);
            addnode(&nodelist[nodeB], nodeA, weightTemp);
        }

        bool visited[nodeN];
        for(int j=0;j<nodeN;j++)
        {
            visited[j] = false;
        }
        visited[0] = true;

        int sum = 0, count = 0;
        while(count < nodeN-1)
        {
            int lowIndex = -1, lowWeight = 201;
            list_pointer lowPointer;
            for(int j=0;j<nodeN;j++)
            {
                if(visited[j]==true)
                {
                    for(list_pointer w = nodelist[j].link;w;w = w->link)
                    {
                        if(w->weight < lowWeight && visited[w->index] == false)
                        {
                            lowWeight = w->weight;
                            lowIndex = w->index;
                            lowPointer = w;
                        }
                    }
                }
            }
            lowPointer->weight = 999;
            sum += lowWeight;
            visited[lowIndex] = true;
            count++;
            // cout << sum << endl;
        }
        cout << sum << endl;
    }

    return 0;
}
