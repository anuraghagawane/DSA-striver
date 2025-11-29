class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int i = 0, j = m;
        
        while(i <= j) {
            int mid = (i+j)/2;
            
            int nthPower = 1;
            for(int i = 0; i<n; i++) {
                nthPower *= mid;
            }
            
            if(nthPower == m) {
                return mid;
            }else if(nthPower > m) {
                j = mid-1;
            }
            else {
                i = mid+1;
            }
        }
        
        return -1;
        
    }
};