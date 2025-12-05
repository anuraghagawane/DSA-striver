class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(auto num: nums) {
            mp[num]++;
        }

        // priority_queue<pair<int, int>> pq;
        // for(auto m : mp) {
        //     pq.push({m.second, m.first});
        // }

        // vector<int> ans;
        // while(k--) {
        //     auto top = pq.top();
        //     pq.pop();
        //     ans.push_back(top.second);
        // }

        vector<vector<int>> freq(nums.size(), vector<int>());
        for(auto m : mp) {
            freq[m.second-1].push_back(m.first);
        } 

        vector<int> ans;
        for(int i = freq.size() - 1; i >= 0; i--) {
            while(freq[i].size() > 0 && k > 0) {
                ans.push_back(freq[i].back());
                freq[i].pop_back();
                k--;
            }
        }

        return ans;
    }
};