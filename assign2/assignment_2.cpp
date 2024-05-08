#include<bits/stdc++.h>
using namespace std;

class node{
    private:
        int data;
        node*left;
        node*right;
    public:
        node(int data):data(data),left(NULL),right(NULL){}
        friend class BST;
};

class BST{
    public:
        node* insertnode(node*&root,node*&newnode){
            node* newroot=root;
            if(root==NULL){
                root=newnode;
                return root;
            }
            if(newnode->data < root->data){
                if(root->left==NULL){
                    root->left=newnode;
                }
                else{
                    insertnode(root->left,newnode);
                }
            }
            else if(newnode->data > root->data){
                if(root->right==NULL){
                    root->right=newnode;
                }
                else{
                    insertnode(root->right,newnode);
                }
            }return newroot;
        }

        void inorder(node* root){
            if(root==NULL)return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

        int minData(node*root){
            while(root->left!=NULL){
                root=root->left;
            }
            return root->data;
        }

        int maxData(node*root){
            while(root->right!=NULL){
                root=root->right;
            }
            return root->data;
        }

        void reverse(node* &root){
            if(root==NULL)return;
            node* temp=root->left;
            root->left=root->right;
            root->right=temp;
            reverse(root->left);
            reverse(root->right);
        }

        bool search(node* root,int val){
            while(root!=NULL){
                if(root->data == val)return true;
                else if(root->data > val)root=root->left;
                else root=root->right;
            }
            return false;
        }

        int longestPathnodes(node* root){//ssimilar to height
            if(root==NULL)return 0;
            int left=longestPathnodes(root->left);
            int right=longestPathnodes(root->right);
            int ans=max(left,right)+1;
            return ans;
        }

        node* deletenode(node* root, int k){
            if(root==NULL){
                return root;
            }

            if(root->data>k){
                root->left = deletenode(root->left,k);
                return root;                
            }

            else if(root->data < k){
                root->right = deletenode(root->right,k);
                return root;
            }

            if(root->left == NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            else{
                node* succParent = root;
                node* succ = root->right;
                while(succ->left != NULL){
                    succParent = succ;
                    succ = succ->left;
                }
                if (succParent != root)
                    succParent->left = succ->right;
                else
                    succParent->right = succ->right;
        
                // Copy Successor Data to root
                root->data = succ->data;
        
                // Delete Successor and return root
                delete succ;
                return root;
            }     
        }

};

int main(){
    BST obj;
    node* root=NULL;
    for(int i=0;i<6;i++){
        cout<<"Data:";
        int d;
        cin>>d;
        node* newnode=new node(d);
        root=obj.insertnode(root,newnode);
    }
    obj.inorder(root);
    cout<<endl;
    root=obj.deletenode(root,7);
    obj.inorder(root);
    cout<<endl;
    return 0;
}


