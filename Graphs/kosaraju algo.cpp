#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto n : adj[node]){
            if(!vis[n]){
                dfs(n, adj, vis, st);
            }
        }

        st.push(node);
    }

    void dfs2(int node, vector<vector<int>> transpose, vector<int>& vis) {
        vis[node] = 1;
        for(auto n : transpose[node]){
            if(!vis[n]){
                dfs2(n, transpose, vis);
            }
        }
    }
public:
    int kosaraju(int n, vector<int> adj[]){
        // do dfs and find finish time
        stack<int> st;
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, adj, vis, st);
        }

        // transpose the graph
        vector<vector<int>> transpose(n);

        for(int i = 0; i < n; i++) {
            vis[i] = 0;
            for(int j = 0; j < adj[i].size(); j++) {
                transpose[adj[i][j]].push_back(i);
            }
        }

        // do dfs and find SCCs
        int scc = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs2(i, transpose, vis);
                scc++;
            }
        }

        return scc;
    }
};

int main() {
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };

    vector<int> adj[n];
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
