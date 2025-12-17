class Solution {
  public:
    int minForAWindow(vector<int>& arr, int k)  {
        int n = arr.size();
        int ans = INT_MIN;
        deque<int> q;
        
        for(int i = 0; i < k; i++) {
            while(!q.empty() && q.back() > arr[i]) {
                q.pop_back();
            }
            q.push_back(arr[i]);
        }
        ans = max(q.front(), ans);
        int i = 0; int j = k;
        while(j < n) {
            if(q.front() == arr[i]) {
                q.pop_front();
            }
            
            while(!q.empty() && q.back() > arr[j]) {
                q.pop_back();
            }
            
            q.push_back(arr[j]);
            
            ans = max(ans, q.front());
            
            i++;
            j++;
            
        }
        
        return ans;
    }
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        
        // vector<int> ans;
        // for(int i = 0; i < arr.size(); i++) {
        //     ans.push_back(minForAWindow(arr, i+1));
        // }
        
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i==n || arr[st.top()] >= arr[i])) {
                int top = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                int size = right - left - 1;
                ans[size - 1] = max(ans[size - 1], arr[top]); 
            }
            st.push(i);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
    }
};