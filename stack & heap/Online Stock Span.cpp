class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int currAns = 1;
        while(!st.empty() && st.top().first <= price) {
            currAns += st.top().second;
            st.pop();
        }
        st.push({price, currAns});
        return currAns;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */