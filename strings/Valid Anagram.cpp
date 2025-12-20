Valid Anagramclass Solution {
public:
    int getind(char ch) {
        return ch - 'a';
    }
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> chs(26, 0);

        for(int i = 0; i < s.length(); i++) {
            chs[getind(s[i])]++;
        }

        for(int i = 0; i < t.length(); i++) {
            if(chs[getind(t[i])] <= 0) {
                return false;
            }

            chs[getind(t[i])]--;
        }

        return true;
    }
};