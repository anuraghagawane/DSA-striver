class Solution {
    vector<vector<string>> ans;
public:
    bool check_pal(string &s, int i, int j) {
        // int i = 0, j = s.length()-1;
        while(i<j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++; j--;
        }
        return true;
    }
    void solve(string &s, int n, int i, vector<string>& curr) {
        if(i >= n) ans.push_back(curr);
        for(int ind = i; ind < n; ind++) {
            //partition
            if(check_pal(s, i, ind)){
                curr.push_back(s.substr(i, ind - i + 1));
                solve(s, n, ind+1, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s, s.length(), 0, curr);
        return ans;
    }
};