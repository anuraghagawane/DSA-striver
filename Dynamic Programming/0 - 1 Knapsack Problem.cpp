class Solution {
  public:
    int solve(int i, int w, int W, int n, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp) {
        if(i >= n || w > W) return 0;
        if(dp[i][w] != -1) return dp[i][w];
        int ans = 0;
        if(w + wt[i] <= W) {
            ans = max(ans, val[i] + solve(i + 1, w + wt[i], W, n, val, wt, dp));
        }
        ans = max(ans, solve(i + 1, w, W, n, val, wt, dp));
        
        return dp[i][w] = ans;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // memo
        // int n = val.size();
        // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        // return solve(0, 0, W, n, val, wt, dp);
        
        // tabulation
        // int n = val.size();
        // vector<vector<int>> dp(n+1, vector<int>(W + 1, 0));
        
        // for(int i = n - 1; i >= 0; i--) {
        //     for(int w = W; w >= 0; w--) {
        //         int ans = 0;
        //         if(w + wt[i] <= W) {
        //             ans = max(ans, val[i] + dp[i + 1][w + wt[i]]);
        //         }
        //         ans = max(ans, dp[i + 1][w]);
                
        //         dp[i][w] = ans;
        //     }
        // }
        
        // return dp[0][0];
        
        
        // space optimized
        int n = val.size();
        vector<int> next(W + 1, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int w = 0; w <= W; w++) {
                int ans = 0;
                if(w + wt[i] <= W) {
                    ans = max(ans, val[i] + next[w + wt[i]]);
                }
                ans = max(ans, next[w]);
                
                next[w] = ans;
            }
        }
        
        return next[0];
    }
};