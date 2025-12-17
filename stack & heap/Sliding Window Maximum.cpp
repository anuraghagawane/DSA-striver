class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;

        for(int i = 0; i<k; i++) {
            while(!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }
            q.push_back(nums[i]);
        }

        vector<int> ans;
        int maxe = q.front();
        ans.push_back(maxe);

        int f = 0, e = k;
        while(e < nums.size()) {
            if(q.front() == nums[f]) q.pop_front();

            while(!q.empty() && q.back() < nums[e]) {
                q.pop_back();
            }
            q.push_back(nums[e]);
            int maxe = q.front();
            ans.push_back(maxe);
            f++;
            e++;
        }

        return ans;
    }
};