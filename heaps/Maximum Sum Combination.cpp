class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> vis;
        
        pq.push({a[0] + b[0], 0, 0});
        vis.insert({0, 0});
        
        vector<int> ans;
        
        while(ans.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            
            ans.push_back(sum);
            
            if(i+1 < a.size() && !vis.count({i+1, j})){
                pq.push({a[i+1] + b[j], i+1, j});
                vis.insert({i+1, j});
            }
            
            if(j+1 < b.size() && !vis.count({i, j+1})){
                pq.push({a[i] + b[j+1], i, j+1});
                vis.insert({i, j+1});
            }
        }
        
        return ans;
    }
};