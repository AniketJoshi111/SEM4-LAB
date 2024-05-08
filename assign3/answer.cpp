
#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	bool rthread;
	bool lthread;
	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
		rthread = true;
		lthread = true;
	}
};

Node* insert(Node*& root, int data){

	Node* ptr = root;
	Node* parent = NULL;

	while(ptr != NULL){

		parent = ptr;

		if(data < ptr->data){
			if(ptr->lthread == false)
				ptr = ptr->left;
			else
				break;
		}
		else{
			if(ptr->rthread == false)
				ptr = ptr->right;
			else
				break;
		}
	}

	Node* temp = new Node(data);

	if(parent == NULL){
		root = temp;
	}
	else if(data < parent->data){
		temp->left = parent->left;
		temp->right = parent;
		parent->left = temp;
		parent->lthread = false;
	}
	else{
		temp->right = parent->right;
		parent->right = temp;
		temp->left = parent;
		parent->rthread = false;
	}

	return root;
}


Node* inorderSuccessor(Node* ptr){

	if(ptr->rthread == true) return ptr->right;  // basically agar right most leaf connected hoti hai root node se toh ptr->right will be inorder successor 

	ptr = ptr->right;
	while(ptr->lthread == false){
		ptr = ptr->left;
	}
	return ptr;
}
void inorderTraverse(Node* root){

	if(root == NULL){
		cout << "empty tree\n";
		return;
	}

	Node* ptr = root;

	while(ptr->lthread == false){
		ptr = ptr->left;	
	}

	while(ptr != NULL){
		cout << ptr->data << " ";
		ptr = inorderSuccessor(ptr);
	}
	cout << endl;
}

void preorderTraverse(Node* root){
    Node* ptr = root;

    while(ptr != NULL){

        cout << ptr->data << " ";

        if(ptr->left != NULL && ptr->lthread == false){
            ptr = ptr->left;
        }
        else if(ptr->right != NULL && ptr->rthread == false){
            ptr = ptr->right;
        }
        else{
            // Move to the inorder successor
            while(ptr != NULL && ptr->rthread == true){
                ptr = ptr->right;
            }

            // If ptr is NULL, it means we have reached the end
            if(ptr == NULL){
                break;
            }

            ptr = ptr->right; // Move to the right child
        }
    }
    cout << endl;
}
Node *getSuccessor(Node *ptr)
{
    Node *succ = ptr->right;
    while (succ->left != NULL && succ->lthread == false)
        succ = succ->left;
    return succ;
}

Node *deleteNode(Node *root, int key)
{
    Node *par = NULL; // Parent of the node to be deleted
    Node *curr = root; // Current node
    bool found = false; // Flag to indicate if key is found
    // Traverse the tree to find the node to be deleted
    while (curr != NULL)
    {
        if (key == curr->data)
        {
            found = true;
            break;
        }
        par = curr;
        if (key < curr->data)
        {
            if (curr->lthread == false)
                curr = curr->left;
            else
                break;
        }
        else
        {
            if (curr->rthread == false)
               { curr = curr->right;}
            else
                break;
        }
    }
    // If key is not found, return root unchanged
    if (found == false)
    {
        cout << "Key not found. Deletion failed." << endl;
        return root;
    }
    // Case 1: Node to be deleted has no children
    if (curr->lthread && curr->rthread)
    {
        // If the node is the root
        if (par == NULL)
        {
            delete curr;
            return NULL;
        }
        // If the node is a left child
        if (curr == par->left)
        {
            par->lthread = true;
            par->left = curr->left;
        }
        // If the node is a right child
        else
        {
            par->rthread = true;
            par->right = curr->right;
        }
        delete curr;
    }
    // Case 2: Node to be deleted has only one child
    else if (curr->lthread || curr->rthread)
    {
        // Find the child node
        Node *child = (curr->lthread) ? curr->left : curr->right;
        // If the node to be deleted is the root
        if (par == NULL)
            return child;
        // If the node to be deleted is a left child
        if (curr == par->left)
            par->left = child;
        // If the node to be deleted is a right child
        else
            par->right = child;
        // Find the inorder successor of the node to be deleted
        Node *succ = getSuccessor(curr);
        if (curr->lthread == false)
            succ->left = curr->left;
        if (curr->rthread == false)
            succ->right = curr->right;
        delete curr;
    }
    // Case 3: Node to be deleted has two children
    else
    {
        // Find the inorder successor of the node to be deleted
        Node *succ = getSuccessor(curr);
        Node *succPar = NULL;
        // Traverse the tree to find the parent of the successor
        while (succPar != NULL && succPar->left != succ)
            succPar = succPar->left;
        // Replace the data of the node to be deleted with the data of the successor
        curr->data = succ->data;
        // Delete the successor node
}
    return root; // Add this line to return the modified root
}

int main() {

	 Node* root = NULL;
    int choice, data, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                root = insert(root, data);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;

            case 3:
                cout << "Inorder Traversal: ";
                inorderTraverse(root);
                cout << endl;
                break;

            case 4:
                cout << "Preorder Traversal: ";
                preorderTraverse(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
