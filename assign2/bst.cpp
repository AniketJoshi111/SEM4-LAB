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

node *insert(node *root, int data)
{
    if (root == nullptr)
    {
        root = new node(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorder(node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


node *createBST(int arr[], int n)
{
    node *root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

int main()
{
    int arr[] = {5, 3, 8, 2, 4, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *root = createBST(arr, n);

    cout << "Inorder traversal of BST: ";
    inorder(root);

    return 0;
}