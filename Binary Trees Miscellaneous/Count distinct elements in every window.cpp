class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = arr.size();
        int i = 0, j = 0;
        while(j < k) {
            mp[arr[j]]++;
            j++;
        }
        
        ans.push_back(mp.size());
        
        while(j < arr.size()) {
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(arr[i]);
            i++;
            
            mp[arr[j]]++;
            
            ans.push_back(mp.size());
            
            j++;
        }
        
        return ans;
    }
};