//find the length of the shortest path  d[i][j]  between each pair of vertices i and j
//The graph may have negative weight edges, but no negative weight cycles.
//O(n^3) => N<=400
const int INF=1e18;
int dist[405][405];
int n;
//infinite value will be used for vertices not connected to each other 
void Floyd_Warshall() {
  for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
              if (dist[i][k] < INF && dist[k][j] < INF)
                  dist[i][j] = min(d[i][j], dist[i][k] + d[k][j]); 
          }
      }
  }
}
