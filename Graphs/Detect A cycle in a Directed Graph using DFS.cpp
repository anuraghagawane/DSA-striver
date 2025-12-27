class Solution {
  public:
    bool checkCycle(vector<vector<int>>& adj, int curr,  vector<int>& dfsvis, vector<int>& vis) {
        dfsvis[curr] = 1;
        vis[curr] = 1;
        
        for(auto neighbor: adj[curr]) {
            if(!vis[neighbor]) {
                if(checkCycle(adj, neighbor, dfsvis, vis)) return true;
            }
            else if(dfsvis[neighbor] == 1) {
                return true;
            }
        }
        
        dfsvis[curr] = 0;
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V+1);
        vector<int> dfsvis(V+1, 0);
        vector<int> vis(V+1, 0);
        
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(checkCycle(adj, i, dfsvis, vis)) return true;
            }
        }
        
        return false;
    }
};