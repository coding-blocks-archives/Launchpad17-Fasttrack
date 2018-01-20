// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    vector<vector<int> > v;
    int nVertices;

    void dfsUtil(int src, vector<bool>& visited) {
        // cout << src << " ";
        visited[src] = true;

        vector<int>& adjList = v[src];
        for (int i = 0; i < adjList.size(); ++i) {
            int ngbr = adjList[i];
            if (visited[ngbr] == false) {
                dfsUtil(ngbr, visited);
            }
        }

    }

    void topologicalSort(int src, vector<bool>& visited, vector<int>& ans) {
        visited[src] = true;
        for (int i = 0; i < v[src].size(); ++i) {
            int ngbr = v[src][i];
            if (visited[ngbr] == false) {
                topologicalSort(ngbr, visited, ans);
            }
        }
        ans.push_back(src);
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

    void dfs(int src) {
        vector<bool> visited(nVertices, false);
        dfsUtil(src, visited);
    }

    int connectedComp() {
        int comp = 0;
        vector<bool> visited(nVertices, false);
        for (int vtx = 0; vtx < nVertices; ++vtx) {
            if (visited[vtx] == false) {
                dfsUtil(vtx, visited);
                ++comp;
                cout << endl;
            }
        }
        return comp;
    }

    vector<int> topologicalSort(int src) {
        vector<int> ans;
        vector<bool> visited(nVertices, false);
        topologicalSort(src, visited, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> topologicalSort() {
        vector<int> inDegree(nVertices, 0);
        queue<int> q;
        vector<bool> visited(nVertices, false);
        vector<int> ans;

        // set the inDegree
        for (int i = 0; i < nVertices; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                int ngbr = v[i][j];
                inDegree[ngbr] += 1;
            }
        }

        // start with the element that's having 0 indegree
        vector<int>::iterator it = find(inDegree.begin(), inDegree.end(), 0);
        int src = it - inDegree.begin();
        // int src  = *it;      // WRONG

        q.push(src);
        visited[src] = true;
        while(!q.empty()){

            int cur = q.front();
            ans.push_back(cur);
            q.pop();

            for(int i = 0; i < v[cur].size(); ++i){
                int ngbr = v[cur][i];
                inDegree[ngbr]--;
                if (inDegree[ngbr] == 0){
                    visited[ngbr] = true;
                    q.push(ngbr);
                }
            }
        }
        return ans;
    }

    void printGraph(){
        for(int i = 0; i < v.size(); ++i){
            cout << i << "\t:";
            for(int j = 0; j < v[i].size(); ++j){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    // Graph g(8);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(1, 4);
    // g.addEdge(2, 3);
    // g.addEdge(4, 5);
    // g.addEdge(4, 6);
    // g.addEdge(5, 6);
    // g.bfs(0);
    // g.bfs(4);
    // int comp = g.connectedComp();
    // cout << "Number of connected Comp " << comp << endl;

    // Graph g(6);
    // g.addEdge(0, 2, false);
    // g.addEdge(0, 1, false);
    // g.addEdge(1, 3, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 5, false);
    // g.addEdge(3, 4, false);
    // auto ans = g.topologicalSort();
    // for (int i = 0; i < ans.size(); ++i) {
    //     cout << ans[i] << " ";
    // }

    const int DIM = 36;
    Graph g(DIM);

    int snakeLadder[DIM] = {};
    snakeLadder[1]      =       14;
    snakeLadder[4]      =       6;
    snakeLadder[8]      =       26;
    snakeLadder[16]     =       3;
    snakeLadder[17]     =       28;
    snakeLadder[19]     =       5;
    snakeLadder[23]     =       15;
    snakeLadder[24]     =       34;
    snakeLadder[31]     =       29;
    snakeLadder[33]     =       11;


    for(int i = 0; i < DIM; ++i){
        // no moves if snake or ladder
        if (snakeLadder[i] != 0){
            g.addEdge(i, snakeLadder[i]);
            continue;
        }  
        for(int dice = 1; dice <= 6; ++dice){
            int dest = i + dice;
            if (i >= 36 or dest >= 36) continue;
           
            if (snakeLadder[dest] != 0){
                dest = snakeLadder[dest];
            }
           
            g.addEdge(i, dest, false);
        }
    }
    g.printGraph();
}