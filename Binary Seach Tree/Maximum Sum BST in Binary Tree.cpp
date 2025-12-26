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
    int maxSum = 0;
    pair<int,pair<int,int>> solve(TreeNode* root) {
        if(root == NULL) return {0, {INT_MAX, INT_MIN}};

        pair<int,pair<int,int>> left = solve(root -> left);
        auto [leftSum, leftPair] = left;
        auto [leftMin, leftMax] = leftPair;
        pair<int,pair<int,int>> right = solve(root -> right);
        auto [rightSum, rightPair] = right;
        auto [rightMin, rightMax] = rightPair;

        if(root -> val > leftMax && root -> val < rightMin) {
            int currSum = root -> val + leftSum + rightSum;
            maxSum = max(currSum, maxSum);
            return {currSum, {min(root -> val, leftMin), max(root -> val, rightMax)}};
        }

        return {0, {INT_MIN, INT_MAX}};
    }
public:
    int maxSumBST(TreeNode* root) {
        solve(root);

        return maxSum;
    }
};