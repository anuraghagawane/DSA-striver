class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(j - i <= 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            ans = min(ans, cuts[j] - cuts[i] + solve(i, k, cuts, dp) + solve(k, j, cuts, dp));
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        // memo
        // cuts.push_back(0);
        // cuts.push_back(n);
        // sort(cuts.begin(), cuts.end());
        // int m = cuts.size();
        // vector<vector<int>> dp(m, vector<int>(m, -1));
        // return solve(0, m - 1, cuts, dp);


        // tabulation
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = i + 1; j < m; j++) {
                int ans = 1e9;
                for(int k = i + 1; k < j; k++) {
                    ans = min(ans, cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }

                dp[i][j] = ans == 1e9 ? 0 : ans;
            }
        }
        return dp[0][m - 1];
    }
};