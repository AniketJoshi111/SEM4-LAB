#include <iostream>
#include <queue>
#include<stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;

        this->left = NULL;
        this->right = NULL;
    }
};

int Create(node *&root)
{
    node *newnode;
    node *que[10];
    int i, cnt, flag, front, rear;
    cout << "Enter number of nodes :";
    cin >> cnt;
    i = 0;
    flag = 1;
    front = rear = 0;
    que[rear++] = root;
    while(i<cnt)
    {
        if (flag)
    {
        cout << "Enter the val:";
        int d;
        cin >> d;
        newnode = new node(d);
    }
    if(root->left==nullptr)
    {
        root->left = newnode;
        i++; flag=1;
        que[rear++] = newnode;
    }
    else if (root->right==nullptr)
    {
        root->right = newnode;
        i++; flag=1;
        que[rear++] = newnode;         // 
    }
    else
    {
        flag=0;
        front++;
        root = que[front];
    }
    }
}
void preorder_non(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    node *t = root;
    stack<node *> s;
    while (t != nullptr)
    {
        cout << t->data << " ";
        s.push(t);
        t = t->left;
    }
    while (!s.empty())
    {
        t = s.top();
        s.pop();

        t = t->right;
        while (t != nullptr)
        {
            cout << t->data << " ";
            s.push(t);
            t = t->left;
        }
    }
}
void inorder_non(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    node *t = root;
    stack<node *> s;
    while (t != nullptr)
    {
        s.push(t);
        t = t->left;
    }
    while (!s.empty())
    {
        t = s.top();
        s.pop();
        cout << t->data << " ";
        t = t->right;
        while (t != nullptr)
        {
            s.push(t);
            t = t->left;
        }
    }
}
int height(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftans = height(root->left);
    int rightans = height(root->right);
    int ans = max(leftans, rightans) + 1;
    return ans;
}
void inorderCount(node* &root,int &cnt)
{
    if(root==nullptr){ return ;}
    inorderCount(root->left,cnt);
    inorderCount(root->right,cnt);
    if(root->left==NULL && root->right==NULL)
    {
        cnt++;
    }
}
int leafnodes(node* root)
{
   int cnt=0;
   inorderCount(root,cnt);
   return cnt;
}
void Menu()
{
    cout << "NON RECURSIVE\n";
    cout << "1.Create Tree\n";
    cout << "2.Preorder \n";
    cout << "3.Inorder \n";
    cout << "4.Postorder \n";
    cout << "5.Exit\n";
}
int main()
{
    node *root = nullptr;
    int ch;
    int ele;
    int cnt = 0;
    node *temp;
    int dis=0;
    do
    {
        Menu();
        cout << "Enter the choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the value:";
            cin >> ele;
            root = new node(ele);
            cnt = Create(root);
            break;
        case 2:
            dis = leafnodes(root);
            cout<<dis<<endl;
            break;
        case 3:

            break;

        default:
            break;
        }
    } while (ch != 4);
}