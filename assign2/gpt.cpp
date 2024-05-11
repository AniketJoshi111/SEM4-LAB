#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insert(node *root, int d) {
    if (root == NULL) {
        root = new node(d);
    } else if (d <= root->data) {
        root->left = insert(root->left, d);
    } else {
        root->right = insert(root->right, d);
    }
    return root;
}

node *createBst(int arr[], int n) {
    node *root = nullptr;
    int d;
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> d;
        root = insert(root, d);
    }
    return root;
}

void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node *findMin(node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

node *deleteNode(node *root, int key) {
    if (root == NULL) return root;
    else if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    // 
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            node *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            node *temp = root;
            root = root->left;
            delete temp;
        } else {
             *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Create BST\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Delete a node\n";
    cout << "4. Exit\n";
}

int main() {
    int choice;
    node *root = nullptr;
    int n;
    int arr[n];
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                root = createBst(arr, n);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            
            case 3:
                int key;
                cout << "Enter the node value to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                cout << "Node with value " << key << " deleted.\n";
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please enter again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
