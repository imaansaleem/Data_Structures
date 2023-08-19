#include "Graphs.cpp"

using namespace std;
int main() {
    Graphs matrix(6); // Nodes are A B C D E F
    matrix.add_edge(0,1);
    matrix.add_edge(0,3);
    matrix.add_edge(0,5);
    matrix.add_edge(1,0);
    matrix.add_edge(1,2);
    matrix.add_edge(2,1);
    matrix.add_edge(2,3);
    matrix.add_edge(2,1);
    matrix.add_edge(3,5);
    matrix.add_edge(4,5);
    matrix.add_edge(5,4);
    cout << "Adjacency Matrix for directed graph: \n\n";
    matrix.show();
    cout << "\n\nDFS: \n\n";
    matrix.DFS(0);
    cout << "\n\nBFS: \n\n";
    matrix.BFS(0);
    cout << "\n";
    matrix.Write_container();
    system("PAUSE");
    return 0;
}
