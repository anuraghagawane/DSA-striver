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
    unordered_map<int, int> inMap;
public:
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int postStart, int postEnd, int inStart, int inEnd) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[postorder[postEnd]];

        int numRight = inEnd - inRoot;

        root -> left = construct(inorder, postorder, postStart, postEnd - numRight - 1, inStart, inRoot - 1);
        root -> right = construct(inorder, postorder, postEnd - numRight, postEnd - 1, inRoot + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return construct(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};