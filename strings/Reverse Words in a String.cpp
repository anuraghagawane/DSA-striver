class Solution {
public:
    string reverseWords(string s) {
        vector<string> ansVec;

        int i, j;
        i = j = s.length() - 1;

        string ans = "";

        while(i >= 0) {
            if(s[i] == ' ') {
                if(i == j) {
                    i--;
                    j--;
                    continue;
                }

                if(!ans.empty()) ans += " ";
                ans += s.substr(i+1, j - i);
                i--;
                j = i;
            }
            else {
                i--;
            }
        }
        if(!ans.empty()) ans += " ";
        ans += s.substr(i+1, j - i);

        if(ans[ans.length()-1] == ' ') {
            ans.pop_back();
        }

        return ans;
    }

};