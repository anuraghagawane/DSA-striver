class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& num, int n, vector<int>& tkn, int taken, vector<int>& curr) {
        if(taken >= n) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i<n; i++) {
            if(tkn[i] == 1) continue;
            tkn[i] = 1;
            curr.push_back(num[i]);
            solve(num, n, tkn, taken+1, curr);
            curr.pop_back();
            tkn[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tkn(nums.size(), 0);
        vector<int> curr;
        solve(nums, nums.size(), tkn, 0, curr);
        return ans;
    }
};