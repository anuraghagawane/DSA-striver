class Solution {
public:
    string getPali(string s, int i, int j) {
        int n = s.length();
        while (i >= 0 && j < n) {
            if(s[i] == s[j]) {
                i--;
                j++;
            }
            else {
                break;
            }
        }

        return s.substr(i+1, j - 1 - i);
    }

    string longestPalindrome(string s) {
        int n =  s.length();
        if(n <= 1) return s;
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(i-1 >= 0 && i+1 < n) {
                if(s[i-1] == s[i+1]) {
                    string currAns = getPali(s, i-1, i+1);
                    if(ans.length() < currAns.length()) {
                        ans = currAns;
                    }
                }
            }
            if(i+1 < n) {
                if(s[i]==s[i+1]) {
                    string currAns = getPali(s, i, i+1);
                    if(ans.length() < currAns.length()) {
                        ans = currAns;
                    }
                }
            }
        }
        if(ans.length() == 0) ans += s[0];
        return ans;
    }
};