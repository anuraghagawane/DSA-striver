class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        bool isNeg = false;

        while(s[i] == ' ') i++;

        if(s[i] == '-' || s[i] == '+') {
            if(s[i] == '-') {
                isNeg = true;
            }
            i++;
        }

        while(s[i] == '0') {
            i++;
        }

        string num = "";
        while(s[i] >= '0' && s[i] <= '9') {
            num += s[i];
            i++;
        }

        int digits = num.size();

        int ans = 0;
        if(digits > 10) {
            return isNeg ? INT_MIN : INT_MAX;
        }
        for(int i = 0; i<digits; i++) {
            long long n = (num[i]-'0') * pow(10, digits - i - 1);
            if(n > INT_MAX) {
                ans = isNeg ? INT_MIN : INT_MAX;
                isNeg = false;
                break;
            }
            if(ans > 0 && (INT_MAX - ans < n)) {
                ans = isNeg ? INT_MIN : INT_MAX;
                isNeg = false;
                break;
            }
            ans += n;
        }
        return isNeg ? 0 - ans : ans;
    }
};