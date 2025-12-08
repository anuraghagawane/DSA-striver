class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        
        vector<int> ans;
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(st.top());
            }
            
            st.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};