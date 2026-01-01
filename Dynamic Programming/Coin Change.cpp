class Solution {
public:
    int solve(int i, int amount, int n, vector<int>& coins, vector<vector<int>>& dp) {
        if(i >= n) return 1e8;
        if(amount == 0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        // not take
        int notTake = solve(i+1, amount, n, coins, dp);
        int take = 1e8;
        if(amount - coins[i] >= 0) {
            take = 1 + solve(i, amount - coins[i], n, coins, dp);
        }

        return dp[i][amount] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        // memo
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // int ans = solve(0, amount, n, coins, dp);
        // if(ans == 1e8) return -1;
        // return ans;

        // tabulation
        // int n = coins.size();
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e8));
        // for(int i = 0; i <= amount; i++) dp[n][i] = 1e8;
        // for(int i = 0; i <= n; i++) dp[i][0] = 0;

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int a = 0; a <= amount; a++) {
        //         int notTake = dp[i+1][a];
        //         int take = 1e8;
        //         if(a - coins[i] >= 0) {
        //             take = 1 + dp[i][a - coins[i]];
        //         }

        //         dp[i][a] = min(notTake, take);
        //     }
        // }


        // int ans = dp[0][amount];
        // if(ans == 1e8) return -1;
        // return ans;

        // space opmtimized
        // int n = coins.size();
        // vector<int> curr(amount + 1, 1e8);
        // vector<int> next(amount + 1, 1e8);
        // next[0] = 0;

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int a = 0; a <= amount; a++) {
        //         int notTake = next[a];
        //         int take = 1e8;
        //         if(a - coins[i] >= 0) {
        //             take = 1 + curr[a - coins[i]];
        //         }

        //         curr[a] = min(notTake, take);
        //     }
        //     next = curr;
        // }


        // int ans = next[amount];
        // if(ans == 1e8) return -1;
        // return ans;

        // one array solution
        int n = coins.size();
        vector<int> curr(amount + 1, 1e8);
        curr[0] = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int a = 0; a <= amount; a++) {
                int notTake = curr[a];
                int take = 1e8;
                if(a - coins[i] >= 0) {
                    take = 1 + curr[a - coins[i]];
                }

                curr[a] = min(notTake, take);
            }
        }


        int ans = curr[amount];
        if(ans == 1e8) return -1;
        return ans;
    }
};