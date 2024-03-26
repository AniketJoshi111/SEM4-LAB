/*Binary Tree implementation */
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};
int Create(Node* root)
{
    
    Node* Newnode;
    Node* que[10];
    int i,cnt,front,rear,flag;
    cout<<"Nodes to insert :";
    cin>>cnt;
    front=rear=0;
    que[rear++]=root;
    i=0;flag=1;
    while(i<cnt){
        if(flag==1)
        {
            int d;
            cout<<"Enter new node data :";
            cin>>d;
            Newnode = new Node(d);
            /*Newnode->left=nullptr;
            Newnode->right=nullptr;*/
        }
        if(root->left==nullptr)
        {
            root->left=Newnode;
            i++;flag=1;
            que[rear++]=Newnode;

        }
        else if(root->right==NULL)
        {
            root->right=Newnode;
            i++;flag=1;
            que[rear++]=Newnode;

        }
        else{
            flag=0;
            front++;
            root = que[front];
        }
    }
    return cnt;
}


void inorderCount(Node* root,int &count){
    if(root==NULL) return;
    inorderCount(root->left,count);   // & is req so count do not reinitialize
    inorderCount(root->right,count);
    if(root->left == NULL && root->right==NULL){
        count++; // found leaf
    } 
}
void inorder(Node* &root) {
    
    if(root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}
void preorder(Node* &root) { 
    
    if(root == NULL) {
        return ;
    }
    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* &root) {
    
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}
Node* swaptree(Node* root) {
        if(root==NULL){
            return NULL;
        }
        Node* temp=root->left;
        root->left=root->right;
        root->right=temp;
        swaptree(root->left);
        swaptree(root->right);
        return root;
}
Node* copy(Node* root)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    Node* cpy = new Node(root->data);
    cpy->left = copy(root->left);
    cpy->right = copy(root->right);
    return cpy;

}
int height(Node* root){
    if(root == NULL) {
        return 0;
    }    
    int left = height(root ->left);
    int right = height(root->right);    
    int ans = max(left, right)+1;
    return ans;
}
int numberOfLeaf(Node*root){
    int cnt=0;
    inorderCount(root,cnt);
    return cnt;

}



void deleteTree(Node* Node) 
{ 
    if (Node == NULL) return; 

    deleteTree(Node->left); 
    deleteTree(Node->right); 
    
    cout << "\n Deleting Node: " << Node->data; 
    delete Node;
} 

void printMenu() {
    cout << "1. Build Tree\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Preorder Traversal\n";
    cout << "4. Postorder Traversal\n";
    cout << "5. Swap Tree\n";
    cout << "6. Calculate Height\n";
    cout << "7. Count Number of Leaf Nodes\n";
    cout << "8. Count Number of Non-Leaf Nodes\n";
    cout << "9. Delete Tree\n";
    cout << "10.Copy tree\n";
    cout<<  "11.Print copied tree\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: ";
}

int main(){
    bool isdeleted = false;
    int ele;
    Node* root;
    Node* temp;
    int choice;
    int cnt=0;

    do {
        printMenu();                 
        cin >> choice;

        switch (choice) {
            case 1:
                isdeleted=false;
                cout<<"Enter root element :";
                cin>>ele;
                root = new Node(ele);
                cnt = Create(root);
                break;

            case 2:
                if(isdeleted==true)
                {
                    cout<<"Tree is deleted :";
                    break;
                }
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                if(isdeleted==true)
                {
                    cout<<"Tree is deleted :";
                    break;
                }
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                if(isdeleted==true)
                {
                    cout<<"Tree is deleted :";
                    break;
                }
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                if(isdeleted==true)
                {
                    cout<<"Tree is deleted :";
                    break;
                }
                root = swaptree(root);
                cout << "Tree inverted.\n";
                break;

            case 6:
                if(isdeleted==true)
                {
                    cout<<"Tree is deleted :";
                    break;
                }
                cout << "Tree Height: " << height(root) << endl;
                break;

            case 7:
                if(isdeleted==true)
                {
                    cout<<"Tree is deleted :";
                    break;
                }
                cout << "Number of Leaf Nodes: " << numberOfLeaf(root) << endl;
                break;

            case 8:
                if(isdeleted==true)
                {
                    cout<<"Tree is deleted :";
                    break;
                }
                cout << "Number of Non-Leaf Nodes: " << cnt-numberOfLeaf(root)+1<< endl;
                break;

            case 9:

                deleteTree(root);
                root = NULL;
                
                cout << "Tree Deleted.\n";
                isdeleted=true;
                break;
            
            case 10:
                if(isdeleted==true)
               {
                cout<<"Tree is deleted "<<endl;
               }
               temp = copy(root);
                break;

            case 11:
               if(isdeleted==true)
               {
                cout<<"Tree is deleted "<<endl;
               }
               cout<<"Printing in inorder manner \n";
               inorder(temp);
               cout<<"Tree is copied"<<endl;
               break;
            case 12:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 12);

    return 0;
}


vedant barve