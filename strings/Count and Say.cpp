class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        int i = 1;
        while(i < n) {
            string news = "";
            int count = 0;
            char currEl = '-';
            for(int i = 0; i < curr.length(); i++) {
                if(curr[i] == currEl) {
                    count++;
                }
                else {
                    if(count != 0) {
                        news += to_string(count);
                        news += currEl;
                    }
                    currEl = curr[i];
                    count = 1;
                }
            }
            if(count != 0) {
                news += to_string(count);
                news += currEl;
            }
            curr = news;
            i++;
        }

        return curr;
    }
};