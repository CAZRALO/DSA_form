#include <bits/stdc++.h>
using namespace std;

struct SegmentTree2D {
    int n, m;
    vector<vector<long long>> tree;
    vector<vector<long long>> a;

    SegmentTree2D(int n, int m) : n(n), m(m) {
        a.assign(n, vector<long long>(m, 0));
        tree.assign(4 * n, vector<long long>(4 * m, 0));
    }

    // build theo y cho 1 node x
    void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx) tree[vx][vy] = a[lx][ly];
            else tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];
        } else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy*2, ly, my);
            build_y(vx, lx, rx, vy*2+1, my+1, ry);
            tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
        }
    }

    // build theo x
    void build_x(int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx*2, lx, mx);
            build_x(vx*2+1, mx+1, rx);
        }
        build_y(vx, lx, rx, 1, 0, m-1);
    }

    // update y
    void update_y(int vx, int lx, int rx, int vy, int ly, int ry,
                  int x, int y, long long new_val) {
        if (ly == ry) {
            if (lx == rx) tree[vx][vy] = new_val;
            else tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];
        } else {
            int my = (ly + ry) / 2;
            if (y <= my) update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
            else update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
            tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
        }
    }

    // update x
    void update_x(int vx, int lx, int rx, int x, int y, long long new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) update_x(vx*2, lx, mx, x, y, new_val);
            else update_x(vx*2+1, mx+1, rx, x, y, new_val);
        }
        update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
    }

    // query y
    long long query_y(int vx, int vy, int ly, int ry,
                      int qly, int qry) {
        if (qly > ry || qry < ly) return 0;
        if (qly <= ly && ry <= qry) return tree[vx][vy];
        int my = (ly + ry) / 2;
        return query_y(vx, vy*2, ly, my, qly, qry) +
               query_y(vx, vy*2+1, my+1, ry, qly, qry);
    }

    // query x
    long long query_x(int vx, int lx, int rx,
                      int qlx, int qrx, int qly, int qry) {
        if (qlx > rx || qrx < lx) return 0;
        if (qlx <= lx && rx <= qrx) {
            return query_y(vx, 1, 0, m-1, qly, qry);
        }
        int mx = (lx + rx) / 2;
        return query_x(vx*2, lx, mx, qlx, qrx, qly, qry) +
               query_x(vx*2+1, mx+1, rx, qlx, qrx, qly, qry);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    SegmentTree2D st(n, m);

    // nhập mảng
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> st.a[i][j];

    st.build_x(1, 0, n-1);

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x, y; long long val;
            cin >> x >> y >> val;
            st.update_x(1, 0, n-1, x, y, val);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << st.query_x(1, 0, n-1, x1, x2, y1, y2) << "\n";
        }
    }
}
