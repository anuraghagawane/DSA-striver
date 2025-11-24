class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& candidates, int target, int n, int i, int currSum, vector<int> &currVec) {
        if(i >= n) {
            if(currSum == target) {
                ans.push_back(currVec);
            }
            return;
        }
        if(currSum > target) return;
        if(currSum == target) {
            ans.push_back(currVec);
            return;
        }

        currVec.push_back(candidates[i]);
        solve(candidates, target, n, i, currSum + candidates[i], currVec);
        currVec.pop_back();
        solve(candidates, target, n, i+1, currSum, currVec);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currVec;
        solve(candidates, target, candidates.size(), 0, 0, currVec);

        return ans;
    }
};