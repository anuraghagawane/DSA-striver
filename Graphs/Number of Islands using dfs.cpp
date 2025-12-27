class Solution {
    vector<vector<int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:
    void solve(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(grid[i][j] == '0' || grid[i][j] == '#') return;
        grid[i][j] = '#';

        for(auto move: moves) {
            int nextRow = i + move[0];
            int nextCol = j + move[1];
            if(nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >=n) continue;
            if(grid[nextRow][nextCol] == '1') solve(grid, nextRow, nextCol, m, n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    solve(grid, i, j, m, n);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};