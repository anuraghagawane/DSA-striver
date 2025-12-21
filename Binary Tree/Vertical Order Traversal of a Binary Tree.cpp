/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int horDis, int level, map<int, vector<pair<int, int>>>& mp) {
        if(root == NULL) return;

        if(mp.find(horDis) != mp.end()) {
            mp[horDis].push_back({level, root->val});
        }
        else {
            mp[horDis] = {{level, root->val}};
        }

        traverse(root->left, horDis - 1, level + 1, mp);
        traverse(root->right, horDis + 1, level + 1, mp);
    }
    static bool comp(pair<int, int> p1, pair<int,int> p2) {
        if(p1.first < p2.first) {
            return true;
        }
        else if(p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;

        traverse(root, 0, 0, mp);

        vector<vector<int>> ans;

        for(auto [key, val]: mp) {
            sort(val.begin(), val.end(), comp);
            vector<int> temp;
            for(auto v : val) {
                temp.push_back(v.second);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};