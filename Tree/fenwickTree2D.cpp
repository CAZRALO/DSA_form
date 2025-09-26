struct fenwickTree2d{
    vector<vector<int>> Tree;
    int m, n;
    fenwickTree2D(int _m = 0, int _n = 0) {
        m = _m;
        n = _n;
        Tree.resize(m + 1);
        for (int i=0;i<=m; +=i) {
            Tree[i].resize(n + 1);
            fill(Tree[i].begin(), Tree[i].end(), 0);
        }
    }
    void update(int x, int y, int val) {
        for(int i = x; i <= m; i += i&-i) {
            for(int j = y; j <= n; j += j&-j){
                Tree[i][j] += val;
            }
        }
    }
    int get(int x, int y) {
        int res = 0;
        for(int i = x; i > 0; i -= i&-i) {
            for(int j = y; j > 0; j -= j&-j) {
                res += Tree[i][j];
            }
        }
        return res;
    }
};
