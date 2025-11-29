class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            int firstEl = mid;
            int secondEl = mid + 1;
            if(mid > 0 && nums[mid-1] == nums[mid]) {
                firstEl--;
                secondEl--;
            }
            else if(mid + 1 < n && nums[mid+1] == nums[mid]) {
                // do nothing
            }
            else {
                return nums[mid];
            }

            if(firstEl % 2){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};