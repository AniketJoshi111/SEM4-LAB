#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr , int n,int i)
{
    int large = i;
    int l  = 2*i+1;
    int r = 2*i+2;

    if(l<n && (arr[large] < arr[l]))
    {
        large = l;
    }
    if(r<n && arr[large] < arr[r])
    {
        large = r;
    }
    if(large!=i)
    {
        swap(arr[large],arr[i]);

        heapify(arr,n,large);
    }
}
void heapsort(vector<int> &arr)
{
    int n = arr.size();

    for(int i=n/2-1;i>=0 ;i--)
    {
        heapify(arr,n,i);
    }

    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}




// Function to print an array
void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    printArray(arr);

    heapsort(arr);

    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}