class Solution {
public:
    int solve(int i, int j, string from, string to, vector<vector<int>>& dp) {
        if(i >= from.length() && j < to.length()) {
            return dp[i][j] = abs(j - (int)to.length());
        }
        if(j >= to.length() && i < from.length()) {
            return dp[i][j] = abs(i - (int)from.length());
        }
        if(i >= from.length() || j >= to.length()) {
            return dp[i][j] = 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        if(from[i] == to[j]) {
            ans = min(ans, solve(i+1, j+1, from, to, dp));
        }
        else {
            int rm = 1 + solve(i + 1, j, from, to, dp);
            int rep = 1 + solve(i + 1, j + 1, from , to, dp);
            int in = 1 + solve(i, j + 1, from , to, dp);

            int currmin = min(rm, min(rep, in));
            ans = min(ans, currmin);
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        //memo
        // vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        // return solve(0, 0, word1, word2, dp);

        // tabulation
        // vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        // int wl1 = word1.length();
        // int wl2 = word2.length();

        // for(int i = 0; i < wl1; i++) {
        //     dp[i][wl2] = abs(i - wl1);
        // }

        // for(int i = 0; i < wl2; i++) {
        //     dp[wl1][i] = abs(i - wl2);
        // }

        // for(int i = wl1 - 1; i >= 0; i--) {
        //     for(int j = wl2 - 1; j >= 0; j--) {
        //         int ans = INT_MAX;
        //         if(word1[i] == word2[j]) {
        //             ans = min(ans, dp[i+1][j+1]);
        //         }
        //         else {
        //             int rm = 1 + dp[i + 1][j];
        //             int rep = 1 + dp[i + 1][j + 1];
        //             int in = 1 + dp[i][j + 1];

        //             int currmin = min(rm, min(rep, in));
        //             ans = min(ans, currmin);
        //         }

        //         dp[i][j] = ans;
        //     }
        // }

        // return dp[0][0];

        // space optimized
        vector<int> curr(word2.length() + 1, 0);
        vector<int> next(word2.length() + 1, 0);
        int wl1 = word1.length();
        int wl2 = word2.length();

        for(int i = 0; i <= wl2; i++) {
            next[i] = abs(i - wl2);
        }

        for(int i = wl1 - 1; i >= 0; i--) {
            curr[wl2] = abs(wl1 - i);
            for(int j = wl2 - 1; j >= 0; j--) {
                int ans = INT_MAX;
                if(word1[i] == word2[j]) {
                    ans = min(ans, next[j+1]);
                }
                else {
                    int rm = 1 + next[j];
                    int rep = 1 + next[j + 1];
                    int in = 1 + curr[j + 1];

                    int currmin = min(rm, min(rep, in));
                    ans = min(ans, currmin);
                }

                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }
};