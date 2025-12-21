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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        long long maxWidth = 0;

        // node, position
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()) {
            long long size = q.size();
            long long first = q.front().second;
            long long last = q.back().second;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                int pos = q.front().second - first;

                if(curr->left != NULL) {
                    q.push({curr->left, (long long)2 * pos + 1});
                }

                if(curr->right != NULL) {
                    q.push({curr->right, (long long)2 * pos + 2});
                }

                maxWidth = max(maxWidth, last - first + 1);
                q.pop();
            }
        }


        return maxWidth;
    }
};