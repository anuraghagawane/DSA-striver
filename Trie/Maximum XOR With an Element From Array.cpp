istruct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit) {
        links[bit] = new Node();
    }
};

class Trie {
    Node* root = new Node();
public:
    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node -> put(bit);
            }
            node = node -> get(bit);
        }
    }

    int getMaxXor(int num) {
        Node* node = root;
        int maxXor = 0;
        for(int i = 31; i >= 0; i--) {
            if(node == NULL) return -1;
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)) {
                maxXor = maxXor | (1 << i);
                node = node -> get(1 - bit);
            }
            else {
                node = node -> get(bit);
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int n = nums.size();
        vector<int> ans(queries.size(), -1);

        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int,int>>> sortedQueries;

        for(int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        int i = 0;

        for(auto query: sortedQueries) {
            while(i < n && nums[i] <= query.first) {
                trie.insert(nums[i]);
                i++;
            }

            int maxXor = trie.getMaxXor(query.second.first);
            if(maxXor != -1) {
                ans[query.second.second] = maxXor;
            }
        }

        return ans;
    }
};