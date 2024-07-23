const int N=1e5+5;

int st[4*N],lz[4*N];

// return maximum of range [l,r]
void push(int id) {
    if (lz[id]) {
        st[id << 1] = lz[id];
        st[(id << 1) + 1] = lz[id];
        lz[id << 1] = lz[id];
        lz[(id << 1) + 1] = lz[id];
        lz[id] = 0;
    }
}
int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return INT_MIN;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    push(id);
    return max(get(id << 1, l, mid, u, v), get((id << 1) + 1, mid + 1, r, u, v));
}
void update(int id, int l, int r, int u, int v, int value) {
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        st[id] = value;
        lz[id] = value;
        return;
    }
    int mid = (l + r) >> 1;
    push(id);
    update(id << 1, l, mid, u, v, value);
    update((id << 1) + 1, mid + 1, r, u, v, value);
    st[id] = max(st[id << 1], st[(id << 1) + 1]);
}
