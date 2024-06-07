//use class 
class DisjointSets {
private:
	vector<int> parents;
	vector<int> sizes;
public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}
	bool connected(int x, int y) { return find(x) == find(y); }
};

//use template 

template <int SZ> struct DSU {
	int par[SZ], sz[SZ];
	DSU() { for (int i=0;i<=SZ;++i) par[i] = -1, sz[i] = 1; }


	int findRoot(int x) {  // path compression
        if (par[x]==x) return x;
		return par[x] = findRoot(par[x]);
	}

	bool unite(int x, int y) {  // union-by-rank
		x = findRoot(x), y = findRoot(y);
		if (x == y) return 0;
		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y], par[y] = x;
		return 1;
	}
  bool connected(int x, int y) { return find(x) == find(y); }
};
