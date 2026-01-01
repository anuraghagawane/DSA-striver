class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == m-1 && j == n-1) return grid[i][j];
        if(i >= m || j >= n) {
            return 1e8;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int right = grid[i][j] + solve(i + 1, j, m, n, grid, dp);
        int down = grid[i][j] + solve(i, j + 1, m, n, grid, dp);

        return dp[i][j] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        //memo
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, m, n, grid, dp);

        // tabulation
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // for(int i = 0; i < m; i++) dp[i][n] = 1e8;
        // for(int i = 0; i < n; i++) dp[m][i] = 1e8;

        // for(int i = m - 1; i >= 0; i--) {
        //     for(int j = n - 1; j >= 0; j--) {
        //         if(i == m - 1 && j == n -1) {
        //             dp[i][j] = grid[i][j];
        //             continue;
        //         }
        //         int right = grid[i][j] + dp[i + 1][j];
        //         int down = grid[i][j] + dp[i][j + 1];

        //         dp[i][j] = min(right, down);
        //     }
        // }
        // return dp[0][0];

        // space optimized
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<int> curr(n+1, 0);
        // vector<int> next(n+1, 0);
        // curr[n] = 1e8;
        // for(int i = 0; i < n; i++) next[i] = 1e8;

        // for(int i = m - 1; i >= 0; i--) {
        //     for(int j = n - 1; j >= 0; j--) {
        //         if(i == m - 1 && j == n -1) {
        //             curr[j] = grid[i][j];
        //             continue;
        //         }
        //         int right = grid[i][j] + next[j];
        //         int down = grid[i][j] + curr[j + 1];

        //         curr[j] = min(right, down);
        //     }
        //     next = curr;
        // }
        // return next[0];

        // 1 vec space optimized
        int m = grid.size();
        int n = grid[0].size();
        vector<int> next(n+1, 0);
        for(int i = 0; i <= n; i++) next[i] = 1e8;

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n -1) {
                    next[j] = grid[i][j];
                    continue;
                }
                int right = grid[i][j] + next[j];
                int down = grid[i][j] + next[j + 1];

                next[j] = min(right, down);
            }
        }
        return next[0];
    }
};