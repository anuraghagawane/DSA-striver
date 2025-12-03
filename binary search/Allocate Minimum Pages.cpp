class Solution {
  public:
    int countStudents(vector<int> arr, int pages) {
        int students = 1;
        int studentPages = 0;
        
        for(auto p: arr) {
            if(studentPages + p <= pages){
                studentPages += p;
            }
            else {
                students++;
                studentPages = p;
            }
        }
        
        return students;
    }
    int solve(vector<int>& arr, int n, int k){
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(arr, mid);
            
            if(students <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        int n = arr.size();
        return solve(arr, n, k);
    }
};