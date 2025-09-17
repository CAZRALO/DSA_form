vector<vector<int>> adj{{1, 2}, {0}, {0, 3, 4}, {2}, {2}};
vector<int> start(adj.size());
vector<int> end(adj.size());
int timedfs = 0;

void euler_tour(int node, int par) {
	start[node] = timedfs++;
	for (int n : adj[node]) {
		if (n != par) { euler_tour(n, node); }
	}
	end[node] = timedfs;
}
