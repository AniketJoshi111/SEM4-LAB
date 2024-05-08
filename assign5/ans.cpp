#include<bits/stdc++.h>
using namespace std;

class node{
    private:
        int key;
        string value;
        node* next;
    public:
        node(int key,string value):key(key),value(value),next(NULL){}
        friend class OpenHashing;
};

class OpenHashing{
    private:
        node* arr[10];
    public:
        void initArr(){
            for(int i=0;i<10;i++){
                arr[i]=new node(i,"");
            }
        }
        int hashValue(int key){
            return (key%10);
        }
        bool find(int key){
            int hash=hashValue(key);
            node* temp=arr[hash];
            temp=temp->next;
            while(temp!=NULL){
                if(temp->key == key){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }
        void insert(int key,string value){
            if(find(key)){
                cout<<"Key already present"<<endl;
                return;
            }
            int hash=hashValue(key);
            node* temp=arr[hash];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new node(key,value);
            cout<<"Element added Successfully"<<endl;
        }

        void deleteKey(int key){
            if(!find(key)){
                cout<<"Key not present"<<endl;
                return;
            }
            int hash=hashValue(key);
            node* temp=arr[hash];
            while(temp->next->key != key){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            cout<<"Element deleted Successfully"<<endl;
        }
        
        void display(){
            for(int i=0;i<10;i++){
                node*temp=arr[i];
                temp=temp->next;
                cout<<i<<":";
                while(temp!=NULL){
                    cout<<"("<<temp->key<<":"<<temp->value<<")"<<"-->";
                    temp=temp->next;
                }
                cout<<"NULL"<<endl;
            }
        }
};

int main() {
    int choice;
    int key;
    string value;
    OpenHashing obj;
    string menu="\n1. Insert Key-Value Pair\n2. Delete Key\n3. Find Key\n4. Display Hash Table\n5. Exit";
    obj.initArr();
    while(true){
        cout<<menu;
        cout<<"\nEnter choice:";
        cin>>choice;
        if(choice==1){
            cout<<"Enter key:";
            cin>>key;
            cout<<"Enter Value:";
            cin>>value;
            obj.insert(key,value);
        }
        else if(choice==2){
            cout<<"Element to Delete:";
            cin>>key;
            obj.deleteKey(key);
        }
        else if(choice==3){
            cout<<"Enter key to Search:";
            cin>>key;
            if(obj.find(key)){
                cout<<endl<<"Element Found"<<endl;
            }
            else{
                cout<<endl<<"Element not Found"<<endl;
            }
        }
        else if(choice==4){
            obj.display();
        }
        else if(choice==5){
            break;
        }
    }
    
    return 0;
}