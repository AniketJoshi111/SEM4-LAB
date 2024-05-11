#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    node() : data(0), next(nullptr) {} // Default constructor
};

class Stack
{
    private:
    int arr[20];
    int top;
    public:
    Stack(){top = -1;}
    void push(int a)
    {
        if(top==20)
        {
            cout<<"Stack overflow\n";
            return ;
        }
        top++;
        arr[top] = a;
    }
    void pop()
    {
        if(top==-1) { cout<<"Stack underflow \n"; return ;}
        top--;
    }
    bool isEmpty()
    {
        return (top==-1);
    }
    int topi()
    {
        if(top==-1)
        { cout<<"NO element \n";
        return -1;}
        return arr[top];
    }
};

class Queue
{
    private:
    int arr[20];
    int front_index; 
    int rear_index;
    public:
    Queue()
    {
        front_index = rear_index = -1;
    }
    void enqueue(int v)
    {
        if(rear_index==19)
        {
            cout<<"queue is full";
            return ;
        }
        arr[++rear_index] = v;
    }
    int front()
    {
        if(front_index==-1 || front_index > rear_index)
        {
            cout<<"no element";
            return -1;
        }
        return arr[front_index];
    }
    void dequeue()
    {
         if(front_index==-1 || front_index > rear_index)
        {
            cout<<"no element";
            return ;
        }
        front_index++;
    }
    bool empty()
    {
        return (front_index == -1 || front_index > rear_index);
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
    Queue q;

    q.enqueue(start); // add
    visited[start] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.dequeue();
        cout<< u <<" ";      // visit 

        node* temp = arr[u]->next;
        while(temp!=nullptr)
        {
            int v = temp->data;
            if(!visited[v])
            {
                cout << v <<" ";
                visited[v] = true;
                q.enqueue(v);
            }
            temp = temp->next;
        }
    }
}
void dfs(node* arr[], int n, int start)
{
    vector<bool> visited(n, false);
    Stack s;

    s.push(start); // add
    visited[start] = true;
    while (!s.isEmpty())  
    {
        int u = s.topi();
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
    dfs(arr, 20, 0);
    cout << endl;
    bfs(arr, 20, 0);
    cout << endl;
    displayList(arr, 20);

    return 0;
}
