class Solution {
    vector<int> ans = {0};
  public:
    void solve(vector<int>& arr, int currSum, int i ) {
        if(i < 0) return;
        
        // skip current
        solve(arr, currSum, i-1);

        //take current
        solve(arr, currSum + arr[i], i-1);
        ans.push_back(currSum + arr[i]);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        solve(arr, 0, arr.size()-1);
        
        return ans;
    }
};
