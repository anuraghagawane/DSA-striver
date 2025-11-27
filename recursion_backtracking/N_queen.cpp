class Solution {
    vector<vector<string>> ans;
public:
    bool isSafe(vector<string>& curr, int r, int c, int n){
        for(int i = r; i >= 0; i--) {
            if(curr[i][c] == 'Q') {
                return false;
            }
        }

        int i = r, j = c;

        while(i>=0 && j>=0) {
            if(curr[i][j] == 'Q') {
                return false;
            }
            i--; j--;
        }
        i = r, j = c;
        while(i>=0 && j<n) {
            if(curr[i][j] == 'Q') {
                return false;
            }
            i--; j++;
        }

        return true;
    }
    bool isSafe2(int r, int c, int n, vector<int>& up, vector<int>& leftDai, vector<int>& rightDai) {
        if(up[c] || rightDai[r+c] || leftDai[n-1+c-r]) {
            return false;
        }
        return true;
    }
    void solve(vector<string>& curr, int r, int n, vector<int>& up, vector<int>& leftDai, vector<int>& rightDai) {
        if(r>=n) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(isSafe2(r, i, n, up, leftDai, rightDai)){
                curr[r][i] = 'Q';
                up[i] = rightDai[r+i] = leftDai[n-1+i-r] = 1;
                solve(curr, r+1, n, up, leftDai, rightDai);
                curr[r][i] = '.';
                up[i] = rightDai[r+i] = leftDai[n-1+i-r] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr;
        vector<int> up(n, 0);
        vector<int> leftDai(2*n - 1, 0);
        vector<int> rightDai(2*n - 1, 0);
        for(int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < n; j++) {
                s += ".";
            }
            curr.push_back(s);
        }
        solve(curr, 0, n, up, leftDai, rightDai);

        return ans;
    }
};