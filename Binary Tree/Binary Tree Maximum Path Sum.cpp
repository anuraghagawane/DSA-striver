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
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        ans = max(ans, root -> val + left + right);

        return max(0, max(root-> val + left, root->val + right));
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);

        return ans;
    }
};