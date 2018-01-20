// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pair {
    int id;
    int weight;
    Pair(int i = 0, int w = 0) {
        id = i;
        weight = w;
    }
    bool operator()(const Pair&a, const Pair& b) {
        return a.weight > b.weight;
    }
};

class Graph {
    // weighted graph
    vector<vector<Pair> > v;
    int nVtx;
public:
    Graph(int n) {
        nVtx = n;
        v.resize(nVtx);
    }

    void addEdge(int src, int dest, int wt) {
        Pair p;
        p.id = dest;
        p.weight = wt;

        v[src].push_back(p);

        p.id = src;     // for bidirectional
        v[dest].push_back(p);
    }

    int dijkstra(int src, int dest) {
        const int inf = 1e5;
        vector<int> dist(nVtx, inf);
        priority_queue<Pair, vector<Pair>, Pair> pq;

        pq.push(Pair(src, 0));

        while (!pq.empty()) {
            Pair p = pq.top();
            pq.pop();

            if (p.weight > dist[p.id]) continue;

            dist[p.id] = p.weight;

            // push all neighbors into the pq
            int cur = p.id;
            for (int i = 0; i < v[cur].size(); ++i) {
                Pair ngbr;
                ngbr.id = v[cur][i].id;
                ngbr.weight = v[cur][i].weight + dist[cur];

                if (ngbr.weight > dist[ngbr.id]) {
                    continue;   // useless...since I have already reached the vtx
                }
                else {
                    pq.push(ngbr);
                }
            }
        }
        return dist[dest];

    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 80);
    g.addEdge(1, 2, 6);
    g.addEdge(1, 4, 20);
    g.addEdge(2, 3, 70);
    g.addEdge(4, 5, 50);
    g.addEdge(4, 6, 10);
    g.addEdge(5, 6, 5);
    cout << g.dijkstra(4, 5);

}