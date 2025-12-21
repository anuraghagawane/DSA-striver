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
    int ans;
public:
    void solve(TreeNode* root, int level) {
        if(root == NULL) return;

        if(ans < level) ans = level;
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
    int maxDepth(TreeNode* root) {
        ans = 0;
        
        solve(root, 1);

        return ans;
    }
};