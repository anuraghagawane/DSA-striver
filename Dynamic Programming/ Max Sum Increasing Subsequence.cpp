class Solution {
  public:
    int solve(int i, int prev, int n, vector<int>& arr, vector<vector<int>>& dp) {
        if(i >= n) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        // not take
        int ans = solve(i+1, prev, n, arr, dp);
        
        if(prev == -1 || arr[prev] < arr[i]) {
            ans = max(ans, arr[i] + solve(i+1, i, n, arr, dp));
        }
        
        return dp[i][prev + 1] = ans;
    }
  
    int maxSumIS(vector<int>& arr) {
        // code here
        // memo
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(0, -1, n, arr, dp);
        
        // tabulation
        // int n = arr.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // for(int i = n - 1; i >= 0; i--) {
        //     for(int prev = i - 1; prev >= -1; prev--) {
        //         int ans = dp[i+1][prev+1];
        
        //         if(prev == -1 || arr[prev] < arr[i]) {
        //             ans = max(ans, arr[i] + dp[i+1][i+1]);
        //         }
                
        //         dp[i][prev + 1] = ans;
        //     }
        // }
        
        // return dp[0][0];
        
        // space optimized
        // int n = arr.size();
        // vector<int> next(n+1, 0);
        // vector<int> curr(n+1, 0);
        
        // for(int i = n - 1; i >= 0; i--) {
        //     for(int prev = i - 1; prev >= -1; prev--) {
        //         int ans = next[prev+1];
        
        //         if(prev == -1 || arr[prev] < arr[i]) {
        //             ans = max(ans, arr[i] + next[i+1]);
        //         }
                
        //         curr[prev + 1] = ans;
        //     }
        //     next = curr;
        // }
        
        // return next[0];
        
        // more space optimized
        int n = arr.size();
        vector<int> curr(n+1, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int prev = -1; prev < i; prev++) {
                int ans = curr[prev+1];
        
                if(prev == -1 || arr[prev] < arr[i]) {
                    ans = max(ans, arr[i] + curr[i+1]);
                }
                
                curr[prev + 1] = ans;
            }
        }
        
        return curr[0];
    }
};