class Solution {
    unordered_map<int, int> dp;
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i = 0; i < startTime.size(); i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        // memo
        // return dfs(0, jobs.size(), jobs);

        int n = jobs.size();
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            int next = findNextBinary(i, jobs);
            int nottake = dp[i+1];
            int take = jobs[i][2] + (next == -1 ? 0 : dp[next]);

            dp[i] = max(take, nottake);
        }

        return dp[0];
    }

    int dfs(int i, int n, vector<vector<int>>& jobs) {
        if(i == n) return 0;
        if(dp.count(i)) return dp[i];
        int next = findNextBinary(i, jobs);
        int nottake = dfs(i+1, n, jobs);
        int take = jobs[i][2] + (next == -1 ? 0 : dfs(next, n, jobs));

        return dp[i] = max(take, nottake);
    }

    int findNext(int i, vector<vector<int>>& jobs) {
        for(int next = i + 1; next < jobs.size(); next++) {
            if(jobs[next][0] >= jobs[i][1]) return next;
        }
        return -1;
    }

    int findNextBinary(int i, vector<vector<int>>& jobs) {
        int n = jobs.size();
        int l = i+1;
        int h = n - 1;
        int target = jobs[i][1];
        int result = -1;

        while(l <= h) {
            int mid = (l + h) / 2;
            if(jobs[mid][0] >= target) {
                h = mid - 1;
                result = mid;
            }
            else l = mid + 1;
        }

        return result;
    }
};