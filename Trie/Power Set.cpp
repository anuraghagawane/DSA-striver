class Solution {
  public:
    void solve(int i, string s, string curr, vector<string>& result) {
        if(i == s.length()) {
            result.push_back(curr);
            return;
        }
        
        curr.push_back(s[i]);
        solve(i+1, s, curr, result);
        curr.pop_back();
        solve(i+1, s, curr, result);
        
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        // vector<string> result;
        // string curr = "";
        
        // solve(0, s, curr, result);
        
        // sort(result.begin(), result.end());
        // return result;
        
        
        vector<string> result;
        int n = s.length();
        int total = 1 << n;
        
        for(int mask = 0; mask < total; mask++) {
            string curr = "";
            
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    curr += s[i];
                }
            }
            
            result.push_back(curr);
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};