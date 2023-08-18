#include <iostream>
#include "queue.cpp"
#define VISITED 1
#define NONVISITED 0
#define NOEDGE 0
#define EDGE 1

using namespace std;

class Graphs{
    int **nodes, size;
    Queue<int>queue;
public:
    Graphs(int count){
        size=count;
        nodes=new int*[count];
        for(int i=0;i<count;i++)
            nodes[i]=new int[count];
        for(int i=0;i<count;i++){
            for(int j=0;j<count;j++){
                nodes[i][j]=NOEDGE;
            }
        }
    }

    void add_edge(int n1, int n2){
        nodes[n1][n2]=EDGE;
    }

    void dfs(int nodeNo, int *visited){
        if(visited[nodeNo]!=VISITED){
            visited[nodeNo]=VISITED;
            cout << nodeNo << ' ';
            //i is column values mapping each node with all nodes
            for(int i=0;i<size;i++)
                if(nodes[nodeNo][i]==EDGE && visited[i]!=VISITED)
                    dfs(i,visited); //recursive call to visit connected nodes
        }
    }

    //user will give the node number from which we will start traversing the graph
    void DFS(int nodeNo){
        int *visited=new int[size];
        for(int i=0;i<size;i++){
            visited[i]=NONVISITED;
        }
        for(int i=nodeNo, j=0; j<size;j++){
            //this will check if all the nodes are visited or not i.e j==size
            //for isolated nodes this loop will run again
            if(visited[i]==NONVISITED){
                dfs(i,visited);
                cout << "\n";
            }
                i=++i%size;
            // it means all the nodes have not traversed yet but max value of node is reached
            // so, we need to start from zero to the node from which we started
        }
        delete []visited;
    }

    void show(){
        cout << "   ";
        for(int k=0;k<size;k++)
            cout << k << ' ';
        cout << "\n   ";
        for(int k=0;k<size*2;k++)
            cout << '-';
        cout << endl;
        for(int i=0;i<size;i++){
            cout << i << "| ";
            for(int j=0;j<size;j++){
                    cout << nodes[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

int main() {
    Graphs matrix(7); // Nodes are 0,1,2,3,4,5,6 5 and 6 are isolated
    matrix.add_edge(0,2);
    matrix.add_edge(0,3);
    matrix.add_edge(0,4);
    matrix.add_edge(1,0);
    matrix.add_edge(1,3);
    matrix.add_edge(2,4);
    matrix.add_edge(3,0);
    matrix.add_edge(4,1);
    matrix.add_edge(4,2);
    matrix.add_edge(4,3);
    cout << "Adjacency Matrix for directed graph: \n\n";
    matrix.show();
    cout << "\n\nDFS: \n\n";
    matrix.DFS(0);
    system("PAUSE");
    return 0;
}
