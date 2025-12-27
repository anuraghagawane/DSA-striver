class Solution {
    vector<int> vis;
    vector<int> ans;
  public:
    void solve(vector<vector<int>>& adj, int i) {
        if(i >= adj.size()) return;
        if(vis[i] == 1) return;
        ans.push_back(i);
        vis[i] = 1;
        for(auto neighbor : adj[i]) {
            solve(adj, neighbor);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        if(adj.size() == 0) return {};
        vis.resize(adj.size(), 0);
        solve(adj, 0);
        
        return ans;
    }
};