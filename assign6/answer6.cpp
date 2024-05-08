#include<iostream>
#include<queue>
#include <stack>
#include <vector>
using namespace std;

class node
{
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

};
void insertInGraph(node* arr[] , int u,int v)
{
    node* head1 = arr[u];
    node* head2 = arr[v];
    while (head1->next!=nullptr)
    {
        head1 = head1->next;
    }
    while (head2->next!=nullptr)
    {
        head2 = head2->next;
    }
    head1->next = new node(v);
    head2->next = new node(u);

    return ;    
}
void bfs(node* arr[], int n,int start)
{
    vector<bool> visited(n,false);
    queue<int> q;

    q.push(start); // add
    visited[start] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<< u <<" ";      // visit 

        node* temp = arr[u]->next;
        while(temp!=nullptr)
        {
            int v = temp->data;
            if(!visited[v])
            {
                cout << v <<" ";
                visited[v] = true;
            }
            temp = temp->next;
        }
    }
}
void dfs(node* arr[], int n, int start)
{
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start); // add
    visited[start] = true;
    while (!s.empty())  
    {
        int u = s.top();
        s.pop();
        cout << u << " "; // visit

        node* temp = arr[u]->next;
        while (temp != nullptr)
        {
            int v = temp->data;
            if (!visited[v])
            {
                cout << v << " ";
                visited[v] = true;
                s.push(v);
            }
            temp = temp->next;
        }
    }
}

void displayList(node* arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        node* head = arr[i];
        while(head!=nullptr){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
}
int main()
{
    node* arr[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = new node();
    }
    insertInGraph(arr  , 0, 1);
    insertInGraph(arr, 0, 2);
    insertInGraph(arr, 0, 3);
    insertInGraph(arr, 0, 4);
    insertInGraph(arr, 1, 5);
    insertInGraph(arr, 2, 5);
    insertInGraph(arr, 3, 6);
    insertInGraph(arr, 4, 6);   
    insertInGraph(arr, 5, 7);
    insertInGraph(arr, 6, 7);
    dfs()
    displayList(arr,10);

    return 0;
}