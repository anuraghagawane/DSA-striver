class Solution {
    vector<string> ans;
    vector<vector<int>> move; 
  public:
    string direction(int i) {
        if(i == 0) {
            return "U";
        }
        if(i == 1) {
            return "L";
        }
        if(i == 2) {
            return "D";
        }
        if(i == 3) {
            return "R";
        }
    }
    void solve(vector<vector<int>>& maze, int n, int i, int j, string& curr, vector<vector<int>>& vis){
        if(i == n-1 && j == n-1) {
            ans.push_back(curr);
            return;
        }
        
        for(int k = 0; k < 4; k++) {
            vector<int> mv = move[k];
            int nextRow = i+mv[0];
            int nextCol = j+mv[1];
            if(nextRow >= n || nextCol >= n || nextRow < 0 || nextCol < 0) {
                continue;
            }
            if(maze[nextRow][nextCol] == 1 && vis[nextRow][nextCol] == 0){
                curr += direction(k);
                vis[i][j] = 1;
                solve(maze, n, nextRow, nextCol, curr, vis);
                curr.pop_back();
                vis[i][j] = 0;
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        // code here
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string s = "";
        solve(maze, n, 0, 0, s, vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};