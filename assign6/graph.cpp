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
void insertGraph(node* arr[],int u,int v)
{
    node* head1 = arr[u];
    node* head2 = arr[v];
    when(head1->next!=nullptr)
    {
        head1 = head1->next;
    }
    while(head2->next!=nullptr)
    {
        head2 = head2->next;
    }
    head1->next = arr[v];
    head2->next = arr[u];

    return ;
}

void bfs(node *arr[] , int n,int start)
{
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(start);
    visited[start] = false;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        cout<< u <<" ";
        // u ki linked list chahiye ab 
        node*  temp = arr[u]->next;
        while(temp->next!=nullptr)
        {
            int v = temp->data;
            
            if(!visited[temp])
            {
                cout<< v <<" ";
                visited[temp] = true;
            }
            temp = temp->next;
        }
    }
}
void dfs(node *arr[],int n,int start)
{
    vector<bool> visited(n,false);
    stack<int> s;
    s.push(start);
    visited[start]=false;
    while(!s.empty())
    {
        int  u  = s.top();s.pop();
        cout << u <<" ";
        node* temp = arr[u]->next;
        while(temp->next!=nullptr)
        {
            int v = temp->data;
            if(!visited[temp])
            {
                cout << v << " ";
                visited[temp] = true;
                s.push(v);
            }
            temp = temp->next;
        }
   }
}
int main()
{
    
    return 0;
}