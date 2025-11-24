class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& candidates, int target, int n, int i, int currSum, vector<int>& curr) {
        if(currSum == target) {
            ans.push_back(curr);
            return;
        }
        if(currSum > target) return;

        for(int ind = i; ind < n; ind++){
            if(i != ind && candidates[ind] == candidates[ind-1]) continue;
            curr.push_back(candidates[ind]);
            solve(candidates, target, n, ind + 1, currSum + candidates[ind], curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        solve(candidates, target, candidates.size(), 0, 0, curr);
        return ans;
    }
};