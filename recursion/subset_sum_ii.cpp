class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& num, vector<int>& curr, int i, int n) {
        if(i >= n) {
            ans.push_back(curr);
            return;
        }

        int j = i;
        while(j>0 && j < n-1 && j!= i && num[j] == num[j-1]) j++;
        //take
        curr.push_back(num[j]);
        solve(num, curr, j+1, n);
        //skip
        curr.pop_back();
        solve(num, curr, j+1, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(nums, curr, 0, nums.size());
        return ans;
    }
};