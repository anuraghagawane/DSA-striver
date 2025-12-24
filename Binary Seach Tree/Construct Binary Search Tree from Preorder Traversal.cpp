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
    int getBoundary(vector<int>& preorder, int start, int end, int val) {
        
        while(start <= end) {
            int mid = (start + end + 1) / 2;
            if(preorder[mid] == val) return mid + 1;
            else if(preorder[mid] < val) start = mid + 1;
            else end = mid - 1;
        }

        return start;
    }
    TreeNode* construct(vector<int>& preorder, int start, int end) {
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);

        int boundary = getBoundary(preorder, start, end, preorder[start]);

        root -> left = construct(preorder, start + 1, boundary - 1);
        root -> right = construct(preorder, boundary, end);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size() - 1);
    }
};