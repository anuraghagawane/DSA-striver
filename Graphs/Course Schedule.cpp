class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> inorder(V, 0);
        
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            inorder[edge[1]]++;
        }
        
        int cnt = 0;
        queue<int> q;
        
        for(int i = 0; i < V; i++) {
            if(inorder[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            cnt++;
            
            for(auto neighbor: adj[front]) {
                inorder[neighbor]--;
                if(inorder[neighbor] == 0) q.push(neighbor);
            }
        }
        
        return V == cnt;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return isCyclic(numCourses, prerequisites);
    }
};