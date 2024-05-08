#include<iostream>
using namespace std;

class Node{

    //each node has a data (value) and a probability

    int data;
    int prob;

    //pointer to left and right child
    Node* left;
    Node* right;

    public:

    //constructors
    Node(){
        data = prob = -1;
        left = right = NULL;
    }
    Node(int data, int prob){
        this->data = data;
        this->prob = prob;
        left = right = NULL;
    }

    friend class Pair;
    friend class OBST;
};

//we need to create a class Pair which will store the optimal cost/weight and the root of pairs of nodes
//NOTE: If there are 5 nodes, we need a matrix of 6x6

class Pair{
    //each pair will have a cost/weight and a root, here root will be just the index of node, so we can take int
    int weight;
    int root;

    public:

    //constructors
    Pair(){
        weight = root = -1;
    }
    Pair(int weight, int root){
        this->weight = weight;
        this->root = root;
    }

    friend class OBST;
};

//we need a class OBST which will store the matrix of pairs and an array of nodes

class OBST{

    //matrix will store the pairwise weight and root, pair can be identified by [i][j] of the 2-D matrix
    Pair **matrix;
    Node *index;
    int nodeCount;

    public:
    //constructors
    OBST(){}
    OBST(int n){
        nodeCount = n+1;
        matrix = new Pair*[nodeCount];  //creating the matrix
        index = new Node[nodeCount];
        for(int i=0; i<nodeCount; i++){
            matrix[i] = new Pair[nodeCount];    //creating a row
            for(int j=0; j<nodeCount; j++){
                if(i==j)
                matrix[i][j] = Pair(0,-1);
                else
                matrix[i][j] = Pair();
            }
            if(i){
                cout<<"Enter data and probability of node "<<i<<endl;
                int data;
                int prob;
                cin>>data>>prob;                //taking input for ith node
                index[i] =  Node(data, prob);
            }
        }
    }
    //calcMin will calculate the minimum weight of each pair and store the corresponding root
    int calcMin(int i, int j){

        if(i>=j) return 0;      //******IMPORTANT BASE CONDITION, jr visarla tr saglyat INT_MAX value store hoil

        int result = INT_MAX;
        int curr = 0;
        int root = -1;

        for(int k=i+1; k<=j; k++){

            //recursive call

            curr = calcMin(i, k-1) + calcMin(k, j) + calcWeight(i,j);
            if(curr < result){
                result = curr;
                root = k;
            }
        }
        matrix[i][j].weight = result;
        matrix[i][j].root = root;
        return result;
    }

    int calcWeight(int i, int j){

        //this will calculate the summation of probs of all the nodes from i to j; i not included

        int weight = 0;
        for(int k=i+1; k<=j; k++){
            weight += index[k].prob;
        }

        return weight;
    }

    //printing the matrix just to check if the code is working

    void printMatrix(){
        for(int i=0; i<nodeCount; i++){
            for(int j=0; j<nodeCount; j++){
                cout<<matrix[i][j].weight<<" ^ "<<matrix[i][j].root<<"  |   ";
            }
            cout<<endl<<endl;
        }
    }

    void buildMatrix(){
        for(int diff=1; diff<nodeCount; diff++){
            for(int i=0; i<nodeCount; i++){
                for(int j=0; j<nodeCount; j++){
                    if(j-i == diff){
                        calcMin(i,j);
                    }
                }
            }
        }
    }

    Node* buildTree(int i, int j){
        if(i==j) return NULL;
        int temp = matrix[i][j].root;
        Node* node = &index[temp];
        node->left = buildTree(i, temp-1);
        node->right = buildTree(temp, j);
        return node;
    }

    void inorder(Node* node){
        if(!node) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
};

int main(){
    OBST o1(4);
    o1.buildMatrix();
    o1.printMatrix();
    Node* root = o1.buildTree(0, 4);
    o1.inorder(root);
    return 0;
}