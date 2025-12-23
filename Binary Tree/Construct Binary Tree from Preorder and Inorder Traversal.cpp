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
    unordered_map<int, int> elIndMap;
public:
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if(inStart > inEnd || preStart > preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = elIndMap[preorder[preStart]];

        int numLeft = inRoot - inStart;

        root -> left = construct(preorder, inorder, preStart + 1, preStart + numLeft, inStart, inRoot - 1);
        root -> right = construct(preorder, inorder, preStart + numLeft + 1, preEnd, inRoot + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            elIndMap[inorder[i]] = i;
        }

        return construct(preorder, inorder, 0, n-1, 0, n-1);

    }
};