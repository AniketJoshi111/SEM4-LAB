#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int **arr;
    int n;
    int *parent;

public:
    Graph()
    {
        int size;
        cout << "Enter the count of vertices: ";
        cin >> size;
        this->n = size;
        arr = new int *[n];
        cout << endl
             << n << endl;
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = 0;
            }
        }
        parent = new int[n];
        parent[0] = -1;
    }

    void inputAdjacencyList()
    {
        cout << "Enter -1 to exit!!!\n";
        while (true)
        {
            int i, j, w;
            cout << "Enter v1: ";
            cin >> i;
            if (i == -1)
                break;
            if (i >= n)
            {
                cout << "\nWrong input! try again.";
                continue;
            }
            cout << "Enter v2: ";
            cin >> j;
            if (j == -1)
                break;
            if (j >= n)
            {
                cout << "\nWrong input! try again.";
                continue;
            }
            cout << "Enter edge weight: ";
            cin >> w;
            if (w == -1)
                break;
            arr[i][j] = w;
            arr[j][i] = w;
        }
    }

    void printList()
    {
        for (int i = 0; i < n; i++)
        {
            cout << endl;
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << "   ";
            }
        }
    }

    int FindMST()
    {
        // vector<int> weights(n, 999);
        int weights[n]; // we can't initialize an array with an non zero values for each element we have use vector or initialize whole array using for;
        for (int i = 0; i < n; i++)
            weights[i] = 9999;
        bool visited[n] = {false};

        parent[0] = -1;
        weights[0] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int v = minimumVertex(weights, visited);
            visited[v] = true;

            for (int j = 0; j < n; j++)
            {
                if (arr[v][j] != 0 && visited[j] == false && arr[v][j] < weights[j])
                {
                    weights[j] = arr[v][j];
                    parent[j] = v;
                }
            }
        }
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            cost += weights[i];
        }

        return cost;
    }

    // int minimumVertex(vector<int> weights, bool *visited)
    int minimumVertex(int *weights, bool *visited)
    {
        int vertex;
        int mini = 1000000;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false && weights[i] < mini)
            {
                mini = weights[i];
                vertex = i;
            }
        }
        return vertex;
    }

    void printMST()
    {
        cout << "\nMST is: \n";
        for (int i = 1; i < n; i++)
        {
            cout << parent[i] << " --- " << i << endl;
        }
    }
};

int main()
{
    // 5 0 1 3 0 2 2 2 1 2 2 4 1 4 3 1 3 2 4 -1
    Graph obj;
    obj.inputAdjacencyList();
    obj.printList();
    int cost = obj.FindMST();
    cout << "\nCost of MST is: " << cost;
    obj.printMST();
    cout << "\n\n\n\nAll done!!!";
}