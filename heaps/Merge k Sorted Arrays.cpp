class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({mat[i][0], {i, 0}});
        }
        
        vector<int> result;
        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();
            
            int val = item.first;
            int i = item.second.first;
            int j = item.second.second;
            
            result.push_back(val);
            if(j + 1 >= m) {
                continue;
            }
            pq.push({mat[i][j+1], {i, j+1}});
        }
        
        return result;
        
    }
};