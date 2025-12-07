class Solution {
public:
    bool isOpening(char ch) {
        if(ch == '(' || ch == '[' || ch == '{') return true;
        return false;
    }

    char getOpening(char ch) {
        if(ch == ')') {
            return '(';
        }
        if(ch == '}') return '{';
        if(ch == ']') return '[';

        return '(';
    }
    bool isValid(string s) {
        stack<int> st;

        for(auto ch: s) {
            if(isOpening(ch)) {
                st.push(ch);
            }
            else {
                if(st.empty()) return false;
                if(getOpening(ch) ==  st.top()) {
                    st.pop();
                }
                else return false;
            }
        }

        return st.empty();
    }
};