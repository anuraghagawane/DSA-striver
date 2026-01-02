class Solution {
    unordered_set<string> st;
public:
    bool solve(string s, int start, vector<int>& dp) {
        if(start == s.size()) {
            return true;
        }
        if(dp[start] != -1) return dp[start];
        for(int i = start; i < s.size(); i++) {
            if(st.count(s.substr(start, i - start + 1)) && solve(s, i + 1, dp)) {
                return true;
            }
        }

        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // memo
        // for(auto word: wordDict) st.insert(word);
        // vector<int> dp(s.length(), -1);
        // return solve(s, 0, dp);

        // tabulation
        for(auto word: wordDict) st.insert(word);
        vector<int> dp(s.length() + 1, 0);
        dp[s.length()] = true;
        for(int start = s.length() - 1; start >= 0; start--) {
            for(int i = start; i < s.size(); i++) {
                if(st.count(s.substr(start, i - start + 1)) && dp[i + 1]) {
                    dp[start] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};