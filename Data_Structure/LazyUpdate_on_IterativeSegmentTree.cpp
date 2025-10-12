struct SegTree {
    int n;
    vector<long long> t, lz;

    SegTree(int _n): n(_n), t(2 * _n), lz(_n) {}

    void apply(int p, long long val, int k) {
        t[p] += val * k;        // cập nhật giá trị node
        if (p < n) lz[p] += val; // nếu không phải lá, gắn nhãn lazy
    }

    void push(int p) {
        for (int h = __lg(n); h > 0; --h) {
            int i = p >> h;
            if (lz[i] != 0) {
                apply(i << 1, lz[i], 1 << (h - 1));
                apply(i << 1 | 1, lz[i], 1 << (h - 1));
                lz[i] = 0;
            }
        }
    }

    void build(int p) {
        while (p > 1) {
            p >>= 1;
            t[p] = t[p << 1] + t[p << 1 | 1] + lz[p] * (p < n ? (n >> __builtin_ctz(p)) : 1);
        }
    }

    void range_add(int l, int r, long long val) {
        int l0 = l + n, r0 = r + n;
        int k = 1;

        push(l0);
        push(r0 - 1);

        for (int L = l + n, R = r + n; L < R; L >>= 1, R >>= 1, k <<= 1) {
            if (L & 1) apply(L++, val, k);
            if (R & 1) apply(--R, val, k);
        }

        build(l0);
        build(r0 - 1);
    }

    long long range_sum(int l, int r) {
        push(l + n);
        push(r - 1);
        long long res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};
