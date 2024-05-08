#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    bool lthread;
    bool rthread;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        this->lthread = false;
        this->rthread = false;
    }
};

void insert(node *&root, int key)
{
    node *ptr = root;
    node *parent = nullptr;

    while (ptr != nullptr)
    {
        if (key == ptr->data)
        {
            cout << "Duplicate key\n";
            return;
        }
        parent = ptr;
        if (key < ptr->data)
        {
            if (ptr->lthread == false)
            {
                ptr = ptr->left;
            }
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
            {
                ptr = ptr->right;
            }
            else
                break;
        }
    }
    // found position
    node *temp = new node(key);
    if (root == nullptr)
    {
        root = temp;
    }
    else if (key < parent->data)
    {
        temp->left = parent->left;
        temp->right = parent; // since temp->right is leaf so parent will be its inordersuccessor
        parent->left = temp;
        temp->lthread = true;
    }
    else
    {
        temp->right = parent->right;
        temp->left = parent;
        parent->right = temp;
        temp->rthread = true;
    }
    return;
}
node *inorderSuccessor(node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;
    ptr = ptr->right;

    while (ptr->lthread == false)
    {
        ptr = ptr->left;
    }
    return ptr;
}
node *inorderPredecessor(node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;

    ptr = ptr->left;
    while (ptr->rthread == false)
    {
        ptr = ptr->right;
    }
    return ptr;
}
void inorder(node *&root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree";
    }
    node *ptr = root;
    while (ptr->lthread == false)
    {
        ptr = ptr->left;
    }
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = inorderSuccessor(ptr);
    }
    return ;
}
void preorder(node *&root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree";
        return ;
    }
    node *ptr = root;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        if (ptr->lthread == false)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = inorderSuccessor(ptr);
        }
    }
    return ;
}
node *delThreadedBst(node *&root, int dkey)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return nullptr;
    }

    node *ptr = root;
    node *par = nullptr;
    bool found = 0;
    while (ptr != nullptr)
    {
        if (dkey == root->data)
        {
            found = 1;
            break;
        }
        if (dkey < root->data)
        {
            if (root->lthread == false)
            {
                root = root->left;
            }
            else
                break;
        }
        else
        {
            if (dkey > root->data)
            {
                if (root->rthread == false)
                {
                    root = root->right;
                }
                else
                    break;
            }
        }
    }
    if (found == 0)
    {
        cout << "dkey is not present in the tree \n";
    }

    // leaf node
    if (ptr->lthread && ptr->rthread)
    {
        if (par->left = ptr)
        {
            par->lthread = ptr->lthread;
            par->left = ptr->left;
        }
        else
        {
            par->rthread = ptr->rthread;
            par->right = ptr->right;
        }
        delete ptr;
        return root;
    }

    // one children
    if (ptr->lthread || ptr->rthread)
    {
        node *child;
        // child ani ptr madhye connection mhanje par-ptr-child asa jhala
        if (ptr->lthread == false)
            child = ptr->left;
        else
            child = ptr->right;
    
        // aata ptr la udvaycha ae 
        if (par == nullptr)
        {
            root = child;
        }
        else if (ptr == par->left)
            par->left = child;
        else
            par->right = child;

        node *s = inorderSuccessor(ptr);
        node *p = inorderPredecessor(ptr);

        if (ptr->lthread == false)
        {
            p->right = s;    // predeccessor ke right mein successor matlab ptr ud gaya if left exist
        }
        else
        {
            if (ptr->rthread == false)
                s->left = p;
        }
        delete ptr;
        return root;
    }

    // two child
    if(!ptr->lthread || !ptr->rthread)
    {
        node* successor = inorderSuccessor(ptr);
        ptr->data = successor->data;
        
        ptr->right = delThreadedBst(ptr->right,successor->data);
        return root;
    }
    return nullptr;
}
void printmenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert\n";
    cout << "2.Inorder Traversal\n";
    cout << " 3.Preorde Traversal\n";
    cout <<" 4.Delete node in tbt\n";

}
int main()
{
    node *root = NULL;
    int choice, data, key;
    do
    {
        printmenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert :";
            cin >> data;
            insert(root, data);
            break;
        case 2:
            cout << "Inorder Traversal is :";
            inorder(root);
            break;
        case 3:
            cout << "Preorder Traversal is :";
            preorder(root);
            break;
        case 4:
            cout<<"Enter the data to be delete: ";
            int data;
            cin>> data;
            root = delThreadedBst(root,data);
            cout<<endl;
            break;
        default:
            break;
        }

    } while (choice != 5);

    return 0;
}