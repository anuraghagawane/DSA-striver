class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;

        for(int i = 0; i<=n; i++) { // i is right smaller
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()]; // curr eleements
                st.pop();

                // int left = st.top(); // this is left smaller
                int width = 0;
                if(st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                ans = max(ans, width * height);
            }

            st.push(i);
        }

        return ans;
    }
};