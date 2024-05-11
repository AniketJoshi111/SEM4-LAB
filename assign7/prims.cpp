#include <bits/stdc++.h>
using namespace std;
#define V 5

class Graph
{
public:
    void create()
    {
        cout<<"Enter -1 to exit \n";
        while (true)
        {
            int i,j,w;
            
        }
        
    }
    int smallestKeyVertex(vector<int> &value, vector<bool> &isMst)
    {
        int minimum = INT_MAX;
        int vertex;
        for (int i = 0; i < V; i++)
        {
            if (isMst[i] == false && value[i] < minimum)
            {
                minimum = value[i];
                vertex = i;
            }
        }
        return vertex;
    }
    void findMST()
    {
        int parent[V];
        vector<int> value(V, INT_MAX);
        vector<bool> isMst(V, false);
        
        parent[0] = -1;
        value[0] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            int U = smallestKeyVertex(value, isMst);
            isMst[U] = true;

            for (int j = 0; j < V; ++j)
            {
                // 3 rules -> unvisited , edge eixist and more than mimi
                if(isMst[j]==false && graph[U][j]!=0 && graph[U][j] < value[j])
                {
                    value[j]  = graph[U][j];
                    parent[j] = U;
                }
            }

        }

        for(int i=1;i<V;i++)
        {
            cout<< parent[i] << "->" <<  i << " "<< "wt->" << graph[parent[i]][i]<<endl;
        }

        return ;
    }
private:
    
    
};
int main()
{
    Graph g;
    g.findMST();
    return 0;
}

