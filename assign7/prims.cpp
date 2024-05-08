#include<bits/stdc++.h>
using namespace std;

#define V 6

int selectMinvertex(vector<int> &value,vector<bool> &isMst)
{
    int minimum  = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(isMst[i]==false && value[i]<minimum)
        {
            minimum = value[i];

        }
    }
    return vertex;
}

