// return minimum of range [l,r]
const int MAXN=1e5+5;
vector<int> A(MAXN),ST(2*MAXN);
int n;

void build(){
    for (int i = 1; i <= n; ++i) {
        ST[n+i] = A[i];
    }
    for (int i = n; i >=1; --i) {
        ST[i]=min(ST[i<<1], ST[i<<1|1]);
    }
}

void update(int pos, int val) {
    for (ST[pos += n] = val; pos > 1; pos >>= 1) {
        ST[pos>>1]=min(ST[pos], ST[pos^1]);
    }
}

int query(int l, int r) {
    int res = 1e18;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { res = min(res, ST[l++]); }
        if (r & 1) { res = min(res, ST[--r]); }
    }
    return res;
}
