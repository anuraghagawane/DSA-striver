class Solution {
public:
    bool solve(int i, int target, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(i == n - 1) return target == nums[i];

        if(dp[i][target] != -1) return dp[i][target];
        int notTaken = solve(i + 1, target, n, nums, dp);

        int taken = false;
        if(nums[i] < target) {
            taken = solve(i + 1, target - nums[i], n, nums, dp);
        }
        return dp[i][target] = notTaken || taken;
    }

    bool canPartition(vector<int>& nums) {
        // memo
        // int n = nums.size();
        // int sum = 0;
        // for(auto n : nums) sum += n;
        // if(sum % 2 != 0) return false;
        // vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        // return solve(0, sum/2, n, nums, dp);

        // tabulation
        // int n = nums.size();
        // int sum = 0;
        // for(auto n : nums) sum += n;
        // if(sum % 2 != 0) return false;
        // int target = sum / 2;
        // vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        // for(int i = 0; i <= n; i++) dp[i][0] = true;

        // if(nums[n - 1] <= target) {
        //     dp[n-1][nums[n-1]] = true;
        // }

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int t = 0; t <= target; t++) {
        //         int notTaken = dp[i + 1][t];

        //         int taken = false;
        //         if(nums[i] <= t) {
        //             taken = dp[i + 1][t - nums[i]];
        //         }
        //         dp[i][t] = notTaken || taken;
        //     }
        // }

        // return dp[0][target];


        // space optimized
        // int n = nums.size();
        // int sum = 0;
        // for(auto n : nums) sum += n;
        // if(sum % 2 != 0) return false;
        // int target = sum / 2;

        // vector<int> next(target+1, 0);
        // vector<int> curr(target+1, 0);
        // for(int i = 0; i <= n; i++) next[0] = true;

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int t = 0; t <= target; t++) {
        //         int notTaken = next[t];

        //         int taken = false;
        //         if(nums[i] <= t) {
        //             taken = next[t - nums[i]];
        //         }
        //         curr[t] = notTaken || taken;
        //     }
        //     next = curr;
        // }

        // return curr[target];

        // space optimized  => 1 vec
        int n = nums.size();
        int sum = 0;
        for(auto n : nums) sum += n;
        if(sum % 2 != 0) return false;
        int target = sum / 2;

        vector<int> next(target+1, 0);
        for(int i = 0; i <= n; i++) next[0] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(int t = target; t >= 0; t--) {
                int notTaken = next[t];

                int taken = false;
                if(nums[i] <= t) {
                    taken = next[t - nums[i]];
                }
                next[t] = notTaken || taken;
            }
        }

        return next[target];
    }
};