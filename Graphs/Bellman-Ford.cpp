// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i < V; i++) {
            for(auto edge: edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != 1e8 && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(dist[u] != 1e8 && dist[v] > dist[u] + wt) {
                return {-1};
            }
        }
        
        
        return dist;
        
    }
};
