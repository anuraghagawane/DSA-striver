class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int currSum = nums[i];
            ans = max(ans, currSum);
            for(int j = i+1; j < n; j++) {
                currSum = currSum * nums[j];
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pre = 1;
        int suf = 1;

        for(int i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre *= nums[i];
            suf *= nums[n - i - 1];

            ans = max(ans, max(pre, suf));
        }

        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxp = nums[0];
        int minp = nums[0];

        for(int i = 1; i < n; i++) {
            int curr = nums[i];

            if(curr < 0) swap(maxp, minp);

            maxp = max(curr, curr * maxp);
            minp = min(curr, curr * minp);

            ans = max(ans, maxp);
        }

        return ans;
    }
};