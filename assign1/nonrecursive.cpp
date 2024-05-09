#include <iostream>
#include <queue>
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

int Create(node *root)
{

    node *Newnode;
    node *que[10];
    int i, cnt, front, rear, flag;
    cout << "Nodes to insert :";
    cin >> cnt;
    front = rear = 0;
    que[rear++] = root;
    i = 0;
    flag = 1;
    while (i < cnt)
    {
        if (flag == 1)
        {
            int d;
            cout << "Enter new node data :";
            cin >> d;
            Newnode = new node(d);
            /*Newnode->left=nullptr;
            Newnode->right=nullptr;*/
        }
        if (root->left == nullptr)
        {
            root->left = Newnode;
            i++;
            flag = 1;
            que[rear++] = Newnode;
        }
        else if (root->right == NULL)
        {
            root->right = Newnode;
            i++;
            flag = 1;
            que[rear++] = Newnode;
        }
        else
        {
            flag = 0;
            front++;
            root = que[front];
        }
    }
    return cnt;
}

void preorder(node *root)
{
    if(root==nullptr){ return ;}
    node* t = root;
    stack<node*> st;
    while(t!=nullptr)
    {
        cout<<t->data<<" ";
        st.push(t);
        t = t->left;
    }
    while(!st.empty())
    {
        t = st.top(); st.pop();
        t = t->right;
        while(t!=nullptr)
        {
            cout<<t->data<<" ";
            st.push(t);
            t = t->left;
        }
    }
    return ;
}
void inorder(node *root)
{
    if(root==nullptr){ return ;}
    node* t = root;
    stack<node*> st;
    while(t!=nullptr)
    {
        st.push(t);
        t = t->left;
    }
    while(!st.empty())
    {
        t = st.top(); st.pop();
        cout<<t->data<<" ";
        t = t->right;
        while(t!=nullptr)
        {
            
            st.push(t);
            t = t->left;
        }
    }
    return ;
}
void postorder(node* root)
{
    if(root==nullptr){return ;}
    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        node* t = s1.top(); s1.pop();
        s2.push(t);
        if(t->left)
        {
            s1.push(t->left);
        }
        if(t->right)
        {
            s1.push(t->right);
        }
    }
    while(!s2.empty())
    {
        cout << s2.top()->data << endl;
        
    }
}
void printmenu()
{   cout<<"NON RECURSIVE\n";
    cout << "1.Create Tree\n";
    cout << "2.Preorder \n";
    cout << "3.Inorder \n";
    cout << "4.Postorder \n";
}

int main()
{
    int ele;
    Node* root;
    Node* temp;
    int choice;
    int cnt=0;
    do
    {
        printmenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data for root node: ";
            cin >> ele;
            root = new node(ele);
            Create(root);
            break;
        case 2:
        cout<<"Preorder traversal :";
        preorder(root);
        break;
        case 2:
        cout<<"Inorder traversal :";
        inorder(root);
        break;
        case 2:
        cout<<"Postorder traversal :";
        postorder(root);
        break;
        default:
            break;
        }
    } while (choice!=4);

    return 0;
}