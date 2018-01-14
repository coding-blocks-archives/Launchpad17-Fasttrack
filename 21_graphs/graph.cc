// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    typedef vector<vector<int> > vvi;
    vvi vtxList;
    int nVertices;

    void dfs(int src, vector<bool>& visited) {
        // if (visited[src] == true) return;

        cout << src << " ";
        visited[src] = true;
        vector<int>& ngbrList = vtxList[src];

        for (int i = 0; i < ngbrList.size(); ++i) {
            int curNgbr = ngbrList[i];
            if (visited[curNgbr] == false) {
                dfs(ngbrList[i], visited);
            }
        }
    }

public:
    Graph(int n) {
        nVertices = n;
        vtxList.resize(n);
    }

    void addEdge(int src, int dest, int biDirectional = true) {
        vtxList[src].push_back(dest);
        if (biDirectional) {
            vtxList[dest].push_back(src);
        }
    }

    void print() {
        for (int i = 0; i < nVertices; ++i) {
            cout << i << "\t: ";
            for (int j = 0; j < vtxList[i].size(); ++j) {
                cout << vtxList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int src) {
        vector<bool> visited(nVertices, false); // look vector ctor C++.com
        dfs(src, visited);
    }

};


int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.print();
    g.dfs(0);
}