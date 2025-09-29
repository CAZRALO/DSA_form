#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n+1);
        sz.resize(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());  // sắp xếp theo trọng số

    DSU dsu(n);
    long long mst_cost = 0;
    vector<Edge> mst_edges;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_cost += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "MST cost = " << mst_cost << "\n";
    cout << "Edges in MST:\n";
    for (auto &e : mst_edges) {
        cout << e.u << " " << e.v << " " << e.w << "\n";
    }

    return 0;
}
