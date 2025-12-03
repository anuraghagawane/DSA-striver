class Solution {
  public:
    bool canPlace(vector<int> &stalls, int k, int distance){
        int count = 1;
        int last = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - last >= distance) {
                count++;
                last = stalls[i];
            }
            if(count >= k) {
                return true;
            }
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls[stalls.size()-1] - stalls[0];
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(canPlace(stalls, k, mid)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return high;
        
    }
};