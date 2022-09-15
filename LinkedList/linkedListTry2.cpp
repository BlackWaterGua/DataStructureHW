#include <iostream>;

using namespace std;

typedef struct list_node * list_pointer;
typedef struct list_node{
    int data = 0;
    list_pointer link = NULL;
};

void ADD(list_pointer ptr, int data)
{
    list_pointer temp = new list_node;
    temp -> data = data;
    temp -> link = NULL;
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
    temp -> data = data;
    list_pointer tmp = ptr;
    for(int i=0;i<index;i++)
    {
        tmp = tmp -> link;
    }
    temp -> link = tmp -> link;
    tmp-> link = temp;
}

void DELETE(list_pointer ptr, int index)
{
    list_pointer trail;
    list_pointer tmp = ptr;
    for(int i=0;i<index;i++)
    {
        trail = tmp;
        tmp = tmp -> link;
    }
    trail->link = tmp->link;
    free(tmp);
}

void REVERSE(list_pointer ptr)
{
    list_pointer trail, middle, head;
    head = ptr->link;
    middle = NULL;
    while(head)
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
    string a;
    list_pointer ptr;
    list_node b;
    b.data = -1;
    ptr = &b;
    int count = 0;
    while(cin >> a)
    {
        if(a == "ADD")
        {
            int dataNum;
            cin >> dataNum;
            ADD(ptr, dataNum);
            Print(ptr);
            count++;
        }
        else if(a == "INSERT")
        {
            int dataNum, indexNum;
            string c;
            cin  >> dataNum >> c >> indexNum;
            if(indexNum > count)
            {
                cout << "Index is out of range!!" << endl;
            }
            else
            {
                INSERT(ptr, dataNum, indexNum);
                count++;
            }
            Print(ptr);
        }
        else if(a == "DELETE")
        {
            int indexNum;
            cin  >> indexNum;
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
        else if(a == "REVERSE")
        {
            REVERSE(ptr);
            Print(ptr);
        }
    }
    return 0;
}
