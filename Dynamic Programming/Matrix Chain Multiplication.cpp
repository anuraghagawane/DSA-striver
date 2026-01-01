class Solution {
  public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int total = INT_MAX;
        for(int k = i; k < j; k++) {
            int cost1 = solve(i, k, arr, dp);
            int cost2 = solve(k + 1, j, arr, dp);
            
            int curr = arr[i-1] * arr[k] * arr[j];
            
            int currTotal = cost1 + cost2 + curr;
            
            total = min(total, currTotal);
        }
        
        return dp[i][j] = total;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        // memo
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(1, n - 1, arr, dp);
        
        // tabulation
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = n-1; i >= 1; i--) {
            for(int j = i + 1; j < n; j++) {
                int total = INT_MAX;
                for(int k = i; k < j; k++) {
                    int cost1 = dp[i][k];
                    int cost2 = dp[k + 1][j];
                    
                    int curr = arr[i-1] * arr[k] * arr[j];
                    
                    int currTotal = cost1 + cost2 + curr;
                    total = min(total, currTotal);
                }
                dp[i][j] = total;
            }
        }
        
        
        return dp[1][n - 1];
    }
};