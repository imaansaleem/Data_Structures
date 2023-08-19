#ifndef GRAPHS
#define GRAPH
#include <iostream>
#include "queue.cpp"
#define VISITED 1
#define NONVISITED 0
#define NOEDGE 0
#define EDGE 1

using namespace std;

class Graphs{
    int **nodes, size;
    int *container;
    int containersize;
    Queue<int>queue;
public:
    Graphs(int count){
        size=count;
        containersize=0;
        nodes=new int*[count];
        for(int i=0;i<count;i++)
            nodes[i]=new int[count];
        for(int i=0;i<count;i++){
            for(int j=0;j<count;j++){
                nodes[i][j]=NOEDGE;
            }
        }
        container=new int[count];
        for(int i=0;i<count;i++)
            container[i]=0;
    }

    void add_edge(int n1, int n2){
        nodes[n1][n2]=EDGE;
    }

    void dfs(int nodeNo, int *visited){
        char character;
        if(visited[nodeNo]!=VISITED){
            visited[nodeNo]=VISITED;
            cout << (char)(nodeNo+'A') << ' ';
            container[containersize++]=nodeNo;
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

    void BFS(int start){
        int current_vertex;
        int *visited=new int[size];
        for(int i=0;i<size;i++){
            visited[i]=NONVISITED;
        }
        for(int i=start,j=0;j<size;j++){
            //this will check if all the nodes are visited or not i.e j==size
            //for isolated nodes this loop will run again
            if(visited[i]==NONVISITED){
                queue.enqueue(i);
                while(!queue.isEmpty()){
                    current_vertex=queue.dequeue();
                    visited[current_vertex]=VISITED;
                    cout << (char)(current_vertex+'A') << ' ';
                    for(int m=0;m<size;m++){
                        if(nodes[current_vertex][m]==EDGE && visited[m]!=VISITED){
                            queue.enqueue(m); //m is the neighbouring element
                            visited[m]=VISITED;
                        }
                    }
                }
            }
            i=++i%size;
        }
    }

    void Write_container(){
        for(int i=size-1;i>=0;i--){
            cout << char(container[i]+'A') << ' ';
        }
        cout << "\n";
    }

    void show(){
        char l='A';
        cout << "   ";
        for(char k='A';k<'G';k++)
            cout << k << ' ';
        cout << "\n   ";
        for(int k=0;k<size*2;k++)
            cout << '-';
        cout << endl;
        for(int i=0;i<size;i++,l++){
            cout << l << "| ";
            for(int j=0;j<size;j++){
                cout << nodes[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};
#endif
