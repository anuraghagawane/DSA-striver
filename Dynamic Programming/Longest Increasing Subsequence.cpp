class Solution {
public:
    int solve(int i, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(i >= n) {
            return 0;
        }
        if(dp[i][prev+1] != -1) return dp[i][prev + 1];
        
        int ans = 0;
        ans = solve(i+1, prev, n, nums, dp);
        
        if(prev == -1) ans = max(ans, solve(i + 1, i, n, nums, dp) + 1);
        else if(nums[i] > nums[prev]) 
            ans = max(ans, 1 + solve(i + 1, i, n, nums, dp));
        

        return dp[i][prev+1] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        //memo
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        // return solve(0, -1, nums.size(), nums, dp);

        // tabulation
        // int n = nums.size();
        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size() + 1, 0));

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int j = i; j >= -1; j--) {
        //         int ans = dp[i+1][j+1];
        
        //         if(j == -1) ans = max(ans, dp[i + 1][i + 1] + 1);
        //         else if(nums[i] > nums[j]) 
        //             ans = max(ans, 1 + dp[i + 1][i + 1]);  
            
        //         dp[i][j + 1] = ans;
        //     }

        // }

        // return dp[0][0];

        // space optimized tabulation
        // int n = nums.size();
        // vector<int> next(nums.size() + 1, 0);

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int j = i; j >= -1; j--) {
        //         int ans = next[j+1];
        
        //         if(j == -1) ans = max(ans, next[i + 1] + 1);
        //         else if(nums[i] > nums[j]) 
        //             ans = max(ans, 1 + next[i + 1]);  
            
        //         next[j + 1] = ans;
        //     }

        // }


        // return next[0];

        // algorithmic solution
        // int n = nums.size();
        // vector<int> lis(n, 1);

        // for(int i = 1; i < n; i++) {
        //     for(int j = 0; j < i; j++) {
        //         if(nums[j] < nums[i] && lis[j] + 1 > lis[i]) {
        //             lis[i] = lis[j] + 1;
        //         }
        //     }
        // }

        // return *max_element(lis.begin(), lis.end());

        // binary search
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(temp.back() < nums[i]) {
                temp.push_back(nums[i]);
                len++;
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return len;
    }
};