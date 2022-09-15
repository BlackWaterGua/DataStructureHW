#include <iostream>

using namespace std;

typedef struct list_node *list_pointer;
typedef struct list_node{
    int data = -1;
    list_pointer link = NULL;
};

void ADD(list_pointer ptr, int data)
{
    list_pointer temp = new list_node;
    temp->data = data;
    temp->link = NULL;
    list_pointer tmp = ptr;
    while(tmp->link)
    {
        tmp = tmp->link;
    }
    tmp->link = temp;
}

void INSERT(list_pointer ptr, int data, int index)
{
    list_pointer temp = new list_node;
    temp->data = data;
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
    list_pointer tmp = ptr;
    list_pointer trail;
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
    list_pointer head = ptr->link, middle = NULL, trail;
    while(head != NULL)
    {
        trail = middle;
        middle = head;
        head = head->link;
        middle->link = trail;
    }
    ptr->link = middle;
}

void Print(list_pointer ptr)
{
    list_pointer tmp = ptr->link;
    while(tmp->link)
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << tmp->data << endl;
}

int main()
{
    list_pointer ptr;
    list_node a;
    ptr = &a;
    string input;
    int count = 0;
    while(cin >> input)
    {
        if(input == "ADD")
        {
            int tempNum;
            cin >> tempNum;
            ADD(ptr, tempNum);
            Print(ptr);
            count++;
        }
        else if(input == "INSERT")
        {
            int tempNum;
            cin >> tempNum;
            string b;
            cin >> b;
            int indexNum;
            cin >> indexNum;
            if(indexNum > count)
            {
                cout << "Index is out of range!!" << endl;
            }
            else
            {
                INSERT(ptr, tempNum, indexNum);
                count++;
            }
            Print(ptr);
        }
        else if(input == "DELETE")
        {
            int indexNum;
            cin >> indexNum;
            if(indexNum > count)
            {
                cout << "Index is out of range!!" << endl;
            }
            else
            {
                DELETE(ptr, indexNum);
                count--;
            }
            Print(ptr);
        }
        else if(input == "REVERSE")
        {
            REVERSE(ptr);
            Print(ptr);
        }
    }
    return 0;
}
