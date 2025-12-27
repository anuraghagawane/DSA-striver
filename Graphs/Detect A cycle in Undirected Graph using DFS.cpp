class Solution {
  public:
    bool solve(int src, int prev, vector<vector<int>>& adj, vector<int>& vis) {
        // <source, parent>
        
        vis[src] = 1;
        for(auto neighbor: adj[src]) {
            if(!vis[neighbor]) {
                if(solve(neighbor, src, adj, vis)) return true;
            }
            else if(prev != neighbor) {
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);        
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < V; i++) {
            if(!vis[i] && solve(i, -1, adj, vis)) return true;
        }
        
        return false;
    }
};