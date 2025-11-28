class Solution {
    unordered_set<string> dict;
public:
    bool solve(string& s, int n, int i, vector<int>& memo){
        if(i >= n) {
            return true;
        }

        if(memo[i] != -1) {
            return memo[i];
        }


        for(int j = i; j < n; j++) {
            string part = s.substr(i, j-i+1);

            if(dict.count(part)){
                if(solve(s, n, j+1, memo)) return memo[i] = true;
            }
        }

        return memo[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.length(), -1);
        for(auto word: wordDict) {
            dict.insert(word);
        }

        return solve(s, s.length(), 0, memo);
    }
};