class Solution {
public:
    vector<vector<string>> solve(int start, string s, vector<vector<bool>>& dp) {
        if(start == s.size()) return {{}};

        vector<vector<string>> ans;
        for(int i = start; i < s.size(); i++) {
            vector<string> tempAns;
            if(dp[start][i]) {
                string currsub = s.substr(start, i - start + 1);
                auto rightAns = solve(i + 1, s, dp);
                for(auto r : rightAns) {
                    r.insert(r.begin(), currsub);
                    ans.push_back(r);
                }
            }
        }

        return ans;
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                if(isPalindrome(sub)) {
                    dp[i][j] = true;
                }
            }
        }
        return solve(0, s, dp);
    }
private:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};