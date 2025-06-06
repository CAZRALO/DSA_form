#define pii pair<int,int>
const int LOG=17;

class LCA {
private:
	vector<pii>adj[100005];
	vector<int> depth;
	vector<int> dist;
	int par[100005][LOG];
public:
	LCA(int n) : depth(n), dist(n,0){}
	void dfs(int u,int p,int d){
		depth[u]=d;
		par[u][0]=p;
		//dist[u]=dist[p]+w;
		for (int i = 1; i < LOG; ++i) {
			par[u][i]=par[par[u][i-1]][i-1];
		}
		for (auto v:adj[u]) {
			if (v!=p) {
				dfs(v,u,d+1);
			}
		}
	}
	int distance(int u,int v){ //find distance from u to v on the weighted graph 
		return dist[u] + dist[v] - 2 * dist[lca(u,v)];
	}
	int lca(int u,int v){
		if (depth[u]<depth[v]) { swap(u,v); }
		int diff = depth[u] - depth[v];
		for (int i = LOG - 1; i >= 0; --i) {
			if (MASK(i)<=diff) {
				u=par[u][i];
				diff -= MASK(i);
			}
		}
		if (u == v) return u;
		for (int i = LOG - 1; i >= 0; --i) {
			if (par[u][i] != par[v][i]) {
				u = par[u][i];
				v = par[v][i];
			}
		}
		return par[u][0];
	}
	int k_thVertex(int u,int v,int k) { //find kth vertex on the way from u to v 
		int l=lca(u,v);
		int dis=depth[u]-depth[l];
		if (k<=dis) {
			f0d(i,LOG) {
				if (MASK(i)<=k) {
					u=par[u][i];
					k-=MASK(i);
				}
			}
			return u;
		}
		k=depth[v]-depth[l]-(k-dis);
		f0d(i,LOG) {
			if (MASK(i)<=k) {
				v=par[v][i];
				k-=MASK(i);
			}
		}
		return v;
	}
	int kth_parent(int u,int k) {
		int u = k;
		for (int i = 0; i < LOG; ++i) {
		        if (k & (1ll << i)) {
		            n = par[n][i];
		            if (n == -1) return -1;
		        }
		}
		    return n;
	}
	void addEdge(int u,int v,int w) {
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
};
