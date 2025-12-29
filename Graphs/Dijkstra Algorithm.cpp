class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V, INT_MAX);
        vector<vector<pair<int, int>>> adj(V);
        for(auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        // dist, node
        // priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<pair<int, int>> st;
        dist[src] = 0;
        // pq.push({0, src});
        st.insert({0, src});
        
        while(!st.empty()) {
            // auto [d, node] = pq.top();
            // pq.pop();
            
            auto top = st.begin();
            st.erase(top);
            int d = top -> first;
            int node = top -> second;
            
            for(auto [adjNode, edw]: adj[node]) {
                
                if(dist[adjNode] > d + edw) {
                    dist[adjNode] = d + edw;
                    // pq.push({dist[adjNode], adjNode});
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};