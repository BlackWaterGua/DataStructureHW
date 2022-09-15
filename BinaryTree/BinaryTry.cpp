#include <iostream>;

using namespace std;

typedef struct binary_node *binary_link;
typedef struct binary_node{
    int data = -1;
    binary_link left = NULL;
    binary_link right = NULL;
};

int maxDeep(binary_link ptr)
{
    if(!ptr)
        return 0;
    int maxLeft = maxDeep(ptr->left);
    int maxRight = maxDeep(ptr->right);
    if(maxLeft >= maxRight)
        return maxLeft+1;
    else
        return maxRight+1;
}

bool ADD(binary_link ptr, int data, int left, int right)
{
    binary_link stack[1000];
    int top = -1;
    binary_link tmp = ptr->left;
    bool found = false;
    while(true)
    {
        for(; tmp; tmp = tmp->left)
        {
            stack[++top] = tmp;
        }
        if(top==-1)
            break;
        tmp = stack[top--];
        if(tmp->data == data)
        {
            found = true;
            break;
        }
        tmp = tmp->right;
    }
    if(!found)
        return false;
    else
    {
        if(left!=0)
        {
            binary_link temp = new binary_node;
            temp->data = left;
            tmp-> left = temp;
        }
        if(right!=0)
        {
            binary_link temp = new binary_node;
            temp->data = right;
            tmp-> right = temp;
        }
        return true;
    }
}

int main()
{
    int a;
    binary_link ptr;
    binary_node b;
    ptr = &b;
    bool valid = true;
    while(cin >> a)
    {
        int inleft, inright;
        cin >> inleft >> inright;
        if(!ptr->left && !ptr->right)
        {
            binary_link temp = new binary_node;
            temp->data = a;
            ptr->left = temp;
        }
        if(valid == true)
            valid = ADD(ptr, a, inleft, inright);
        // cout << valid << endl;
    }
    if(valid == false)
    {
        cout << "Invalid tree" << endl;
    }
    else if(!ptr->left)
    {
        cout << "Tree is empty" << endl;
    }
    else
    {
        int leafCount = 0, height = 0;
        binary_link tmp = ptr->left;
        binary_link stack[1000];
        int top = -1;
        while(true)
        {
            for(; tmp; tmp = tmp->left)
            {
                stack[++top] = tmp;
            }
            if(top==-1)
                break;
            tmp = stack[top--];
            if(!tmp->left && !tmp->right)
            {
                leafCount++;
            }
            tmp = tmp->right;
        }
        // cout << "test";
        height = maxDeep(ptr->left);
        cout << height << endl << leafCount << endl;
    }
    return 0;
}
