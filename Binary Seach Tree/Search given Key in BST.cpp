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
    TreeNode* ans;
public:
    Solution() {
        ans = NULL;
    }

    void solve(TreeNode* root, int val) {
        if(root == NULL) return;


        if(ans != NULL) return;

        if(root -> val == val) {
            ans = root;
            return;
        }
        else if(root -> val > val) {
            solve(root -> left, val);
        }
        else {
            solve(root -> right, val);
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        // solve(root, val);
        // return ans;
        while(root != NULL && root->val != val) {
            if(val < root -> val) root = root -> left;
            else root = root -> right;
        }

        return root;
    }
};