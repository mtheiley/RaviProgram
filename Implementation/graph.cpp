#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Allows for different numerical types when defining graph
template <class Cost, class Index>
using Graph = vector<vector<pair<Cost,Index>>>;

//Demonstrate DFS Traversal
template <class Cost, class Index>
void DFS(Graph<Cost,Index>& graph, Index node) {
    if(node >= graph.size()) {
        cout << "Error, attempted to search outside graph" << endl;
        exit(1);
    }

    for(auto[cost, child] : graph[node]) {
        cout << node << "->" << child << " cost: " << cost << endl;
        DFS(graph, child);
    }
}

//Demonstrate BFS Traversal
template <class Cost, class Index>
void BFS(Graph<Cost,Index>& graph, Index start) {
    queue<Index> indexQueue;
    indexQueue.push(start);
    
    while(!indexQueue.empty()) {
        Index node = indexQueue.front();
        indexQueue.pop();
        
        for(auto[cost, child] : graph[node]) {
            cout << node << "->" << child << " cost: " << cost << endl;
            indexQueue.push(child);
        }
    }
}

int main() {
    Graph<int, int> graph = {
        {{1, 1}, {3, 3}},
        {{2, 2}},
        {{10, 5}},
        {{1, 4}},
        {{6, 1}, {4, 5}},
        {}
    };

    cout << "------ DFS ------" << endl;
    DFS(graph, 0);
    cout << "------ BFS ------" << endl;
    BFS(graph, 0);
    cout << "-----------------" << endl;
}