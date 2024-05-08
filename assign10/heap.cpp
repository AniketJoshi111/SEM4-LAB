#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr,int n,int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l<n && arr[l]>arr[largest])
    {
        largest = l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest =r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);

        heapify(arr,n,largest);
    }
    return ;
}

void heapsort(vector<int> &arr,int n)
{
    for(int i =n/2 ; i>0;i++)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=1;i--)
    {
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
    return ;
}
void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = 6;
    cout << "Original array: ";
    printArray(arr);

    heapsort(arr,n);

    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}