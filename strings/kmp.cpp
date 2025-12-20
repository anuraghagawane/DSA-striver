class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;

        vector<int> lps(needle.length(), 0);

        int prevlps = 0;
        int i = 1;

        while (i < needle.length()) {
            if(needle[i] == needle[prevlps]) {
                lps[i] = prevlps + 1;
                prevlps++;
                i++;
            }
            else if(prevlps == 0) {
                lps[i] = 0;
                i++;
            }
            else {
                prevlps = lps[prevlps - 1];
            }
        }

        i = 0;
        int j = 0;

        while(i < haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                if(j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
            if(j == needle.length()) {
                return i - needle.length();
            }
        }

        return -1;
    }
};