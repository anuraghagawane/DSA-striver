/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans;
public:
    bool isAnc(bool left, bool right, TreeNode* root, TreeNode* p, TreeNode* q){
        // cout<<left<<" "<<right<<" "<<root->val<<" "<<p->val<<" "<<q->val<<endl;
        if(left && right) return true;

        if((left || right) && (root == p || root == q)) {
            return true;
        }

        return false;
    }
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        bool left = solve(root->left, p, q);
        bool right = solve(root->right, p, q);

        if(isAnc(left, right, root, p, q) && ans == NULL) ans = root;

        return left || right || root == p || root == q;
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if(root == NULL || p == root || q == root) {
            return root;
        }

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else {
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        return LCA(root, p, q);
        return ans;
    }
};