void dijkstra(int src) {
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int>dist(n+5,LLONG_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        auto [cdist, u] = pq.top();
        pq.pop();
        if (cdist > dist[u]) { continue; }
        for (auto [v,w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    //for (int i = 1; i <= n; ++i)
    //    cout<<"distance from src to i = " << dist[i] << '\n';
}
