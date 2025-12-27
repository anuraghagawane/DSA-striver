class Solution {
  public:
    bool solve(int src, vector<vector<int>>& adj, vector<int>& vis) {
        // <source, parent>
        queue<pair<int, int>> q;
        
        vis[src] = 1;
        
        q.push({src, -1});
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int curr = front.first;
            int parent = front.second;
            
            for(auto neighbor: adj[curr]) {
                if(!vis[neighbor]){
                    q.push({neighbor, curr});
                    vis[neighbor] = 1;
                }
                else if(parent != neighbor) {
                    return true;
                }
                
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
            if(!vis[i] && solve(i, adj, vis)) return true;
        }
        
        return false;
    }
};