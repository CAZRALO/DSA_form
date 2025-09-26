#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n;
vector<int> adj[MAXN];
int color[MAXN]; 
int subSize[MAXN], bigChild[MAXN];
int answer[MAXN];

int cntColor[MAXN]; // đếm số lần xuất hiện của từng màu
int distinctColors = 0;

// --- DFS1: tính size + con nặng ---
int dfsSize(int u, int p) {
    subSize[u] = 1;
    int maxsz = -1;
    for (int v : adj[u]) if (v != p) {
        int sz = dfsSize(v, u);
        subSize[u] += sz;
        if (sz > maxsz) {
            maxsz = sz;
            bigChild[u] = v;
        }
    }
    return subSize[u];
}

// --- add/remove dữ liệu ---
void addNode(int u, int p, int val) {
    int c = color[u];
    cntColor[c] += val;
    if (val == 1 && cntColor[c] == 1) distinctColors++;
    if (val == -1 && cntColor[c] == 0) distinctColors--;
    for (int v : adj[u]) if (v != p) addNode(v, u, val);
}

// --- DFS DSU on tree ---
void dfs(int u, int p, bool keep) {
    // 1. Duyệt con nhỏ
    for (int v : adj[u]) if (v != p && v != bigChild[u]) {
        dfs(v, u, false);
    }
    // 2. Duyệt con nặng
    if (bigChild[u]) dfs(bigChild[u], u, true);

    // 3. Gộp dữ liệu từ con nhỏ
    for (int v : adj[u]) if (v != p && v != bigChild[u]) {
        addNode(v, u, +1);
    }

    // 4. Thêm chính u
    int c = color[u];
    cntColor[c]++;
    if (cntColor[c] == 1) distinctColors++;

    // 5. Trả lời cho node u
    answer[u] = distinctColors;

    // 6. Nếu không giữ, xóa dữ liệu u
    if (!keep) {
        addNode(u, p, -1);
        distinctColors = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=1;i<=n;i++) cin >> color[i];
    for (int i=1;i<n;i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsSize(1,0);
    dfs(1,0,true);

    for (int i=1;i<=n;i++) cout << answer[i] << " ";
    cout << "\n";
}
