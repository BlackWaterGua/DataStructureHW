#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct list_node *list_pointer;
typedef struct list_node{
    int data;
    list_pointer link;
};

void PrintList(list_pointer ptr)
{
    list_pointer tmp = ptr;
    while(tmp->link!=NULL)
    {
        tmp = tmp->link;
        if(tmp->link==NULL)
        {
            break;
        }
        cout << tmp->data << " ";
    }
    cout << tmp->data << endl;
}

void ADD(list_pointer ptr, int data)
{
    list_pointer temp = (list_pointer)malloc(sizeof(list_node));
    temp->data = data;
    temp->link = NULL;
    list_pointer tmp = ptr;
    while(tmp->link!=NULL)
    {
        tmp = tmp->link;
    }
    tmp->link = temp;
}

void INSERT(list_pointer ptr, int data, int index)
{
    list_pointer temp = (list_pointer)malloc(sizeof(list_node));
    temp->data = data;
    temp->link = NULL;
    list_pointer tmp = ptr;
    for(int i=0;i<index;i++)
    {
        tmp = tmp->link;
    }
    temp->link = tmp->link;
    tmp->link = temp;
}

void DELETE(list_pointer ptr, int index)
{
    list_pointer tmp = ptr, trail;
    for(int i=0;i<index;i++)
    {
        trail = tmp;
        tmp = tmp->link;
    }
    trail->link = tmp->link;
    free(tmp);
}

void REVERSE(list_pointer ptr)
{
    list_pointer trail, middle, lead;
    lead = ptr->link;
    middle = NULL;
    while(lead!=NULL)
    {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    ptr->link = middle;
}

int main()
{
    int count = 0, handleNum=0, dataNum=0, indexNum=0;
    string order;
    list_pointer ptr;
    list_node none;
    ptr = &none;
    ptr->link = NULL;
    int data[100], index[100];
    string inputHandler[100];
    while(cin >> order)
    {
        inputHandler[handleNum] = order;
        handleNum++;
        if(order == "ADD")
        {
            cin >> data[dataNum];
            dataNum++;
        }
        if(order == "INSERT")
        {
            string VaryUseLessBEHIND;
            cin >> data[dataNum] >> VaryUseLessBEHIND >> index[indexNum];
            dataNum++;
            indexNum++;
        }
        if(order == "DELETE")
        {
            cin >> index[indexNum];
            indexNum++;
        }
    }
    dataNum = 0;
    indexNum = 0;
    for(int i=0;i<handleNum;i++)
    {
        order = inputHandler[i];
        if(order == "ADD")
        {
            int AddData;
            AddData = data[dataNum];
            dataNum++;
            ADD(ptr, AddData);
            PrintList(ptr);
            count++;
        }
        if(order == "INSERT")
        {
            int InsertData, InsertIndex;
            InsertData = data[dataNum];
            dataNum++;
            InsertIndex = index[indexNum];
            indexNum++;
            if(InsertIndex > count)
            {
                cout << "Index is out of range!!" << endl;
                PrintList(ptr);
                continue;
            }
            INSERT(ptr, InsertData, InsertIndex);
            PrintList(ptr);
            count++;
        }
        if(order == "DELETE")
        {
            int DeleteIndex;
            DeleteIndex = index[indexNum];
            indexNum++;
            if(DeleteIndex > count)
            {
                cout << "Index is out of range!!" << endl;
                PrintList(ptr);
                continue;
            }
            DELETE(ptr, DeleteIndex);
            PrintList(ptr);
            count--;
        }
        if(order == "REVERSE")
        {
            REVERSE(ptr);
            PrintList(ptr);
        }
    }
}
