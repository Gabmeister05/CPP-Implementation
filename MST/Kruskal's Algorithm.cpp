#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

struct DSU {
    vector<int> parent;
    DSU(int n) { parent.resize(n); for(int i=0; i<n; i++) parent[i] = i; }
    int find(int i) { return (parent[i] == i) ? i : (parent[i] = find(parent[i])); }
    void unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mst_weight = 0;

    for (auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_weight += edge.weight;
        }
    }
    return mst_weight;
}