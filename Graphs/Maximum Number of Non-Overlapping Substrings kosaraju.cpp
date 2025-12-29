class Solution {
    void dfs(int start, vector<vector<int>>& g, vector<int>& vis, stack<int>& st) {
        vis[start] = 1;

        for(auto node: g[start]) {
            if(!vis[node]) dfs(node, g, vis, st);
        }
        st.push(start);
    }

    void dfs2(int start, vector<vector<int>>& gr, vector<int>& vis,vector<int>& temp) {
        vis[start] = 1;
        //check by refactoring this.
        if(gr[start].size() == 0) {
            return;
        };

        temp.push_back(start);
        for(auto node: gr[start]) {
            if(!vis[node]) dfs2(node, gr, vis, temp);
        }
    }

    void dfs_to_check_outdegree(int start, vector<vector<int>>& g, map<int,int> &mp, vector<int> & vis, bool &flg) {
        vis[start] = 1;

        for(auto node: g[start]) {
            if(mp.find(node) == mp.end()) {
                flg = false;
                return;
            }
            if(!vis[node]) dfs_to_check_outdegree(node, g, mp, vis, flg);
        }
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> l(26, INT_MAX), r(26, INT_MIN);

        for(int i = 0; i < n; ++i) {
            l[s[i]-'a'] = min(l[s[i]-'a'], i);
            r[s[i]-'a'] = i;
        }

        // create the graph
        vector<vector<int>> g(27);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                if(l[s[i] - 'a'] != INT_MAX) {
                    if(l[j] <= i && r[j] >= i) {
                        g[j].push_back(s[i] - 'a');
                    }
                }
            }
        }

        //kosaraju starts
        // get end times
        n = 26;
        stack<int> st;
        vector<int> vis(26, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, g, vis, st);
        }

        // transpose the graph
        vector<vector<int>> gr(n);
        for(int i = 0;  i < n; i++) {
            for(auto ch: g[i]) {
                gr[ch].push_back(i);
            }
        }



        // find SCCs
        vector<vector<int>> scc;
        vis.clear();
        vis.resize(26, 0);

        for(int i=0;i<n;i++) {
            int node = st.top();
            st.pop();

            if(vis[node]) continue;
            vector<int> temp;
            dfs2(node, gr, vis, temp);
            scc.push_back(temp);
        }

        vector<string> ans;
        for(auto it: scc) {
            vector<int> vis(n, 0);
            if(it.size() != 0) {
                map<int, int> mp;
                for(auto ele: it) {
                    mp[ele] = 1;
                }
                bool flg = true;
                dfs_to_check_outdegree(it[0], g, mp, vis, flg);

                if(flg == true) {
                    int min_l = 1e9, max_r = -1;
                    for(auto ele: it) {
                        min_l = min(min_l, l[ele]);
                        max_r = max(max_r, r[ele]);
                    }

                    ans.push_back(s.substr(min_l, max_r - min_l + 1));
                }
            }
        }

        return ans;
    }
};