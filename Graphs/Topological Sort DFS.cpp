class Solution {
  public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& topoSort) {
        
        vis[i] = 1;
        
        for(auto node: adj[i]) {
            if(!vis[node]) dfs(node, adj, vis, topoSort);
        }
        
        topoSort.push_back(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> topoSort;
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, adj, vis, topoSort);
        }
        
        reverse(topoSort.begin(), topoSort.end());
    
        return topoSort;
    }
};