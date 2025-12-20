class Solution {
public:
    int lps(string& s, int low, int high,  vector<vector<int>>& dp) {
        if(low > high) return 0;

        if(low == high) return 1;

        if(dp[low][high] != -1) return dp[low][high];

        if(s[low] == s[high]) return dp[low][high] = 2 + lps(s, low + 1, high - 1, dp);


        return dp[low][high] = max(lps(s, low + 1, high, dp), lps(s, low, high - 1, dp));
    }

    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return s.length() - lps(s, 0, s.length() - 1, dp);
    }
};