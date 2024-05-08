#include <iostream>
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
        lthread = true;
        rthread = true;
    }
};

void insert(node *&root, int key)
{
    node *ptr = root;
    node *par = NULL; // Parent of key to be inserted
    while (ptr != NULL)
    {
        // If key already exists, return
        if (key == (ptr->data))
        {
            cout << "Duplicate Key ";
            return;
        }
        par = ptr; // Update parent pointerroot
        // Moving on left subtree.
        if (key < ptr->data)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        // Moving on right subtree.
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    node *tmp = new node(key);

    if (par == NULL)
    {
        root = tmp;
    }
    else if (key < (par->data))
    {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = false;
        par->left = tmp;
    }
    else
    {
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = false;
        par->right = tmp;
    }
}

node *inorderSuccessor(node *ptr)
{
    // If rthread is set, we can quickly find
    if (ptr->rthread == true)
        return ptr->right;
    // Else return leftmost child of right subtree
    ptr = ptr->right;
    while (ptr->lthread == false)
        ptr = ptr->left;
    return ptr;
}

node *inorderPredecessor(node *ptr)
{
    // If rthread is set, we can quickly find
    if (ptr->lthread == true)
        return ptr->left;
    // Else return leftmost child of right subtree
    ptr = ptr->left;
    while (ptr->rthread == false)
        ptr = ptr->right;
    return ptr;
}

// Printing the threaded tree
void inorder(node *&root)
{
    if (root == NULL)
        cout << "Tree is empty";
    // Reach leftmost node
    node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;

    // One by one print successors
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = inorderSuccessor(ptr);
    }
}
int mini(node *root)
{
    node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}
node *delThreadedBST(node *&root, int dkey)
{
    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    // Initialize parent as NULL and ptrent
    // Node as root.
    node *par = NULL;
    node *ptr = root;
    // Set true if key is found
    bool found = 0;
    // Search key in BST : find Node and its
    // parent.
    while (ptr != NULL)
    {
        if (dkey == ptr->data)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->data)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found == 0)
        cout << "dkey not present in tree\n";

    // leaf node
    if (ptr->lthread && ptr->rthread)
    {

        if (par->left == ptr)
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

    // 1 child
    if (ptr->lthread || ptr->rthread)
    {
        node *child;

        // Initialize child Node to be deleted
        // left child.
        if (ptr->lthread == false)
            child = ptr->left;

        // Node to be deleted has right child.
        else
            child = ptr->right;

        // Node to be deleted is root Node.
        if (par == NULL)
            root = child;

        // Node is left child of its parent.
        else if (ptr == par->left)
            par->left = child;
        else
            par->right = child;

        // Find successor and predecessor
        node *s = inorderSuccessor(ptr);
        node *p = inorderPredecessor(ptr);

        // If ptr has left subtree.
        if (ptr->lthread == false)
            p->right = s;

        // If ptr has right subtree.
        else
        {
            if (ptr->rthread == false)
                s->left = p;
        }

        free(ptr);
        return root;
    }

    // 2 child
    if (!ptr->lthread || !ptr->rthread)
    {
        node *successor = inorderSuccessor(ptr);
        ptr->data = successor->data;
        ptr->left = delThreadedBst(ptr->left, successor->data);
        ptr->right = delThreadedBST(ptr->right, successor->data);
        return root;
    }
    return NULL;
}

int main()
{
    node *root = NULL;
    while (true)
    {
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Inorder" << endl;
        cout << "4.Stop" << endl;

        int choice;
        cout << "Enter choice:";
        cin >> choice;

        if (choice == 1)
        {
            cout << endl;
            cout << "Enter data to insert:";
            int data;
            cin >> data;
            insert(root, data);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << endl;
            cout << "Enter data to delete:";
            int data;
            cin >> data;
            root = delThreadedBST(root, data);
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << endl;
            inorder(root);
            cout << endl;
        }
        else if (choice == 4)
        {
            break;
        }
    }
    return 0;
}