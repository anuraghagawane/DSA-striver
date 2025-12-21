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
    void traverse(TreeNode* root, int level, vector<int>& view) {
        if(root == NULL) return;

        if(level == view.size()) {
            view.push_back(root->val);
        }

        traverse(root->right, level+1, view);
        traverse(root->left, level+1, view);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;

        traverse(root, 0, view);

        return view;
    }
};