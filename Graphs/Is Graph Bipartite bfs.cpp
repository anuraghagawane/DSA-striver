class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> color(size, -1);

        for(int i = 0; i < size; i++) {
            if(color[i] == -1 && !check(i, graph, color)) {
                return false;
            }
        }

        return true;
    }
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            int nextColor = color[front] == 0 ? 1 : 0;
            for(auto node: graph[front]) {
                if(color[node] == -1) {
                    color[node] = nextColor;
                    q.push(node);
                }
                else if(color[node] != nextColor) {
                    return false;
                }
            }
        }

        return true;
    }
};