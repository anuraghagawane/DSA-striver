class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int n = version1.length();
        int m = version2.length();

        while(i < n && j < m) {
            string v1Curr = "";
            while(i < n && version1[i] != '.') {
                v1Curr += version1[i];
                i++;
            }

            string v2Curr = "";
            while(j < m && version2[j] != '.') {
                v2Curr += version2[j];
                j++;
            }
            
            int iv1 = stoi(v1Curr);
            int iv2 = stoi(v2Curr);
            if(iv1 < iv2) {
                return -1;
            }
            else if(iv2 < iv1) {
                return 1;
            }

            i++;
            j++;
        }

        string v1Curr = "";
        while(i < n) {
            while(i < n && version1[i] != '.') {
                v1Curr += version1[i];
                i++;
            }
            if(v1Curr.length() > 0 && stoi(v1Curr) > 0) {
                return 1;
            }
            v1Curr = "";
            i++;
        }
        if(v1Curr.length() > 0 && stoi(v1Curr) > 0) {
            return 1;
        }

        string v2Curr = "";
        while(j < m) {
            while(j < m && version2[j] != '.') {
                v2Curr += version2[j];
                j++;
            }
            if(v2Curr.length() > 0 && stoi(v2Curr) > 0) {
                return -1;
            }
            v2Curr = "";
            j++;
        }
        if(v2Curr.length() > 0 && stoi(v2Curr) > 0) {
            return -1;
        }

        return 0;
    }
};