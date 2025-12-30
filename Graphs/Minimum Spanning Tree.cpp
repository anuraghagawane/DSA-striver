class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, 0});
        
        int sum = 0;
        vector<int> vis(V, 0);
        while(!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            
            sum += w;
            
            for(auto [adjNode, edw]: adj[node]) {
                if(!vis[adjNode]) {
                    pq.push({edw, adjNode});
                }
            }
        }
        
        return sum;
    }
};