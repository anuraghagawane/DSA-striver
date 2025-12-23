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
    void solve(TreeNode* root) {
        if(root == NULL) return;
        // solve(root -> left);

        if(root -> left != NULL) {
            TreeNode* leftsright = root -> left;
            while(leftsright -> right != NULL) leftsright = leftsright -> right;
            if(root != NULL) cout<<leftsright->val<<endl;
            TreeNode* rootRight = root -> right;
            leftsright -> right = rootRight;
            root -> right = root -> left;
            root -> left = NULL;
        }
        solve(root -> right);
    }
    void flatten(TreeNode* root) {
        // solve(root);
        TreeNode* curr = root;
        while(curr) {
            if(curr -> left != NULL) {
                TreeNode* leftsright = curr -> left;
                while(leftsright -> right != NULL) leftsright = leftsright -> right;
                TreeNode* currRight = curr -> right;
                leftsright -> right = currRight;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }

            curr = curr -> right;
        }
    }
};