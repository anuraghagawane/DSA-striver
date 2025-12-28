class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> color(size, -1);

        for(int i = 0; i < size; i++) {
            if(color[i] == -1 && !check(i, 0, graph, color)) {
                return false;
            }
        }

        return true;
    }
private:
    bool check(int start, int prev, vector<vector<int>>& graph, vector<int>& color) {
        if(color[start] == -1) {
            color[start] = color[prev] == 0 ? 1 : 0;
        }

        for(auto node: graph[start]) {
            if(color[node] == -1) {
                if(!check(node, start, graph, color)) return false;
            }
            else if(color[node] == color[start]) return false;
        }

        return true;
    }
};