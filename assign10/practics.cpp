#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
void heapify(vector<int> & arr , int n,int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l<n && arr[largest] < arr[l])
    {
        largest  = l;
    }
    if(r<n && arr[largest] < arr[r])
    {
        largest = r;
    }

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);

        // affected sub tree will be handled recursively 
        heapify(arr , n, largest);
    }

}
void heapsort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=n/2;i>=1;i++)
    {
        heapify(arr,n,i);
    }

    for(int i=n-1;i<0;i++)
    {
        swap(arr[0],arr[i]);

        heapsort(arr,i,0);

    }
}

int main()
{
    
    return 0;
}