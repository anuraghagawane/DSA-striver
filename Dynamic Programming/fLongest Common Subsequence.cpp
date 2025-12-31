class Solution {
public:
    int solve(int i, int j, int m, int n, string text1, string text2, vector<vector<int>>& dp) {
        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        
        if(text1[i] == text2[j]) {
            ans = max(ans, 1 + solve(i + 1, j + 1, m, n, text1, text2, dp));
        }
        else {
            ans = max(ans, solve(i, j + 1, m, n, text1, text2, dp));
            ans = max(ans, solve(i + 1, j, m, n, text1, text2, dp));
            ans = max(ans, solve(i + 1, j + 1, m, n, text1, text2, dp));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {

        // memoization
        // int m = text1.size();
        // int n = text2.size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, text1.size(), text2.size(), text1, text2, dp);

        //tabulation
        // int m = text1.size();
        // int n = text2.size();

        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // for(int i = m - 1; i >= 0; i--) {
        //     for(int j = n - 1; j >= 0; j--) {
        //         int ans = 0;
        //         if(text1[i] == text2[j]) {
        //             ans = max(ans, 1 + dp[i + 1][j + 1]);
        //         }
        //         else {
        //             ans = max(ans, dp[i][j + 1]);
        //             ans = max(ans, dp[i + 1][j]);
        //             ans = max(ans, dp[i + 1][j + 1]);
        //         }

        //         dp[i][j] = ans;
        //     }
        // }

        // return dp[0][0];

        // space optimized
        int m = text1.size();
        int n = text2.size();

        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = max(ans, 1 + next[j + 1]);
                }
                else {
                    ans = max(ans, curr[j + 1]);
                    ans = max(ans, next[j]);
                    ans = max(ans, next[j + 1]);
                }

                curr[j] = ans;
            }
            next = curr;
        }

        return curr[0];
    }
};