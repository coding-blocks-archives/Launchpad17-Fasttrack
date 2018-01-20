// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int> > v;
    int nVertices;

    void dfsUtil(int src, vector<bool>& visited){
        cout << src << " ";
        visited[src] = true;

        vector<int>& adjList = v[src];
        for(int i = 0; i < adjList.size(); ++i){
            int ngbr = adjList[i];
            if (visited[ngbr] == false){
                dfsUtil(ngbr, visited);
            }
        }

    }

public:
    Graph(int n) {
        nVertices = n;
        v.resize(n);
    }

    void addEdge(int src, int dest, int bidirectional = true) {
        v[src].push_back(dest);
        if (bidirectional) v[dest].push_back(src);
    }

    // bfs
    void bfs(int src) {
        vector<bool> visited(nVertices, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (q.empty() == false) {
            int curVtx = q.front();
            q.pop();
            cout << curVtx << " ";

            // push all unvisited neighbors into the queue
            vector<int>& adjList = v[curVtx];
            for (int i = 0; i < adjList.size(); ++i) {
                int curNgbr = adjList[i];
                if (visited[curNgbr] == false) {
                    q.push(curNgbr);
                    visited[curNgbr] = true;
                }
            }
        }
    }

    void dfs(int src){
        vector<bool> visited(nVertices, false);
        dfsUtil(src, visited);
    }

    int connectedComp(){
        int comp = 0;
        vector<bool> visited(nVertices, false);
        for(int vtx = 0; vtx < nVertices; ++vtx){
            if (visited[vtx] == false){
                dfsUtil(vtx, visited);
                ++comp;
                cout << endl;
            }
        }
        return comp;
    }

    

};

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    // g.bfs(0);
    // g.bfs(4);
    int comp = g.connectedComp();
    cout << "Number of connected Comp " << comp << endl;

}