#include <iostream>
using namespace std;
class node
{

private:
    int key;
    string val;
    node *next;

public:
    node(int key, string val) : key(key), val(val), next(nullptr) {}
    friend class OpenHashing;
};
class OpenHashing
{
private:
    node *arr[10];

public:
    void initArr()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = new node(i, "");
        }
    }
    int hashcode(int key)
    {
        return (key % 10);
    }

    bool find(int key)
    {
        int hash = hashcode(key);
        node *temp = arr[hash];
        temp = temp->next;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void insert(int key, string value)
    {
        if (find(key))
        {
            cout << "Already present\n";
            return;
        }
        int hash = hashcode(key);
        node *temp = arr[hash];
        temp = temp->next;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new node(key, value);
        cout << "Element added successfully" << endl;
    }
    void Delete(int key)
    {
        if (!find(key))
        {
            cout << "Element not present \n";
            return;
        }
        int hash = hashcode(key);
        node *temp = arr[hash];
        temp = temp->next;
        while (temp->key != key)
        {
            temp = temp->next;
        }
        // bhetli
        temp->next = temp->next->next;
        cout << "Deleted element successfully\n";
        return;
    }
    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            node *temp = arr[i];
            while (temp->next != nullptr)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
class Menu
{
    public:
    Menu()
    {
        cout<<"\n1. Insert Key-Value Pair\n2. Delete Key\n3. Find Key\n4. Display Hash Table\n5. Exit";
    }
} ;
int main()
{
    OpenHashing obj;
    int ch;
    int key;
    string val;
    obj.initArr();
    do
    {
        Menu();
        cout<<"Enter the choice :";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the key :";
            cin>>key;
            cout<<endl;
            cout<<"Enter the value :";
            cin>>val;
            obj.insert(key,val);
            break;
        case 2:
            cout<<"Enter the key to delete:";
            cin>>key;
            obj.Delete(key);
            break;
        case 3:
            cout<<"Enter the key to find:";
            cin>>key;
            obj.find(key);
            break;
        case 4:
            cout<<"Hash Table ";
            cout<<endl;
            obj.display();
            break;
        
        default:
            break;
        }
    } while (ch!=5);
    
    return 0;
}