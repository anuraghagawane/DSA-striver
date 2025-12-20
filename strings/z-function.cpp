class Solution {
public:
    vector<int> zAlgo(string s) {
        int n = s.length();
        int l = 0, r = 0;
        vector<int> z(n, 0);
        for(int i = 1; i < n; i++) {
            if(i <= r) {
                // min(known, boundary till right)
                z[i] = min(z[i - l], r - i + 1);
            }

            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }
    int strStr(string haystack, string needle) {
        string combined = needle + "$" + haystack;

        vector<int> z = zAlgo(combined);

        for(int i = needle.length() + 1; i < combined.length(); i++) {
            if(z[i] == needle.length()) {
                return i - needle.length() - 1;
            }
        }

        return -1;
    }
};