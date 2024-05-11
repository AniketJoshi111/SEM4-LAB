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

node *insert(node *root, int value)
{
    if(root==nullptr)
    {
        return new node(value);
    }
    else if(root->data > value)
    {
        root->left = insert(root->left,value);
    }
    else if(root->data < value)
    {
        root->right = insert(root->right,value);
    }
    return root;
}

int findNodesInLongestPath(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = findNodesInLongestPath(root->left);
    int right = findNodesInLongestPath(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int findMin(node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root->data;
}

int findMax(node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->data;
}

void inorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* search(node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

node *invertTree(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void displayMenu()
{
    cout << "Binary Search Tree Operations:" << endl;
    cout << "1. Create BST" << endl;
    cout << "2. Insert In BST" << endl;
    cout << "3. Find number of nodes in the longest path" << endl;
    cout << "4. Find minimum element" << endl;
    cout << "5. Find maximum element" << endl;
    cout << "6. Search for an element" << endl;
    cout << "7. Invert the tree" << endl;
    cout << "8. Inorder" << endl;
    cout << "9. Exit" << endl;
}

int main()
{
    node *root = nullptr;
    int choice, value,num;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter number of elements to insert\n";
            cin>>num;
            cout<<"Enter the values:";
            for(int i=0;i<num;i++)
            {
                int c;
                cin>>c;
                root = insert(root,c);
            }
            break;
        case 2:
            cout << "Enter value to insert:";
            int a;
            cin >> a;
            root = insert(root, a);
        case 3:
            cout << "Number of nodes in the longest path: " << findNodesInLongestPath(root) << endl;
            break;
        case 4:
            cout << "Minimum element: " << findMin(root) << endl;
            break;
        case 5:
            cout << "Maximum element: " << findMax(root) << endl;
            break;
        case 6:
            cout << "Enter the value to search: ";
            cin >> value;
            if (search(root, value))
            {
                cout << "Element found in the tree." << endl;
            }
            else
            {
                cout << "Element not found in the tree." << endl;
            }
            break;
        case 7:
            root = invertTree(root);
            cout << "Tree inverted successfully." << endl;
            break;
        case 8:
            cout << "Printing inorder:";
            inorder(root);
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}