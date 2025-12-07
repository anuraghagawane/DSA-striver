class Solution {
  public:
    void sortInsert(stack<int> &st, int x) {
        if(st.empty() || st.top() < x) {
            st.push(x);
            return;
        }
        
        int curr = st.top();
        st.pop();
        
        sortInsert(st, x);
        
        st.push(curr);
    }
  
    void sortStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
        
        int curr = st.top();
        st.pop();
        
        sortStack(st);
        
        sortInsert(st, curr);
    }
};
