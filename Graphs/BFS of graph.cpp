class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<bool> vis(adj.size(), false);
        vector<int> ans;
        queue<int> q;
        
        q.push(0);
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            vis[front] = true;
            for(auto neighbor: adj[front]) {
                if(!vis[neighbor]){
                    q.push(neighbor);
                    vis[neighbor] = true;
                }
            }
        }
        
        return ans;
    }
};