template <typename T> class SparseTable {
  private:
	int n, log2dist;
	vector<vector<T>> st;
  public:
	SparseTable(const vector<T> &v) {
		n = (int)v.size();
		log2dist = 1 + __lg(n);
		st.resize(log2dist);
		st[0] = v;
		for (int i = 1; i < log2dist; i++) {
			st[i].resize(n - (1ll << i) + 1);
			for (int j = 0; j + (1 << i) <= n; j++) {
				st[i][j] = min(st[i - 1][j], st[i - 1][j + (1ll << (i - 1))]);
			}
		}
	}

	// return minimum on the range [l, r] 
	T query(int l, int r) {
		int i = __lg(r - l + 1);
		return min(st[i][l], st[i][r - (1ll << i) + 1]);
	}
};
