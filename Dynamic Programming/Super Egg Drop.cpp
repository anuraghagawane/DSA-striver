class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& dp) {
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;

        if(dp[k][n] != -1) return dp[k][n];

        int ans = 1e6;
        int l = 1, h = n;

        // linear search
        // for(int i = 1; i <= n; i++) {
        //     ans = min(ans, 1 + max(solve(k - 1, i - 1, dp), solve(k, n - i, dp)));
        // }
        
        // binary search
        while(l <= h) {
            int mid = (l + h) / 2;
            int left = solve(k - 1, mid - 1, dp);
            int right = solve(k, n - mid, dp);

            ans = min(ans, 1 + max(left, right));

            if(left < right) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        return dp[k][n] = ans;
    } 
    int superEggDrop(int k, int n) {
        // memo
        // vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        // return solve(k, n, dp);

        // tabulation

        if(n == 0 || n == 1) return n;
        if(k == 1) return n;

        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

        for(int i = 0; i <= k; i++) dp[i][0] = 0, dp[i][1] = 1;
        for(int i = 0; i <= n; i++) dp[0][i] = 0, dp[1][i] = i;

        for(int i = 2; i <= k; i++) {
            for(int j = 2; j <= n; j++) {
                int ans = 1e6;
                int l = 1, h = j;

                while(l <= h) {
                    int mid = (l + h) / 2;
                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];

                    ans = min(ans, 1 + max(left, right));

                    if(left < right) {
                        l = mid + 1;
                    }
                    else {
                        h = mid - 1;
                    }
                }

                dp[i][j] = ans;
            }
        }

        return dp[k][n];
    }
};