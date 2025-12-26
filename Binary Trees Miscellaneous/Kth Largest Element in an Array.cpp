class Solution {
public:
    int randomIndex(int &left, int &right) {
        // length of the array 
        int len = right - left + 1;
        
        // Return a random index from the array 
        return (rand() % len) + left;
    }
    int quickSelect(vector<int>& nums, int k, int l, int r) {
        int pivotIndex = randomIndex(l, r);
        swap(nums[r], nums[pivotIndex]);
        int p = r;
        int ind = l;
        for(int i = l; i < r; i++) {
            if(nums[i] <= nums[p]){
                swap(nums[i], nums[ind]);
                ind++;
            }
        }

        swap(nums[ind], nums[p]);
        if(ind < k) {
            return quickSelect(nums, k, ind + 1, r);
        }
        else if (ind > k) {
            return quickSelect(nums, k, l, ind - 1);
        }
        else {
            return nums[ind];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for(auto num : nums) {
        //     pq.push(num);
        // }

        // while(--k) {
        //     pq.pop();
        // }

        // return pq.top();

        k = nums.size() - k;
        return quickSelect(nums, k, 0, nums.size() - 1);
    }
};