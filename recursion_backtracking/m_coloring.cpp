class Solution {
    unordered_map<int, vector<int>> adj;
  public:
    bool can_colour(int node, int colour, unordered_map<int, int>& currCol) {
        for(auto toNode: adj[node]){
            if(currCol[toNode] == colour){
                return false;
            }
        }
        
        return true;
    }
    bool solve(int v, int m, int node, unordered_map<int, int>& currCol) {
        if(node >= v) return true;
        for(int colour = 0; colour < m; colour++) {
            if(can_colour(node, colour, currCol)) {
                currCol[node] = colour;
                if(solve(v, m, node+1, currCol)) return true;
                currCol[node] = -1;
            }
        }
        
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        // create and adjacency list
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int, int> currCol;
        for(int i = 0; i < v; i++) currCol[i] = -1;
        return solve(v, m, 0, currCol);
    }
};