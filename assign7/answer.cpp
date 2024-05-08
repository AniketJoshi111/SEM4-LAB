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

int main()
{

    return 0;
}
