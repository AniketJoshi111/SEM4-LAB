#include<bits/stdc++.h>
using namespace std;

class node{
    private:    
        int data;
        node* left;
        node* right;
        bool lthread;
        bool rthread;
    public:
        node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
            lthread=true;
            rthread=true;
        }
        friend class TBST;
};

class TBST{
    public:

        node* insert(node* &root,int key){

            node* ptr=root;
            node* par=NULL;
            while(ptr != NULL){
                if(key==ptr->data){
                    cout<<"Duplicate Key";
                    return root;
                }

                par=ptr;

                if(key < ptr->data){
                    if(ptr->lthread == false){
                        ptr=ptr->left;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(ptr->rthread==false){
                        ptr=ptr->right;
                    }
                    else{
                        break;
                    }
                }
            }

            node* temp=new node(key);

            if(par==NULL){
                root=temp;
            }
            else if(key <par->data){
                temp->left=par->left;
                // temp->lthread=par->lthread;
                temp->right=par;
                par->lthread=false;
                par->left=temp;
            }
            else{
                temp->left=par;
                temp->right=par->right;
                par->rthread=false;
                par->right=temp;
            }
            return root;
        }

        node* inorderSuccessor(node* ptr){
            if(ptr->rthread==true){
                return ptr->right;
            }

            ptr=ptr->right;
            while(ptr->lthread == false){
                ptr=ptr->left;
            }
            return ptr;
        }

        node* inorderPredecessor(node* ptr){
            if(ptr->lthread==true){
                return ptr->left;
            }
            ptr=ptr->left;
            while(ptr->rthread == false){
                ptr=ptr->right;
            }
            return ptr;
        }

        void inorder(node* &root){
            if(root==NULL){
                cout<<"Tree Is Empty";
                return;
            }
            node* ptr=root;
            while(ptr->lthread==false){
                ptr=ptr->left;
            }
            while (ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=inorderSuccessor(ptr);
            }                  
        }
        void preorder(node* root){
            if (root == NULL) return;
            stack<node*> s;
            s.push(root);
            while(!s.empty()){
                node*temp=s.top();
                s.pop();
                cout<<temp->data<<" ";
                if(temp->rthread==false)s.push(temp->right); //imp(first right child then left)
                if(temp->lthread==false)s.push(temp->left);
            }
        }
        //leaf
        node* caseA(node*& root,node*&par,node*&ptr){
            if(par==NULL){//root node is to be deleted
                root=NULL;
            }
            else if(ptr==par->left){
                par->lthread=true;
                par->left=ptr->left;
            }
            else{
                par->rthread=true;
                par->right=ptr->right;
            }

            delete ptr;
            return root;
        }
        // one child 
        node* caseB(node*& root,node*&par,node*&ptr){
            node* child;
            if(ptr->lthread==false){
                child=ptr->left;
            }
            else{
                child=ptr->right;
            }

            if(par==NULL){
                root=child;
            }
            else if(ptr==par->left){
                par->left=child;
            }
            else{
                par->right=child;
            }
            node* s=inorderSuccessor(ptr);
            node* p=inorderPredecessor(ptr);
            if(ptr->lthread==false){
                p->right=s;
            }
            else if(ptr->rthread==false){
                s->left=p;
            }
            delete ptr;
            return root;
        }
        node* caseC(node*& root,node*&par,node*&ptr){
            node* parSucc=ptr;
            node* succ=ptr->right;

            while(succ->lthread==false){
                parSucc=succ;
                succ=succ->left;
            }

            ptr->data=succ->data;

            if(succ->lthread==true&&succ->rthread==true){
                root=caseA(root,parSucc,succ);
            }
            else{
                root=caseB(root,parSucc,succ);
            }
            return root;
        }
        node* delTBST(node* &root,int dkey){
            node* par=NULL;
            node* ptr=root;
            int found=0;
            while(ptr!=NULL){
                if(ptr->data==dkey){
                    found=1;
                    break;
                }
                par=ptr;
                if(dkey<ptr->data){
                    if(ptr->lthread==false){
                        ptr=ptr->left;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(ptr->rthread==false){
                        ptr=ptr->right;
                    }
                    else{
                        break;
                    }
                }
            }
            if(found==0){
                cout<<"Key not Present\n";
                // return NULL;
            }
            else if(ptr->lthread==false&&ptr->rthread==false){
                root=caseC(root,par,ptr);
            }
            else if(ptr->lthread==false){
                root=caseB(root,par,ptr);
            }
            else if(ptr->rthread==false){
                root=caseB(root,par,ptr);
            }
            else{
                root=caseA(root,par,ptr);
            }
            return root;
        }

        
};
int main(){
    TBST obj;
    node* root=NULL;
    for(int i=0;i<9;i++){
        int val;
        cout<<"Enter data:";
        cin>>val;
        root=obj.insert(root,val);
    }
    obj.inorder(root);
    cout<<endl;
    obj.delTBST(root,);
    obj.inorder(root);
    return 0;
}
