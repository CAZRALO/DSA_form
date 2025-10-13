#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
ll st[4 * N];
ll lz[4 * N];

// push lazy add ở node id xuống 2 con
void push(int id, int l, int r) {
    if (lz[id] != 0 && l != r) {
        int mid = (l + r) >> 1;
        int L = id << 1, R = L | 1;
        // áp dụng lên con trái
        lz[L] += lz[id];
        st[L] += lz[id] * (mid - l + 1);
        // áp dụng lên con phải
        lz[R] += lz[id];
        st[R] += lz[id] * (r - mid);
        // clear current
        lz[id] = 0;
    } else if (l == r) {
        lz[id] = 0;
    }
}

ll get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    push(id, l, r);
    return get(id << 1, l, mid, u, v) + get((id << 1) + 1, mid + 1, r, u, v);
}

void update(int id, int l, int r, int u, int v, ll value) {
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        st[id] += value * (r - l + 1);
        lz[id] += value;
        return;
    }
    int mid = (l + r) >> 1;
    push(id, l, r);
    update(id << 1, l, mid, u, v, value);
    update((id << 1) + 1, mid + 1, r, u, v, value);
    st[id] = st[id << 1] + st[(id << 1) + 1];
}

void build(int id, int l, int r, const vector<ll>& a) {
    lz[id] = 0;
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid, a);
    build((id << 1) + 1, mid + 1, r, a);
    st[id] = st[id << 1] + st[(id << 1) + 1];
}

