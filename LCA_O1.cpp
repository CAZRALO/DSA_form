int n;
vector<vector<int>>adj;
class LCA{
private : 
    vector<int>E;
    vector<int>depthE;
    vector<int>firstOcc;
    vector<int>depthNode;
    vector<int>lg;
    vector<vector<int>>st;
public :
    void dfs(int u, int p = 0, int d = 1) {
        firstOcc[u] = E.size();
        E.push_back(u);
        depthE.push_back(d);
        for(int v : adj[u]) {
            if(v == p) continue;
            dfs(v, u, d+1);
            E.push_back(u);
            depthE.push_back(d);
        }
    }
    void buildLCA(int root = 0) {
        int M = 2*n - 1;
        E.reserve(M);
        depthE.reserve(M);
        firstOcc.assign(N, -1);
        depthNode.assign(N, 0);
        dfs(root);
        lg.assign(M+1, 0);
        for(int i = 2; i <= M; ++i)
            lg[i] = lg[i/2] + 1;
        int K = lg[M];
        st.assign(K+1, vector<int>(M));
        for(int i = 0; i < M; ++i)
            st[0][i] = i;
        for(int k = 1; k <= K; ++k) {
            for(int i = 0; i + (1<<k) <= M; ++i) {
                int x = st[k-1][i];
                int y = st[k-1][i + (1ll<<(k-1))];
                st[k][i] = (depthE[x] < depthE[y] ? x : y);
            }
        }
    }
    int rmq(int L, int R) {
        int k = lg[R - L + 1];
        int x = st[k][L];
        int y = st[k][R - (1ll<<k) + 1];
        return (depthE[x] < depthE[y] ? x : y);
    }
    int lca(int u, int v) {
        int L = firstOcc[u];
        int R = firstOcc[v];
        if(L > R) swap(L, R);
        int idx = rmq(L, R);
        return E[idx];
    }

};
